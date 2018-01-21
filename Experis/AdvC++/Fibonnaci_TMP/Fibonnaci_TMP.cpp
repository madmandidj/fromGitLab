#include<iostream>



template<unsigned int N>
class FibonnaciTMP
{
public:
	static const unsigned int fibby = FibonnaciTMP<N-2>::fibby + FibonnaciTMP<N-1>::fibby;
};

template<>
class FibonnaciTMP<1>
{
public:
	static const unsigned int fibby = 1;
};

template<>
class FibonnaciTMP<0>
{
public:
	static const unsigned int fibby = 0;
};









int main()
{
	std::cout << FibonnaciTMP<0>::fibby << std::endl;
	std::cout << FibonnaciTMP<1>::fibby << std::endl;
	std::cout << FibonnaciTMP<2>::fibby << std::endl;
	std::cout << FibonnaciTMP<3>::fibby << std::endl;
	std::cout << FibonnaciTMP<4>::fibby << std::endl;
	std::cout << FibonnaciTMP<5>::fibby << std::endl;
	std::cout << FibonnaciTMP<6>::fibby << std::endl;
	std::cout << FibonnaciTMP<7>::fibby << std::endl;
}
