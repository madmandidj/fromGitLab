#include "memPage_t.h"
#include <iostream>

using namespace std;




int main()
{
	memPage_t mPage;
	unsigned int i = 1300230230;
	int j = 168;
	unsigned int k;
	int l;
	
	mPage.Write(&i, sizeof(unsigned int));
	
	mPage.SetPosition(0);
	
	mPage.Read(&k, sizeof(unsigned int));
	
	cout << "i = " << i << ", k = " << k << ", size = " << mPage.GetSize() << endl;
	
	mPage.SetPosition(mPage.GetSize());
	
	mPage.Write(&j, sizeof(int));
	
	mPage.SetPosition(mPage.GetSize() -sizeof(int));
	
	mPage.Read(&l, sizeof(int));
	
	cout << "j = " << j << ", l = " << l << ", size = " << mPage.GetSize() << endl;
	
	return 0;
}












