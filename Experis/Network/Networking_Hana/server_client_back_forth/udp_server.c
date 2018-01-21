#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>





typedef struct sockaddr_in sockaddr_in;



int main(int argc, char* argv[])
{
	int sock;
	sockaddr_in sin;
	int sin_len;
	int read_bytes;
	char buffer[4096];
	int closeResult;
	int arg;
	int port;
	
	
	
	while ((arg = getopt (argc, argv, "i:p:")) != -1)
    {
		switch (arg)
		  {
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
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(8888);
	
	if(bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
	{
		perror("bind failed\n");
		abort();
	}
	
	
	
	/*server - receive message */
	sin_len = sizeof(sin);

	read_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&sin, &sin_len);
	if (read_bytes < 0)
	{
		perror("recvfrom failed\n");
		abort();
	}
	buffer[sizeof(buffer)] = '\0';
	printf("%s\n", buffer);
	
	
	/*clost socket */
	if (closeResult = close(sock) < 0)
	{
		perror("close socket failed\n");
		abort();
	}
	
	return 0;
}















