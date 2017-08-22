testVector.out: TESTGenericVector.c ../../lib/libVector.so.1.0
	gcc -o testVector.out -I../../inc TESTGenericVector.c ../../lib/libVector.so.1.0

../../lib/libVector.so.1.0: GenericVector.o
	gcc -shared -Wl,-soname,libVector.so.1 -o libVector.so.1.0 GenericVector.o
	ln -sf libVector.so.1.0 libVector.so.1
	mv libVector.so.1.0 ../../lib
	mv libVector.so.1 ../../lib

GenericVector.o: GenericVector.c ../../inc/ADTDefs.h ../../inc/GenericVector.h
	gcc -Wall -fPIC -c *.c -I ../../inc

clean:
	rm testVector.out GenericVector.o TESTGenericVector.o ../../lib/libVector.so.1.0 ../../lib/libVector.so.1
