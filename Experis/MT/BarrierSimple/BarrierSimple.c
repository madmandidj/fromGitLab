#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/syscall.h>
#include <sys/types.h>


typedef void* (*ThreadFunc)(void* _context);




typedef struct Package
{
	unsigned int 		m_countersNum;
	int*				m_countArr;
	int					m_countSum;
	pthread_t* 			m_threadIDs;
  	unsigned int* 		m_orderIDs;
	pthread_barrier_t 	m_barrier;
	pthread_barrier_t 	m_barrier2;
	pthread_mutex_t		m_mutex;
	pthread_mutex_t		m_mutex2;
	pthread_t			m_summerID;
	
}Package;




unsigned int GetCurThread(void)
{
	static int id = 0;
	
	return id++;
}





void* CounterFunc(Package* _package) 
{
	size_t iterIndex;
	size_t counterIndex;
	unsigned int curThread;
	int sleepTime;
	pid_t test;
	
	curThread = GetCurThread();
	_package->m_orderIDs[curThread] = curThread;
	
	for (iterIndex = 0; iterIndex < 4; ++iterIndex)
	{
		pthread_barrier_wait(&_package->m_barrier);
	
		sleepTime = 1 + rand() % 3;
		++_package->m_countArr[curThread];
		sleep(sleepTime);
		
		printf("Iteration %u for thread %u is done\n", iterIndex, curThread);
		pthread_barrier_wait(&_package->m_barrier2);

		
	}
	
	printf("thread %u, thread ID: %u going!\n", curThread, _package->m_orderIDs[curThread]);
	pthread_exit(NULL);
}





void* SummerFunc(Package* _package) 
{
	size_t index;

	pthread_barrier_wait(&_package->m_barrier);
	pthread_barrier_wait(&_package->m_barrier2);
	
	for(index = 0; index < _package->m_countersNum; ++index)
	{
		_package->m_countSum += _package->m_countArr[index];
	}
	
	printf("Count Sum = %d\n", _package->m_countSum);
	_package->m_countSum = 0;
	pthread_exit(NULL);
}





Package* InitProgram(unsigned int _countersNum)
{
	Package* package;
	
	package = malloc(sizeof(Package));
	
	package->m_countersNum = _countersNum;
	package->m_countSum = 0;

	package->m_threadIDs = malloc(package->m_countersNum * sizeof(pthread_t));
	package->m_orderIDs = malloc(package->m_countersNum * sizeof(unsigned int));
	package->m_countArr = malloc(package->m_countersNum * sizeof(int));
	
	srand(time(NULL));
	pthread_mutex_init(&package->m_mutex, NULL);
	pthread_mutex_init(&package->m_mutex2, NULL);
	pthread_barrier_init(&package->m_barrier, NULL, package->m_countersNum + 1);
	pthread_barrier_init(&package->m_barrier2, NULL, package->m_countersNum + 1);
	
	return package;
}





void RunCounters(Package* _package)
{
	size_t index;
	
	for (index = 0; index  < _package->m_countersNum; ++index) 
	{
		pthread_create(&_package->m_threadIDs[index], NULL, (ThreadFunc)CounterFunc, _package);
 	}
 	
	return;
}






void ClenaupProgram(Package* _package)
{
	pthread_barrier_destroy(&_package->m_barrier);
	pthread_barrier_destroy(&_package->m_barrier2);
	pthread_mutex_destroy(&_package->m_mutex);
	free(_package->m_countArr);
	free(_package->m_threadIDs);
	free(_package->m_orderIDs);
	free(_package);
	
	return;
}





int main()
{
	Package* package;
	size_t index;
	unsigned int numOfCounters = 4;
	
	package = InitProgram(numOfCounters);
	
	RunCounters(package);

	printf("main() is ready.\n");
	
	for (index = 0; index < 4; ++index)
	{
		pthread_create(&package->m_summerID, NULL, (ThreadFunc)SummerFunc, package);
	
		pthread_join(package->m_summerID, NULL);
		
		printf("Joined on summerizer!\n");
	}
	
	ClenaupProgram(package);

	return 0;
}







