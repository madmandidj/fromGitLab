#include "CommSock.h"

namespace netcpp
{
CommSock::CommSock(const FD_t& _fd)
{
	m_fd = _fd;
	m_isConnected = true; //TODO: How to ensure that FD was connected? _fd.IsActive() ?
}

CommSock::~CommSock()
{
	// Empty
}

char* CommSock::GetBuf() const
{
	ThrowIfDisconnected(__FILE__, __LINE__, "in GetBuf(), socket is disconnected");
	return m_buffer;
}

}//namespace netcpp

