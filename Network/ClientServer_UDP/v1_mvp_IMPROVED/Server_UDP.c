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

    while ((option = getopt(_argc, _argv,"p:")) != -1) {
        switch (option) {
             case 'p' :
             	*_port = atoi(optarg);
                 break;
             default:
                 exit(EXIT_FAILURE);
        }
    }
}

void OpenSocket(int* _sock)
{
	*_sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (*_sock < 0)
	{
		perror("socket failed\n");
		abort();
	}
}

void InitSockAddr(struct sockaddr_in* _sin, int* _port)
{
	memset(_sin, 0, sizeof(*_sin));
	_sin->sin_family = AF_INET;
	_sin->sin_addr.s_addr = INADDR_ANY;
	_sin->sin_port = htons(*_port);
}

void DoBind(int* _sock, struct sockaddr_in* _sin)
{
	if(bind(*_sock, (struct sockaddr*) _sin, sizeof(*_sin)) < 0)
	{
		perror("bind failed\n");
		abort();
	}
}

int ReadFrom(int* _sock, char* _buffer, struct sockaddr_in* _sin, int* _sin_len)
{
	int read_bytes;
	read_bytes = recvfrom(*_sock, _buffer, sizeof(_buffer), 0, (struct sockaddr*) _sin, _sin_len);
	if (read_bytes < 0)
	{
		perror("recvfrom failed\n");
		abort();
	}
	return read_bytes;
}

void ProcessMessage(char* _buffer)
{
	_buffer[sizeof(_buffer)] = '\0';
}

int main(int _argc, char* _argv[])
{
	int port;
	int sock;
	struct sockaddr_in sin;
	int sin_len;
	char buffer[4096];
	int read_bytes;
	sin_len = sizeof(sin);

	GetInputParam(_argc, _argv, &port);
	OpenSocket(&sock);
	InitSockAddr(&sin, &port);
	DoBind(&sock, &sin);
	read_bytes = ReadFrom(&sock, buffer, &sin, &sin_len);
	ProcessMessage(buffer);
	printf("%s\n", buffer);
	
	if (close(sock))
	{
		perror("close failed");
		abort();
	}
	return 0;
}
