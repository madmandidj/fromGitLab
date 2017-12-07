#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define BUFFER_LEN 4096
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




int main(int _argc, char* _argv[])
{
	int sock;
	struct sockaddr_in sin;
	int sent_bytes;
	char data[] = "Maftiya\n\0";
	int option = 0;
	int port;
	char myIP[256];
	ssize_t numOfBitsWritten;
	char buffer[BUFFER_LEN];
	
	GetInputParam(_argc, _argv, &port, myIP);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("socket() failed");
		abort();
	}
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(myIP);
	sin.sin_port = htons(port);
	
	if (connect(sock, (struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
		perror("connection failed");
		abort();
	}
	
	numOfBitsWritten = write(sock, data, strlen(data));
	
	read(sock, buffer, BUFFER_LEN);
	
	printf("%s\n", buffer);
	
	close(sock);
	sleep(3);
	printf("done\n");
	return 0;
}


