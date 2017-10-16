FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32

VIRT_PATH = ./virtIO_t/
ASCII_PATH = ./asciiIO_t/
BIN_PATH = ./binIO_t/

objects = virtIO_t.o binIO_t.o asciiIO_t.o TESTvirtIO.o


TESTVirtIO: $(objects) 
	g++ $(FLAGS) -o TESTVirtIO $(objects) 


TESTvirtIO.o: TESTvirtIO.cpp $(ASCII_PATH)asciiIO_t.h $(BIN_PATH)binIO_t.h 
	g++ $(FLAGS) -c  TESTvirtIO.cpp


asciiIO_t.o: $(ASCII_PATH)asciiIO_t.cpp $(ASCII_PATH)asciiIO_t.h $(VIRT_PATH)virtIO_t.h		
	g++ $(FLAGS) -c  $(ASCII_PATH)asciiIO_t.cpp 
	
	
binIO_t.o: $(BIN_PATH)binIO_t.cpp $(BIN_PATH)binIO_t.h $(VIRT_PATH)virtIO_t.h	 		
	g++ $(FLAGS) -c  $(BIN_PATH)binIO_t.cpp 
	
	
virtIO_t.o: $(VIRT_PATH)virtIO_t.cpp $(VIRT_PATH)virtIO_t.h		
	g++ $(FLAGS) -c  $(VIRT_PATH)virtIO_t.cpp
	
	
clean:
	rm TESTVirtIO $(objects)	
 







