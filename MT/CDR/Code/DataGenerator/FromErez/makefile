INC = ../inc

CC = gcc
CFLAGS = -ansi -Wall -pedantic -Wconversion -std=gnu99 -m32 -pthread -g
CFLAGS += -I$(INC)

CdrMaker : CdrMaker.c
	$(CC) $(CFLAGS) $< -o $@

clean : 
	rm CdrMaker
