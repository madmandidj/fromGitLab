#include "ServerSock.h"
#include "../CommSock/CommSock.h"

namespace netcpp
{
ServerSock::ServerSock(int _port, size_t _backLog)
{
	Initialize(_port, _backLog);
}

ServerSock::~ServerSock()
{
	// Empty
}

SharedPtr_t ServerSock::AcceptClient()
{
	FD_t fd;
	fd = Accept();
	SharedPtr_t commSock(new CommSock(fd));
	return commSock;
}

void ServerSock::Initialize(int _port, size_t _backLog)
{
	Socket(AF_INET, SOCK_STREAM, 0);
	SetSockOpt(SOL_SOCKET, SO_REUSEADDR, 1);
	m_sin.SetSockAddrIn(AF_INET, _port, INADDR_ANY);
	Bind();
	Listen(_backLog);
	m_isConnected = true;
}

}//namespace netcpp


