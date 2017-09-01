FLAGS1 = -g -ansi -pedantic -Wall -Wconversion -Werror -o ServerMsgQ.out
FLAGS2 = -g -ansi -pedantic -Wall -Wconversion -Werror -o ClientMsgQ.out
FLAGS3 = -g -ansi -pedantic -Wall -Wconversion -Werror -o MyMQWatchdog.out


all: ServerMsgQ.out ClientMsgQ.out MyMQWatchdog.out

ServerMsgQ.out: ServerMsgQ.c 
	gcc $(FLAGS1) ServerMsgQ.c MyMsgQ.c
	
ClientMsgQ.out: ClientMsgQ.c 
	gcc $(FLAGS2) ClientMsgQ.c MyMsgQ.c

MyMQWatchdog.out: MyMQWatchdog.c
	gcc $(FLAGS3) MyMQWatchdog.c MyMsgQ.c

clean:
	rm ClientMsgQ.out ServerMsgQ.out MyMQWatchdog.out
