#include "BitSet.h"
#include "../BitRef/BitRef.h"
#include<iostream>


int main()
{
	advcpp::BitSet<33, unsigned char> bs1;
	bs1.Set(true, 3);
	std::cout << bs1 << std::endl;
	
	bool boolArr[] = {1,0,0,1,0,0,0,0,1,1};
	advcpp::BitSet<10> bs2(boolArr, 10);
	std::cout << bs2 << std::endl;
//	std::cout << bs2.Count() << std::endl;
	
	bool boolArr2[] = {1,1,1,0,1,1,1,1,0,1};
	advcpp::BitSet<10> bs3(boolArr2, 10);
	std::cout << bs3 << std::endl;
	
	advcpp::BitSet<10> bs4;
	bs4 = bs2 & bs3;
	std::cout << bs4 << std::endl;
	
	advcpp::BitSet<10> bs5(boolArr2, 10);
	bs5 &= bs2;
	std::cout << bs5 << std::endl;
	
	advcpp::BitSet<10> bs6(boolArr2, 10);
	bs6 |= bs2;
	std::cout << bs6 << std::endl;
	
	advcpp::BitSet<10> bs7(boolArr2, 10);
	bs7 ^= bs2;
	std::cout << bs7 << std::endl;
	
	
	
	
	
	advcpp::BitSet<10> bs8(boolArr2, 10);
	bs8 ^= bs2;
//	std::cout << bs8 << std::endl;
	bs8.Flip(9);
	std::cout << bs8 << std::endl;
	std::cout << (bs8[9]) << std::endl;
//	std::cout << bs8 << std::endl;
	bs8[9] = 0;
	std::cout << bs8 << std::endl;
	std::cout << (bs8[9]) << std::endl;
	
	bs8[9] = 1;
	std::cout << bs8 << std::endl;
	std::cout << (bs8[9]) << std::endl;
	
	bs8[9] = bs8[0];
	std::cout << bs8 << std::endl;
	std::cout << (bs8[9]) << std::endl;
	
	bs8[9] = 1;
	std::cout << bs8 << std::endl;
	std::cout << (bs8[9]) << std::endl;
	
	bs8[9] = bs8[7];
	
	std::cout << bs8.Any() << std::endl;
	
	bool boolArr3[] = {0,0,0,0,0,0,0,0,0,0};
	advcpp::BitSet<10> bs9(boolArr3, 10);
	std::cout << bs9.Any() << std::endl;
	
	bool boolArr4[] = {1,1,1,1,1,1,1,1,1,1};
	advcpp::BitSet<10> bs10(boolArr4, 10);
	std::cout << bs10 << std::endl;
	
	std::cout << bs10.All() << std::endl;
	std::cout << bs8.All() << std::endl;
	
	std::cout << bs9.None() << std::endl;
	std::cout << bs8.None() << std::endl;
	return 0;
}


















