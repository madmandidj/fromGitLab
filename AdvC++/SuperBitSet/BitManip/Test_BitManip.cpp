#include "BitManip.h"


int main()
{
	unsigned char c = 27;
	advcpp::BitManip<unsigned char> bm1(&c);
	std::cout << bm1 << std::endl;
	bm1.Set(7);
	std::cout << bm1 << std::endl;
	bm1.Set(7);
	std::cout << bm1 << std::endl;
	std::cout << bm1.Get(7) << std::endl;
	bm1.Clear(7); 
	std::cout << bm1 << std::endl;
	bm1.Clear(7); 
	std::cout << bm1 << std::endl;
	std::cout << bm1 << std::endl;
	std::cout << bm1.Get(7) << std::endl;
	std::cout << bm1.Get(0) << std::endl;
	
	return 0;
}








