#include "../Mutex/Mutex.h"
#include "../CondVar/CondVar.h"
#include "Thread.h"
#include<iostream>
#include<unistd.h>

typedef struct Dog
{
	void* Run()
	{
		std::cout << "Dog is wagging tail" << std::endl;
		return 0;
	}
}Dog;

int main()
{
	int x = 10;
	advcpp::Mutex mutex;
	advcpp::CondVar condvar(mutex);
	
	Dog myDog;
	
	advcpp::Thread<Dog, &Dog::Run> thread1(&myDog);
	
	thread1.Join();
	
	return 0;
}




