#include "ClientCPP.h"
#include<iostream>
#include<string.h>
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
	Send(data, strlen(data));
	Receive();
	std::cout << "Client received: " << m_clientSock.m_buffer << std::endl;
}

int Client::Send(void* _data, size_t _length) const
{
	return m_clientSock.Send(_data, _length);
}

int Client::Receive() const
{
	return m_clientSock.Receive();
}

bool Client::IsConnected() const
{
	return m_clientSock.m_isConnected;
}



}//namespace netcpp

