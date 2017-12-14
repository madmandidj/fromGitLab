#include "CommSock.h"
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
	return write(m_fd.m_rawFd, _data, _length);
}

int CommSock::Receive() const
{
	int numOfBytesRead = read(m_fd.m_rawFd, m_buffer, BUFFER_LEN);
	if(-1 == numOfBytesRead)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)
		{
			return -1;
		}
		throw std::runtime_error("read() returned -1, errno is undetermined");
	}
	return numOfBytesRead;
}

char* CommSock::GetBuf() const
{
	return m_buffer;
}
}//namespace netcpp

