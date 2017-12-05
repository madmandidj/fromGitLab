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
	struct sockaddr_in6 sin;
	char question1[] = "what is your name?";
	char question2[] = "what is your age?";
	char answer1[] = "Very ugly name, shame on you";
	char answer2[] = "Good Name!";	
	char answer3[] = "You get a toy";
	char answer4[] = "You get money";
	char ip[64];
	int port;
	int arg;
	int read_bytes;
	char buffer[4096];
	int sin_len;
	char dest[16];
	
	/*ipv6 */
	
	
	
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
	
/*	udp6_socket = socket(AF_INET6, SOCK_DGRAM, protocol);*/
	
	sock = socket(AF_INET6, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		perror("socket failed\n");
		abort();
	}
	
	
	memset(&sin, 0, sizeof(sin));
	sin.sin6_family = AF_INET6;
/*	sin.sin6_addr.s6_addr = inet_pton(AF_INET6, ip, dest);*/
	if(inet_pton(AF_INET6, ip, &(sin.sin6_addr)) <= 0);
	sin.sin6_port = htons(8888);
	
	
	/*question */
	sent_bytes = sendto(sock, question2, strlen(question2) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));
	if (sent_bytes < 0)
	{
		perror("sendto failed\n");
		abort();
	}
	
	
	/* receive answer */
	read_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&sin, &sin_len);
	if (read_bytes < 0)
	{
		perror("recvfrom failed");
		abort();
	}
	
	printf("%s\n", buffer);
	
	
	if(strcmp(buffer, "my name is Eyal") == 0)
	{
		/*send response */
		sent_bytes = sendto(sock, answer1, strlen(answer1) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));
		if (sent_bytes < 0)
		{
			perror("sendto failed\n");
			abort();
		}
		
	}
	else
	{
		sent_bytes = sendto(sock, answer2, strlen(answer2) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));
		if (sent_bytes < 0)
		{
			perror("sendto failed\n");
			abort();
		}
	}
	
	
	
	
	
	
/*	sent_bytes = sendto(sock, question2, strlen(question2) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));*/
/*	if (sent_bytes < 0)*/
/*	{*/
/*		perror("sendto failed\n");*/
/*		abort();*/
/*	}*/
/*	*/
/*	*/
/*	read_bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&sin, &sin_len);*/
/*	if (read_bytes < 0)*/
/*	{*/
/*		perror("recvfrom failed");*/
/*		abort();*/
/*	}*/
/*	*/
/*	if(strcmp(buffer, "my name is Eyal") == 0)*/
/*	{*/
/*		sent_bytes = sendto(sock, answer3, strlen(answer3) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));*/
/*		if (sent_bytes < 0)*/
/*		{*/
/*			perror("sendto failed\n");*/
/*			abort();*/
/*		}*/
/*		*/
/*	}*/
/*	else*/
/*	{*/
/*		sent_bytes = sendto(sock, answer4, strlen(answer4) + 1, 0, (struct sockaddr*)&sin, sizeof(sin));*/
/*		if (sent_bytes < 0)*/
/*		{*/
/*			perror("sendto failed\n");*/
/*			abort();*/
/*		}*/
/*	}*/
/*	*/
/*	printf("%s\n", buffer);*/
	
	
	return 0;
}







