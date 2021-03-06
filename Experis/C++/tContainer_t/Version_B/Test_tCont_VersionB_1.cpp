#include "tContainer_t.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int i = 666;
	
	int j = 777;
	
	int k = 888;
	
	int* ip = &i;
	
	int* jp = &j;
	
	int* kp = &k;
	
	int* ptr;

//	tContainer_t<int, vector<int*> > cont;

	tContainer_t<int, vector> cont;

//	tContainer_t<int, list> cont;
	
	cont.InsertElement(ip);
	
	cont.InsertElement(jp);
	
	cont.InsertElement(kp);
	
	ptr = cont.Find(323);
	
	if (0 == ptr)
	{
		cout << "Not Found"<< endl;
	}
	else
	{
		cout << "Found = " << *ptr << endl;
	}
	
	cout << "Element Num = " << cont.NumOfElements() << endl;
	
	cont.RemoveAll();
	
	cout << "Element Num = " << cont.NumOfElements() << endl;
	
	int* heapInt = new int;
	
	int* heapInt1 = new int;
	
	int* heapInt2 = new int;
	
	int* heapInt3 = new int;
	
	*heapInt = 1234;
	
	*heapInt1 = 222;
	
	*heapInt2 = 171;
	
	*heapInt3 = 717;
	
	cont.InsertElement(heapInt);
	
	cont.InsertElement(heapInt1);
	
	cont.InsertElement(heapInt2);
	
	cont.InsertElement(heapInt3);
	
	cout << "Element Num = " << cont.NumOfElements() << endl;
	
	ptr = cont[2];
	
	cout << "Element Num = " << *ptr << endl;
	
	cont.RemoveAndDeleteAll();

	cout << "Element Num = " << cont.NumOfElements() << endl;
	
	return 0;
}


