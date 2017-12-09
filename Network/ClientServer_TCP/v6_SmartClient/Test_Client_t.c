#include "Client_t.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define CLIENT_NUM 1
#define NUM_OF_REPS 100

int main()
{
	size_t index;
	size_t reps = 0;
	int curClient;
	Client_t* clientArr[CLIENT_NUM];
	size_t connectedClients[CLIENT_NUM];
	size_t disconnectedClients[CLIENT_NUM];
	size_t numOfConnected = 0;
	size_t numOfDisconnected = CLIENT_NUM;
	
	srand(0);
	for (index = 0; index < CLIENT_NUM; ++index)
	{
		clientArr[index] = ClientCreate(8888, "127.0.0.1");
		disconnectedClients[index] = index;
	}
	
	ClientRun(clientArr[0]);
	
	ClientDisconnect(clientArr[0]);
	
	ClientInit(clientArr[0], 8888, "127.0.0.1");
	
	ClientRun(clientArr[0]);
	
	ClientDestroy(clientArr[0]);
	/*
		
	*/
	
/*	for (reps = 0; reps < (numOfDisconnected * 30)/100; ++reps)*/
/*	{*/
/*		clientArr*/
/*	}*/
	
/*	while (reps < NUM_OF_REPS)*/
/*	{*/
/*		*/
/*		curClient = rand() % NUM_OF_REPS;*/
/*		++reps;*/
/*	}*/
	
	
	
	
/*	Client_t* client;*/
/*	client = ClientCreate(8888, "127.0.0.1");*/
/*	ClientRun(client);*/
/*	ClientDestroy(client);*/
	return 0;
}
