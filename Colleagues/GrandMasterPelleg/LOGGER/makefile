# Global definitions
CC=gcc
CFLAGS= -g -Wconversion -ansi -pthread -I$(INC_DIR) -I$(CONFIG_DIR) \
		-m32 -std=gnu99

# Directory structure
INC_DIR = ../inc
LIB_DIR = ../lib
CONFIG_DIR = ./LoggerConfig

#library, sources and objects
LIB_NAME = libLogger.a
LIB_FILE = $(LIB_DIR)/$(LIB_NAME)

LIB_SRCS = logger.c $(CONFIG_DIR)/LoggerConfig.c
LIB_OBJ = logger.o LoggerConfig.o

#dependencies

commit: $(LIB_OBJ)
		ar -cvq $(LIB_NAME) $(LIB_OBJ)
		mv $(LIB_NAME) $(LIB_DIR)
		mv *.o obj

logger.o:	logger.c $(INC_DIR)/logger.h $(CONFIG_DIR)/LoggerConfig.h
			$(CC) $(CFLAGS) -c logger.c
			
LoggerConfig.o: 	$(CONFIG_DIR)/LoggerConfig.c \
					$(CONFIG_DIR)/LoggerConfig.h
					$(CC) $(CFLAGS) -c \
					$(CONFIG_DIR)/LoggerConfig.c

$(LIB_FILE): $(LIB_OBJS)


test:	$(LIB_OBJ) $(INC_DIR)/logger.h $(CONFIG_DIR)/LoggerConfig.h \
		testLogger.c
		$(CC) $(CFLAGS) -o testLogger $(LIB_OBJ) testLogger.c
		./testLogger
			
make clean:
			-rm *.o
			-rm $(CONFIG_DIR)/*.o
			-rm *.out
			-rm ./logs/*.log
