#include "BitSet.h"
#include<iostream>


int main()
{
	advcpp::BitSet<33> bs1;
//	std::cout << bs1.GetNumOfBits() << std::endl;
//	std::cout << bs1.GetNumOfBitContainers() << std::endl;
//	std::cout << CHAR_BIT << std::endl;
//	std::cout << bs1.Get(5) << std::endl;
	bs1.Set(true, 1);
	std::cout << bs1 << std::endl;
	return 0;
}


















