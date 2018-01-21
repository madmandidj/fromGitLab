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
#include <signal.h>
#include <sys/select.h>
#define BUFFER_LEN 256
#define BACK_LOG 1000
#define MAX_CLIENT_NUM 1000

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
	int		m_numOfClients;
	fd_set	m_fdSet;
	int		m_maxFdVal;
};
/*************************
**************************
Server_t SIGINT handle
**************************
**************************/
static volatile int keepRunning = 1;

void intHandler(int dummy) 
{
    keepRunning = 0;
}
/************************************
*************************************
Static functions forward declarations
*************************************
************************************/
static int InitServer(Server_t* _server, int _port);
static void ServerRoutine(Server_t* _server);
static void CheckNewClients(Server_t* _server);
static void CheckCurrentClients(Server_t* _server, fd_set _fdSet, int _activity);
static void DestroySockets(int* _socket, void* _context);

static Server_t* AllocateMemory();
static void InitializeDataMembers(Server_t* _server, AppFunc _func);
static int InitializeServer(Server_t* _server, int _port);
/************************************
*************************************
Server_t API function implementations
*************************************
************************************/
static Server_t* AllocateMemory()
{
	Server_t* server;
	if (NULL == (server = malloc(sizeof(Server_t))))
	{
		return NULL;
	}
	server->m_clientList = ListCreate();
	if (NULL == server->m_clientList)
	{
		free(server);
		return NULL;
	}
	return server;
}

static void InitializeDataMembers(Server_t* _server, AppFunc _func)
{
	_server->m_appFunc = _func;
	_server->m_numOfClients = 0;
	_server->m_maxFdVal = 0;
}

