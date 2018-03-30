FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
VEC_PATH = ../Vector/
objects = Vector.o Queue.o TEST_Queue.o


TEST_Queue.out: $(objects) 
	gcc $(FLAGS) -o TEST_Queue.out  $(objects)

TEST_Queue.o: TEST_Queue.c $(INC_PATH)Queue.h $(INC_PATH)Vector.h $(INC_PATH)VectorFunctions.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c TEST_Queue.c

Queue.o: Queue.c $(INC_PATH)Queue.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c Queue.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Queue.out

