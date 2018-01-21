#define _GNU_SOURCE

#include "Barrier.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <unistd.h>




typedef struct BarPkg
{
	Barrier* 		m_barrier;
	pthread_t*		m_threadIDs;
	int 			m_numOfCounters;
	int				m_numOfIterations;
	int*			m_countArr;
	int				m_countersSum;
	pthread_mutex_t m_countIncMutex;
}BarPkg;






typedef struct Params
{
	int m_numOfCounters;
	int m_numOfIterations;
}Params;








int ProduceThreadNum(void)
{
	static int num = 0;
	
	return ++num;
}








void BarrierConfig(int _argc, char* _argv[], Params* _params)
{
	int opt;
	
	/*
	 Set defaults:
	*/
	_params->m_numOfCounters = 5;
	_params->m_numOfIterations = 5;
	
	while ((opt = getopt(_argc, _argv, "c:i:")) != -1) {
	   switch (opt) 
	   {
		case 'c':
			_params->m_numOfCounters = atoi(optarg);
		   break;
		   
		case 'i':
			_params->m_numOfIterations = atoi(optarg);
		   break;
		   
		default: 
		fprintf(stderr, "Usage: %s [-c Counters #] [-i Iterations #]  \n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}

	return;
}








BarPkg* BarPkgCreate(Barrier* _barrier, int _numOfCounters, int _numOfIterations)
{
	BarPkg* barPkg;
	
	barPkg = malloc(sizeof(BarPkg));
	if (NULL == barPkg)
	{
		return NULL;
	}
	
	barPkg->m_numOfIterations = _numOfIterations;
	barPkg->m_numOfCounters = _numOfCounters;
	
	barPkg->m_countArr = malloc((unsigned int)_numOfCounters * sizeof(int));
	if (NULL == barPkg->m_countArr)
	{
		free(barPkg);
		return NULL;
	}
	
	barPkg->m_threadIDs = malloc((unsigned int)barPkg->m_numOfCounters * sizeof(pthread_t));
	if (NULL == barPkg->m_threadIDs)
	{
		free(barPkg->m_countArr);
		free(barPkg);
	}
	
	barPkg->m_countersSum = 0;
	
	return barPkg;
}







void BarPkgDestroy(BarPkg* _barPkg)
{
	free(_barPkg->m_threadIDs);
	free(_barPkg->m_countArr);
	free(_barPkg);
	
	return;
}






void CalculateCountersSum(BarPkg* _barPkg)
{
	int index;
	
	for (index = 0; index < _barPkg->m_numOfCounters; ++index)
	{
		_barPkg->m_countersSum += _barPkg->m_countArr[index];
	}
	
	return;
}






void* SummarizerRoutine(void* _context)
{
	
	BarrierWait(((BarPkg*)_context)->m_barrier);
	
	CalculateCountersSum(((BarPkg*)_context));
	
	return NULL;
}






void* CounterRoutine(void* _context)
{
	int index;
	int threadNum;
	
	threadNum = ProduceThreadNum();
	
	for (index = 0; index < ((BarPkg*)_context)->m_numOfIterations; ++index)
	{
		++((BarPkg*)_context)->m_countArr[threadNum];
		usleep(300000);
	}
	
	BarrierWait(((BarPkg*)_context)->m_barrier);
	
	sleep(2);
	
	return NULL;
}








int main(int argc, char* argv[])
{
	int index;
	Params params;
	BarPkg* sumPkg;
/*	BarPkg* couPkg;*/
	Barrier* barrier;
/*	pthread_mutex_t countIncMutex;*/
	pthread_t sumThreadID;
	int joinErr;
	
	BarrierConfig(argc, argv, &params);
	
	barrier = BarrierCreate(params.m_numOfCounters + 1);
	
	sumPkg = BarPkgCreate(barrier, params.m_numOfCounters, params.m_numOfIterations);
/*	couPkg = BarPkgCreate(barrier, params.m_numOfCounters, params.m_numOfIterations);*/
	
	if (pthread_create(&sumThreadID, NULL, (ThreadRoutine)SummarizerRoutine, sumPkg))
	{
		return 1;
	}
	
	for (index = 0; index < 3; ++index)
	{
		
		if (pthread_create(sumPkg->m_threadIDs + index, NULL, (ThreadRoutine)CounterRoutine, sumPkg))
		{
			return 1;
		}
		
		joinErr = pthread_join(sumThreadID, NULL);
		printf("joinErr = %d\n", joinErr);
		
	}
	
	/*
	Get parameters
	Create barrier
	for (num of iterations)
	{
		run summarizer
		for(num of counters)
		{
			run counters
		}
		join summarizer
		print sum
	}
	destroy barrier
	*/
	
	return 0;
}







