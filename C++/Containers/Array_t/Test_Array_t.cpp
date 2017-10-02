#include "Array_t.h"
#include <iostream>



int main()
{
	Array_t<int*> array;
	
	int* intArr = new int[5];
	
	intArr[0] = 785;
	
	intArr[1] = 999;
	
//	delete[] intArr;
	
	return 0;
}












