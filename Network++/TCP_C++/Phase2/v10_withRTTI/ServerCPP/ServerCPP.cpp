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
//static const size_t BACKLOG = 1001;

/////////////////////////////////////
////Public Function Implementations
/////////////////////////////////////
Server::Server(AppFunc _func, int _port, size_t _maxClientNum, size_t _backlog):
								m_serverSock(new ServerSock(_port, _backlog)) 
								,m_maxClientNum(_maxClientNum)
								,m_appFunc(_func)									
{
	m_fdSet.Add(m_serverSock);
	m_fdSet.Add(STDIN_FILENO);
}

Server::~Server()
{
	//Empty
}

void Server::Run() //TODO: if server is active on construction, then this is lying. Should connect in run. Maybe server should have GoOnline and GoOffline functions?
{
	int activity;
	while(1)
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
//						throw;
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
	CommSharedPtr_t commSock;
	try
	{
		commSock = m_serverSock->AcceptClient();
	}
	catch(std::exception& _exc)
	{
		throw;
	}
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
		try
		{
			numOfBytes = commSock->Receive();
		}
		catch(const EagainExc& _exc) //TODO: Change Receive() to return ssize_t, and this can be -1
		{
			std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
			++itCur;
			continue;
		}
		catch(std::exception& _exc)
		{
			std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
			throw;
		}
		if (0 == numOfBytes) //TODO: this can be moved to within the Receive try() block?
		{
			RemoveClient(commSock, itCur, itEnd);
			std::cout << "received 0, closed commSock" << std::endl;
			continue;
		}
		
		char* data = commSock->GetBuf(); //TODO: is this redundant because of friendship?
		
		try
		{
			m_appFunc(data);
		}
		catch(std::exception& _exc)
		{
			std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
			throw;
		}
		try
		{
			commSock->Send(data, numOfBytes, MSG_NOSIGNAL);
		}
		catch(std::exception& _exc)
		{
			std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
			throw;
		}
		++itCur;
	}
}

void Server::RemoveClient(CommSock* const _commSock, 
							std::list< CommSharedPtr_t >::iterator& _itCur,
							std::list< CommSharedPtr_t >::iterator& _itEnd)
{
	//TODO: add try and catches
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
	if (-1 == close(_commSock->m_fd.GetRawFd()))
	{
		return false;
	}
	
	return true;
}

}//namespace netcpp

