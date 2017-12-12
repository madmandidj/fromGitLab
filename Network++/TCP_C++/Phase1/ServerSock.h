#ifndef __SERVERSOCK_H__
#define __SERVERSOCK_H__

#include "Socket_t.h"
#include "CommSock.h"
#include <tr1/memory>

namespace netcpp
{
class ServerSock : public Socket_t
{
public:
    explicit ServerSock();
/*    ServerSock& operator=(const FD_t& _fd);*/
    virtual ~ServerSock();
/*    bool IsActive() const;*/
	void Initialize(int _port, size_t _backLog);
    std::tr1::shared_ptr<CommSock> AcceptClient();
    bool RemoveClient(std::tr1::shared_ptr<CommSock>);
protected:
    ServerSock(const ServerSock& _servSock);
    ServerSock& operator=(const ServerSock& _servSock);
////    Inherited:
////	FD_t 			m_fd;
////	SockAddrIn_t	m_sin;
};



}//namespace netcpp
#endif//#ifndef __SERVERSOCK_H__
