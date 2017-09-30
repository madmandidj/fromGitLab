#include "memPage_t.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	unsigned int i = 1300230230;
	int j = 168;
	unsigned int k;
	int l;
	
	
	
	vector<memPage_t*> v; // CTOR of vector of pointers to page
	
	memPage_t* pg1 = new memPage_t(16);
	
	pg1->Write(&i, sizeof(unsigned int));
	
	pg1->Write(&j, sizeof(unsigned int));
	
	v.push_back(pg1); // add new pointer to page to the end of vector ?
	
	memPage_t* mPage;
	
	mPage = v.at(0);
	
	mPage->SetPosition(0);
	
	mPage->Read(&k, sizeof(unsigned int));
	
	cout <<"k = " << k << endl;
	
	mPage->Read(&l, sizeof(int));
	
	cout <<"l = " << l << endl;
	
	cout <<"size = " << mPage->GetSize() << endl;
	
	delete pg1;
	
	
	return 0;
}












