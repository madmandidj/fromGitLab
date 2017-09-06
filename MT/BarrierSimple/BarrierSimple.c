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
	pthread_t* 			m_threadIDs;
  	unsigned int* 		m_orderIDs;
	pthread_barrier_t* 	m_barrier;
	
}Package;




unsigned int GetCurThread(void)
{
	static int id = 0;
	
	return ++id;
}





void* TestFunc(Package* _package) 
{
	unsigned int curThread;
	int sleepTime;
	pid_t test;
	

	sleepTime = 1 + rand() % 3;
	
	curThread = GetCurThread();
	
	_package->m_orderIDs[curThread] = syscall(SYS_gettid);
	

	printf("thread %u, thread ID: %u, Wait for %d seconds.\n", curThread, _package->m_orderIDs[curThread], sleepTime);
	sleep(sleepTime);
	
	printf("thread %u, thread ID: %u I'm ready...\n", curThread, _package->m_orderIDs[curThread]);

	pthread_barrier_wait(_package->m_barrier);

	printf("thread %u, thread ID: %u going!\n", curThread, _package->m_orderIDs[curThread]);
	
	return NULL;
}



Package* InitProgram(unsigned int _countersNum)
{
	Package* package;
	
	package = malloc(sizeof(Package));
	
	package->m_countersNum = _countersNum;
	
	package->m_barrier = malloc(sizeof(pthread_barrier_t));
	package->m_threadIDs = malloc(package->m_countersNum * sizeof(pthread_t));
	package->m_orderIDs = malloc(package->m_countersNum * sizeof(unsigned int));
	
	srand(time(NULL));
	pthread_barrier_init(package->m_barrier, NULL, (package->m_countersNum/2) + 1);
	
	return package;
}





void RunThreads(Package* _package)
{
	size_t index;
	
	for (index = 0; index  < _package->m_countersNum; ++index) 
	{
		_package->m_orderIDs[index] = index;
		pthread_create(&_package->m_threadIDs[index], NULL, (ThreadFunc)TestFunc, _package);
 	}
 	
	return;
}



void JoinThreads(Package* _package)
{
	size_t index;
	
	for (index = 0; index < _package->m_countersNum; ++index) 
	{
		pthread_join(_package->m_threadIDs[index], NULL);
	}
	
	return;
}



void ClenaupProgram(Package* _package)
{
	pthread_barrier_destroy(_package->m_barrier);
	free(_package->m_barrier);
	free(_package->m_threadIDs);
	free(_package->m_orderIDs);
	free(_package);
	
	return;
}


int main()
{
	Package* package;
	size_t index;
	
	package = InitProgram(10);
	
	RunThreads(package);

	printf("main() is ready.\n");

  	pthread_barrier_wait(package->m_barrier);

	printf("main() is going!\n");
	
	JoinThreads(package);
	
	ClenaupProgram(package);

	return 0;
}







