#FLAGS = -ansi -pedantic -Wall -Wconversion
#INC_PATH = ../../inc/
#LIB_PATH = ../../lib/
#VECTOR_PATH = ../Vector/

#testheap.out: TestHeap.c $(LIB_PATH)libheap.a $(LIB_PATH)libvector.a
#	gcc $(FLAGS) -o testheap.out TestHeap.c -L$(LIB_PATH) -lheap -L$(LIB_PATH) -lvector

#../../lib/libheap.a: Heap.o $(VECTOR_PATH)GenericVector.o $(VECTOR_PATH)GenericVector.c $(INC_PATH)ADTDefs.h $(INC_PATH)GenericVector.h
#	ar -cvq $(LIB_PATH)libheap.a Heap.o
#	
#Heap.o: Heap.c $(INC_PATH)Heap.h $(VECTOR_PATH)GenericVector.o $(VECTOR_PATH)GenericVector.c $(INC_PATH)ADTDefs.h $(INC_PATH)GenericVector.h
#	 gcc $(FLAGS) -c Heap.c

#../../lib/libvector.a: $(VECTOR_PATH)GenericVector.o
#	ar -cvq $(LIB_PATH)libvector.a $(VECTOR_PATH)GenericVector.o
#	
#GenericVector.o: $(VECTOR_PATH)GenericVector.c $(INC_PATH)ADTDefs.h $(INC_PATH)GenericVector.h
#	 gcc $(FLAGS) -c $(VECTOR_PATH)GenericVector.c
#	 mv GenericVector.o $(VECTOR_PATH)

#clean:
#	rm $(LIB_PATH)libvector.a $(VECTOR_PATH)GenericVector.o testheap.out $(LIB_PATH)libheap.a Heap.o




FLAGS = -ansi -pedantic -Wall -Wconversion
INC_PATH = ../../inc/
LIB_PATH = ../../lib/
LIST_PATH = ../DoubleLinkedList/

teststack.out: TestStack.c $(LIB_PATH)libstack.a $(LIB_PATH)liblist.a
	gcc $(FLAGS) -o teststack.out TestStack.c -L$(LIB_PATH) -lstack -L$(LIB_PATH) -llist
	
Stack.c: Stack.c $(INC_PATH)list.h

../../lib/libstack.a: Stack.o
	ar -cvq $(LIB_PATH)libstack.a Stack.o
	
../../lib/liblist.a: list.o
	ar -cvq $(LIB_PATH)liblist.a list.o
	
Stack.o: Stack.c $(INC_PATH)Stack.h
	 gcc $(FLAGS) -c Stack.c

clean:
	rm $(LIB_PATH)libstack.a stack.o teststack.out $(LIB_PATH)liblist.a $(LIST_PATH)list.o
