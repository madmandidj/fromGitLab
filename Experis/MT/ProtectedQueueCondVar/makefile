FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread
SRC_PATH = ./src/
INC_PATH = ./inc/
OBJ_PATH = ./obj/
objects =  $(OBJ_PATH)ProtectedQueueCondVar.o $(OBJ_PATH)PCPQconfig.o $(OBJ_PATH)PQProducers.o $(OBJ_PATH)PQConsumers.o $(OBJ_PATH)TestPCCondArg.o  



TestPCCondArg: $(objects) 
	gcc $(FLAGS) -o TestPCCondArg  $(objects)
	
	
	
$(OBJ_PATH)TestPCCondArg.o: $(SRC_PATH)TestPCCondArg.c $(INC_PATH)ProtectedQueue.h \
									$(INC_PATH)PQProducers.h \
										$(INC_PATH)PQConsumers.h \
											$(INC_PATH)PCPQconfig.h				
	gcc $(FLAGS) -c  $(SRC_PATH)TestPCCondArg.c 
	mv TestPCCondArg.o $(OBJ_PATH)



$(OBJ_PATH)PQConsumers.o: $(SRC_PATH)PQConsumers.c $(INC_PATH)ProtectedQueue.h \
													$(INC_PATH)PQConsumers.h \
													 $(INC_PATH)PCPQconfig.h
	gcc $(FLAGS) -c  $(SRC_PATH)PQConsumers.c
	mv PQConsumers.o $(OBJ_PATH)



$(OBJ_PATH)PQProducers.o: $(SRC_PATH)PQProducers.c $(INC_PATH)ProtectedQueue.h \
													$(INC_PATH)PQProducers.h \
													 $(INC_PATH)PCPQconfig.h
	gcc $(FLAGS) -c  $(SRC_PATH)PQProducers.c
	mv PQProducers.o $(OBJ_PATH)



$(OBJ_PATH)PCPQconfig.o: $(SRC_PATH)PCPQconfig.c $(INC_PATH)PCPQconfig.h
	gcc $(FLAGS) -c  $(SRC_PATH)PCPQconfig.c
	mv PCPQconfig.o $(OBJ_PATH)



$(OBJ_PATH)ProtectedQueueCondVar.o: $(SRC_PATH)ProtectedQueueCondVar.c $(INC_PATH)ProtectedQueue.h
	gcc $(FLAGS) -c  $(SRC_PATH)ProtectedQueueCondVar.c
	mv ProtectedQueueCondVar.o $(OBJ_PATH)



clean:
	rm TestPCCondArg $(objects)
	
	
	
