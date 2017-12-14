#ifndef __SERVERSOCK_H__
#define __SERVERSOCK_H__

#include "../Socket_t/Socket_t.h"
#include <tr1/memory>

namespace netcpp
{
class ServerSock : public Socket_t
{
public:
    explicit ServerSock(int _port, size_t _backLog);
    virtual ~ServerSock();
    std::tr1::shared_ptr<Socket_t> AcceptClient();
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
