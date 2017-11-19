#include<iostream>
#include<vector>
#include<list>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void MyFunc (int _i) 
{  
	cout << ' ' << _i << endl;
}

int main()
{
	srand(time(NULL));
	const size_t size = 10;
	int intArr[size];
	for (size_t index = 0; index < size; ++index)
	{
		intArr[index] = rand() % size;
	}
	
//	//std::vector
//	cout << "Vector" << endl;
//	vector<int> vec1(intArr, intArr + size);
//	for (size_t index = 0; index < size; ++index)
//	{
//		cout << vec1[index] << endl;
//	}
//	
//	//std::list
//	cout << "List" << endl;
//	list<int> list1(intArr, intArr + size);
//	 for (std::list<int>::iterator it = list1.begin(); it != list1.end(); it++)
//	{
//		cout << *it << endl;
//	}

	cout << "Vector" << endl;
	vector<int> vec1(intArr, intArr + size);
	for_each(vec1.begin(), vec1.end(), MyFunc);
	
	cout << "List" << endl;
	list<int> list1(intArr, intArr + size);
	for_each(list1.begin(), list1.end(), MyFunc);
	
	return 0;
}
