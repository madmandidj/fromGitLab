testlist.out: TestList.c list_functions.c list.c ../../lib/liblist.a
	gcc -ansi -pedantic -Wall -Wconversion -g -o testlist.out TestList.c -L../../lib -llist 
	
../../lib/liblist.a: list_functions.o list.o 
	ar -cvq ../../lib/liblist.a list.o list_functions.o
	
list_functions.o: list_functions.c ../../inc/list_functions.h
	 gcc -ansi -pedantic -Wall -Wconversion -c list_functions.c
	 
list_itr.o: list.c  ../../inc/list.h
	gcc -ansi -pedantic -Wall -Wconversion -g -c list.c	 
	
list.o: list.c 
	 gcc -ansi -pedantic -Wall -Wconversion -g -c list.c
	 	
clean:
	rm testlist.out ../../lib/liblist.a list_functions.o list.o
