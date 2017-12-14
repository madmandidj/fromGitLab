#include "ServerCPP.h"
#include "../FD_t/FD_t.h"
#include "../Socket_t/Socket_t.h"
#include "../ServerSock/ServerSock.h"
#include "../CommSock/CommSock.h"
#include "../NetExceptions/NetExceptions.h"
#include<unistd.h> //STDIN_FILENO
#include<iostream>
namespace netcpp
{
static const size_t BACKLOG = 1001;

/////////////////////////////////////
////Public Function Implementations
/////////////////////////////////////
Server::Server(AppFunc _func, int _port):m_serverSock(new ServerSock(_port, BACKLOG)), m_appFunc(_func)
{
	m_fdSet.Add(m_serverSock);
	m_fdSet.Add(STDIN_FILENO);
}

Server::~Server()
{
	//Empty
}

void Server::Run()
{
	int activity;
	while(1)
	{	try
		{
			activity = m_fdSet.GetActivity();	
		}
		catch(std::exception& _exc)
		{
			throw;
		}
		if (0 < activity)
		{
			if(m_fdSet.IsFdActive(m_serverSock))
			{
				try
				{
					CheckNewClients();
				}
				catch(std::exception& _exc)
				{
					throw;
				}
			}
			CheckCurrentClients();
		}
		else
		{
			//TODO: when timeout implemented, remove all clients that have timedout
		}
	}
}



/////////////////////////////////////
////Private Function Implementations
/////////////////////////////////////
void Server::CheckNewClients()
{
	CommSharedPtr_t commSock;
	try
	{
		commSock = m_serverSock->AcceptClient();
	}
	catch(std::exception& _exc)
	{
		throw;
	}
	try
	{
		m_fdSet.Add(commSock);
	}
	catch(std::exception _exc)
	{
		return;
	}
	m_commSockets.push_front(commSock);
}

void Server::CheckCurrentClients()
{
	std::list< CommSharedPtr_t >::iterator itCur = m_commSockets.begin();
	std::list< CommSharedPtr_t >::iterator itEnd = m_commSockets.end();
	CommSock* commSock;
	int numOfBytes;
	while (itCur != itEnd)
	{
		commSock = dynamic_cast<CommSock*>((*itCur).get());
		if(0 == commSock || !m_fdSet.IsFdActive(*itCur))
		{
			++itCur;
			continue;
		}
		try
		{
			numOfBytes = commSock->Receive();
		}
		catch(const SocketCloseByPeerExc& _exc)
		{
			RemoveClient(itCur, itEnd);
			continue;
		}
		catch(const EagainExc& _exc)
		{
			++itCur;
			continue;
		}
		catch(std::exception& _exc)
		{
			std::cout << _exc.what() << std::endl;
			throw;
		}
		char* data = commSock->GetBuf();
		m_appFunc(data);
		commSock->Send(data, numOfBytes);
		++itCur;
	}
}

void Server::RemoveClient(std::list< CommSharedPtr_t >::iterator& _itCur,
							std::list< CommSharedPtr_t >::iterator& _itEnd)
{
	std::list< CommSharedPtr_t >::iterator itTemp;
	itTemp = _itCur;
	++itTemp;
	m_fdSet.Remove(*_itCur);
	m_commSockets.erase(_itCur);
	_itCur = itTemp;
	_itEnd = m_commSockets.end();
}					

}//namespace netcpp

