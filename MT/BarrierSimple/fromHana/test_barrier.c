#include <stdio.h>
#include <stdlib.h> /*getopt */
#include <getopt.h>
#include "barrier.h"


#define DEFAULT_ITERATIONS 5
#define DEFAULT_COUNTERS 10
#define SUMMARIZER_THREAD 1


typedef void* (*StartRoutine) (void*);

typedef struct CountInfo CountInfo;


struct CountInfo
{
	unsigned int 	m_nCounters;
	unsigned int 	m_iterations;
	int* 			m_mutualCountArr;
	Barrier* 		m_barrier;
};

void ParseParameters(int _argc, char* _argv[], CountInfo* _countInfo);
CountInfo* CreateCountInfo();
void  InitCountInfo(CountInfo* _countInfo);
void* CounterRoutine(CountInfo* _countInfo);
int* SummerizeRoutine(CountInfo* _countInfo);
int CreateCountThreads(CountInfo* _info);
int CreateSummarizer (CountInfo* _info);
void DestroyCountInfo(CountInfo* _countInfo);
int GetThreadIndex ();



int main(int argc, char* argv[])
{
	CountInfo* countInfo = NULL;
	
	countInfo = CreateCountInfo();
	
	/*the parsing function is actually also part of the init, because user info goes into the struct */
	ParseParameters(argc, argv, countInfo); 
	InitCountInfo(countInfo);
	
	/*create all counting threads. Only created once */
	if ( 0 != CreateCountThreads(countInfo))
	{
		DestroyCountInfo(countInfo);
		return 0;
	}
	
	/*loop for summairze thread */
	if (0 != CreateSummarizer(countInfo))
	{
		DestroyCountInfo(countInfo);
		return 0;
	}
	
	DestroyCountInfo(countInfo);
	
	return 0;
}




CountInfo* CreateCountInfo()
{
	CountInfo* countInfo = NULL;
	
	countInfo = malloc(sizeof(CountInfo));
	if (NULL == countInfo)
	{
		return NULL;
	} 
	
	countInfo->m_nCounters = 0;
	countInfo->m_iterations = 0;
	
	return countInfo;
}

void DestroyCountInfo(CountInfo* _countInfo)
{
	BarrierDestory(_countInfo->m_barrier);
	free(_countInfo);
}







void ParseParameters(int _argc, char* _argv[], CountInfo* _countInfo)
{
	int opt;
	
	_countInfo->m_iterations = DEFAULT_ITERATIONS;
	_countInfo->m_nCounters = DEFAULT_COUNTERS;
	
	while ((opt = getopt(_argc, _argv, "n:i:")) != -1) {
	   switch (opt) 
	   {
		case 'n':
			_countInfo->m_nCounters = (unsigned int)atoi(optarg);
		   break;
		   
		case 'i':
			_countInfo->m_iterations = (unsigned int)atoi(optarg);
		   break;
		   
		   	
		default: 
		fprintf(stderr, "Usage: %s [-i number of iterations] [-n number of counter threads] \n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
}


/*nCounters and iterations are actually already initiated */
void  InitCountInfo(CountInfo* _countInfo)
{
	_countInfo->m_mutualCountArr = malloc(_countInfo->m_nCounters*sizeof(int));
	_countInfo->m_barrier = BarrierCreate(_countInfo->m_nCounters + SUMMARIZER_THREAD);	

}



int CreateCountThreads(CountInfo* _info)
{
	int i;
	int res;
	pthread_t threadCounter;
	
	for (i = 0; i < _info->m_nCounters; ++i)
	{
		res = pthread_create(&threadCounter, NULL, (StartRoutine)CounterRoutine, (void*) _info);
		if (0 != res)
		{
			perror("pthread create");
			return res;
		}
		 pthread_detach(threadCounter);
	}
	return 0;
}


int CreateSummarizer (CountInfo* _info)
{
	int i;
	pthread_t summarizer;
	int sum = 0;
	int* result = &sum; 
	int res;
	
	result = malloc(sizeof(int));
	
	for (i = 0; i < _info->m_iterations; ++i)
	{
		res = pthread_create(&summarizer, NULL, (StartRoutine)SummerizeRoutine, (void*) _info);
		if (0 != res)
		{
			perror("pthread create");
			return -1;
		}
		
		pthread_join(summarizer, (void**)(&result));
		printf("loop number %d, current array count: %d\n", i, *result);
	}
	
	return 0;
}

/*
int BarrierWait(Barrier* _barrier, ThreadFunc _threadFunc, void* _context)
*/

void* CounterRoutine(CountInfo* _countInfo)
{
	int i,j;
	int index = -1;
	int myCount = 0;
	
	/*while in case the mutex fails. Theoretically can be endless loop */
	while(index < 0)
	{
		index = GetThreadIndex();		
	}
	
	printf("counter thread, my index is %d\n", index);
	_countInfo->m_mutualCountArr[index] = 0;
	
	for (j = 0; j < _countInfo->m_iterations; ++j)
	{
		myCount = 0;
		BarrierWait(_countInfo->m_barrier);
		
		for (i = 1; i <= index; ++i)
		{
			myCount+= i;
		}
		
		_countInfo->m_mutualCountArr[index] = myCount;
		printf("thread %d, count result: %d\n", index, _countInfo->m_mutualCountArr[index]);
	
		BarrierWait(_countInfo->m_barrier);
	}
	
	return NULL;
}


int* SummerizeRoutine(CountInfo* _countInfo)
{
	int i;
	int* totalCount = 0;
	
	totalCount = malloc(sizeof(int));
	BarrierWait(_countInfo->m_barrier);
	BarrierWait(_countInfo->m_barrier);
	
	for (i = 0; i < _countInfo->m_nCounters; ++i)
	{
		*totalCount+= _countInfo->m_mutualCountArr[i];
		_countInfo->m_mutualCountArr[i] = 0;	
	}
	printf("total count: %d\n", *totalCount);
	/*TODO check what is the return. Need to change maybe to pthread exit */
	
	pthread_exit((void*)totalCount);
}





int GetThreadIndex ()
{
	static int  index = 0;
	static pthread_mutex_t mutex;
	
	pthread_mutex_init(&mutex, NULL);
	if (0 != pthread_mutex_lock(&mutex))
	{
		return -1;
	}
	
	index++;
	
	if (0 != pthread_mutex_unlock(&mutex))
	{
		return -1;
	}
	
	
	return index - 1;
}






















