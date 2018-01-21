#include "Array_t.h"
#include <iostream>



int main()
{	
	size_t initCap = 10;
	size_t blockSize = 5;
	size_t initNumOfElems = 0;
	
	Array_t<int> arrayInt(initNumOfElems, initCap, blockSize);

	int int1 = 100;
	
	int int2 = 200;
	
	int int3 = 300;
	
	int int4 = 400;
	
	int* int1p;
	
	int* int2p;
	
	int* int3p;
	
	int* int4p;
	
	int1p = &int1;
	
	int2p = &int2;
	
	int3p = &int3;
	
	int4p = &int4;
	
	arrayInt.Insert(int1p);

	arrayInt.Append(int2p, 0);
	
	arrayInt.Prepend(int3p, 0);
	
	std::cout << arrayInt.GetElementIndex(int1p) << std::endl;
	
	std::cout << arrayInt.GetElementIndex(int3p) << std::endl;
	
	std::cout << arrayInt.GetElementIndex(int2p) << std::endl;

	return 0;
}












