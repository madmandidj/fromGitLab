#include "Client_t.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include<string.h>

#define CLIENT_NUM 50
#define NUM_OF_REPS 100
typedef struct SmartClient
{
	Client_t* 	m_client;
	int			m_isConnected;
}SmartClient;

int main(int _argc, char* _argv[])
{
	int randNum;
	size_t index;
	size_t reps = 0;
	int curClient;
	SmartClient smartClientArr[CLIENT_NUM];
	SmartClient* connectedClients[CLIENT_NUM];
	int numOfConnected;
	SmartClient* disconnectedClients[CLIENT_NUM];
	int numOfDisconnected;
	Client_t* clientArr[CLIENT_NUM];
	char ip[128];
	
	if(1 == _argc)
	{
		strcpy(ip, "127.0.0.1");
	}
	else if(2 == _argc)
	{
		strcpy(ip, _argv[1]);
	}
	else
	{
		printf("Invalid num of arguments to main()\n");
		abort();
	}

	srand(0);
	for (index = 0; index < CLIENT_NUM; ++index)
	{
/*		smartClientArr[index].m_client = ClientCreate(8888, "127.0.0.1");*/
/*		if (!ClientConnect(smartClientArr[index].m_client, 8888, "127.0.0.1"))*/
		smartClientArr[index].m_client = ClientCreate(8888, ip);
		if (!ClientConnect(smartClientArr[index].m_client, 8888, ip))
		{
			perror("Client connect error");
			abort();
		}
		smartClientArr[index].m_isConnected = 1;
		ClientRun(smartClientArr[index].m_client);
	}
	
	for (index = 0; index < CLIENT_NUM; ++index)
	{
		ClientDestroy(smartClientArr[index].m_client);
	}


	return 0;
}
