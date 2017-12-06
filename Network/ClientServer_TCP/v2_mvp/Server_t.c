#include "Server_t.h"
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
#define BUFFER_LEN 4096

struct Server_t
{
	struct sockaddr_in 	m_server_sin;
	int					m_serverSock;
	struct sockaddr_in	m_client_sinArr[NCLIENTS];
	int					m_client_sockArr[NCLIENTS];
	size_t				m_curClientNum;
	AppFunc 			m_appFunc;
};

Server_t* ServerCreate(AppFunc _func, int _port)
{
	int optval = 1;
	const int back_log = 32;
	
	Server_t* server = malloc(sizeof(Server_t));
	if (NULL == server)
	{
		return NULL;
	}
	
	server->m_curClientNum = 0;
	
	server->m_appFunc = _func;
	
/*	server->m_serverSock = socket(AF_INET, SOCK_STREAM, O_NONBLOCK);*/
	server->m_serverSock = socket(AF_INET, SOCK_STREAM, SOCK_NONBLOCK);
	if (server->m_serverSock < 0)
	{
		free(server);
		return NULL;
	}
	
	if (setsockopt(server->m_serverSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		close(server->m_serverSock);
		free(server);
		return NULL;
	}
	
	memset(&server->m_server_sin, 0, sizeof(server->m_server_sin));
	server->m_server_sin.sin_family = AF_INET;
	server->m_server_sin.sin_addr.s_addr = INADDR_ANY;
	server->m_server_sin.sin_port = htons(_port);
	
	if(bind(server->m_serverSock, (struct sockaddr*) &server->m_server_sin, sizeof(server->m_server_sin)) < 0)
	{
		close(server->m_serverSock);
		free(server);
		return NULL;
	}
	
	if (listen(server->m_serverSock, back_log) < 0)
	{
		close(server->m_serverSock);
		free(server);
		return NULL;
	}
	
	return server;
}

static void CheckNewClients(Server_t* _server)
{
	int addr_len = sizeof(_server->m_client_sinArr[_server->m_curClientNum]);
	
	_server->m_client_sockArr[_server->m_curClientNum] = accept(_server->m_serverSock, 
														(struct sockaddr*) &_server->m_client_sinArr[_server->m_curClientNum], 
														&addr_len);
														
	if (0 < _server->m_client_sockArr[_server->m_curClientNum])
	{
		++_server->m_curClientNum;
	}
	else if (errno != EAGAIN && errno != EWOULDBLOCK)
	{
		/* DO something */
	}
}

static void CheckCurrentClients(Server_t* _server)
{
	size_t index;
	char buffer[256];
	int numOfBytesRead;
	
	for (index = 0; index < _server->m_curClientNum; ++index)
	{
		numOfBytesRead = read(_server->m_client_sockArr[_server->m_curClientNum], 
								buffer, BUFFER_LEN);
		if(0 == numOfBytesRead)
		{
			/* Handle client closed socket */
			printf("In Server, client closed socket\n");
		}
		if(-1 == numOfBytesRead)
		{
			/* DO something */
			printf("Server read failed\n");
			abort();
		}
		
		_server->m_appFunc(buffer);
	}
}

void ServerRun(Server_t* _server)
{
	size_t runNum = 0;
	
	for(;;)
	{
		printf("Run number %lu\n", runNum);
		CheckNewClients(_server);
		CheckCurrentClients(_server);
		sleep(1);
		++runNum;
	}
}

void ServerDestroy(Server_t* _server)
{
	size_t index;
	
	free(_server);
	/*TODO: complete this function */
}










/*****************************************
******************************************/



void* PrintShit(void* _buffer)
{
	printf("PrintShit: %s", (char*)_buffer);
	return NULL;
}

int main()
{
	Server_t* server;
	const int port = 8888;
	server = ServerCreate(PrintShit, port);
	ServerRun(server);
	
	return 0;
}

