#include "Client_t.h"
#include <stdio.h>



int main()
{
	Client_t* client;
	client = ClientCreate(8888, "127.0.0.1");
	ClientRun(client);
	ClientDestroy(client);
	return 0;
}
