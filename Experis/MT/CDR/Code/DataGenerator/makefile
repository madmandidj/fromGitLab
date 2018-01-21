FLAGS = -g -ansi -pedantic -Wall -Wconversion -Werror -pthread -m32
OBJ_PATH = ./obj/
objects = $(OBJ_PATH)DataGenerator.o $(OBJ_PATH)TestDataGenerator.o


TestDataGenerator: $(objects) 
	gcc $(FLAGS) -o TestDataGenerator  $(objects) -lm



$(OBJ_PATH)TestDataGenerator.o: $(UIMNGR_PATH)DataGenerator.c \
							$(UIMNGR_PATH)DataGenerator.h
	gcc $(FLAGS) -c  $(UIMNGR_PATH)TestDataGenerator.c 
	mv TestDataGenerator.o $(OBJ_PATH)
	
$(OBJ_PATH)DataGenerator.o: $(UIMNGR_PATH)DataGenerator.c \
							$(UIMNGR_PATH)DataGenerator.h
	gcc $(FLAGS) -c  $(UIMNGR_PATH)DataGenerator.c 
	mv DataGenerator.o $(OBJ_PATH)
	
clean:
	rm TestDataGenerator $(objects)	
	
