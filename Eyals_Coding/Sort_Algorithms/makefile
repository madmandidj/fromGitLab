FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../Data_Structures/inc/
VEC_PATH = ../Data_Structures/source/Vector/
objects = Vector.o Bubble.o Shake.o Insertion.o Shell.o Selection.o Quick.o Merge.o TEST_Sort_Algorithms.o


TEST_Sort_Algorithms.out: $(objects)
	gcc $(FLAGS) -o TEST_Sort_Algorithms.out  $(objects) 

TEST_Sort_Algorithms.o: TEST_Sort_Algorithms.c Sort_Algorithms.h $(INC_PATH)Vector.h 
	gcc $(FLAGS) -c TEST_Sort_Algorithms.c

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

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Sort_Algorithms.out

