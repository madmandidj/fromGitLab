#ifndef __SOCKET_T_H__
#define __SOCKET_T_H__

#include "../FD_t/FD_t.h"
#include "../SockAddrIn_t/SockAddrIn_t.h"

namespace netcpp
{
class Socket_t
{
public:
	explicit Socket_t();
	virtual ~Socket_t();
	friend class FDSet_t;
protected:
	FD_t 			m_fd;
	SockAddrIn_t	m_sin;
	bool			m_isConnected;
private:
	Socket_t(const Socket_t& _socket);
	Socket_t& operator=(const Socket_t& _socket);
};
}//namespace netcpp
#endif//#ifndef __SOCKET_T_H__

//TODO: Remove this if not needed
//	enum SOCKTERR
//	{
//		SOCKTERR_EAGAIN
//		, SOCKTERR_SELECTFAIL
//		, SOCKTERR_SOCKETFAIL
//		, SOCKTERR_CONNECTFAIL
//		, SOCKTERR_SETSOCKOPTFAIL
//		, SOCKTERR_BINDFAIL
//		, SOCKTERR_LISTENFAIL
//		, SOCKTERR_ISCONNECTED
//		, SOCKTERR_ISDISCONNECTED
//		, SOCKTERR_BROKENPIPE
//		, SOCKTERR_TOOMANYOPENFILES
//		, SOCKTERR_UNKNOWNERRNO
//	}SOCKTERR;






