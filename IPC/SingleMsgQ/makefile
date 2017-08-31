FLAGS1 = -g -ansi -pedantic -Wall -Wconversion -Werror -o ServerMsgQ.out
FLAGS2 = -g -ansi -pedantic -Wall -Wconversion -Werror -o ClientMsgQ.out

all: ServerMsgQ.out ClientMsgQ.out

ServerMsgQ.out: ServerMsgQ.c
	gcc $(FLAGS1) ServerMsgQ.c 
	
ClientMsgQ.out: ClientMsgQ.c
	gcc $(FLAGS2) ClientMsgQ.c 


clean:
	rm ClientMsgQ.out ServerMsgQ.out
