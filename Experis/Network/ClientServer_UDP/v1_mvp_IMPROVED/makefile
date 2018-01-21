all: Server.out Client.out

Server.out: Server_UDP.c
	gcc Server_UDP.c -o Server.out -g

Client.out: Client_UDP.c
	gcc Client_UDP.c -o Client.out -g
	
clean:
	rm Server.out Client.out
