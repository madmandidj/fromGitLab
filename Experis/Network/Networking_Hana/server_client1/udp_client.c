#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>





int main(int argc, char* argv[])
{
	int sock;
	ssize_t sent_bytes;
	struct sockaddr_in sin;
	char message[] = "hello Eyal";
	char ip[64];
	int port;
	int arg;
	
	
	
	while ((arg = getopt (argc, argv, "i:p:")) != -1)
    {
		switch (arg)
		  {
			  case 'i':
			  {
				strcpy(ip, optarg);
				break;
			  }
			  case 'p':
			  {
				port = atoi(optarg);
				break;
			  }
			  default:
				abort ();
		  }
	}
	
	
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		perror("socket failed\n");
		abort();
	}
	
	
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(ip);
	sin.sin_port = htons(8888);
	
	
	sent_bytes = sendto(sock, message, strlen(message) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));
	if (sent_bytes < 0)
	{
		perror("sendto failed\n");
		abort();
	}
	return 0;
}
