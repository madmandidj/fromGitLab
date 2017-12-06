#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
/*#include <getopt.h>*/

int main(int argc, char* argv[])
{
	int option = 0;
	int port;
	const int totalNumOfMsgs = 2;
	int numOfMsgs;
	int sent_bytes;
	char data[128];
	if (argc == 1)
	{
		perror("Invalid num of arguments");
		exit(EXIT_FAILURE);
	}

    while ((option = getopt(argc, argv,"p:")) != -1) {
        switch (option) {
             case 'p' :
             	port = atoi(optarg);
                 break;
             default:
                 exit(EXIT_FAILURE);
        }
    }
    
/*	int sock = socket(AF_INET, SOCK_DGRAM, 0);*/
	int sock = socket(AF_INET6, SOCK_DGRAM, 0);
/*	struct sockaddr_in sin;*/
	struct sockaddr_in6 sin;
	int sin_len = sizeof(sin);
	char buffer[4096];
	int read_bytes;
	
	if (sock < 0)
	{
		perror("socket failed\n");
		abort();
	}
	
	memset(&sin, 0, sizeof(sin));
	sin.sin6_family = AF_INET6;
	sin.sin6_addr = in6addr_any;
	sin.sin6_port = htons(port);
	if(bind(sock, (struct sockaddr*) &sin, sizeof(sin)) < 0)
	{
		perror("bind failed\n");
		abort();
	}
	
	for (numOfMsgs = 0; numOfMsgs < totalNumOfMsgs; ++numOfMsgs)
	{
		read_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*) &sin, &sin_len);
		if (read_bytes < 0)
		{
			perror("recvfrom failed\n");
			abort();
		}
		buffer[sizeof(buffer)] = '\0';
		printf("Received: %s\n", buffer);
		
		if (!strcmp(buffer, "what is your name?"))
		{
			strcpy(data, "my name is Eyal");
		}
		else if (!strcmp(buffer, "what is your age?"))
		{
			strcpy(data, "my age is 12 yummy");
		}
		sent_bytes = sendto(sock, data, strlen(data) + 1, 0, (struct sockaddr*) &sin, sizeof(sin));
		if (sent_bytes < 0)
		{
			perror("sendto failed\n");
			abort();
		}
	}
	
	if (close(sock))
	{
		perror("close failed");
		abort();
	}
	return 0;
}
