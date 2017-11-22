#include "FantasticSingleton.h"
#include <tr1/memory>
#include <iostream>

struct Dog
{
	double m_home;
	float m_barkings;
	int m_owner;
};

int main()
{
	std::tr1::shared_ptr<Dog> dogA = Singleton<Dog>::GetInstance();
	std::tr1::shared_ptr<Dog> dogB = Singleton<Dog>::GetInstance();
	std::tr1::shared_ptr<Dog> dogC = Singleton<Dog>::GetInstance();
	
	std::cout << dogA << std::endl;
	std::cout << dogB << std::endl;
	std::cout << dogC << std::endl;
	
	return 0;
}
