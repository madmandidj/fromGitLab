all: Server_t.out Client_t.out

Server_t.out: Server_t.h Server_t.c Test_Server_t.c
	gcc Test_Server_t.c Server_t.c list.c list_functions.c -o Server_t.out -g

Client_t.out: Client_t.h Client_t.c Test_Client_t.c
	gcc Test_Client_t.c Client_t.c -o Client_t.out -g
	
clean:
	rm Server_t.out Client_t.out
