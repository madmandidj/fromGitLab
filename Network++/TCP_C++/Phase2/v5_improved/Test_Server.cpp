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
	try
	{
		netcpp::Server server(PrintStuffInCPP, 8888);
		server.Run();
	}
	catch(const std::exception& _exc)
	{
		std::cout << _exc.what() << std::endl;
	}
	return 0;
}
