FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32
PONG2K_PATH = ./Pong2k/
SCREEN_PATH = ./Pong2k_Screen/
SCREEN_PIXEL_PATH = ./Pong2k_Screen_Pixel/

# INC_PATH = ../Data_Structures/inc/
# VEC_PATH = ../Data_Structures/source/Vector/
# HEAP_PATH = ../Data_Structures/source/Heap/
# GEN_FUNC_PATH = ../GeneralFunctions/
objects = Pong2k_Screen_Pixel.o Pong2k_Screen.o Pong2k.o


Test_Pong2k.out: $(objects)
	gcc $(FLAGS) -o Test_Pong2k.out  $(objects)

Pong2k.o: $(PONG2K_PATH)Pong2k.c $(PONG2K_PATH)Pong2k.h $(SCREEN_PATH)Pong2k_Screen.h
	gcc $(FLAGS) -c $(PONG2K_PATH)Pong2k.c -o Pong2k.o

Pong2k_Screen.o: $(SCREEN_PATH)Pong2k_Screen.c $(SCREEN_PATH)Pong2k_Screen.h $(SCREEN_PIXEL_PATH)Pong2k_Screen_Pixel.h
	gcc $(FLAGS) -c $(SCREEN_PATH)Pong2k_Screen.c -o Pong2k_Screen.o

Pong2k_Screen_Pixel.o: $(SCREEN_PIXEL_PATH)Pong2k_Screen_Pixel.c $(SCREEN_PIXEL_PATH)Pong2k_Screen_Pixel.h
	gcc $(FLAGS) -c $(SCREEN_PIXEL_PATH)Pong2k_Screen_Pixel.c -o Pong2k_Screen_Pixel.o

clean:
	rm Test_Pong2k.out $(objects)



