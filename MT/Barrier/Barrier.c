#include "Barrier.h"

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
struct Barrier
{
	int					m_capacity;
	int					m_numOfWaiting;
	pthread_mutex_t 	m_mutex;
	pthread_cond_t		m_cond;
};
*/


Barrier* BarrierCreate(int _capacity)
{
	Barrier* barrier = NULL;
	
	return barrier;
}





void BarrierDestroy(Barrier* _barrier)
{

	return;
}




int BarrierWait(Barrier* _barrier)
{

	return 0;
}





