FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
DS_INC_PATH = ../Data_Structures/inc/
VEC_PATH = ../Data_Structures/source/Vector/
objects = Vector.o GeneralFunctions.o TEST_GeneralFunctions.o


TEST_GeneralFunctions.out: $(objects) 
	gcc $(FLAGS) -o TEST_GeneralFunctions.out  $(objects)

TEST_GeneralFunctions.o: TEST_GeneralFunctions.c GeneralFunctions.h $(DS_INC_PATH)mu_test.h
	gcc $(FLAGS) -c TEST_GeneralFunctions.c

GeneralFunctions.o: GeneralFunctions.c GeneralFunctions.h
	gcc $(FLAGS) -c GeneralFunctions.c
	
Vector.o: $(VEC_PATH)Vector.c $(DS_INC_PATH)Vector.h $(DS_INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_GeneralFunctions.out
