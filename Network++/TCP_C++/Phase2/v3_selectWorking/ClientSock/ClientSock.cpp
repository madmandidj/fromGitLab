#include "ClientSock.h"
#include "../NetExceptions/NetExceptions.h"
#include <stdexcept>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <iostream>

namespace netcpp
{
static const size_t BUFFER_LEN = 256;
ClientSock::ClientSock()
{
	//Empty
}

ClientSock::~ClientSock()
{
	if (m_isConnected)
	{
		close(m_fd.m_rawFd);
		m_isConnected = false;
	}
	std::cout << "~ClientSock()" << std::endl;
}

ClientSock& ClientSock::operator=(const FD_t& _fd)
{
	m_fd = _fd;
	return *this;
}

void ClientSock::Connect(int _port, const char* _ip)
{
	if (m_isConnected)
	{
		throw SocketIsConnectedExc(__FILE__, __LINE__, "in Connect() socket is connected");
	}
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd < 0)
	{
		throw SocketFailedExc(__FILE__, __LINE__, "in Connect(), socket() failed");
	}
	m_sin.Reset();
	m_sin.SetSockAddrIn(AF_INET, _port, _ip);
	
	if (connect(m_fd.m_rawFd, (struct sockaddr*) &m_sin.m_rawSin, sizeof(m_sin.m_rawSin)) < 0)
	{
		throw ConnectFailedExc(__FILE__, __LINE__, "in Connect(), connect() failed");
	}
	m_isConnected = true;
}

void ClientSock::Disconnect()
{
	if (m_isConnected)
	{
		close(m_fd.m_rawFd);
		m_isConnected = false;
	}
	else
	{
		throw SocketIsDisconnectedExc(__FILE__, __LINE__, "in Disconnect() socket is disconnected");
	}
}

int ClientSock::Send(void* _data, size_t _length) const
{
	int numOfBytesSent;
	
	if (!m_isConnected)
	{
		throw SocketIsDisconnectedExc(__FILE__, __LINE__, "in Send() socket is disconnected");
	}
	else
	{
		numOfBytesSent = send(m_fd.m_rawFd, _data, _length, MSG_NOSIGNAL);
		if (-1 == numOfBytesSent)
		{
			if (errno != EPIPE)
			{
				throw UnspecifiedErrnoExc(__FILE__, __LINE__, "send() returned -1");
			}
		}
	}
	return numOfBytesSent;
}

int ClientSock::Receive() const
{
	static size_t count = 0;
	
	if (m_isConnected)
	{
		int numOfBytesRead = read(m_fd.m_rawFd, m_buffer, BUFFER_LEN);
		if(0 == numOfBytesRead)
		{
			throw SocketCloseByPeerExc(__FILE__, __LINE__, "read() returned 0 in Receive()");
		}
		if(-1 == numOfBytesRead)
		{
			if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)
			{
				throw EagainExc(__FILE__, __LINE__, "read() EAGAIN in Receive()");
			}
			throw UnspecifiedErrnoExc(__FILE__, __LINE__, "read() EAGAIN in Receive()");
		}
		++count;
		return numOfBytesRead;
		
	}
	else
	{
		//TODO: add appropriate NetException
		throw std::runtime_error("ClientSock::Receive() Client is not connected");
	}
}
}//namespace netcpp

