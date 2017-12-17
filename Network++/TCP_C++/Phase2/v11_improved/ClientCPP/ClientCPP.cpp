#include "ClientCPP.h"
//#include "../NetExceptions/NetExceptions.h"
#include <iostream>
#include <string.h>
#include <unistd.h>

namespace netcpp
{
Client::Client()
{
	//Empty
}

Client::~Client()
{
	//Empty
}

int Client::Connect(int _port, const char* _ip)
{
	m_clientSock.Connect(_port, _ip);
	return 1;
}

int Client::Disconnect()
{
	m_clientSock.Disconnect();
	return 1;
}

void Client::Run()
{
	char data[256] = "This is a test\0";
	ssize_t result;
	Send(data, strlen(data));
	result = Receive();
	if (-1 == result)
	{
		m_clientSock.Disconnect();
		std::cout << "Client received -1, EAGAIN **Is this allowed?" << std::endl;
		return;
	}
	else if (0 == result)
	{
		m_clientSock.Disconnect();
		std::cout << "Client received 0, disconnected " << std::endl;
		return;
	}
	std::cout << "Client received: " << m_clientSock.m_buffer << ", result = " << result << std::endl;
}

int Client::Send(void* _data, size_t _length) const
{
	return m_clientSock.Send(_data, _length, MSG_NOSIGNAL);
}

ssize_t Client::Receive() const
{
	return m_clientSock.Receive();
}

bool Client::IsConnected() const
{
	return m_clientSock.m_isConnected;
}



}//namespace netcpp

