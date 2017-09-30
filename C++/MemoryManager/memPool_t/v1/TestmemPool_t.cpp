#include "memPool_t.h"
#include <iostream>







int main()
{
	
	memPool_t* mPool = new memPool_t(10);
	
	delete mPool;
	
	return 0;
}









