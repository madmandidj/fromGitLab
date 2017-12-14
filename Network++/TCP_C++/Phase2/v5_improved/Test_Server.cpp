#include "./ServerCPP/ServerCPP.h"
//#include "./NetExceptions/NetExceptions.h"
#include<iostream>
using namespace std;

void* PrintStuffInCPP(void* _context)
{
	std::cout << (char*)_context << std::endl;
	return 0;
}

int main()
{
	netcpp::Server server(PrintStuffInCPP, 8888);
	try
	{
		server.Run();
	}
	catch(const std::exception& _exc)
	{
		std::cout << _exc.what() << std::endl;
	}
	return 0;
}
