all: Server_t.out Client.out

Server_t.out: Server_t.h Server_t.c Test_Server_t.c
	gcc Test_Server_t.c Server_t.c list.c list_functions.c -o Server_t.out -g

Client.out: Client_TCP.c
	gcc Client_TCP.c -o Client.out -g
	
clean:
	rm Server_t.out Client.out
