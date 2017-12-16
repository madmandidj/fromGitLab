#ifndef __SERVERSOCK_H__
#define __SERVERSOCK_H__

#include "../Socket_t/Socket_t.h" //includes FD_t.h and SockAddrIn_t.h
#if (defined (__linux__))
#	include<tr1/memory>	//std::tr1::shared_ptr
#	define IS_LINUX 1
#elif (defined (__APPLE__))
#	include<memory>	//std::tr1::shared_ptr
#	define IS_APPLE 1
#endif

namespace netcpp
{
#ifdef IS_LINUX
	typedef std::tr1::shared_ptr<Socket_t> SharedPtr_t;
#endif
#ifdef IS_APPLE
	typedef std::shared_ptr<Socket_t> SharedPtr_t;
#endif
class ServerSock : public Socket_t
{
public:
    explicit ServerSock(int _port, size_t _backLog);
    virtual ~ServerSock();
    SharedPtr_t AcceptClient();
protected:
////    Inherited:
////	FD_t 			m_fd;
////	SockAddrIn_t	m_sin;
////	bool			m_isConnected;
private:
		void Initialize(int _port, size_t _backLog);
	    ServerSock(const ServerSock& _servSock);
	    ServerSock& operator=(const ServerSock& _servSock);
};
}//namespace netcpp
#endif//#ifndef __SERVERSOCK_H__
