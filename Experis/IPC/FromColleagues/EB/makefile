CFLAGS = -ansi -pedantic -Wall -Wconversion -std=gnu99 -g

all : Client.out Server.out

Client.out : Client.c Package.o
	gcc $(CFLAGS) $^ -pthread -o $@

Server.out : Server.c Package.o
	gcc $(CFLAGS) $^ -pthread -o $@

Package.o : Package.c
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm Client.out Server.out Package.o