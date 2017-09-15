FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread 
OBJ_PATH = ./obj/
PROCMNGR_PATH = ./ProcessingManager/
PROC_PATH = ./Processor/
ACCUM_PATH = ./Accumulator/
CONT_PATH = $(ACCUM_PATH)Container/
HASH_PATH = $(CONT_PATH)HashMap/
RCVR_PATH = ../Comms/Receiver/
MSGQ_PATH = ../Comms/MsgQueue/
CHDEFS_PATH = ../Comms/ChannelDefs/
objects = $(OBJ_PATH)list.o $(OBJ_PATH)MsgQ.o $(OBJ_PATH)Receiver.o $(OBJ_PATH)HashMap.o $(OBJ_PATH)Container.o $(OBJ_PATH)Accumulator.o $(OBJ_PATH)Processor.o $(OBJ_PATH)ProcessingManager.o

#FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread
#SRC_PATH = ./src/
#INC_PATH = ./inc/
#OBJ_PATH = ./obj/
#objects =  $(OBJ_PATH)ProtectedQueue.o $(OBJ_PATH)PCPQconfig.o $(OBJ_PATH)PQProducers.o $(OBJ_PATH)PQConsumers.o $(OBJ_PATH)TestPCPQ.o  

TestProcMngr: $(objects) 
	gcc $(FLAGS) -o TestProcMngr  $(objects) -lm



$(OBJ_PATH)ProcessingManager.o: $(PROCMNGR_PATH)ProcessingManager.c \
							$(PROCMNGR_PATH)ProcessingManager.h \
							$(RCVR_PATH)Receiver.h \
							$(ACCUM_PATH)Accumulator.h \
							$(PROC_PATH)Processor.h 		
	gcc $(FLAGS) -c  $(PROCMNGR_PATH)ProcessingManager.c 
	mv ProcessingManager.o $(OBJ_PATH)
	
	
	
$(OBJ_PATH)Processor.o: $(PROC_PATH)Processor.c \
							$(PROC_PATH)Processor.h \
							$(RCVR_PATH)Receiver.h \
							$(ACCUM_PATH)Accumulator.h 	
	gcc $(FLAGS) -c  $(PROC_PATH)Processor.c 
	mv Processor.o $(OBJ_PATH)
	
	
	
$(OBJ_PATH)Accumulator.o: $(ACCUM_PATH)Accumulator.c \
							$(ACCUM_PATH)Accumulator.h \
							$(CONT_PATH)Container.h 
	gcc $(FLAGS) -c  $(ACCUM_PATH)Accumulator.c 
	mv Accumulator.o $(OBJ_PATH)
	
	
	
$(OBJ_PATH)Container.o: $(CONT_PATH)Container.c \
							$(CONT_PATH)Container.h \
							$(HASH_PATH)HashMap.h 
	gcc $(FLAGS) -c  $(CONT_PATH)Container.c 
	mv Container.o $(OBJ_PATH)	
	
	
	
$(OBJ_PATH)HashMap.o: $(HASH_PATH)HashMap.c \
							$(HASH_PATH)HashMap.h \
							$(HASH_PATH)list_itr.h 
	gcc $(FLAGS) -c $(HASH_PATH)HashMap.c 
	mv HashMap.o $(OBJ_PATH)
	


$(OBJ_PATH)list.o: $(HASH_PATH)list.c \
							$(HASH_PATH)list_itr.h 
	gcc $(FLAGS) -c  $(HASH_PATH)list.c 
	mv list.o $(OBJ_PATH)			
	
	
	
$(OBJ_PATH)Receiver.o: $(RCVR_PATH)Receiver.c \
							$(RCVR_PATH)Receiver.h \
							$(MSGQ_PATH)MsgQ.h
	gcc $(FLAGS) -c  $(RCVR_PATH)Receiver.c 
	mv Receiver.o $(OBJ_PATH)	
	
	
	
$(OBJ_PATH)MsgQ.o: $(MSGQ_PATH)MsgQ.c \
							$(MSGQ_PATH)MsgQ.h \
							$(MSGQ_PATH)MsgType.h
	gcc $(FLAGS) -c  $(MSGQ_PATH)MsgQ.c 
	mv MsgQ.o $(OBJ_PATH)	
	
	
	
clean:
	rm TestProcMngr $(objects)	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
#TestPCPQ: $(objects) 
#	gcc $(FLAGS) -o TestPCPQ  $(objects)	
	
#$(OBJ_PATH)TestPCPQ.o: $(SRC_PATH)TestPCPQ.c $(INC_PATH)ProtectedQueue.h \
#									$(INC_PATH)PQProducers.h \
#										$(INC_PATH)PQConsumers.h \
#											$(INC_PATH)PCPQconfig.h				
#	gcc $(FLAGS) -c  $(SRC_PATH)TestPCPQ.c 
#	mv TestPCPQ.o $(OBJ_PATH)



#$(OBJ_PATH)PQConsumers.o: $(SRC_PATH)PQConsumers.c $(INC_PATH)ProtectedQueue.h \
#													$(INC_PATH)PQConsumers.h \
#													 $(INC_PATH)PCPQconfig.h
#	gcc $(FLAGS) -c  $(SRC_PATH)PQConsumers.c
#	mv PQConsumers.o $(OBJ_PATH)



#$(OBJ_PATH)PQProducers.o: $(SRC_PATH)PQProducers.c $(INC_PATH)ProtectedQueue.h \
#													$(INC_PATH)PQProducers.h \
#													 $(INC_PATH)PCPQconfig.h
#	gcc $(FLAGS) -c  $(SRC_PATH)PQProducers.c
#	mv PQProducers.o $(OBJ_PATH)



#$(OBJ_PATH)PCPQconfig.o: $(SRC_PATH)PCPQconfig.c $(INC_PATH)PCPQconfig.h
#	gcc $(FLAGS) -c  $(SRC_PATH)PCPQconfig.c
#	mv PCPQconfig.o $(OBJ_PATH)



#$(OBJ_PATH)ProtectedQueue.o: $(SRC_PATH)ProtectedQueue.c $(INC_PATH)ProtectedQueue.h
#	gcc $(FLAGS) -c  $(SRC_PATH)ProtectedQueue.c
#	mv ProtectedQueue.o $(OBJ_PATH)



#clean:
#	rm TestPCPQ $(objects)
	
	
	
