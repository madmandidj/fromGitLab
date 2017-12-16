#include "ClientCPP.h"
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<csignal>

using namespace std;

static bool keepRunning = true;

void intHandler(int dummy) 
{
    keepRunning = 0;
}
	
int main(int _argc, char* _argv[])
{	
//	const int CLIENT_NUM = 999;
	size_t numOfClients;
	int randClient;
	size_t index;
//	netcpp::Client smartClientArr[CLIENT_NUM];
	netcpp::Client* smartClientArr;
	
	size_t numOfConnected = 0;
	char ip[128];
	int port;
	size_t numToDisconnect = 0;
	size_t numToRun = 0;
	size_t numToConnect = 0;
	signal(SIGINT, intHandler);
//	
	srand(time(NULL));
	
	/*******
	Check input arguments
	*******/
	if(1 == _argc)
	{
		strcpy(ip, "127.0.0.1");
		port = 8888;
		numOfClients = 1000;
	}
	else if(2 == _argc)
	{
		std::cout << "char* ip(127.0.0.1), int port(8888), int numOfClients(1000)" << std::endl;
		return 0;
	}
	else if(4 == _argc)
	{
		strcpy(ip, _argv[1]);
		port = atoi(_argv[2]);
		numOfClients = atoi(_argv[3]);
	}
	else
	{
		std::cout << "Invalid num of arguments to main() " << std::endl;
		abort();
	}
	
	
	smartClientArr = new netcpp::Client[numOfClients];
	
	
	/*******
	Create and Connect all Clients and Do initial Run
	*******/
	for (index = 0; index < numOfClients; ++index)
	{
		try
		{
			smartClientArr[index].Connect(port, ip);
			std::cout << "Client " << index << "connected" << endl;
			++numOfConnected;
			smartClientArr[index].Run();
		}
		catch(const std::exception& _exc)
		{
			//TODO:
			int mynum =rand() % 100;
			std::cout << mynum << std::endl;
			sleep(2);
		}
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
			randClient = rand() % numOfClients;
			while (!smartClientArr[randClient].IsConnected())
			{
				randClient = rand() % numOfClients;
			}
			smartClientArr[randClient].Disconnect();
			--numOfConnected;
			std::cout << "Client " << randClient << "disconnected" << endl;
		}
		/*******
		30% of connected clients should run
		*******/
		numToRun = (numOfConnected * 30) / 100;
		for(index = 0; index < numToRun; ++index)
		{
			randClient = rand() % numOfClients;
			while (!smartClientArr[randClient].IsConnected())
			{
				randClient = rand() % numOfClients;
			}
			try
			{
				smartClientArr[randClient].Run();
			}
			catch(std::exception& _exc)
			{
				std::cout << _exc.what() << std::endl;
				sleep(2);
			}
			std::cout << "Client " << randClient << "ran" << endl;
		}
		/*******
		30% of disconnected clients should connect
		*******/
		numToConnect = (30 *(numOfClients - numOfConnected)) / 100;
		for(index = 0; index < numToConnect; ++index)
		{
			randClient = rand() % numOfClients;
			while (smartClientArr[randClient].IsConnected())
			{
				randClient = rand() % numOfClients;
			}
			try
			{
				smartClientArr[randClient].Connect(port, ip);
			}
			catch(const std::exception& _exc)
			{
				//TODO:
				std::cout << _exc.what() << std::endl;
				sleep(2);
			}
			++numOfConnected;
			std::cout << "Client " << randClient << "connected" << endl;
		}
	}

	delete[] smartClientArr;
	return 0;
}

























