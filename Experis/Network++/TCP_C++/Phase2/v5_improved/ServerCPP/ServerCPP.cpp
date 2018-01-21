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
						std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
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
			std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
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
		std::cout << "here" << std::endl;
		commSock = m_serverSock->AcceptClient();
	}
	catch(std::exception& _exc)
	{
		std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
		throw;
	}

	if (!m_fdSet.Add(commSock))
	{
		CloseCommSock(dynamic_cast<CommSock*>(commSock.get()));
		return;
	}

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
		catch(const SocketCloseByPeerExc& _exc)
		{
			std::cout << __FILE__ << __LINE__ << _exc.what() << std::endl;
			RemoveClient(commSock, itCur, itEnd);
			continue;
		}
		catch(const EagainExc& _exc)
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
		char* data = commSock->GetBuf();
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
			commSock->Send(data, numOfBytes);
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
	CloseCommSock(_commSock);
	m_commSockets.erase(_itCur);
	_itCur = itTemp;
	_itEnd = m_commSockets.end();
	std::cout << "Client disconnected and removed" << std::endl;
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

