#include <iostream>
#include <string>
#include <map>

using namespace std;


struct myStruct
{
	string m_ISBN;
	string m_title;
	size_t m_numOfCopies;
};


int main()
{
	myStruct mystrct = {"1234567891", "LOTR1", 5};
	myStruct mystrct2 = {"1234567892", "LOTR1", 5};
	myStruct* mystrctPtr;
	
//	pair<const string, myStruct*> value_type;

	map<string, myStruct*> intMap;
	int x = 101;
	int y = 202;
	int z = 303;
	
	intMap[mystrct.m_ISBN] = &mystrct;
	intMap[mystrct2.m_ISBN] = &mystrct2;
	
//	pair<const string, myStruct*> testPair;
	
	mystrctPtr = intMap[mystrct.m_ISBN];
	cout << mystrctPtr->m_ISBN << endl;
	cout << intMap.size() << endl;
	
	mystrctPtr = intMap[mystrct2.m_ISBN];
	cout << mystrctPtr->m_ISBN << endl;
	cout << intMap.size() << endl;
	
	
	cout << sizeof(int) << endl;
	
	cout << sizeof(long long int) << endl;
	
	long long int test = 1234567890123;
	
	cout << test << endl;
	
	return 0;
}










