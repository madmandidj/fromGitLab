#include "ServerCPP.h"
//#include "./NetExceptions/NetExceptions.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

void* PrintStuffInCPP(void* _context)
{
	static size_t count = 1;
	std::cout << (char*)_context << " " << count << std::endl;
	++count;
	return 0;
}

int main(int _argc, char* _argv[]) //port, maxClientNum, backLog
{
	int port;
	int maxClientNum;
	int backLog;
	
	/*******
	Check input arguments
	*******/
	if(1 == _argc)
	{
		port = 8888;
		maxClientNum = 1000;
		backLog = 1000;
	}
	else if(2 == _argc)
	{
		std::cout << "int port(8888), int maxClientNum(1000), int backLog(1000)" << std::endl;
		return 0;
	}
	else if(3 == _argc)
	{
		port = atoi(_argv[1]);
		maxClientNum = atoi(_argv[2]);
		backLog = maxClientNum;
	}
	else if(4 == _argc)
	{
		port = atoi(_argv[1]);
		maxClientNum = atoi(_argv[2]);
		backLog = atoi(_argv[3]);
	}
	else
	{
		std::cout << "Invalid num of arguments to main() " << std::endl;
		abort();
	}
	
	
	try
	{
		netcpp::Server server(PrintStuffInCPP, port, maxClientNum, backLog);
		server.Run();
	}
	catch(const std::exception& _exc)
	{
		std::cout << _exc.what() << std::endl;
	}
	return 0;
}
