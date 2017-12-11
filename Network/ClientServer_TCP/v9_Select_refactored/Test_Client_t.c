#include "Client_t.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include<string.h>
#include <signal.h>
#define CLIENT_NUM 1000
#define PORT 1234

typedef struct SmartClient
{
	Client_t* 	m_client;
	int			m_isConnected;
}SmartClient;

static volatile int keepRunning = 1;

void intHandler(int dummy) 
{
    keepRunning = 0;
}

int main(int _argc, char* _argv[])
{
	int randClient;
	size_t index;
	SmartClient smartClientArr[CLIENT_NUM];
	int numOfConnected = 0;
	char ip[128];
	int numToDisconnect = 0;
	int numToRun = 0;
	int numToConnect = 0;
	signal(SIGINT, intHandler);
	
	srand(0);
	
	/*******
	Check input arguments (IP) and Init
	*******/
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
	/*******
	Create and Connect all Clients and Do initial Run
	*******/
	for (index = 0; index < CLIENT_NUM; ++index)
	{
		smartClientArr[index].m_client = ClientCreate(PORT, ip);
		if (!ClientConnect(smartClientArr[index].m_client, PORT, ip))
		{
			perror("Client connect error");
			abort();
		}
		smartClientArr[index].m_isConnected = 1;
		++numOfConnected;
		ClientRun(smartClientArr[index].m_client);
	}
	/*******
	Do SmartClient Loop
	*******/
	while (keepRunning)
	{
		/*******
		10% of connected clients should disconnect
		*******/
		numToDisconnect = (numOfConnected * 10) / 100;
		for(index = 0; index < numToDisconnect; ++index)
		{
			randClient = rand() % CLIENT_NUM;
			while (!smartClientArr[randClient].m_isConnected)
			{
				randClient = rand() % CLIENT_NUM;
			}
			printf("Disconnecting Client %u\n", randClient);
			ClientDisconnect(smartClientArr[randClient].m_client);
			smartClientArr[randClient].m_isConnected = 0;
			--numOfConnected;
		}
		/*******
		30% of connected clients should run
		*******/
		numToRun = (numOfConnected * 30) / 100;
		for(index = 0; index < numToRun; ++index)
		{
			randClient = rand() % CLIENT_NUM;
			while (!smartClientArr[randClient].m_isConnected)
			{
				randClient = rand() % CLIENT_NUM;
			}
			printf("Running Client %u\n", randClient);
			ClientRun(smartClientArr[randClient].m_client);
		}
		/*******
		30% of disconnected clients should connect
		*******/
		numToConnect = (30 *(CLIENT_NUM - numOfConnected)) / 100;
		for(index = 0; index < numToConnect; ++index)
		{
			randClient = rand() % CLIENT_NUM;
			while (smartClientArr[randClient].m_isConnected)
			{
				randClient = rand() % CLIENT_NUM;
			}
			printf("Connecting Client %u\n", randClient);
			if (!ClientConnect(smartClientArr[randClient].m_client, PORT, ip))
			{
				perror("Client connect error");
				abort();
			}
			smartClientArr[randClient].m_isConnected = 1;
			++numOfConnected;
		}
	}
	/*******
	Destroy all Clients after receiving SIGINT
	*******/
	for (index = 0; index < CLIENT_NUM; ++index)
	{
		ClientDestroy(smartClientArr[index].m_client);
		printf("Destroyed Client %lu\n", (long unsigned int)index);
	}

	return 0;
}
