FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
VEC_PATH = ../../source/Vector/
MERGE_SORT_PATH = ../../../Sort_Algorithms/
objects = Merge.o VectorFunctions.o Vector.o Heap.o HeapFunctions.o TEST_Heap.o


TEST_Heap.out: $(objects) 
	gcc $(FLAGS) -o TEST_Heap.out  $(objects)

TEST_Heap.o: TEST_Heap.c Heap.c $(INC_PATH)Vector.h $(INC_PATH)VectorFunctions.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c TEST_Heap.c

Merge.o: $(MERGE_SORT_PATH)Merge.c $(MERGE_SORT_PATH)Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(MERGE_SORT_PATH)Merge.c

HeapFunctions.o: HeapFunctions.c $(INC_PATH)HeapFunctions.h $(INC_PATH)VectorFunctions.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c HeapFunctions.c

Heap.o: Heap.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h $(INC_PATH)Heap.h
	gcc $(FLAGS) -c Heap.c

VectorFunctions.o: $(VEC_PATH)VectorFunctions.c $(INC_PATH)VectorFunctions.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)VectorFunctions.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Heap.out
