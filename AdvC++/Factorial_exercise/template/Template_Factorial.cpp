#include <iostream>

template<unsigned int N>
class Factorial
{
public:
	static const unsigned int fact = N * Factorial<N-1>::fact;
};


template<>
class Factorial<0>
{
public:
	static const unsigned int fact = 1;
};

int main()
{
	std::cout << Factorial<10>::fact << std::endl;
	return 0;
}
