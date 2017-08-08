testvector.out: TESTGenericVector.c ../../lib/libvector.a
	gcc -ansi -pedantic -Wall -Wconversion -Werror -o testvector.out TESTGenericVector.c -L../../lib -lvector 
	
../../lib/libvector.a: GenericVector.o
	ar -cvq ../../lib/libvector.a GenericVector.o
	
GenericVector.o: GenericVector.c ../../inc/ADTDefs.h ../../inc/GenericVector.h
	 gcc -ansi -pedantic -Wall -Wconversion -c GenericVector.c
	

