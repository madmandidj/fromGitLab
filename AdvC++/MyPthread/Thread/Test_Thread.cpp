#include "../Mutex/Mutex.h"
#include "../CondVar/CondVar.h"
#include "Thread.h"
#include<iostream>
#include<unistd.h>
#include<vector>

class Dog
{
public:
	void* Run()
	{
		std::cout << "Dog is wagging tail" << std::endl;
		return 0;
	}
};

int main()
{
//	int x = 10;
//	advcpp::Mutex mutex;
//	advcpp::CondVar condvar(mutex);

	const size_t numOfThreads = 400;
	
	Dog myDog;
	
	std::vector< advcpp::Thread<Dog, &Dog::Run>* > threadsVec;
	
	for (size_t index = 0; index < numOfThreads; ++index)
	{	
		advcpp::Thread<Dog, &Dog::Run>* thread = new advcpp::Thread<Dog, &Dog::Run>(&myDog);
		threadsVec.push_back(thread);
	}
	
	return 0;
}




