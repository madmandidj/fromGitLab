#include "ServerSock.h"
//#include "FD_t.h"

namespace netcpp
{
ServerSock::ServerSock()
{
	//TODO:
}

ServerSock::~ServerSock()
{
	//TODO:
}

void ServerSock::Initialize(int _port, size_t _backLog)
{
	int optval = 1;
//	int flags;
	
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd < 0)
	{
		throw std::runtime_error("socket() failed");
	}
	
	if (setsockopt(m_fd.GetRawFD(), SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		throw std::runtime_error("setsockopt() failed");
	}
	
	m_sin.SetSockAddrIn(AF_INET, _port, INADDR_ANY);
	
	if(bind(m_fd.GetRawFD(), ((struct sockaddr*) &(m_sin.GetRawSin())), sizeof(m_sin.GetRawSin())) < 0)
	{
		throw std::runtime_error("bind() failed");
	}
	
	if (listen(m_fd.GetRawFD(), _backLog) < 0)
	{
		throw std::runtime_error("bind() failed");
	}
}


}//namespace netcpp
