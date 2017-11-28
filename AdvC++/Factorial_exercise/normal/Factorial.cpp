#include <iostream>

unsigned int Factorial(unsigned int _num)
{
	if (0 == _num || 1 == _num)
	{
		return 1;
	}
	
	return _num * Factorial(_num - 1);
}


int main()
{
	std::cout << Factorial(5) << std::endl;
	return 0;
}
