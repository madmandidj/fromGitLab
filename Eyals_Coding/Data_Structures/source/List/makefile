FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
GEN_FUNC_PATH = ../../../GeneralFunctions/
VEC_PATH = ../Vector/
objects = Vector.o GeneralFunctions.o List.o ListTEST.o


TEST_List.out: $(objects) 
	gcc $(FLAGS) -o TEST_List.out  $(objects)

ListTEST.o: ListTEST.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)List.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c ListTEST.c

List.o: List.c $(INC_PATH)List.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c List.c
	
GeneralFunctions.o: $(GEN_FUNC_PATH)GeneralFunctions.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h 
	gcc $(FLAGS) -c $(GEN_FUNC_PATH)GeneralFunctions.c

Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c

clean:
	rm $(objects) TEST_List.out

