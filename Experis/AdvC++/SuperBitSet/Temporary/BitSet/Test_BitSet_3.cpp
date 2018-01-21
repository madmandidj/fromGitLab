#include "BitSet.h"
#include "../BitRef/BitRef.h"
#include<iostream>


int main()
{
	bool arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	advcpp::BitSet<9, unsigned char> bs1(arr1, 9);
	std::cout << bs1 << std::endl;
	
	bool arr2[] = {0, 0, 0, 0, 1, 0, 0, 0, 0};
	advcpp::BitSet<9, unsigned char> bs2(arr2, 9);
	std::cout << bs2 << std::endl;
	
//	advcpp::BitSet<9, unsigned char> bs2(arr1, 9);
//	std::cout << bs2 << std::endl;
	
	bs1 = bs1 & bs2;
	
	std::cout << bs1 << std::endl;
	return 0;
}


















