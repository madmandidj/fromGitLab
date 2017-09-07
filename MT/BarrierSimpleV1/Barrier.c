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
	unsigned int		m_workDoneFlag;
	unsigned int		m_capacity;
	unsigned int		m_waiting;
	unsigned int		m_curBatch;
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
	barrier->m_waiting = 0;
	barrier->m_curBatch = 0;
	barrier->m_workDoneFlag = 1;
	
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






static unsigned int GetArrivalNum(void)
{
	static unsigned int num = 0;
	
	return num++;
}







static void WaitOutsideBarrier(Barrier* _barrier, unsigned int _batchNum)
{
	while (_batchNum != _barrier->m_curBatch)
	{
		pthread_cond_wait(&_barrier->m_workDoneCond, &_barrier->m_mutex);
	}
	
	return;
}






static void WaitInsideBarrier(Barrier* _barrier)
{
	unsigned int curThread = 0;
	
	_barrier->m_workDoneFlag = 0;
	
	while (_barrier->m_waiting < _barrier->m_capacity)
	{
		++_barrier->m_waiting;
		if (_barrier->m_capacity == _barrier->m_waiting)
		{
			break;
		}
/*		if (_barrier->m_waiting == _barrier->m_capacity)*/
/*		{*/
/*			pthread_cond_broadcast(&_barrier->m_waitInCond);*/
/*		}*/
		pthread_cond_wait(&_barrier->m_waitInCond, &_barrier->m_mutex);
	}
	
	pthread_cond_broadcast(&_barrier->m_waitInCond);
/*	*/
/*	++curThread;*/
/*	*/
/*	if (curThread == _barrier->m_capacity)*/
/*	{*/
/*		_barrier->m_waiting = 0;*/
/*	}*/
	
	return;
}





static unsigned int GetNumOfDone()
{
	static int num = 0;
	
	return num++;
}




static void WaitWorkDone(Barrier* _barrier, BarrierAction _func, void* _context, unsigned int _arrivalNum)
{	
	unsigned int numOfDone = 0;
	
	if (_func)
	{
		_func(_context);
	}
	
	numOfDone = GetNumOfDone() % _barrier->m_capacity;
	
	if (numOfDone == _barrier->m_capacity - 1)
	{
		pthread_cond_broadcast(&_barrier->m_workDoneCond);
		++_barrier->m_curBatch;
	}
	
	while (numOfDone != _barrier->m_capacity - 1)
	{
		pthread_cond_wait(&_barrier->m_waitOutCond, &_barrier->m_mutex);
	}
	
	_barrier->m_workDoneFlag = 1;
	
	pthread_exit(NULL);
	
	return;
}






int BarrierWait(Barrier* _barrier, BarrierAction _func, void* _context)
{
	unsigned int arrivalNum = 0;
	unsigned int batchNum = 0;
	
	
	arrivalNum = GetArrivalNum();
	batchNum = arrivalNum / _barrier->m_capacity;
	
	pthread_mutex_lock(&_barrier->m_mutex);
	
	WaitOutsideBarrier(_barrier, batchNum);
	WaitInsideBarrier(_barrier);
	WaitWorkDone(_barrier, NULL, NULL, arrivalNum);
	
	pthread_mutex_unlock(&_barrier->m_mutex);
	
	return 1;
}




