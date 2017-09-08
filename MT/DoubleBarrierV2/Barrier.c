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


struct Barrier
{
	pthread_cond_t 		m_waitOutCond;
	pthread_cond_t 		m_waitInCond;
	pthread_cond_t 		m_workDoneCond;
	pthread_mutex_t		m_mutex;
	
	unsigned int		m_capacity;
	unsigned int		m_numEntered;
	unsigned int		m_numDone;
	unsigned int		m_waitingInside;
	unsigned int		m_curBatch;
	unsigned int		m_workDoneFlag;
	
	unsigned int		m_arrivalNum;
	
	pid_t				m_summerID;
};




Barrier* BarrierCreate(unsigned int _capacity)
{
	Barrier* barrier;
	
	barrier = malloc(sizeof(Barrier));
	
	if (pthread_mutex_init(&barrier->m_mutex, NULL))
	{
		free(barrier);
		return NULL;
	}
	
	if (pthread_cond_init(&barrier->m_waitOutCond, NULL))
	{
		pthread_mutex_destroy(&barrier->m_mutex);
		free(barrier);
		return NULL;
	}
	
	if (pthread_cond_init(&barrier->m_waitInCond, NULL))
	{
		pthread_cond_destroy(&barrier->m_waitOutCond);
		pthread_mutex_destroy(&barrier->m_mutex);
		free(barrier);
		return NULL;
	}
	
	if (pthread_cond_init(&barrier->m_workDoneCond, NULL))
	{
		pthread_cond_destroy(&barrier->m_waitInCond);
		pthread_cond_destroy(&barrier->m_waitOutCond);
		pthread_mutex_destroy(&barrier->m_mutex);
		free(barrier);
		return NULL;
	}
	
	barrier->m_capacity = _capacity;
	barrier->m_waitingInside = 0;
	barrier->m_curBatch = 1;
	barrier->m_numEntered = 0;
	barrier->m_numDone = 0;
	barrier->m_workDoneFlag = 0;
	
	return barrier;
}






void BarrierDestroy(Barrier* _barrier)
{
	pthread_cond_destroy(&_barrier->m_waitOutCond);
	pthread_cond_destroy(&_barrier->m_waitInCond);
	pthread_cond_destroy(&_barrier->m_workDoneCond);
	pthread_mutex_destroy(&_barrier->m_mutex);
	free(_barrier);
	
	return;
}








static void WaitOutsideBarrier(Barrier* _barrier, unsigned int _batchNum)
{
	while (_barrier->m_curBatch != _batchNum)
	{	
		pthread_cond_wait(&_barrier->m_workDoneCond, &_barrier->m_mutex);
	}
	
	return;
}




static void GetWaitingInside(Barrier* _barrier)
{
	_barrier->m_waitingInside++;
	_barrier->m_waitingInside = _barrier->m_waitingInside % _barrier->m_capacity;
	return;
}





static void WaitInsideBarrier(Barrier* _barrier)
{
	GetWaitingInside(_barrier);
	printf("_barrier->m_waitingInside = %u\n", _barrier->m_waitingInside);
	while (_barrier->m_waitingInside > 0)
	{
		pthread_cond_wait(&_barrier->m_waitInCond, &_barrier->m_mutex);
	}
	
	pthread_cond_broadcast(&_barrier->m_waitInCond);
	
	
	return;
}



static void GetNumOfDone(Barrier* _barrier)
{
	++_barrier->m_numDone;
	
	return;
}




static void WaitWorkDone(Barrier* _barrier, BarrierAction _func, void* _context, unsigned int _arrivalNum)
{	
	unsigned int numOfDone = 0;
	
	if (_func)
	{
		_func(_context);
	}
	
	_barrier->m_workDoneFlag = 1;

	GetNumOfDone(_barrier);
	_barrier->m_numDone = _barrier->m_numDone % _barrier->m_capacity;

	while (_barrier->m_numDone != 0)
	{
		pthread_cond_wait(&_barrier->m_waitOutCond, &_barrier->m_mutex);
		_barrier->m_workDoneFlag = 0;
	}
	
	if (_barrier->m_workDoneFlag)
	{
		++_barrier->m_curBatch;
	}

	pthread_cond_broadcast(&_barrier->m_waitOutCond);
	
	return;
}



static void GetArrivalNum(Barrier* _barrier)
{
	_barrier->m_numEntered++;
	return;
}


pid_t barrierTID;


int BarrierWait(Barrier* _barrier, BarrierAction _func, void* _context)
{
	unsigned int batchNum = 0;
	
	pthread_mutex_lock(&_barrier->m_mutex);
	
	barrierTID = syscall(SYS_gettid);
	
	GetArrivalNum(_barrier);

	batchNum = (_barrier->m_numEntered / (_barrier->m_capacity + 1)) + 1;
	
	WaitOutsideBarrier(_barrier, batchNum);
	
	WaitInsideBarrier(_barrier);
/*	printf("here\n");*/
	WaitWorkDone(_barrier, _func, _context, _barrier->m_numEntered);
	
	pthread_cond_broadcast(&_barrier->m_workDoneCond);
	
	pthread_mutex_unlock(&_barrier->m_mutex);
	
	return 1;
}




