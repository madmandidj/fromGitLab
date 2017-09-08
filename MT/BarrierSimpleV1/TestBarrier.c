#define _GNU_SOURCE

#include "Barrier.h"

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
	Barrier*			m_myBarrier;
	pthread_mutex_t		m_mutex;
	pthread_mutex_t		m_mutex2;
	pthread_t			m_summerID;
	
}Package;




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
	
	package->m_myBarrier = BarrierCreate(package->m_countersNum + 1);
	
	return package;
}



unsigned int GetCurThread(void)
{
	static int id = 0;
	
	return id++;
}

pid_t counterTID;

void* CounterFunc(Package* _package) 
{
	size_t iterIndex;
	size_t counterIndex;
	unsigned int curThread;
	int sleepTime;
	pid_t test;
	
	counterTID = syscall(SYS_gettid);
	printf("CounterFunc: countertid = %u\n", counterTID);
	
	curThread = GetCurThread();
	_package->m_orderIDs[curThread] = curThread;
	
	for (iterIndex = 0; iterIndex < 4; ++iterIndex)
	{
		sleepTime = 1 + rand() % 3;
		++_package->m_countArr[curThread];
		sleep(sleepTime);
		printf("CounterFunc: calling barrierwait\n");
		BarrierWait(_package->m_myBarrier, NULL, NULL);	
		printf("CounterFunc: left barrierwait\n");
	}

	pthread_exit(NULL);
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



int MySummerAction(Package* _package)
{
	size_t index;
	for(index = 0; index < _package->m_countersNum; ++index)
	{
		_package->m_countSum += _package->m_countArr[index];
		 
	}
	printf("SummerAction: countSum = %u\n", _package->m_countSum);
	_package->m_countSum = 0;
	
	return 1;
}



pid_t summerTID;


void* SummerFunc(Package* _package) 
{
	size_t index;

	summerTID = syscall(SYS_gettid);
	printf("SummerFunc: summertid = %u\n", summerTID);
	
	printf("SummerFunc: calling barrierwait\n");
	BarrierWait(_package->m_myBarrier, (BarrierAction)MySummerAction, (void*)_package);
	printf("SummerFunc: left barrierwait\n");
	
	pthread_exit(NULL);
}



void ClenaupProgram(Package* _package)
{
	BarrierDestroy(_package->m_myBarrier);
	pthread_mutex_destroy(&_package->m_mutex);
	free(_package->m_countArr);
	free(_package->m_threadIDs);
	free(_package->m_orderIDs);
	free(_package);
	
	return;
}

/*int numOfIterations*/

int main()
{
	Package* package;
	size_t index;
	unsigned int numOfCounters = 2;
	
	
	package = InitProgram(numOfCounters);
	
	RunCounters(package);

	
	for (index = 0; index < numOfCounters; ++index)
	{
		printf("MAIN: iteration %u\n", index + 1);
		pthread_create(&package->m_summerID, NULL, (ThreadFunc)SummerFunc, package);
		printf("MAIN: calling join\n");
		pthread_join(package->m_summerID, NULL);
		printf("MAIN: left join\n");
	}
	
	ClenaupProgram(package);

	return 0;
}







