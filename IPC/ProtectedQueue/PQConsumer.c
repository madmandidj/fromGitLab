#include "PQProducers.h"
#include <pthread.h>




struct Consumers
{
	pthread_t* 	m_threadIDs;
	size_t 		m_numOfCons;
	Queue* 		m_P2C;
	Queue* 		m_C2P;
	sem_t*		m_prodAtnd
};






Consumers* ConsumersCreate(size_t _numOfCons, Queue* _P2C, Queue* _C2P);
{
	Consumers* cons;	
	
	if (0 == _numOfCons || NULL == _P2C || NULL == _C2P)
	{
		return NULL;
	}
	
	cons = malloc(sizeof(Producers));
	if (NULL == cons)
	{
		return NULL;
	}
	
	cons->m_threadIDs = malloc(_numOfCons * sizeof(pthread_t));
	if (NULL == cons->m_threadIDs)
	{
		free(cons);
		return NULL;
	}
	
	cons->m_numOfCons = _numOfCons;
	cons->m_P2C = _P2C;
	cons->m_C2P = _C2P;
	
	cons->m_prodAtnd = sem_open(C_ATND_SEM, O_CREAT, 0666, 0);
	
	return cons;
}





void ConsumersDelete(Consumers* _cons);
{
	if (NULL == _prods)
	{
		return;
	}
	
	free(_cons->m_threadIDs);
	free(_cons);
	
	return;
}







static void* ConsumersRoutine(void* _cons)
{	
	/*
	ADTErr err;
	*/
	size_t index;
	void* rcvMsg;

	
	if (NULL == _prods)
	{
		return NULL;
	}
	
	/*
	psuedo code:
	wait for client to sign in
	receive message
	return message
	*/
	
	
	/*
	
	sem_post(_prods->m_prodAtnd);
	
	for(index = 0; index < ((Producers*)_prods)->m_numOfMsgs; ++index)
	{
		ProQueueInsert(((Producers*)_prods)->m_P2C, ((Producers*)_prods)->m_msgArr[index]);
		ProQueueRemove(((Producers*)_prods)->m_C2P, &rcvMsg);
	}
	
	sem_wait(_prods->m_prodAtnd);
	
	sem_close(_prods->m_prodAtnd);
	
	pthread_exit(NULL);
	
	return NULL;
	*/
}







int ProducersRun(Producers* _prods)
{
	size_t index;
	
	if (NULL == _prods)
	{
		return 1;
	}
	
	for (index = 0; index < _prods->m_numOfProds; ++index)
	{
		if (pthread_create(_prods->m_threadIDs + index, NULL, ProducersRoutine, _prods))
		{
			return 1;
		}
	}
	
	return 0;
}







void ProducersJoin(Producers* _prods)
{
	size_t index;
	
	if (NULL == _prods)
	{
		return;
	}
	
	for (index = 0; index < _prods->m_numOfProds; ++index)
	{
		pthread_join(_prods->m_threadIDs[index], NULL);
	}
	
	return;
}