static int InitializeServer(Server_t* _server, int _port)
{
	int optval = 1;
	int flags;
	struct sockaddr_in server_sin;
	
	FD_ZERO(&_server->m_fdSet);
	
	_server->m_serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if (_server->m_serverSock < 0)
	{
		/*TODO: destroy list */
		ListDestroy(&_server->m_clientList, NULL);
		free(_server);
		return 0;
	}
	_server->m_maxFdVal = _server->m_serverSock;
	
	FD_SET(_server->m_serverSock, &_server->m_fdSet);
	FD_SET(STDIN_FILENO, &_server->m_fdSet);
	
	if (setsockopt(_server->m_serverSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		ListDestroy(&_server->m_clientList, NULL);
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
		ListDestroy(&_server->m_clientList, NULL);
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	if (listen(_server->m_serverSock, BACK_LOG) < 0)
	{
		ListDestroy(&_server->m_clientList, NULL);
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	return 1;
}

Server_t* ServerCreate(AppFunc _func, int _port)
{
	Server_t* server;
	if (NULL == _func)
	{
		return NULL;
	}
	if (NULL == (server = AllocateMemory()))
	{
		return NULL;
	}
	InitializeDataMembers(server, _func);
	if (!InitializeServer(server, _port))
	{
		return NULL;
	}
	return server;
}

int ServerRun(Server_t* _server)
{
	size_t runNum = 0;
	
	if (NULL == _server)
	{
		return 0;
	}	
	signal(SIGINT, intHandler);
	while(keepRunning)
	{
		ServerRoutine(_server);
	}
	
	return 1;
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
	
	FD_ZERO(&_server->m_fdSet);
	
	_server->m_serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if (_server->m_serverSock < 0)
	{
		/*TODO: destroy list */
		ListDestroy(&_server->m_clientList, NULL);
		free(_server);
		return 0;
	}
	_server->m_maxFdVal = _server->m_serverSock;
	
	FD_SET(_server->m_serverSock, &_server->m_fdSet);
	FD_SET(STDIN_FILENO, &_server->m_fdSet);
	
	if (setsockopt(_server->m_serverSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		ListDestroy(&_server->m_clientList, NULL);
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
		ListDestroy(&_server->m_clientList, NULL);
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	if (listen(_server->m_serverSock, BACK_LOG) < 0)
	{
		ListDestroy(&_server->m_clientList, NULL);
		close(_server->m_serverSock);
		free(_server);
		return 0;
	}
	
	return 1;
}



static void ServerRoutine(Server_t* _server)
{
	fd_set fdSet;
	int activity;
	fdSet = _server->m_fdSet;
	
	activity = select(_server->m_maxFdVal + 1, &fdSet, NULL, NULL, NULL);
	if (activity == 0)
	{
		printf("activity == 0\n");
		return;
	}
	if (-1 == activity)
	{
		perror("select failed");
		abort();
	}
	else
	{
		printf("activity > 0\n");
		if (FD_ISSET(STDIN_FILENO, &fdSet))
		{
			keepRunning = 0;
			return;
		}
		
		if (FD_ISSET(_server->m_serverSock, &fdSet))
		{
			CheckNewClients(_server);
		}
		
		CheckCurrentClients(_server, fdSet, activity);
	}
	return;
}

static void CheckNewClients(Server_t* _server)
{
	struct sockaddr_in clientSin;
	int addr_len = sizeof(clientSin);
	int tempClientSock = 0;
	int* clientSock;
	int flags;
	fd_set fdSet;
	int activity;
	size_t fd;
	
	tempClientSock = accept(_server->m_serverSock, (struct sockaddr*) &clientSin, &addr_len);
	if (-1 == tempClientSock)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			/* DO something */
			/* printf("CheckNewClients, errno is EAGAIN or EWOULDBLOCK\n");*/
			return;
		}
		else if (errno != EMFILE)
		{
			perror("accept failed");
			abort();
		}
		 printf("CheckNewClients unhandled errno!!!\n");
		 return;
	}
	if (_server->m_numOfClients >= MAX_CLIENT_NUM)
	{
		printf("Maximum client number reached, closing %d", tempClientSock);
		close(tempClientSock);
		return;
	}
	if (0 < tempClientSock)
	{
		clientSock = malloc(sizeof(int));
		if (NULL == clientSock)
		{
			//TODO: handle malloc fail
		}
		*clientSock = tempClientSock;
		if (_server->m_maxFdVal < *clientSock)
		{
			_server->m_maxFdVal = *clientSock;
		}
		ListPushTail(_server->m_clientList, clientSock);
		FD_SET(*clientSock, &_server->m_fdSet);
		++_server->m_numOfClients;	
	}
}

static void CheckCurrentClients(Server_t* _server, fd_set _fdSet, int _activity)
{
	int activity;
	char buffer[BUFFER_LEN];
	int numOfBytesRead;
	ListItr itr;
	ListItr tempItr;
	ListItr itrListEnd;
	int* removedSock;
	int numOfDone = 0;
	
	itr = ListItrBegin(_server->m_clientList);
	itrListEnd = ListItrEnd(_server->m_clientList);
	
	while(!ListItrEquals(itr, itrListEnd) && numOfDone < _activity)
	{
		if (!FD_ISSET(*(int*)ListItrGet(itr), &_fdSet))
		{
			itr = ListItrNext(itr);
			continue;
		}
	
		numOfBytesRead = read(*(int*)ListItrGet(itr), buffer, BUFFER_LEN);
		if(0 == numOfBytesRead)
		{
			/* Handle client closed socket */
			if (-1 == close(*(int*)ListItrGet(itr)))
			{
				/*TODO: handle this */
			}
			FD_CLR(*(int*)ListItrGet(itr), &_server->m_fdSet);
			tempItr = ListItrNext(itr);
			removedSock = ListItrRemove(itr);
			--_server->m_numOfClients;
			free(removedSock);
			itrListEnd = ListItrEnd(_server->m_clientList);
			itr = tempItr;
			continue;
		}
		if(-1 == numOfBytesRead)
		{
			if (errno == EAGAIN || errno == EWOULDBLOCK || errno == ECONNRESET) /*TODO: ECONNRESET should be handled seperately? */
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
		++numOfDone;
	}
}

static void DestroySockets(int* _socket, void* _context)
{
	close(*_socket);
	free(_socket);
}
