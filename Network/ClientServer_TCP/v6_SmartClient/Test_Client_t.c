#include "Client_t.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define CLIENT_NUM 50
#define NUM_OF_REPS 100
typedef struct SmartClient
{
	Client_t* 	m_client;
	int			m_isConnected;
}SmartClient;

int main()
{
/*	size_t index;*/
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

	
	srand(0);
	for (index = 0; index < CLIENT_NUM; ++index)
	{
		smartClientArr[index].m_client = ClientCreate(8888, "127.0.0.1");
		if (!ClientConnect(smartClientArr[index].m_client, 8888, "127.0.0.1"))
		{
			perror("Client connect error");
			abort();
		}
		smartClientArr[index].m_isConnected = 1;
		ClientRun(smartClientArr[index].m_client);
	}
	
/*	for(;;)*/
/*	{*/
/*		int ThirtyPercentOfClients;*/
/*		ThirtyPercentOfClients = (CLIENT_NUM*3)/100;*/
/*		for(index = 0; index < ThirtyPercentOfClients; ++index)*/
/*		{*/
/*			*/
/*		}*/
/*	}*/
	
	
	for (index = 0; index < CLIENT_NUM; ++index)
	{
		ClientDestroy(smartClientArr[index].m_client);
	}
	
	
	
/*	ClientRun(clientArr[0]);*/
/*	*/
/*	ClientDisconnect(clientArr[0]);*/
/*	*/
/*	ClientConnect(clientArr[0], 8888, "127.0.0.1");*/
/*	*/
/*	ClientRun(clientArr[0]);*/
/*	*/
/*	ClientDestroy(clientArr[0]);*/

	return 0;
}
