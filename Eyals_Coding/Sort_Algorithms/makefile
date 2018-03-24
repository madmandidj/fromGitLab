FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../Data_Structures/inc/
VEC_PATH = ../Data_Structures/source/Vector/
objects = Vector.o Bubble.o TEST_Sort_Algorithms.o


TEST_Sort_Algorithms.out: $(objects)
	gcc $(FLAGS) -o TEST_Sort_Algorithms.out  $(objects) 

TEST_Sort_Algorithms.o: TEST_Sort_Algorithms.c Sort_Algorithms.h $(INC_PATH)Vector.h 
	gcc $(FLAGS) -c TEST_Sort_Algorithms.c
	
Bubble.o: Bubble.c Sort_Algorithms.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c Bubble.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_Sort_Algorithms.out

