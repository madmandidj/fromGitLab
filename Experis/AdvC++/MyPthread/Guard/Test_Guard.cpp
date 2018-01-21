#include "Guard.h"
#include "../Mutex/Mutex.h"
#include<iostream>
#include<unistd.h>

typedef struct MyStruct
{
	advcpp::Mutex& 	m_mutex;
	int&			m_xPtr;
}MyStruct;

void* ThreadFunc1(void* mystruct)
{
	MyStruct* msPtr = (MyStruct*)mystruct;
	advcpp::Guard g1(msPtr->m_mutex);
	std::cout << "(before increment)x = " << msPtr->m_xPtr << std::endl;
	++(msPtr->m_xPtr);
	std::cout << "(after increment)x = " << msPtr->m_xPtr << std::endl;
	--(msPtr->m_xPtr);
	std::cout << "(after decrement)x = " << msPtr->m_xPtr << std::endl;
	return 0;
}

int main()
{
	const size_t numOfThreads = 20;
	pthread_t threads[numOfThreads];
	int x = 17;
	advcpp::Mutex mutex;
	MyStruct mystruct = {mutex, x};
	
	for (size_t index = 0; index < numOfThreads; ++index)
	{
		pthread_create(&threads[index], 0, ThreadFunc1, &mystruct);	
	}
	
	for (size_t index = 0; index < numOfThreads; ++index)
	{
		pthread_join(threads[index], 0);	
	}
	
	return 0;
}





