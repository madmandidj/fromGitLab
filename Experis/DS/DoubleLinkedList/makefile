FLAGS = -ansi -pedantic -Wall -Wconversion -g 
INC_PATH = ../../inc/
LIB_PATH = ../../lib/

testlist.out: TestList.c list_functions.c list.c $(LIB_PATH)liblist.a
	gcc -ansi -pedantic -Wall -Wconversion -g -o testlist.out TestList.c -L$(LIB_PATH) -llist 
	
$(LIB_PATH)liblist.a: list_functions.o list.o 
	ar -cvq $(LIB_PATH)liblist.a list.o list_functions.o
	
list_functions.o: list_functions.c $(INC_PATH)list_functions.h
	 gcc -ansi -pedantic -Wall -Wconversion -c list_functions.c
	 
list_itr.o: list_itr.c  $(INC_PATH)list_itr.h
	gcc -ansi -pedantic -Wall -Wconversion -g -c list_itr.c	 
	
list.o: list.c $(INC_PATH)list.h
	 gcc -ansi -pedantic -Wall -Wconversion -g -c list.c
	 	
clean:
	rm testlist.out $(LIB_PATH)liblist.a list_functions.o list.o 
