FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
GEN_FUNC_PATH = ../../../GeneralFunctions/
objects = GeneralFunctions.o Vector.o VectorTEST.o
#Generalfunctions is not needed here for now but left it anyway.


TEST_Vector.out: $(objects) 
	gcc $(FLAGS) -o TEST_Vector.out  $(objects)

VectorTEST.o: VectorTEST.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c VectorTEST.c

Vector.o: Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c Vector.c
	
GeneralFunctions.o: $(GEN_FUNC_PATH)GeneralFunctions.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(GEN_FUNC_PATH)GeneralFunctions.c 

clean:
	rm $(objects) TEST_Vector.out

