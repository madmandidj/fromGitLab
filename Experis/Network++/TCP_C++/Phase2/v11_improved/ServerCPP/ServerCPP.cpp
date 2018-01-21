#include "ServerCPP.h"
//#include "../FD_t/FD_t.h"
//#include "../Socket_t/Socket_t.h"
#include "../ServerSock/ServerSock.h"
#include "../CommSock/CommSock.h"
//#include "../NetExceptions/NetExceptions.h"
#include<unistd.h> //STDIN_FILENO
#include<iostream>
#include<csignal>
namespace netcpp
{
static bool serverShouldRun = true;
void ServerStopRunning(int _dummy) 
{
	serverShouldRun = false;
}
/////////////////////////////////////
////Public Function Implementations
/////////////////////////////////////
Server::Server(AppFunc _func, int _port, size_t _maxClientNum, size_t _backlog):
								m_serverSock(new ServerSock(_port, _backlog)) 
								,m_maxClientNum(_maxClientNum)
								,m_shouldRun(true)
								,m_appFunc(_func) //TODO: Should Server connect on construction or not?						
{
	m_fdSet.Add(m_serverSock);
	m_fdSet.Add(STDIN_FILENO);
	signal(SIGINT, ServerStopRunning);
}

Server::~Server()
{
	//Empty
}


void Server::Run() 
{
	int activity;
	while(serverShouldRun)
	{	
		try
		{
			activity = m_fdSet.GetActivity();	
			if (0 < activity)
			{
				if(m_fdSet.IsFdActive(m_serverSock))
				{
					try
					{					
						CheckNewClients();
					}
					catch(const std::exception& _exc)
					{
						std::cout << "*****" << __FILE__ << __LINE__ << "*****" << _exc.what() << std::endl;
						sleep(2);
					}
				}
				CheckCurrentClients();
			}
			else
			{
				//TODO: when timeout implemented, remove all clients that have timedout
				std::cout << "activity = 0" << std::endl;
			}
		}
		catch(const std::exception& _exc)
		{
			throw;
		}
	}
}



/////////////////////////////////////
////Private Function Implementations
/////////////////////////////////////
void Server::CheckNewClients()
{
	CommSharedPtr_t commSock = m_serverSock->AcceptClient();
	if(m_commSockets.size() == m_maxClientNum)
	{
		std::cout << "Max client num reached" << std::endl;
		return;
	}
	m_fdSet.Add(commSock);
	m_commSockets.push_front(commSock);	
	std::cout << "Client connected" << std::endl;
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
		numOfBytes = commSock->Receive();
		if (-1 == numOfBytes) 
		{
			std::cout << "received -1, EAgain" << std::endl;
			++itCur;
			continue;
		}
		if (0 == numOfBytes) 
		{
			RemoveClient(commSock, itCur, itEnd);
			std::cout << "received 0, closed commSock" << std::endl;
			continue;
		}
		char* data = commSock->GetBuf(); //TODO: is this redundant because of friendship?
		m_appFunc(data);
		commSock->Send(data, numOfBytes, MSG_NOSIGNAL);
		++itCur;
	}
}

void Server::RemoveClient(CommSock* const _commSock, 
							std::list< CommSharedPtr_t >::iterator& _itCur,
							std::list< CommSharedPtr_t >::iterator& _itEnd)
{
	std::list< CommSharedPtr_t >::iterator itTemp;
	itTemp = _itCur;
	++itTemp;
	if (!m_fdSet.Remove(*_itCur))
	{
		throw std::runtime_error("line 163, RemoveClient(), m_fdSet.Remove() failed");
	}
	m_commSockets.erase(_itCur);
	_itCur = itTemp;
	_itEnd = m_commSockets.end();
}	

bool Server::CloseCommSock(CommSock* const _commSock)
{
	if (0 == _commSock)
	{
		return false;
	}
	if (-1 == close(_commSock->m_fd))
	{
		return false;
	}
	
	return true;
}

}//namespace netcpp

