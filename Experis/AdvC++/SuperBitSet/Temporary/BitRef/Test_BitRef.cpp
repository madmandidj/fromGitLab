#include "BitRef.h"


int main()
{
	unsigned char c = -1;
	advcpp::BitRef<3, unsigned char> br1(&c);
	std::cout << br1.Get() << std::endl;
	br1.Clear();
	std::cout << br1.Get() << std::endl;
	return 0;
}
