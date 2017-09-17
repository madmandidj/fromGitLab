FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread 
OBJ_PATH = ./obj/
FEEDMNGR_PATH = ./FeederManager/
READER_PATH = ./Reader/
DATAGEN_PATH = ../DataGenerator/
TRNS_PATH = ../Comms/Transmitter/
RCVR_PATH = ../Comms/Receiver/
MSGQ_PATH = ../Comms/MsgQueue/
CHDEFS_PATH = ../Comms/ChannelDefs/
objects = $(OBJ_PATH)MsgQ.o $(OBJ_PATH)Receiver.o $(OBJ_PATH)Transmitter.o $(OBJ_PATH)DataGenerator.o $(OBJ_PATH)Reader.o $(OBJ_PATH)FeederManager.o


TestFeedMngr: $(objects) 
	gcc $(FLAGS) -o TestFeedMngr  $(objects) 



$(OBJ_PATH)FeederManager.o: $(FEEDMNGR_PATH)FeederManager.c \
							$(FEEDMNGR_PATH)FeederManager.h \
							$(READER_PATH)Reader.h \
							$(DATAGEN_PATH)DataGenerator.h \
							$(TRNS_PATH)Transmitter.h \
							$(RCVR_PATH)Receiver.h 		
	gcc $(FLAGS) -c  $(FEEDMNGR_PATH)FeederManager.c 
	mv FeederManager.o $(OBJ_PATH)
	
	
	
$(OBJ_PATH)Reader.o: $(READER_PATH)Reader.c \
							$(READER_PATH)Reader.h \
							$(DATAGEN_PATH)DataGenerator.h \
							$(TRNS_PATH)Transmitter.h \
							$(RCVR_PATH)Receiver.h 		
	gcc $(FLAGS) -c  $(READER_PATH)Reader.c 
	mv Reader.o $(OBJ_PATH)	
	
	
	
$(OBJ_PATH)DataGenerator.o: $(DATAGEN_PATH)DataGenerator.c \
							$(DATAGEN_PATH)DataGenerator.h 
	gcc $(FLAGS) -c  $(DATAGEN_PATH)DataGenerator.c 
	mv DataGenerator.o $(OBJ_PATH)
	
	
	
$(OBJ_PATH)Transmitter.o: $(TRNS_PATH)Transmitter.c \
							$(TRNS_PATH)Transmitter.h \
							$(MSGQ_PATH)MsgQ.h
	gcc $(FLAGS) -c  $(TRNS_PATH)Transmitter.c 
	mv Transmitter.o $(OBJ_PATH)
	


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
	rm TestFeedMngr $(objects)	
	
