FLAGS = -ansi -pedantic -Wall -Wconversion
INC_PATH = ../../inc/
LIB_PATH = ../../lib/

testvector.out: TESTGenericVector.c $(LIB_PATH)libvector.a
	gcc $(FLAGS) -o testvector.out TESTGenericVector.c -L$(LIB_PATH) -lvector 
	
../../lib/libvector.a: GenericVector.o
	ar -cvq $(LIB_PATH)libvector.a GenericVector.o
	
GenericVector.o: GenericVector.c $(INC_PATH)ADTDefs.h $(INC_PATH)GenericVector.h
	 gcc $(FLAGS) -c GenericVector.c
	
clean:
	rm testvector.out $(LIB_PATH)libvector.a GenericVector.o
