#include "./memPool_t/memPool_t.h"
#include <iostream>

using namespace std;





int main()
{
	int a = 101;
	int b = 102;
	int c = 103;
	
	int x;
	
	memPool_t* mPool = new memPool_t(8);
	
	mPool->Write(&a, sizeof(int));
	
	mPool->Write(&b, sizeof(int));
	
	mPool->Write(&c, sizeof(int));
	
	cout << " position = " << mPool->GetPosition() << endl;
	
	mPool->SetPosition(0);
	
	mPool->Read(&x, sizeof(int));

	cout << " x = " << x << endl;
	
	cout << " size = " << mPool->GetSize() << endl;
	
	delete mPool;
	
	return 0;
}
