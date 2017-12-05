#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(int argc, char* argv[])
{
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in sin;
	int sent_bytes;
	char data[] = "Yooo Hana";
	int option = 0;
	int port;
	char* myIP;

    while ((option = getopt(argc, argv,"p:i:")) != -1) {
        switch (option) {
             case 'p' :
             	port = atoi(optarg);
             case 'i' :
             	myIP = optarg;
                 break;
             default:
                 exit(EXIT_FAILURE);
        }
    }
	
	if (sock < 0)
	{
		perror("socket failed\n");
		abort();
	}
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(myIP);
	sin.sin_port = htons(port);
	sent_bytes = sendto(sock, data, strlen(data) + 1, 0, (struct sockaddr*) &sin, sizeof(sin));
	if (sent_bytes < 0)
	{
		perror("sendto failed\n");
		abort();
	}
	return 0;
}
