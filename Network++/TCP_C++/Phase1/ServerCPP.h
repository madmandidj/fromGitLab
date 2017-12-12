#ifndef __SERVERCPP_H__
#define __SERVERCPP_H__
#include "Socket_t.h"
#include "SockAddr_t.h"
#include "ServerSock.h"
#include "CommSock.h"
namespace netcpp
{
typedef void* (*AppFunc)(void*);
class Server
{
public:
    explicit Server(AppFunc _func, int port);
    ~Server();
    Run();
private:
    Server(const Server&);
    Server& operator=(const Server&);
    ServerSock  m_servSock;
    CommSock    m_commSock; //Should be vector of CommSock?
    AppFunc     m_appFunc;
};




}//namespace netcpp
#endif//#ifndef __SERVERCPP_H__
