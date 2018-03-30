FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
VEC_PATH = ../Vector/
objects = Vector.o Stack.o TEST_Stack.o


TEST_Stack.out: $(objects) 
	gcc $(FLAGS) -o TEST_Stack.out  $(objects)

TEST_Stack.o: TEST_Stack.c $(INC_PATH)Stack.h $(INC_PATH)Vector.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c TEST_Stack.c

Stack.o: Stack.c $(INC_PATH)Stack.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c Stack.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Stack.out

