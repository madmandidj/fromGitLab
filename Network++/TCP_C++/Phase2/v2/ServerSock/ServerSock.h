#ifndef __SERVERSOCK_H__
#define __SERVERSOCK_H__

#include "../Socket_t/Socket_t.h"
/*#include "CommSock.h"*/
#include <tr1/memory>

namespace netcpp
{
class ServerSock : public Socket_t
{
public:
    explicit ServerSock(int _port, size_t _backLog);
/*    ServerSock& operator=(const FD_t& _fd);*/
    virtual ~ServerSock();
/*    bool IsActive() const;*/
    std::tr1::shared_ptr<Socket_t> AcceptClient();
/*    bool RemoveClient(std::tr1::shared_ptr<Socket_t>);*/
protected:
////    Inherited:
////	FD_t 			m_fd;
////	SockAddrIn_t	m_sin;
private:
		void Initialize(int _port, size_t _backLog);
	    ServerSock(const ServerSock& _servSock);
	    ServerSock& operator=(const ServerSock& _servSock);
};



}//namespace netcpp
#endif//#ifndef __SERVERSOCK_H__
