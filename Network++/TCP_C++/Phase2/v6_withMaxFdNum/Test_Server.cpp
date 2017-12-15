#include "./ServerCPP/ServerCPP.h"
//#include "./NetExceptions/NetExceptions.h"
#include<iostream>
using namespace std;

void* PrintStuffInCPP(void* _context)
{
	static size_t count = 1;
	std::cout << (char*)_context << " " << count << std::endl;
	++count;
	return 0;
}

int main()
{
	const size_t maxNumOfClients = 1000;
	const size_t backLog = maxNumOfClients + 2;
	try
	{
		netcpp::Server server(PrintStuffInCPP, 8888, maxNumOfClients, backLog);
		server.Run();
	}
	catch(const std::exception& _exc)
	{
		std::cout << _exc.what() << std::endl;
	}
	return 0;
}
