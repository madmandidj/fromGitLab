all: Server_t.out Client.out

Server_t.out: Server_t.c
	gcc Server_t.c -o Server_t.out -g

Client.out: Client_TCP.c
	gcc Client_TCP.c -o Client.out -g
	
clean:
	rm Server_t.out Client.out
