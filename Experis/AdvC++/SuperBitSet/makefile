FLAGS = -ansi -pedantic -Wall -g -std=c++98
SET_PATH = ./BitSet/
MANIP_PATH = ./BitManip/
REF_PATH = ./BitRef/
objects = Test_SuperBitSet.o

Test_SuperBitSet.out: $(objects)
	g++ $(objects) $(FLAGS) -o Test_SuperBitSet.out
	
Test_SuperBitSet.o: Test_SuperBitSet.cpp $(SET_PATH)BitSet.h $(MANIP_PATH)BitManip.h $(REF_PATH)BitRef.h
	g++ -c Test_SuperBitSet.cpp $(FLAGS) 
	
clean:
	rm  Test_SuperBitSet.out $(objects) 
