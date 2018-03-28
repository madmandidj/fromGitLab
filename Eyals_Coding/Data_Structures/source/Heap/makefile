FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
VEC_PATH = ../../source/Vector/
objects = Vector.o Heap.o TEST_Heap.o


TEST_Heap.out: $(objects) 
	gcc $(FLAGS) -o TEST_Heap.out  $(objects)

TEST_Heap.o: TEST_Heap.c Heap.c $(INC_PATH)Vector.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c TEST_Heap.c

Heap.o: Heap.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h $(INC_PATH)Heap.h
	gcc $(FLAGS) -c Heap.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Heap.out
