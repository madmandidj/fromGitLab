//#define _GNU_SOURCE
#include "Socket_t.h"
#include "../ServerSock/ServerSock.h"
#include "../NetExceptions/NetExceptions.h"
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>

namespace netcpp
{
static const size_t BUFFER_LEN = 256; //TODO: This should be inside Msg_t

Socket_t::Socket_t():m_isConnected(false)
{
	//Empty
}

Socket_t::~Socket_t()
{
	if (m_isConnected)
	{
		Close();
	}
	std::cout << "~Socket_t, fd = " << m_fd.m_rawFd << std::endl;
}

FD_t Socket_t::Accept(int _flags) 
{
	ThrowIfNotServerSocket(__FILE__, __LINE__, ", Accept() this object is not ServerSock");
	socklen_t addr_len = sizeof(m_sin.m_rawSin);
	FD_t fd;
	fd = accept4(m_fd.m_rawFd, (struct sockaddr*) &m_sin.m_rawSin, &addr_len, _flags);
	if (fd == -1)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			throw EagainExc(__FILE__, __LINE__, ", accept() EAGAIN");
		}
		else if (errno == EMFILE)
		{
			throw TooManyOpenFilesExc(__FILE__, __LINE__, ", accept() EMFILE");
		}
		else
		{
			throw UnspecifiedErrnoExc(__FILE__, __LINE__, ", accept() unspecified errno");
		}
	}
	return fd;
}

void Socket_t::Connect()
{
	ThrowIfIsServerSocket(__FILE__, __LINE__, ", Connect() this object is a ServerSock");
	if (connect(m_fd.m_rawFd, (struct sockaddr*) &m_sin.m_rawSin, sizeof(m_sin.m_rawSin)) < 0)
	{
		throw ConnectFailedExc(__FILE__, __LINE__, ", connect() failed");
	}
	m_isConnected = true;
}

void Socket_t::Close()
{
	close(m_fd.m_rawFd);
	m_isConnected = false;
}

int Socket_t::Send(void* _data, size_t _length, int _flags) const
{
	ThrowIfIsServerSocket(__FILE__, __LINE__, ", Send() this object is a ServerSock");
	ThrowIfDisconnected(__FILE__, __LINE__, ", Send() socket is disconnected");
	int numOfBytesSent = send(m_fd.m_rawFd, _data, _length, _flags);
	if (-1 == numOfBytesSent)
	{
		if (errno != EPIPE)
		{			
			throw UnspecifiedErrnoExc(__FILE__, __LINE__, ", Send() unspecified errno");
		}
		throw BrokenPipeExc(__FILE__, __LINE__, ", Send() broken pipe");
	}
	return numOfBytesSent;
}


size_t Socket_t::Receive() const
{
	ThrowIfIsServerSocket(__FILE__, __LINE__, ", Receive() this object is a ServerSock");
	ThrowIfDisconnected(__FILE__, __LINE__, ", Receive() socket is disconnected");
	int numOfBytesRead = read(m_fd.m_rawFd, m_buffer, BUFFER_LEN);
	if(0 == numOfBytesRead)
	{
		return 0;
	}
	if(-1 == numOfBytesRead)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)
		{
			throw EagainExc(__FILE__, __LINE__, ", Receive() EAGAIN");
		}
		throw UnspecifiedErrnoExc(__FILE__, __LINE__, ", Receive() Unspecified errno");
	}
	return numOfBytesRead;
}

void Socket_t::Socket(int _family, int _type, int _protocol)
{
	if ((m_fd = socket(_family, _type, _protocol)) < 0)
	{
		throw SocketFailedExc(__FILE__, __LINE__, ", socket() failed");
	}
}

void Socket_t::SetSockOpt(int _level, int _optName, int _optVal)
{
	if (setsockopt(m_fd.m_rawFd, _level, _optName, &_optVal, sizeof(_optVal)) < 0)
	{
		throw SetSockOptFailedExc(__FILE__, __LINE__, ", setsockopt() failed");
	}
}

void Socket_t::Bind()
{
	if(bind(m_fd.m_rawFd, ((struct sockaddr*) &(m_sin.m_rawSin)), sizeof(m_sin.m_rawSin)) < 0)
	{
		throw BindFailedExc(__FILE__, __LINE__, ", bind() failed");
	}
}

void Socket_t::Listen(size_t _backLog)
{
	if (listen(m_fd.m_rawFd, _backLog) < 0)
	{
		throw ListenFailedExc(__FILE__, __LINE__, ", listen() failed");
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

void Socket_t::ThrowIfIsServerSocket(const char* _fileName, int _lineNum, const char* _userStr) const
{
	const ServerSock* serverSock;
	serverSock = dynamic_cast<const ServerSock*>(this);
	if (0 != serverSock)
	{
		throw IsServerSocketExc(_fileName, _lineNum, _userStr);
	}
}

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








