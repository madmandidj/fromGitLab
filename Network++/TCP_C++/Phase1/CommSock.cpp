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
	//Empty
}

CommSock::~CommSock()
{
	close(m_fd.GetRawFD());
	//TODO: close socket
}

int CommSock::Send(void* _data, size_t _length) const
{
	return write(m_fd.GetRawFD(), _data, _length);
}

int CommSock::Receive() const
{
	int numOfBytesRead = read(m_fd.GetRawFD(), m_buffer, BUFFER_LEN);
//	if(0 == numOfBytesRead)
//	{
//		throw std::runtime_error("read() returned 0, Client closed socket");
//	}
	if(-1 == numOfBytesRead)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET)
		{
			throw std::runtime_error("read() returned -1, errno is EAGAIN || EWOULDBLOCK || ECONNRESET");
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

