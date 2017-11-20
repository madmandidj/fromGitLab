FLAGS = -ansi -pedantic -Wall -g -std=c++98
BITSET_PATH = ./BitSet/
objects = Test_SuperBitSet_Algo.o

Test_SuperBitSet_Algo.out: $(objects)
	g++ $(FLAGS) $(objects) -o Test_SuperBitSet_Algo.out
	
Test_SuperBitSet_Algo.o: Test_SuperBitSet_Algo.cpp $(BITSET_PATH)BitSet.h $(BITSET_PATH)BitSet_Helper.h 
	g++ $(FLAGS) -c Test_SuperBitSet_Algo.cpp
	
clean:
	rm  Test_SuperBitSet_Algo.out $(objects) 
