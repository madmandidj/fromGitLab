#include "ClientSock.h"
#include "../NetExceptions/NetExceptions.h"
#include<stdexcept>
#include <unistd.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<iostream>
namespace netcpp
{
static const size_t BUFFER_LEN = 256;

ClientSock::ClientSock():m_isConnected(false)
{
	//Empty
}

ClientSock::~ClientSock()
{
	if (m_isConnected)
	{
		close(m_fd.GetRawFD());
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
		throw std::runtime_error("Client is already connected");
	}
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd < 0)
	{
		throw std::runtime_error("Client socket() failed");
	}
	
	memset(&m_sin.GetRawSin(), 0, sizeof(m_sin.GetRawSin())); //TODO: change this to reset()
	m_sin.SetSockAddrIn(AF_INET, _port, _ip);
	
	if (connect(m_fd.GetRawFD(), (struct sockaddr*) &m_sin.GetRawSin(), sizeof(m_sin.GetRawSin())) < 0)
	{
		throw std::runtime_error("Client connect() failed");
	}
	m_isConnected = true;
}

void ClientSock::Disconnect()
{
	if (m_isConnected)
	{
		close(m_fd.GetRawFD());
		m_isConnected = false;
	}
	else
	{
		throw std::runtime_error("ClientSock::Disconnect() Client is not connected");
	}
}

int ClientSock::Send(void* _data, size_t _length) const
{
	if (m_isConnected)
	{
		return send(m_fd.GetRawFD(), _data, _length, MSG_NOSIGNAL);
//		printf("Num of bytes wrote = %d\n",numOfBytes);
//		printf("Client sent %lu and %s\n", (long unsigned int)ClientRunNum, data);
	}
	else
	{
		throw std::runtime_error("ClientSock::Send() Client is not connected");
	}
}

int ClientSock::Receive() const
{
	static size_t count = 0;
	
	if (m_isConnected)
	{
		int numOfBytesRead = read(m_fd.GetRawFD(), m_buffer, BUFFER_LEN);
		if(0 == numOfBytesRead)
		{
//			throw std::runtime_error("read() returned 0, Server closed socket");
			throw ReceivedZeroBytes_exc();
		}
		if(-1 == numOfBytesRead)
		{
			if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)
			{
				throw EAGAIN_exc();
//				throw std::runtime_error("read() returned -1, errno is EAGAIN || EWOULDBLOCK || ECONNRESET");
			}
			std::cout << "count is " << count << std::endl;
			perror("read() returned -1");
			throw std::runtime_error("read() returned -1, errno is undetermined");
		}
		++count;
		return numOfBytesRead;
		
	}
	else
	{
		throw std::runtime_error("ClientSock::Receive() Client is not connected");
	}
}

}//namespace netcpp



