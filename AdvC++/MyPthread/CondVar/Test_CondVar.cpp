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
	static size_t threadID = 0;
	return ++threadID;
}

size_t GetNumOfDoneThreads()
{
	static size_t NumOfDoneThreads = 0;
	return ++NumOfDoneThreads;
}

void DoWork(MyStruct* _msPtr)
{
	std::cout << "(before increment)x = " << _msPtr->m_xRef << std::endl;
	++(_msPtr->m_xRef);
	std::cout << "(after increment)x = " << _msPtr->m_xRef << std::endl;
	--(_msPtr->m_xRef);
	std::cout << "(after decrement)x = " << _msPtr->m_xRef << std::endl;
}

void* ThreadFunc1(void* mystruct)
{
	MyStruct* msPtr = (MyStruct*)mystruct;
	msPtr->m_mutex.Lock();
	size_t myID = GetThreadID();
	std::cout << "thread " << myID << " got ID" << std::endl;
	while (myID != currentWorkingThread)
	{
		std::cout << "Thread waiting " << myID << std::endl;
//		msPtr->m_condVar.Wait(msPtr->m_mutex);
		msPtr->m_condVar.Wait();
		std::cout << "Thread awake " << myID << std::endl;
	}
	DoWork(msPtr);
	--currentWorkingThread;
	msPtr->m_mutex.Unlock();
	msPtr->m_condVar.NotifyAll();
	return 0;
}

int main()
{
	pthread_t threads[numOfThreads];
	int x = 10;
	advcpp::Mutex mutex;
	advcpp::CondVar condvar(mutex);
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




