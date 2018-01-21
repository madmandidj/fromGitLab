#include "Socket_t.h"
#include "../ServerSock/ServerSock.h"
#include "../NetExceptions/NetExceptions.h"
#include <errno.h>

namespace netcpp
{
Socket_t::Socket_t():m_isConnected(false)
{
	//Empty
}

Socket_t::~Socket_t()
{
	//Empty
}


FD_t Socket_t::Accept(int _flags) 
{
	//TODO:: Add throwifdisconnected or if this is not serversock
	ThrowIfNotServerSocket(__FILE__, __LINE__, "Accept(), this object is not ServerSock");
	socklen_t addr_len = sizeof(m_sin.m_rawSin);
	FD_t fd;
	fd = accept4(m_fd.m_rawFd, (struct sockaddr*) &m_sin.m_rawSin, &addr_len, _flags);
	if (fd == -1)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			throw EagainExc(__FILE__, __LINE__, "accept() EAGAIN");
		}
		else if (errno == EMFILE)
		{
			throw TooManyOpenFilesExc(__FILE__, __LINE__, "accept() EMFILE");
		}
		else
		{
			throw UnspecifiedErrnoExc(__FILE__, __LINE__, "accept() unspecified errno");
		}
	}
	return fd;
}

void Socket_t::Socket(int _family, int _type, int _protocol)
{
	if ((m_fd = socket(_family, _type, _protocol)) < 0)
	{
		throw SocketFailedExc(__FILE__, __LINE__, "socket() failed");
	}
}

void Socket_t::SetSockOpt(int _level, int _optName, int _optVal)
{
	if (setsockopt(m_fd.m_rawFd, _level, _optName, &_optVal, sizeof(_optVal)) < 0)
	{
		throw SetSockOptFailedExc(__FILE__, __LINE__, "setsockopt() failed");
	}
}

void Socket_t::Bind()
{
	if(bind(m_fd.m_rawFd, ((struct sockaddr*) &(m_sin.m_rawSin)), sizeof(m_sin.m_rawSin)) < 0)
	{
		throw BindFailedExc(__FILE__, __LINE__, "bind() failed");
	}
}

void Socket_t::Listen(size_t _backLog)
{
	if (listen(m_fd.m_rawFd, _backLog) < 0)
	{
		throw ListenFailedExc(__FILE__, __LINE__, "listen() failed");
	}
}

void Socket_t::ThrowIfConnected(const char* _fileName, int _lineNum, const char* _userStr) const
{
	if (m_isConnected)
	{
		throw SocketIsConnectedExc(_fileName, _lineNum, _userStr);
	}
}

void Socket_t::ThrowIfDisconnected(const char* _fileName, int _lineNum, const char* _userStr) const
{
	if (!m_isConnected)
	{
		throw SocketIsDisconnectedExc(_fileName, _lineNum, _userStr);
	}
}

//TODO: This is undefined reference when linking TestClient.out
void Socket_t::ThrowIfNotServerSocket(const char* _fileName, int _lineNum, const char* _userStr) const
{
	const ServerSock* serverSock;
	serverSock = dynamic_cast<const ServerSock*>(this);
	if (0 == serverSock)
	{
		throw NotServerSocketExc(_fileName, _lineNum, _userStr);
	}
}

}//namespace netcpp








