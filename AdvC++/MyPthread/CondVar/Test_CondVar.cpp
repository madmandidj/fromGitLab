#include "CondVar.h"
#include"../Mutex/Mutex.h"
#include<iostream>
#include<unistd.h>

const size_t numOfThreads = 3;

typedef struct MyStruct
{
	advcpp::Mutex& 		m_mutex;
	advcpp::CondVar& 	m_condVar;
	int&				m_xRef;
	size_t				m_ID;
}MyStruct;

static size_t numOfThreadsEntered = 0;

size_t OnNewThread()
{
//	static size_t numOfThreadsEntered = 0;
	return ++numOfThreadsEntered;
}

void* ThreadFunc1(void* mystruct)
{
	MyStruct* msPtr = (MyStruct*)mystruct;
	msPtr->m_mutex.Lock();
	size_t thisThreadNum = OnNewThread();
	while (thisThreadNum < numOfThreads)
	{
//		thisThreadNum = OnNewThread();
//		sleep(1);
		msPtr->m_condVar.Wait(msPtr->m_mutex);
		thisThreadNum = numOfThreadsEntered;
	}
	msPtr->m_mutex.Unlock();
	msPtr->m_condVar.NotifyAll();
	std::cout << "(before increment)x = " << msPtr->m_xRef << std::endl;
	++(msPtr->m_xRef);
	std::cout << "(after increment)x = " << msPtr->m_xRef << std::endl;
	--(msPtr->m_xRef);
	std::cout << "(after decrement)x = " << msPtr->m_xRef << std::endl;
	return 0;
}

int main()
{
	pthread_t threads[numOfThreads];
	int x = 10;
	advcpp::Mutex mutex;
	advcpp::CondVar condvar;
	MyStruct mystruct = {mutex, condvar, x};
	
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




