#define _GNU_SOURCE
#include "Barrier.h"

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>


struct Barrier
{
	int					m_capacity;
	int					m_numOfWaiting;
	pthread_mutex_t 	m_mutex;
	pthread_cond_t		m_cond;
	pthread_barrier_t	m_barrier;
};



Barrier* BarrierCreate(int _capacity)
{
	Barrier* barrier;
	
	barrier = malloc(sizeof(Barrier));
	if (NULL == barrier)
	{
		return NULL;
	}
	
	barrier->m_capacity = _capacity;
	barrier->m_numOfWaiting = 0;	
	
	if (pthread_mutex_init(&barrier->m_mutex, NULL))
	{
		free(barrier);
		return NULL;
	}
	
	if (pthread_cond_init(&barrier->m_cond, NULL))
	{
		pthread_mutex_destroy(&barrier->m_mutex);
		free(barrier);
		return NULL;
	}
	
	if (pthread_barrier_init(&barrier->m_barrier, NULL, (unsigned int)barrier->m_capacity))
	{
		pthread_cond_destroy(&barrier->m_cond);
		pthread_mutex_destroy(&barrier->m_mutex);
		free(barrier);
		return NULL;
	}
	 
	
	return barrier;
}





void BarrierDestroy(Barrier* _barrier)
{

	pthread_cond_destroy(&_barrier->m_cond);
	pthread_mutex_destroy(&_barrier->m_mutex);
	pthread_barrier_destroy(&_barrier->m_barrier);
	free(_barrier);
	return;
}




int BarrierWait(Barrier* _barrier)
{
	int barErr;
	
	barErr = pthread_barrier_wait(&_barrier->m_barrier);
	
	if(PTHREAD_BARRIER_SERIAL_THREAD == barErr)
	{
		printf("Barrier wait done: This is PTHREAD_BARRIER_SERIAL_THREAD thread\n");
	}
	else
	{
		printf("Barrier wait done: barErr == %d\n", barErr);
	}
	
	return barErr;
}





