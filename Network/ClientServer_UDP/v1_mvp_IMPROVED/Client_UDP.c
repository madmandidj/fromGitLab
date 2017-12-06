#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void GetInputParam(int _argc, char* _argv[], int* _port, char* _myIP)
{
	int option = 0;
	if (_argc <= 2)
	{
		perror("Invalid num of arguments");
		exit(EXIT_FAILURE);
	}
	
    while ((option = getopt(_argc, _argv,"p:i:")) != -1) 
    {
		switch (option) 
		{
		     case 'p' :
		     	*_port = atoi(optarg);
		     case 'i' :
				strcpy(_myIP, optarg);
		         break;
		     default:
		         exit(EXIT_FAILURE);
		}
    }
}

int OpenSocket()
{
	int sock;
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		perror("socket failed\n");
		abort();
	}
	return sock;
}

void InitSockAddr(struct sockaddr_in* _sin, char* _myIP, int _port)
{
	memset(_sin, 0, sizeof(*_sin));
	_sin->sin_family = AF_INET;
	_sin->sin_addr.s_addr = inet_addr(_myIP);
	_sin->sin_port = htons(_port);
}

int SendTo(int _sock, char* _data, struct sockaddr_in* _sin)
{
	int sent_bytes;
	sent_bytes = sendto(_sock, _data, strlen(_data) + 1, 0, (struct sockaddr*) _sin, sizeof(*_sin));
	if (sent_bytes < 0)
	{
		perror("sendto failed\n");
		abort();
	}
	return sent_bytes;
}


int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in sin;
	int sent_bytes;
	char data[] = "Yooo Hana";
	int option = 0;
	int port;
	char myIP[256];

	GetInputParam(argc, argv, &port, myIP);
	
/*	sock = socket(AF_INET, SOCK_DGRAM, 0);*/
/*	if (sock < 0)*/
/*	{*/
/*		perror("socket failed\n");*/
/*		abort();*/
/*	}*/
	sock = OpenSocket();
	
/*	memset(&sin, 0, sizeof(sin));*/
/*	sin.sin_family = AF_INET;*/
/*	sin.sin_addr.s_addr = inet_addr(myIP);*/
/*	sin.sin_port = htons(port);*/
	InitSockAddr(&sin, myIP, port);

/*	sent_bytes = sendto(sock, data, strlen(data) + 1, 0, (struct sockaddr*) &sin, sizeof(sin));*/
/*	if (sent_bytes < 0)*/
/*	{*/
/*		perror("sendto failed\n");*/
/*		abort();*/
/*	}*/
	SendTo(sock, data, &sin);
	return 0;
}
