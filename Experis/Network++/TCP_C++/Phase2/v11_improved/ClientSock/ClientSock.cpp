#include "ClientSock.h"

namespace netcpp
{
ClientSock::ClientSock()
{
	// Empty
}

ClientSock::~ClientSock()
{
	// Empty
}

ClientSock& ClientSock::operator=(const FD_t& _fd)
{
	ThrowIfConnected(__FILE__, __LINE__, "in operator=() socket is connected");
	m_fd = _fd;
	return *this;
}

void ClientSock::Connect(int _port, const char* _ip)
{
	ThrowIfConnected(__FILE__, __LINE__, "in Connect() socket is connected");	
	Socket(AF_INET, SOCK_STREAM, 0);
	m_sin.Reset();
	m_sin.SetSockAddrIn(AF_INET, _port, _ip);
	Socket_t::Connect();
}

void ClientSock::Disconnect()
{
	ThrowIfDisconnected(__FILE__, __LINE__, "in Disconnect(), socket is disconnected");
	Close();
}

}//namespace netcpp

