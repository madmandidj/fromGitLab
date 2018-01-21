FLAGS = -g -ansi -pedantic -Wall -Wconversion -pthread -m32
objects = String_t.o TestString_t.o


TestStringT: $(objects) 
	g++ $(FLAGS) -o TestStringT  $(objects) 


TestString_t.o: TestString_t.cpp String_t.cpp String_t.h  		
	g++ $(FLAGS) -c  TestString_t.cpp 
	
	
String_t.o: String_t.cpp String_t.h  		
	g++ $(FLAGS) -c  String_t.cpp 

	
clean:
	rm TestStringT $(objects)	
	
