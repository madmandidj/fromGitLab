#include "SockAddrIn_t.h"
#include <string.h>

//#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>

namespace netcpp
{
void SockAddrIn_t::SetSockAddrIn(short _family, unsigned short _port, const char* _addr)
{
	memset(&m_sin, 0, sizeof(m_sin));
	m_sin.sin_family = _family;
	m_sin.sin_addr.s_addr = (NULL == _addr) ? INADDR_ANY : inet_addr(_addr);
	m_sin.sin_port = htons(_port);
}

sockaddr_in& SockAddrIn_t::GetRawSin() const
{
	return const_cast<sockaddr_in&>(m_sin);
}





}//namespace netcpp
