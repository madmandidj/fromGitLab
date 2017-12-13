#include "ClientCPP.h"

using namespace std;

int main()
{
	netcpp::Client client;
	client.Connect(8888, "127.0.0.1");
	client.Run();
	return 0;
}
