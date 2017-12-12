#ifndef __SOCKET_T_H__
#define __SOCKET_T_H__

#include "FD_t.h"
namespace netcpp
{
class Socket_t
{
public:
	explicit Socket_t();
	Socket_t(const Socket_t& _socket);
	Socket_t& operator=(const Socket_t& _socket);
	virtual ~Socket_t();
protected:
	FD_t 		m_fd;
	SockAddr_t	m_sockaddr;
};











}//namespace netcpp
#endif//#ifndef __SOCKET_T_H__


