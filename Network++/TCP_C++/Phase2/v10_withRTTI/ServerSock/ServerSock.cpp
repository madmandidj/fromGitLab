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
	FD_t fd;
	fd = Accept(0);
	SharedPtr_t commSock(new CommSock(fd));
	return commSock;
}

void ServerSock::Initialize(int _port, size_t _backLog)
{
	Socket(AF_INET, SOCK_STREAM, 0);
	SetSockOpt(SOL_SOCKET, SO_REUSEADDR, 1);
	m_sin.SetSockAddrIn(AF_INET, _port, INADDR_ANY);
	Bind();
	Listen(_backLog);
	m_isConnected = true;
}
}//namespace netcpp


