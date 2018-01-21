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
	m_isConnected = true; //TODO: How to ensure that FD was connected? _fd.IsActive() ?
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
	ThrowIfDisconnected(__FILE__, __LINE__, "in Send(), socket is disconnected");
	int numOfBytesSent = send(m_fd.m_rawFd, _data, _length, MSG_NOSIGNAL);
	if (-1 == numOfBytesSent)
	{
		if (errno != EPIPE)
		{			
			throw UnspecifiedErrnoExc(__FILE__, __LINE__, "in Send(), unspecified errno");
		}
		throw BrokenPipeExc(__FILE__, __LINE__, "in Send(), broken pipe");
	}
	return numOfBytesSent;
}

size_t CommSock::Receive() const //TODO: return a Msg_t here
{
	ThrowIfDisconnected(__FILE__, __LINE__, "in Receive(), socket is disconnected");
	int numOfBytesRead = read(m_fd.m_rawFd, m_buffer, BUFFER_LEN);
	if(0 == numOfBytesRead)
	{
		return 0;
	}
	if(-1 == numOfBytesRead)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)
		{
			throw EagainExc(__FILE__, __LINE__, "in Receive(), read() EAGAIN");
		}
		throw UnspecifiedErrnoExc(__FILE__, __LINE__, "in Receive(), unspecified errno");
	}
	return numOfBytesRead;
}

char* CommSock::GetBuf() const
{
	ThrowIfDisconnected(__FILE__, __LINE__, "in GetBuf(), socket is disconnected");
	return m_buffer;
}
}//namespace netcpp

