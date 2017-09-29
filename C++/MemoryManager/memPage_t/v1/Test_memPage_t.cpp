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
	
	mPage.WriteToPage(&i, sizeof(unsigned int));
	
	mPage.SetPagePosition(0);
	
	mPage.ReadFromPage(&k, sizeof(unsigned int));
	
	cout << "i = " << i << ", k = " << k << ", size = " << mPage.GetPageSize() << endl;
	
	mPage.SetPagePosition(mPage.GetPageSize());
	
	mPage.WriteToPage(&j, sizeof(int));
	
	mPage.SetPagePosition(mPage.GetPageSize() -sizeof(int));
	
	mPage.ReadFromPage(&l, sizeof(int));
	
	cout << "j = " << j << ", l = " << l << ", size = " << mPage.GetPageSize() << endl;
	
	return 0;
}












