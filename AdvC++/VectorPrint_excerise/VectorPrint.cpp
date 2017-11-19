#include<iostream>
#include<vector>
#include<list>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

void MyFuncPrint(int _i) 
{  
	cout << ' ' << _i << endl;
}


int MyFuncSum(int _num)
{
	static int sum = 0;
	sum += _num;
	return sum;
}

size_t MyFuncToSum(std::vector<int>& _vec) 
{  
	for_each(_vec.begin(), _vec.end(), MyFuncSum);
	int sum = MyFuncSum(0);
	MyFuncSum(-sum);
	return sum;
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
////EXERCISE 1
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

////EXERCISE 2
//	cout << "Vector" << endl;
//	vector<int> vec1(intArr, intArr + size);
//	for_each(vec1.begin(), vec1.end(), MyFuncPrint);
//	
//	cout << "List" << endl;
//	list<int> list1(intArr, intArr + size);
//	for_each(list1.begin(), list1.end(), MyFuncPrint);

//EXERCISE 3
	cout << "Vector" << endl;
	vector<int> vec1(intArr, intArr + size);
	
	for_each(vec1.begin(), vec1.end(), MyFuncPrint);
	int sum = MyFuncToSum(vec1);
	cout << "Sum = " << sum << endl;
	
	sum = MyFuncToSum(vec1);
	cout << "Sum = " << sum << endl;
	return 0;
}
