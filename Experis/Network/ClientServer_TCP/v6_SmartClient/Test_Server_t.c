#include "Server_t.h"
#include <stdio.h>

void* PrintIt(void* _buffer)
{
	printf("%s", (char*)(_buffer + sizeof(size_t)));
	printf("%u\n", *(size_t*)_buffer);
	return NULL;
}

int main()
{
	Server_t* server;
	const int port = 8888;
	server = ServerCreate(PrintIt, port);
	ServerRun(server);
	ServerDestroy(server);
	return 0;
}
