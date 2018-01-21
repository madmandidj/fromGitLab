#include "ServerSock.h"
#include "../CommSock/CommSock.h"
#include "../FD_t/FD_t.h"
#include<stdexcept>
#include<iostream>
#include <errno.h>
#include<fcntl.h>

namespace netcpp
{
ServerSock::ServerSock(int _port, size_t _backLog)
{
	Initialize(_port, _backLog);
}

ServerSock::~ServerSock()
{
	//TODO:
}

std::tr1::shared_ptr<Socket_t> ServerSock::AcceptClient()
{
//	int flags;
	
	socklen_t addr_len = sizeof(m_sin.GetRawSin());
	FD_t fd;
	fd = accept(m_fd.GetRawFD(), (struct sockaddr*) &m_sin.GetRawSin(), &addr_len);
	if (fd == -1)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			throw std::runtime_error("accept() failed with EAGAIN or EWOULDBLOCK");
		}
		else
		{
			throw std::runtime_error("accept() failed untracked error");
		}
	}
//	if (-1 == (flags = fcntl(fd.GetRawFD(), F_GETFL)))
//	{
//		throw std::runtime_error("AcceptClient() fcntl() F_GETFL failed");
//	}
//	
//	if (-1 == fcntl(fd.GetRawFD(), F_SETFL, flags | O_NONBLOCK))
//	{
//		throw std::runtime_error("AcceptClient() fcntl() F_SETFL failed");
//	}
	std::tr1::shared_ptr<Socket_t> commSock(new CommSock(fd));
	return commSock;
}



void ServerSock::Initialize(int _port, size_t _backLog)
{
	int optval = 1;
//	int flags;
	
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd < 0)
	{
		throw std::runtime_error("socket() failed");
	}
	
//	if (-1 == (flags = fcntl(m_fd.GetRawFD(), F_GETFL)))
//	{
//		throw std::runtime_error("ServerSock, Initialize() fcntl() F_GETFL failed");
//	}
//	
//	if (-1 == fcntl(m_fd.GetRawFD(), F_SETFL, flags | O_NONBLOCK))
//	{
//		throw std::runtime_error("ServerSock, Initialize() fcntl() F_SETFL failed");
//	}
	
	if (setsockopt(m_fd.GetRawFD(), SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		throw std::runtime_error("setsockopt() failed");
	}
	
	m_sin.SetSockAddrIn(AF_INET, _port, INADDR_ANY);
	
	if(bind(m_fd.GetRawFD(), ((struct sockaddr*) &(m_sin.GetRawSin())), sizeof(m_sin.GetRawSin())) < 0)
	{
		throw std::runtime_error("bind() failed");
	}
	
	if (listen(m_fd.GetRawFD(), _backLog) < 0)
	{
		throw std::runtime_error("bind() failed");
	}
}


}//namespace netcpp


