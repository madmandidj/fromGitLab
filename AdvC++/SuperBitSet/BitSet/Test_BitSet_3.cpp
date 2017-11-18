#include "BitSet.h"
#include "../BitRef/BitRef.h"
#include<iostream>


int main()
{
	
	const size_t size = 64;
	
	bool boolArr1[size] = {0,0,0,0,0,0,0,0,0};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	unsigned char c = 12;
	advcpp::BitManip<unsigned char> bm1(&c);
	
	bool boolArr2[size] = {0,1,1,0,0,0,0,0,1};
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	
	
	bs1 | bs2.Flip();
	
	bs1 | bs2.Flip();
	
	bs1 | bs2.Flip(0);
	
	bs1 | bs2.Flip(size - 1);
	
	
	
	std::cout << bs1 << std::endl;
	std::cout << bs2 << std::endl;

	advcpp::BitSet<size, unsigned char> bs3;
	
	bs3 = bs1 ^ bs2;
	
	std::cout << bs3 << std::endl;
	return 0;
}


















