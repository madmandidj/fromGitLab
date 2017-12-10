#include "Server_t.h"
#include <stdio.h>
#define PORT 1234

void* PrintIt(void* _buffer)
{
	printf("%s", (char*)(_buffer + sizeof(size_t)));
	printf("%lu\n", *(size_t*)_buffer);
	return NULL;
}

int main()
{
	Server_t* server;
	const int port = PORT;
	server = ServerCreate(PrintIt, port);
	ServerRun(server);
	ServerDestroy(server);
	return 0;
}
