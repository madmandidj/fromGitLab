#include "BitSet.h"
//#include "BitSet_Helper.h"
#include<iostream>
#include<exception>
#include<stddef.h>

using namespace std;




int main()
{
	const size_t size = 9;
	bool boolArr1[size] = {1,1,1,1,0,1,1,1,1};
	bool boolArr2[size] = {1,1,1,1,0,0,1,1,1};
	
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
//	advcpp::BitSet<size, unsigned char> bs3;
	
	bs1[0] = 1;
	
	cout << bs1[0] << endl;
	
	cout << bs1 << endl;
	
	cout << (bs1 & bs2) << endl;
	
	return 0;
}



