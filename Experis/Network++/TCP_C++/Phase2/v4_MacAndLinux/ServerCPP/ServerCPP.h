#ifndef __SERVERCPP_H__
#define __SERVERCPP_H__

#include "../FDSet_t/FDSet_t.h"
#include <list>
#if (defined (__linux__))
#	include<tr1/memory>	//std::tr1::shared_ptr
#	define IS_LINUX 1
#elif (defined (__APPLE__))
#	include<memory>	//std::tr1::shared_ptr
#	define IS_APPLE 1
#endif

namespace netcpp
{
class Socket_t;
class ServerSock;
#ifdef IS_LINUX
	typedef std::tr1::shared_ptr<Socket_t> CommSharedPtr_t;
	typedef std::tr1::shared_ptr<ServerSock> ServSharedPtr_t;
#endif
#ifdef IS_APPLE
	typedef std::shared_ptr<Socket_t> CommSharedPtr_t;
	typedef std::shared_ptr<ServerSock> ServSharedPtr_t;
#endif
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
	void RemoveClient(std::list< CommSharedPtr_t >::iterator& _itCur,
						std::list< CommSharedPtr_t >::iterator& _itEnd);
    Server(const Server&);
    Server& operator=(const Server&);
private:
	ServSharedPtr_t m_serverSock;
    std::list<CommSharedPtr_t > m_commSockets;
    FDSet_t m_fdSet;
    AppFunc m_appFunc;
};
}//namespace netcpp
#endif//#ifndef __SERVERCPP_H__
