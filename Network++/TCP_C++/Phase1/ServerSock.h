#ifndef __SERVERSOCK_H__
#define __SERVERSOCK_H__

#include "Socket_t.h"

namespace netcpp
{
class ServerSock : public Server_t
{
public:
    explicit ServerSock();
    ServerSock(const ServerSock& _servSock);
    ServerSock& operator=(const ServerSock& _servSock);
    virtual ~ServerSock();
    AcceptClient();
    RemoveClient();
protected:
////    Inherited:
////	FD_t 		m_fd;
private:

};
}
#endif//#ifndef __SERVERSOCK_H__
