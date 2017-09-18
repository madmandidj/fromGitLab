FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread -m32
OBJ_PATH = ./obj/
UIMNGR_PATH = ./UIManager/
TRNS_PATH = ../Comms/Transmitter/
MSGQ_PATH = ../Comms/MsgQueue/
CHDEFS_PATH = ../Comms/ChannelDefs/
objects = $(OBJ_PATH)MsgQ.o $(OBJ_PATH)Transmitter.o $(OBJ_PATH)UIManager.o


TestUIMngr: $(objects) 
	gcc $(FLAGS) -o TestUIMngr  $(objects) -lm



$(OBJ_PATH)UIManager.o: $(UIMNGR_PATH)UIManager.c \
							$(UIMNGR_PATH)UIManager.h \
							$(TRNS_PATH)Transmitter.h 
	gcc $(FLAGS) -c  $(UIMNGR_PATH)UIManager.c 
	mv UIManager.o $(OBJ_PATH)
	
	
	
$(OBJ_PATH)Transmitter.o: $(TRNS_PATH)Transmitter.c \
							$(TRNS_PATH)Transmitter.h \
							$(MSGQ_PATH)MsgQ.h
	gcc $(FLAGS) -c  $(TRNS_PATH)Transmitter.c 
	mv Transmitter.o $(OBJ_PATH)
	


$(OBJ_PATH)MsgQ.o: $(MSGQ_PATH)MsgQ.c \
							$(MSGQ_PATH)MsgQ.h \
							$(MSGQ_PATH)MsgType.h
	gcc $(FLAGS) -c  $(MSGQ_PATH)MsgQ.c 
	mv MsgQ.o $(OBJ_PATH)
	
	
	
clean:
	rm TestUIMngr $(objects)	
	
