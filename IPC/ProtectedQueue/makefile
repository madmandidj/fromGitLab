FLAGS1 = -g -ansi -pedantic -Wall -Wconversion -Werror -o TestPQ.out -pthread


all: TestPQ.out  




TestPQ.out: TestProtectedQueue.c ProtectedQueue.c ProtectedQueue.h
	gcc $(FLAGS1) TestProtectedQueue.c ProtectedQueue.c
	



clean:
	rm TestPQ.out 
