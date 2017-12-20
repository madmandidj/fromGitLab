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
//	int Send(void* _data, size_t _length) const;
//	size_t Receive() const;
	friend class Server;
protected:
////    Inherited:
////	FD_t 			m_fd;
////	SockAddrIn_t	m_sin;
////	bool			m_isConnected;
////	mutable char m_buffer[256]; //This should be Msg_t
private:
	char* GetBuf() const; //TODO: is this redundant? this will change to msg_t anyway
	CommSock(const CommSock&);
	CommSock& operator=(const CommSock&);
};
}//namespace netcpp
#endif//#ifndef __COMMSOCK_H__
