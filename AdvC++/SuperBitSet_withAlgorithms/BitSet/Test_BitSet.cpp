#include "BitSet.h"
#include<iostream>
#include<exception>
#include<stddef.h>

using namespace std;




int main()
{
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};
	bool boolArr2[size] = {0,1,0,0,0,0,0,1,0};
	bool boolResult[size] = {0,1,0,0,0,0,0,1,0};
//	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
//	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
//	advcpp::BitSet<size, unsigned char> bs3(boolResult, size);
	advcpp::BitSet<size, unsigned char> bs4;
	
	cout << bs4[0] << endl;
	
	bs4[0] = 1;
	
	cout << bs4[0] << endl;
	
	bs4[0] = 0;
	
	cout << bs4[0] << endl;
	return 0;
}



