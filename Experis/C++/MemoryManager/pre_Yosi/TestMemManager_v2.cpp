#include "./memPool_t/memPool_t.h"
#include <iostream>

using namespace std;




/*

1. Create mPool
2. Get pool size
3. Get position
4. Set position
5. Read to current position
6.  Write from current position
7. Get default page capacity
8. Set default page capacity
9. Delete mPool

*/


int main()
{
	int a = 1010101015;
	int b = 1010101016;
	int c = 1010101017;
	
	int x;
	int y;
	int z;

	memPool_t* mPool = new memPool_t();
	
	mPool->Write(&a, sizeof(int));
	
	mPool->Write(&b, sizeof(int));
	
	mPool->Write(&c, sizeof(int));
	
//	cout << " position = " << mPool->GetPosition() << endl;
	
	mPool->SetPosition(0);
	
	mPool->Read(&x, sizeof(int));
	
	mPool->Read(&y, sizeof(int));
	
	mPool->Read(&z, sizeof(int));

	cout << " x = " << x << ", y = " << y << ", z = " << z << endl;
	
//	cout << " size = " << mPool->GetSize() << endl;
	
	delete mPool;
	
	return 0;
}
