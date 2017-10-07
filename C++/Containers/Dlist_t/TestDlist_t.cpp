#include "Dlist_t.h"
#include <iostream>
using namespace std;


int main()
{
	LList<int*> lList;
	LList<int*>::Iterator itr;
	
	int* arr = new int[5];
	
	arr[0] = 785;
	
	arr[1] = 999;
	
	lList.pushBack(arr);
	
	itr = lList.end();
	
	std::cout << *itr.get() << std::endl;
	
	lList.pushBack(arr + 1);
	
	itr = lList.end();
	
	std::cout << *itr.get() << std::endl;
	
	delete[] arr;
	
	return 0;
}












