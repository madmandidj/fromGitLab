#include "Array_t.h"
#include <iostream>



int main()
{	
	size_t initCap = 10;
	size_t blockSize = 5;
	size_t initNumOfElems = 0;
	
	Array_t<int> arrayInt(initNumOfElems, initCap, blockSize);

	int int1 = 785;
	
	int int2 = 345;
	
	int* int1p;
	
	int* int2p;
	
	int* removedInt;
	
	int1p = &int1;
	
	int2p = &int2;
	
	int* int3p;
	
	arrayInt.Insert(int1p);
	
	arrayInt.Insert(int2p);
	
	int int3 = 666;
	
	int3p = &int3;
	
	arrayInt.Prepend(int3p, 1);
	
	std::cout << arrayInt.GetElementIndex(int1p) << std::endl;
	
	std::cout << arrayInt.GetElementIndex(int3p) << std::endl;
	
	std::cout << arrayInt.GetElementIndex(int2p) << std::endl;

	return 0;
}












