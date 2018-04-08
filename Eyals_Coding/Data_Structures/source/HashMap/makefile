FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
LIST_PATH = ../../source/List/
GEN_FUNC_PATH = ../../../GeneralFunctions/
VEC_PATH = ../../source/Vector/
objects = Vector.o GeneralFunctions.o List.o HashMap.o TEST_HashMap.o

TEST_HashMap.out: $(objects) 
	gcc $(FLAGS) -o TEST_HashMap.out  $(objects) -lm

TEST_HashMap.o: TEST_HashMap.c $(INC_PATH)List.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h $(GEN_FUNC_PATH)GeneralFunctions.h
	gcc $(FLAGS) -c TEST_HashMap.c

HashMap.o: HashMap.c $(INC_PATH)List.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c HashMap.c

List.o: $(LIST_PATH)List.c $(INC_PATH)List.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(LIST_PATH)List.c
	
GeneralFunctions.o: $(GEN_FUNC_PATH)GeneralFunctions.c $(GEN_FUNC_PATH)GeneralFunctions.h $(INC_PATH)Vector.h
	gcc $(FLAGS) -c $(GEN_FUNC_PATH)GeneralFunctions.c
	
Vector.o: $(VEC_PATH)Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c $(VEC_PATH)Vector.c
	
clean:
	rm $(objects) TEST_HashMap.out


