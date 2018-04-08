FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
VEC_PATH = ../Vector/
GEN_FUNC_PATH = ../../../GeneralFunctions/
objects = Vector.o Queue.o TEST_Queue.o


TEST_Queue.out: $(objects) 
	gcc $(FLAGS) -o TEST_Queue.out  $(objects)

TEST_Queue.o: TEST_Queue.c $(INC_PATH)Queue.h $(INC_PATH)Vector.h $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c TEST_Queue.c

Queue.o: Queue.c $(INC_PATH)Queue.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c Queue.c
	
GeneralFunctions.o: $(GEN_FUNC_PATH)GeneralFunctions.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h 
	gcc $(FLAGS) -c $(GEN_FUNC_PATH)GeneralFunctions.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Queue.out

