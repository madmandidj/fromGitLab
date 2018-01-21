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
TARGET=m
LIB_SRCS=a.c b.c
LIB_OBJS=$(LIB_SRCS:.c=.o)

LIB_FILE=$(LIB_DIR)/$(LIB_NAME)

# Dependencies
all: $(TARGET)

$(TARGET): $(OBJS)

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(OBJS:.o=.c) > depends


commit: $(LIB_FILE)

$(LIB_FILE): $(LIB_OBJS)
	$(AR) cvr $@ $?


clean:
	-rm *.o
	-rm m

run:
	./m 4 6
	./m 6 4
	./m 10

