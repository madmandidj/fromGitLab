#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

void GetInputParam(int _argc, char* _argv[], int* _port)
{
	int option = 0;
	if (_argc == 1)
	{
		perror("Invalid num of arguments");
		exit(EXIT_FAILURE);
	}

    while ((option = getopt(_argc, _argv,"p:")) != -1) 
    {
        switch (option) 
        {
             case 'p' :
             	*_port = atoi(optarg);
                 break;
             default:
                 exit(EXIT_FAILURE);
        }
    }
}

int main(int _argc, char* _argv[])
{
	int port;
	int sock;
	int optval = 1;
	struct sockaddr_in sin;
	struct sockaddr_in client_sin;
	int client_sock;
	int addr_len = sizeof(client_sin);
	int sin_len;
	char buffer[4096];
	int read_bytes;
	const int back_log = 32;
	sin_len = sizeof(sin);
	ssize_t numOfBytesRead;

	GetInputParam(_argc, _argv, &port);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("socket() failed");
		abort();
	}
	
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		perror("reuse failed");
		abort();
	}
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	
	if(bind(sock, (struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
		perror("bind failed\n");
		abort();
	}
	
	if (listen(sock, back_log) < 0)
	{
		perror("listen failed");
		abort();
	}
	
	client_sock = accept(sock, (struct sockaddr*) &client_sin, &addr_len);
	if (client_sock < 0)
	{
		perror("accept fail");
		abort();
	}
	
	numOfBytesRead = read(client_sock, buffer, sizeof(buffer));
	if(-1 == numOfBytesRead)
	{
		perror("read fail");
		abort();
	}
	
	printf("%s\n", buffer);
	
	return 0;
}
