#include "Server_t.h"
#include <stdio.h>
void* PrintIt(void* _buffer)
{
/*	size_t index;*/
/*	for (index = 0; index < 5; ++index)*/
/*	{	*/
		printf("%s", (char*)_buffer);
/*	}*/
/*	fflush(stdout);*/
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
