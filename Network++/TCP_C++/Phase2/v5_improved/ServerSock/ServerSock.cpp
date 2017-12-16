#include "ServerSock.h"
#include "../CommSock/CommSock.h"
#include "../NetExceptions/NetExceptions.h"
#include <stdexcept>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h> //close()

namespace netcpp
{
ServerSock::ServerSock(int _port, size_t _backLog)
{
	Initialize(_port, _backLog);
}

ServerSock::~ServerSock()
{
	if(m_isConnected)
	{
		close(m_fd.m_rawFd);
	}
}

SharedPtr_t ServerSock::AcceptClient()
{
	socklen_t addr_len = sizeof(m_sin.m_rawSin);
	FD_t fd;
	fd = accept(m_fd.m_rawFd, (struct sockaddr*) &m_sin.m_rawSin, &addr_len);
	if (fd == -1)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			throw EagainExc(__FILE__, __LINE__, "in AcceptClient(), accept() EAGAIN");
		}
		else
		{
			throw UnspecifiedErrnoExc(__FILE__, __LINE__, "in AcceptClient(), accept() unspecified errno");
		}
	}
	SharedPtr_t commSock(new CommSock(fd));
	return commSock;
}

void ServerSock::Initialize(int _port, size_t _backLog)
{
	int optval = 1;
	
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd < 0)
	{
		throw SocketFailedExc(__FILE__, __LINE__, "in Initialize(), socket() failed");
	}
	if (setsockopt(m_fd.m_rawFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		throw SetSockOptFailedExc(__FILE__, __LINE__, "in Initialize(), setsockopt() failed");
	}
	m_sin.SetSockAddrIn(AF_INET, _port, INADDR_ANY);
	if(bind(m_fd.m_rawFd, ((struct sockaddr*) &(m_sin.m_rawSin)), sizeof(m_sin.m_rawSin)) < 0)
	{
		throw BindFailedExc(__FILE__, __LINE__, "in Initialize(), bind() failed");
	}
	if (listen(m_fd.m_rawFd, _backLog) < 0)
	{
		throw ListenFailedExc(__FILE__, __LINE__, "in Initialize(), listen() failed");
	}
	m_isConnected = true;
}
}//namespace netcpp

