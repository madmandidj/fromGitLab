all: Server.out Client.out

Server.out: Server_TCP.c
	gcc Server_TCP.c -o Server.out -g

Client.out: Client_TCP.c
	gcc Client_TCP.c -o Client.out -g
	
clean:
	rm Server.out Client.out
