FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread
SRC_PATH = ./src/
INC_PATH = ./inc/
OBJ_PATH = ./obj/
objects =  $(OBJ_PATH)TestPCPQ.o $(OBJ_PATH)ProtectedQueue.o $(OBJ_PATH)PQConsumers.o $(OBJ_PATH)PQProducers.o


TestPCPQ: $(objects) 
	gcc $(FLAGS) -o TestPCPQ  $(objects)
	
	
	
$(OBJ_PATH)TestPCPQ.o: $(SRC_PATH)TestPCPQ.c $(INC_PATH)ProtectedQueue.h \
									$(INC_PATH)PQProducers.h \
										$(INC_PATH)PQConsumers.h
	gcc $(FLAGS) -c  $(SRC_PATH)TestPCPQ.c 
	mv TestPCPQ.o $(OBJ_PATH)


$(OBJ_PATH)ProtectedQueue.o: $(SRC_PATH)ProtectedQueue.c $(INC_PATH)ProtectedQueue.h
	gcc $(FLAGS) -c  $(SRC_PATH)ProtectedQueue.c
	mv ProtectedQueue.o $(OBJ_PATH)


$(OBJ_PATH)PQConsumers.o: $(SRC_PATH)PQConsumers.c $(INC_PATH)ProtectedQueue.h \
													$(INC_PATH)PQConsumers.h
	gcc $(FLAGS) -c  $(SRC_PATH)PQConsumers.c
	mv PQConsumers.o $(OBJ_PATH)


$(OBJ_PATH)PQProducers.o: $(SRC_PATH)PQProducers.c $(INC_PATH)ProtectedQueue.h \
													$(INC_PATH)PQProducers.h
	gcc $(FLAGS) -c  $(SRC_PATH)PQProducers.c
	mv PQProducers.o $(OBJ_PATH)


clean:
	rm TestPCPQ $(objects)
