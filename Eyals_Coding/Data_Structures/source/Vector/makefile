FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
INC_PATH = ../../inc/
objects = Vector.o VectorTEST.o


VectorTEST.out: $(objects) 
	gcc $(FLAGS) -o VectorTEST.out  $(objects)

VectorTEST.o: VectorTEST.c $(INC_PATH)Vector.h $(INC_PATH)mu_test.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c VectorTEST.c

Vector.o: Vector.c $(INC_PATH)Vector.h $(INC_PATH)ADTErr.h
	gcc $(FLAGS) -c Vector.c

clean:
	rm $(objects) VectorTEST.out

