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
    
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in sin;
	int sin_len = sizeof(sin);
	char buffer[4096];
	int read_bytes;
	
	if (sock < 0)
	{
		perror("socket failed\n");
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
	
	read_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*) &sin, &sin_len);
	if (read_bytes < 0)
	{
		perror("recvfrom failed\n");
		abort();
	}
	
	buffer[sizeof(buffer)] = '\0';
	printf("%s\n", buffer);
	
	if (close(sock))
	{
		perror("close failed");
		abort();
	}
	return 0;
}
