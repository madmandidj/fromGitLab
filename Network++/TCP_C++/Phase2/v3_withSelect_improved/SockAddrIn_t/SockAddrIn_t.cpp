#include "SockAddrIn_t.h"
#include <string.h>
#include <arpa/inet.h>

namespace netcpp
{
void SockAddrIn_t::SetSockAddrIn(short _family, unsigned short _port, const char* _addr)
{
	Reset();
	m_rawSin.sin_family = _family;
	m_rawSin.sin_addr.s_addr = (NULL == _addr) ? INADDR_ANY : inet_addr(_addr);
	m_rawSin.sin_port = htons(_port);
}

void SockAddrIn_t::Reset()
{
	memset(&m_rawSin, 0, sizeof(m_rawSin));
}
}//namespace netcpp

