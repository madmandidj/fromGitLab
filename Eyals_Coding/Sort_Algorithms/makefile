FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../Data_Structures/inc/
VEC_PATH = ../Data_Structures/source/Vector/
HEAP_PATH = ../Data_Structures/source/Heap/
GEN_FUNC_PATH = ../GeneralFunctions/
objects = GeneralFunctions.o Vector.o Heap.o HeapFunctions.o Bubble.o Shake.o Insertion.o Shell.o Selection.o Quick.o Merge.o Counting.o Radix.o TEST_Sort_Algorithms.o


TEST_Sort_Algorithms.out: $(objects)
	gcc $(FLAGS) -o TEST_Sort_Algorithms.out  $(objects) 

TEST_Sort_Algorithms.o: TEST_Sort_Algorithms.c Sort_Algorithms.h $(INC_PATH)Vector.h $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Heap.h $(INC_PATH)HeapFunctions.h
	gcc $(FLAGS) -c TEST_Sort_Algorithms.c

Radix.o: Radix.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Radix.c

Counting.o: Counting.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Counting.c

Merge.o: Merge.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Merge.c

Quick.o: Quick.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Quick.c

Selection.o: Selection.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Selection.c

Shell.o: Shell.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Shell.c

Insertion.o: Insertion.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Insertion.c

Shake.o: Shake.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Shake.c
	
Bubble.o: Bubble.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Bubble.c
	
HeapFunctions.o: $(HEAP_PATH)HeapFunctions.c $(INC_PATH)HeapFunctions.h $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(HEAP_PATH)HeapFunctions.c
	
Heap.o: $(HEAP_PATH)Heap.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h $(INC_PATH)Heap.h
	gcc $(FLAGS) -c $(HEAP_PATH)Heap.c
	
#VectorFunctions.o: $(VEC_PATH)VectorFunctions.c $(INC_PATH)VectorFunctions.h $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
#	gcc $(FLAGS) -c $(VEC_PATH)VectorFunctions.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c
	
GeneralFunctions.o: $(GEN_FUNC_PATH)GeneralFunctions.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(GEN_FUNC_PATH)GeneralFunctions.c

clean:
	rm $(objects) TEST_Sort_Algorithms.out

