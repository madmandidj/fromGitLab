FLAGS = -ansi -pedantic -Wall -g
BUFFER_PATH = ./Buffer/
STRING_PATH = ./String/
#objects = Buffer.o String.o TestString.o
objects = String.o TestString.o

TestString.out: $(objects)
	g++ $(FLAGS) $(objects) -o TestString.out
	
TestString.o: $(BUFFER_PATH)Buffer.h $(STRING_PATH)String.h TestString.cpp
	g++ $(FLAGS) -c TestString.cpp -o TestString.o
	
String.o: $(BUFFER_PATH)Buffer.h $(STRING_PATH)String.h $(STRING_PATH)String.cpp
	g++ $(FLAGS) -c $(STRING_PATH)String.cpp -o String.o  
	
#Buffer.o: $(BUFFER_PATH)Buffer.h
#	g++ $(FLAGS) -c $(BUFFER_PATH)Buffer.h -o Buffer.o
	
clean:
	rm TestString.out $(objects)
	
