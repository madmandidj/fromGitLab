FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
objects = List.o ListTEST.o


ListTEST.out: $(objects) 
	gcc $(FLAGS) -o ListTEST.out  $(objects)

ListTEST.o: ListTEST.c $(INC_PATH)List.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c ListTEST.c

List.o: List.c $(INC_PATH)List.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c List.c

clean:
	rm $(objects) ListTEST.out

