#include "ServerCPP.h"
#include "ServerSock.h"
//#include "FD_t.h"
namespace netcpp
{
static const size_t BACKLOG = 500;
/////////////////////////////////////
////Public Function Implementations
/////////////////////////////////////
Server::Server(AppFunc _func, int _port):m_servSock(new ServerSock),m_appFunc(_func)
{
	InitializeServer(_port);
}



/////////////////////////////////////
////Private Function Implementations
/////////////////////////////////////
void Server::InitializeServer(int _port)
{
	static_cast<ServerSock*>(m_servSock)->Initialize(_port, BACKLOG);
}



}//namespace netcpp
