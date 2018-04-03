FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
DS_INC_PATH = ../Data_Structures/inc/
objects = GeneralFunctions.o TEST_GeneralFunctions.o


TEST_GeneralFunctions.out: $(objects) 
	gcc $(FLAGS) -o TEST_GeneralFunctions.out  $(objects)

TEST_GeneralFunctions.o: TEST_GeneralFunctions.c GeneralFunctions.h $(DS_INC_PATH)mu_test.h
	gcc $(FLAGS) -c TEST_GeneralFunctions.c

GeneralFunctions.o: GeneralFunctions.c GeneralFunctions.h
	gcc $(FLAGS) -c GeneralFunctions.c

clean:
	rm $(objects) TEST_GeneralFunctions.out
