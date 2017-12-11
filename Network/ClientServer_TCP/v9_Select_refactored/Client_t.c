#include "Client_t.h"
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define BUFFER_LEN 256
/*************************
**************************
Client_t struct definition
**************************
**************************/
struct Client_t
{
	int m_sock;
};
/************************************
*************************************
Client_t static function forward declarations
*************************************
************************************/
int ClientDoConnect(Client_t* _client, int _port, char* _ip);
/************************************
*************************************
Client_t API function implementations
*************************************
************************************/
Client_t* ClientCreate(int _port, char* _ip)
{
	if (NULL == _ip)
	{
		return NULL;
	}
	Client_t* client = malloc(sizeof(Client_t));
	if (NULL == client)
	{
		return NULL;
	}
	
	return client;
}

void ClientDestroy(Client_t* _client)
{
	close(_client->m_sock);
	free(_client);
}

void ClientRun(Client_t* _client)
{
	static size_t ClientRunNum = 0;
	char sendData[BUFFER_LEN];
	char rcvData[BUFFER_LEN];
	char data[] = "Maftiya\n\0";
	int numOfBytes;
	size_t receivedRunNum;
	char receivedData[BUFFER_LEN];
	
	++ClientRunNum;
	
	memcpy(sendData, &ClientRunNum, sizeof(size_t));
	memcpy(sendData + sizeof(size_t), data, strlen(data) + 1);
/*	numOfBytes = write(_client->m_sock, sendData, sizeof(size_t) + strlen(data) + 1);*/
	numOfBytes = send(_client->m_sock, sendData, sizeof(size_t) + strlen(data) + 1, MSG_NOSIGNAL);
	printf("Num of bytes wrote = %d\n",numOfBytes);
	printf("Client sent %lu and %s\n", (long unsigned int)ClientRunNum, data);
	
	numOfBytes = read(_client->m_sock, rcvData, BUFFER_LEN);
	if(0 < numOfBytes)
	{	
		printf("Num of bytes read = %d\n",numOfBytes);
		memcpy(&receivedRunNum, rcvData, sizeof(size_t));
		memcpy(receivedData, rcvData + sizeof(size_t), numOfBytes - sizeof(size_t));
		printf("Client received %lu and %s\n", (long unsigned int)receivedRunNum, receivedData);
	}
	else
	{
		printf("Bytes read is 0 or negative\n");
	}
}

int ClientConnect(Client_t* _client, int _port, char* _ip)
{
	_client->m_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (0 > _client->m_sock)
	{
		free(_client);
		return 0;
	}
	
	return ClientDoConnect(_client, _port, _ip);
}

void ClientDisconnect(Client_t* _client)
{
	close(_client->m_sock);
}

/************************************
*************************************
Client_t static function definitions
*************************************
************************************/
int ClientDoConnect(Client_t* _client, int _port, char* _ip)
{
	struct sockaddr_in sin;
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(_ip);
	sin.sin_port = htons(_port);
	if (connect(_client->m_sock, (struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
		free(_client);
		return 0;
	}
	return 1;
}


























