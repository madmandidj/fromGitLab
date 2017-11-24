#include "CondVar.h"
#include"../Mutex/Mutex.h"
#include<iostream>
#include<unistd.h>

const size_t numOfThreads = 3;
size_t numOfDoneThreads = 0;
size_t currentWorkingThread = 3;

typedef struct MyStruct
{
	advcpp::Mutex& 		m_mutex;
	advcpp::CondVar& 	m_condVar;
	int&				m_xRef;
	size_t				m_ID;
}MyStruct;



size_t GetThreadID()
{
//	static size_t numOfThreadsEntered = 0;
	static size_t threadID = 0;
	return ++threadID;
}

size_t GetNumOfDoneThreads()
{
//	static size_t numOfThreadsEntered = 0;
	static size_t NumOfDoneThreads = 0;
	return ++NumOfDoneThreads;
}

void* ThreadFunc1(void* mystruct)
{
	MyStruct* msPtr = (MyStruct*)mystruct;
	msPtr->m_mutex.Lock();
//	msPtr->m_condVar.NotifyAll();
	msPtr->m_ID = GetThreadID();
	std::cout << "thread " << msPtr->m_ID << " got ID" << std::endl;
	while (msPtr->m_ID != currentWorkingThread)
	{
		std::cout << "Thread waiting " << msPtr->m_ID << std::endl;
		msPtr->m_condVar.Wait(msPtr->m_mutex);
		std::cout << "Thread awake " << msPtr->m_ID << std::endl;
	}
	std::cout << "(before increment)x = " << msPtr->m_xRef << std::endl;
	++(msPtr->m_xRef);
	std::cout << "(after increment)x = " << msPtr->m_xRef << std::endl;
	--(msPtr->m_xRef);
	std::cout << "(after decrement)x = " << msPtr->m_xRef << std::endl;
	--currentWorkingThread;
	msPtr->m_mutex.Unlock();
	msPtr->m_condVar.NotifyOne();
//	msPtr->m_mutex.Unlock();
	while(currentWorkingThread > 0)
	{	
		std::cout << "Thread notifying " << msPtr->m_ID << std::endl;
		msPtr->m_condVar.NotifyOne();
		sleep(1);
	}
	

	return 0;
}

int main()
{
	pthread_t threads[numOfThreads];
	int x = 10;
	advcpp::Mutex mutex;
	advcpp::CondVar condvar;
	MyStruct mystruct = {mutex, condvar, x, 1};
	
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




