FLAGS = -ansi -pedantic -Wall -Wconversion
INC_PATH = ../../inc/
LIB_PATH = ../../lib/ 

binarytree.out: BinaryTree.c ../../lib/libbinarytree.a
	 gcc -ansi -pedantic -Wall -Wconversion -o binarytree.out TestBinaryTree.c -L../../lib -lbinarytree 
	
../../lib/libbinarytree.a: BinaryTree.o
	ar -cvq ../../lib/libbinarytree.a BinaryTree.o
	
BinaryTree.o: BinaryTree.c ../../inc/GenericVector.h
	 gcc -ansi -pedantic -Wall -Wconversion -c BinaryTree.c
	
clean:
	rm testbinarytree.out ../../lib/libbinarytree.a BinaryTree.o
