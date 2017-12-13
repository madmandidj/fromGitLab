#include "ServerCPP.h"
#include<iostream>
using namespace std;

void* PrintStuffInCPP(void* _context)
{
	std::cout << "In PrintStuffInCPP()" << std::endl;
	return 0;
}

int main()
{
	netcpp::Server server(PrintStuffInCPP, 8888);
	server.Run();
	return 0;
}
