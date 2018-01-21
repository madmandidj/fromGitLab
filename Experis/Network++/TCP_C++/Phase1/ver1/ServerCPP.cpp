#include "ServerCPP.h"
#include "ServerSock.h"
#include "CommSock.h"
#include "FD_t.h"
#include<iostream>
namespace netcpp
{
static const size_t BACKLOG = 500;

/////////////////////////////////////
////Public Function Implementations
/////////////////////////////////////
Server::Server(AppFunc _func, int _port):m_serverSock(new ServerSock(_port, BACKLOG)), m_appFunc(_func)
{
//	std::tr1::shared_ptr<Socket_t> m_server(new ServerSock(_port, BACKLOG));
//	m_commSockets.insert(m_commSockets.begin(), serverSock);
//	InitializeServer(_port);
}

Server::~Server()
{
	//Empty
}

void Server::Run()
{
	while(1)
	{	
		try
		{
			CheckNewClients();
		}
		catch(std::exception& _exc)
		{
			//TODO: something
		}
		CheckCurrentClients();
	}
}



/////////////////////////////////////
////Private Function Implementations
/////////////////////////////////////
//void Server::InitializeServer(int _port)
//{
////	static_cast<ServerSock*>(m_servSock)->Initialize(_port, BACKLOG);
//}
void Server::CheckNewClients()
{
	std::tr1::shared_ptr<Socket_t> commSock;
	try
	{
		commSock = m_serverSock->AcceptClient();
	}
	catch(std::exception& _exc)
	{
//		std::cout << "CheckNewClients() caught: "<< _exc.what() << std::endl;
		throw;
	}
	
	m_commSockets.push_front(commSock);
}

void Server::CheckCurrentClients()
{
	std::list< std::tr1::shared_ptr<Socket_t> >::iterator itCur = m_commSockets.begin();
	std::list< std::tr1::shared_ptr<Socket_t> >::iterator itEnd = m_commSockets.end();
	std::list< std::tr1::shared_ptr<Socket_t> >::iterator itTemp;
	CommSock* commSock;
	int numOfBytes;
	while (itCur != itEnd)
	{
		commSock = dynamic_cast<CommSock*>((*itCur).get());
		try
		{
			numOfBytes = commSock->Receive();
		}
		catch(std::exception& _exc)
		{
			throw;
		}
		if(-1 == numOfBytes)
		{
			++itCur;
			continue;
		}
		if(0 == numOfBytes)
		{
			itTemp = itCur;
			++itTemp;
			m_commSockets.erase(itCur);
			itCur = itTemp;
			itEnd = m_commSockets.end();
			continue;
		}
		char* data = commSock->GetBuf();
		m_appFunc(data);
		commSock->Send(data, numOfBytes);
		++itCur;
	}
}


}//namespace netcpp
