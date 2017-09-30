#include "memPool_t.h"
#include <iostream>

using namespace std;






int main()
{
	int a = 101;
	
	int x;
	
	memPool_t* mPool = new memPool_t(10);
	
	mPool->Write(&a, sizeof(int));
	
	mPool->SetPosition(0);
	
	mPool->Read(&x, sizeof(int));

	cout << " x = " << x << endl;
	
	delete mPool;
	
	return 0;
}









