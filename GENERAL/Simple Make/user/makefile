# Global definitions
CC=gcc
CFLAGS=-g -Wall -Werror
LDFLAGS=-g
# Directory structure
INC_DIR=../inc
CFLAGS += -I$(INC_DIR)
LIB_DIR=../lib
LIB_NAME=libADS.a

# all contents of current directory
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
# Target and sources
TARGET=u
LIB_FILE=$(LIB_DIR)/$(LIB_NAME)

# Dependencies
all: $(TARGET)

$(TARGET): $(OBJS) $(LIB_FILE)

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SRCS) > depends


clean:
	-rm *.o
	-rm u

run:
	./u 4 6
	./u 6 4
	./u 10

