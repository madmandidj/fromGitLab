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
VECTOR_PATH = ../Vector/



testheap.out: VECTOR TestHeap.c $(LIB_PATH)libheap.a $(LIB_PATH)libvector.a 
	gcc $(FLAGS) -o testheap.out TestHeap.c -L$(LIB_PATH) -lheap -L$(LIB_PATH) -lvector

VECTOR: 
	make -C $(VECTOR_PATH)

../../lib/libheap.a: Heap.o 
	ar -cvq $(LIB_PATH)libheap.a Heap.o
	
Heap.o: Heap.c $(INC_PATH)Heap.h
	 gcc $(FLAGS) -c Heap.c

clean:
	make -C $(VECTOR_PATH) clean
	rm testheap.out $(LIB_PATH)libheap.a Heap.o
