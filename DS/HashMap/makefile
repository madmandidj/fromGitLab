FLAGS = -ansi -pedantic -Wall -Wconversion
INC_PATH = ../../inc/
LIB_PATH = ../../lib/
LIST_PATH = ../DoubleLinkedList/



testhashmap.out: LIST TestHashMap.c $(LIB_PATH)libhashmap.a $(LIB_PATH)liblist.a 
	gcc $(FLAGS) -o testhashmap.out TestHashMap.c -L$(LIB_PATH) -lhashmap -L$(LIB_PATH) -llist

LIST: 
	make -C $(LIST_PATH)

../../lib/libhashmap.a: HashMap.o 
	ar -cvq $(LIB_PATH)libhashmap.a HashMap.o
	
HashMap.o: HashMap.c $(INC_PATH)HashMap.h
	 gcc $(FLAGS) -c HashMap.c

clean:
	make -C $(LIST_PATH) clean
	rm testhashmap.out $(LIB_PATH)libhashmap.a HashMap.o
