//#include "CondVar.h"
//#include"../Mutex/Mutex.h"
#include<pthread.h>
#include<iostream>
#include<unistd.h>

const size_t numOfThreads = 3;
size_t numOfDoneThreads = 0;
size_t currentWorkingThread = 3;

typedef struct MyStruct
{
	pthread_mutex_t& 	m_mutex;
	pthread_cond_t& 	m_condVar;
	int&				m_xRef;
//	size_t				m_ID;
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

void* ThreadFunc1(void* mystruct)
{
	MyStruct* msPtr = (MyStruct*)mystruct;
	pthread_mutex_lock(&msPtr->m_mutex);
//	msPtr->m_ID = GetThreadID();
	size_t myID = GetThreadID();
	std::cout << "thread " << myID << " got ID" << std::endl;
	while (myID != currentWorkingThread)
	{
		std::cout << "Thread waiting " << myID << std::endl;
		pthread_cond_wait(&msPtr->m_condVar, &msPtr->m_mutex);
		std::cout << "Thread awake " << myID << std::endl;
	}
	std::cout << "Thread left while loop " << myID << std::endl;
	--currentWorkingThread;
	pthread_mutex_unlock(&msPtr->m_mutex);
	pthread_cond_broadcast(&msPtr->m_condVar);
//	while(currentWorkingThread > 0)
//	{	
//		msPtr->m_condVar.NotifyOne();
//		pthread_cond_broadcast(&msPtr->m_condVar);
	sleep(1);
//	}
	

	return 0;
}

int main()
{
	pthread_t threads[numOfThreads];
	int x = 10;
	pthread_mutex_t mutex;
	pthread_cond_t condvar;
	
	pthread_cond_init(&condvar, 0);
	pthread_mutex_init(&mutex, 0);
	
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




