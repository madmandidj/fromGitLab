#ifndef __COMMSOCK_H__
#define __COMMSOCK_H__

#include "../Socket_t/Socket_t.h" //includes FD_t.h and SockAddrIn_t.h
#if (defined (__APPLE__))
#	define MSG_NOSIGNAL 0
#endif


namespace netcpp
{
class CommSock : public Socket_t
{
public:
	explicit CommSock(const FD_t& _fd);
	virtual ~CommSock();
	int Send(void* _data, size_t _length) const;
	size_t Receive() const;
	char* GetBuf() const;
	friend class Server;
protected:
////    Inherited:
////	FD_t 			m_fd;
////	SockAddrIn_t	m_sin;
////	bool			m_isConnected;
private:
	CommSock(const CommSock&);
	CommSock& operator=(const CommSock&);
	mutable char m_buffer[256];
};
}//namespace netcpp
#endif//#ifndef __COMMSOCK_H__

