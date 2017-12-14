#ifndef __SERVERCPP_H__
#define __SERVERCPP_H__

#include "../FDSet_t/FDSet_t.h"
#include <tr1/memory>
#include <list>

namespace netcpp
{
class Socket_t;
class ServerSock;
typedef void* (*AppFunc)(void*);

class Server
{
public:
    explicit Server(AppFunc _func, int _port);
    ~Server();
    void Run();
private:
	void CheckNewClients();
	void CheckCurrentClients();
    Server(const Server&);
    Server& operator=(const Server&);
private:
	std::tr1::shared_ptr<ServerSock> m_serverSock;
    std::list<std::tr1::shared_ptr<Socket_t> > m_commSockets;
    FDSet_t m_fdSet;
    AppFunc m_appFunc;
};
}//namespace netcpp
#endif//#ifndef __SERVERCPP_H__
