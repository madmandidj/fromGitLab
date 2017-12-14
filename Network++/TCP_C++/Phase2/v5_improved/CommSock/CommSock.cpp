#include "CommSock.h"
#include "../NetExceptions/NetExceptions.h"
#include<unistd.h>
#include<stdexcept>
#include<errno.h>

namespace netcpp
{
static const size_t BUFFER_LEN = 256;

CommSock::CommSock(const FD_t& _fd)
{
	m_fd = _fd;
	m_isConnected = true;
}

CommSock::~CommSock()
{
	if(m_isConnected)
	{
		close(m_fd.m_rawFd);
	}
}

int CommSock::Send(void* _data, size_t _length) const
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

int CommSock::Receive() const
{
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
		return numOfBytesRead;
		
	}
	else
	{
		//TODO: add appropriate NetException
		throw std::runtime_error("CommSock::Receive() Socket is not connected");
	}
}

char* CommSock::GetBuf() const
{
	return m_buffer;
}
}//namespace netcpp

