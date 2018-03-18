#include "ClientCPP.h"
#include "../NetExceptions/NetExceptions.h"
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
	try
	{
		Send(data, strlen(data));
	}
	catch(NetException& _exc)
	{
		std::cout << "Client caught send exception" << std::endl;
		std::cout << _exc.what() << std::endl;
	}
	catch(std::exception& _exc)
	{
		std::cout << "Client caught std::exception" << std::endl;
		std::cout << _exc.what() << std::endl;
	}
	try
	{
		Receive();
	}
	catch(EagainExc& _exc)
	{
		return;
	}
	catch(SocketCloseByPeerExc& _exc)
	{
		m_clientSock.Disconnect();
		std::cout << "Socket closed by peer, Client disconnected " << std::endl;
		return;
	}
	catch(NetException& _exc)
	{
		std::cout << "Client caught read exception" << std::endl;
		std::cout << _exc.what() << std::endl;
	}
	catch(std::exception& _exc)
	{
		std::cout << "Client caught std::exception" << std::endl;
		std::cout << _exc.what() << std::endl;
	}
	std::cout << "Client received: " << m_clientSock.m_buffer << std::endl;
}

int Client::Send(void* _data, size_t _length) const
{
	int result;
	try
	{
		result = m_clientSock.Send(_data, _length);
	}
	catch(NetException& _exc)
	{
		std::cout << _exc.what() << std::endl;
	}
	return result;
}

int Client::Receive() const
{
	int result;
	try
	{
		result = m_clientSock.Receive();
	}
	catch(NetException& _exc)
	{
		std::cout << _exc.what() << std::endl;
	}
	return result;
}

bool Client::IsConnected() const
{
	return m_clientSock.m_isConnected;
}



}//namespace netcpp
