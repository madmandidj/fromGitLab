FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
GENERAL_FUNC_PATH = ../../../GeneralFunctions/
objects = GeneralFunctions.o List.o ListTEST.o


TEST_List.out: $(objects) 
	gcc $(FLAGS) -o TEST_List.out  $(objects)

ListTEST.o: ListTEST.c $(GENERAL_FUNC_PATH)GeneralFunctions.h $(INC_PATH)List.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c ListTEST.c

List.o: List.c $(INC_PATH)List.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c List.c
	
GeneralFunctions.o: $(GENERAL_FUNC_PATH)GeneralFunctions.c $(GENERAL_FUNC_PATH)GeneralFunctions.h
	gcc $(FLAGS) -c $(GENERAL_FUNC_PATH)GeneralFunctions.c

clean:
	rm $(objects) TEST_List.out

