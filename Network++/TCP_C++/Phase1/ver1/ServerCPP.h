#ifndef __SERVERCPP_H__
#define __SERVERCPP_H__
#include "Socket_t.h"
#include "ServerSock.h"
#include <tr1/memory>
#include <list>
namespace netcpp
{

typedef void* (*AppFunc)(void*);

class Server
{
public:
    explicit Server(AppFunc _func, int _port);
    ~Server();
    void Run();
private:
    Server(const Server&);
    Server& operator=(const Server&);
private:
	void CheckNewClients();
	void CheckCurrentClients();
	std::tr1::shared_ptr<ServerSock> m_serverSock;
    std::list<std::tr1::shared_ptr<Socket_t> > m_commSockets;
    AppFunc m_appFunc;
};




}//namespace netcpp
#endif//#ifndef __SERVERCPP_H__
