#include "Server_t.h"
#include "list.h"
#include "list_itr.h"
#include <sys/types.h> 	/* socket, getsockopt */
#include <sys/socket.h> /* socket, getsockopt */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h> /* htons */
#include <fcntl.h> /* O_NONBLOCK */
#include <errno.h>
#include <stdio.h>
#define NCLIENTS 64
#define BUFFER_LEN 256
#define BACK_LOG 32
/*************************
**************************
Server_t struct definition
**************************
**************************/
struct Server_t
{
	int		m_serverSock;
	List*	m_clientList;
	AppFunc m_appFunc;
};
/************************************
*************************************
Static functions forward declarations
*************************************
************************************/
static int InitServer(Server_t* _server, int _port);
static void CheckNewClients(Server_t* _server);
static void CheckCurrentClients(Server_t* _server);
static void DestroySockets(int* _socket, void* _context);
/************************************
*************************************
Server_t API function implementations
*************************************
************************************/
Server_t* ServerCreate(AppFunc _func, int _port)
{
	Server_t* server = malloc(sizeof(Server_t));
	if (NULL == server)
	{
		return NULL;
	}
	server->m_clientList = ListCreate();
	if (NULL == server->m_clientList)
	{
		return NULL;
	}
	server->m_appFunc = _func;
	if (!InitServer(server, _port))
	{
		return NULL;
	}
	return server;
}

int ServerRun(Server_t* _server)
{
	if (NULL == _server)
	{
		return 0;
	}
	size_t runNum = 0;
	while(1)
	{
		printf("Run number %lu\n", runNum);
		CheckNewClients(_server);
		CheckCurrentClients(_server);
		sleep(1);
		++runNum;
	}
	
	return 1; /*TODO: make this relevant */
}

int ServerDestroy(Server_t* _server)
{
	if (NULL == _server)
	{
		return 0;
	}
	size_t index;
	ListDestroy(&_server->m_clientList, (UserActionFunc)DestroySockets);
	free(_server);
	return 1;
}
/***************************************
***************************************
Server_t Static function implementations 
***************************************
***************************************/
static int InitServer(Server_t* _server, int _port)
{
	int optval = 1;
	int flags;
	struct sockaddr_in server_sin;
	
	_server->m_serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if (_server->m_serverSock < 0)
	{
		free(_server);
		return 0;
	}
	
	if (-1 == (flags = fcntl(_server->m_serverSock, F_GETFL)))
	{
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	if (-1 == fcntl(_server->m_serverSock, F_SETFL, flags | O_NONBLOCK))
	{
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	if (setsockopt(_server->m_serverSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}

	memset(&server_sin, 0, sizeof(server_sin));
	server_sin.sin_family = AF_INET;
	server_sin.sin_addr.s_addr = INADDR_ANY;
	server_sin.sin_port = htons(_port);
	
	if(bind(_server->m_serverSock, (struct sockaddr*) &server_sin, sizeof(server_sin)) < 0)
	{
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	if (listen(_server->m_serverSock, BACK_LOG) < 0)
	{
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	return 1;
}

static void CheckNewClients(Server_t* _server)
{
	struct sockaddr_in clientSin;
	int addr_len = sizeof(clientSin);
	int tempClientSock = 0;
	int* clientSock;
	int flags;
	
	tempClientSock = accept(_server->m_serverSock, (struct sockaddr*) &clientSin, &addr_len);
	if (0 < tempClientSock)
	{
		clientSock = malloc(sizeof(int));
		if (NULL == clientSock)
		{
			//TODO: handle malloc fail
		}
		*clientSock = tempClientSock;
		if (-1 == (flags = fcntl(*clientSock, F_GETFL)))
		{
			close(*clientSock);
			free(_server);
			return;
		}
		if (-1 == fcntl(*clientSock, F_SETFL, flags | O_NONBLOCK))
		{
			close(*clientSock);
			free(_server);
			return;
		}
		ListPushTail(_server->m_clientList, clientSock);
	}
	else if (errno != EAGAIN && errno != EWOULDBLOCK)
	{
		/* DO something */
		perror("accpet failed");
		abort();
	}
}

static void CheckCurrentClients(Server_t* _server)
{
	size_t index;
	char buffer[BUFFER_LEN];
	int numOfBytesRead;
	ListItr itr;
	ListItr tempItr;
	ListItr itrListEnd;
	int* removedSock;
	itr = ListItrBegin(_server->m_clientList);
	itrListEnd = ListItrEnd(_server->m_clientList);

	while(!ListItrEquals(itr, itrListEnd))
	{
		numOfBytesRead = read(*(int*)ListItrGet(itr), buffer, BUFFER_LEN);
		if(0 == numOfBytesRead)
		{
			/* Handle client closed socket */
			if (-1 == close(*(int*)ListItrGet(itr)))
			{
				/*TODO: handle this */
			}
			tempItr = ListItrNext(itr);
			removedSock = ListItrRemove(itr);
			free(removedSock);
			itrListEnd = ListItrEnd(_server->m_clientList);
			itr = tempItr;
			continue;
		}
		if(-1 == numOfBytesRead)
		{
			if (errno == EAGAIN && errno == EWOULDBLOCK)
			{
				itr = ListItrNext(itr);
				continue;
			}
			printf("Server read failed, errno = %d\n", errno);
			abort();
		}
		_server->m_appFunc(buffer);
		write(*(int*)ListItrGet(itr), buffer, numOfBytesRead);
		itr = ListItrNext(itr);
	}
}

static void DestroySockets(int* _socket, void* _context)
{
	close(*_socket);
	free(_socket);
	printf("here\n");
}
