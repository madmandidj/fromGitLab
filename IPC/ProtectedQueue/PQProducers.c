#include "PQProducers.h"
#include <pthread.h>




struct Producers
{
	pthread_t** 	m_threadIDs;
	size_t 			m_numOfProds;
	size_t			m_numOfMsgs;
	void**			m_msgArr;
	Queue* 			m_P2C;
	Queue* 			m_C2P;
};






Producers* ProducersCreate(size_t _numOfProds, size_t _numOfMsgs, void** _msgArr, Queue* _P2C, Queue* _C2P)
{
	Producers* prods;	
	
	if (0 == _numOfProds || 0 == _numOfMsgs || NULL == _P2C || NULL == _C2P)
	{
		return NULL;
	}
	
	prods = malloc(sizeof(Producers));
	if (NULL == prods)
	{
		return NULL;
	}
	
	prods->m_threadIDs = malloc(_numOfProds * sizeof(pthread_t*));
	if (NULL == prods->m_threadIDs)
	{
		free(prods);
		return NULL;
	}
	
	prods->m_numOfProds = _numOfProds;
	prods->m_numOfMsgs = _numOfMsgs;
	prods->m_P2C = _P2C;
	prods->m_C2P = _C2P;
	
	return prods;
}





void ProducersDelete(Producers* _prods)
{
	if (NULL == _prods)
	{
		return;
	}
	
	free(_prods->m_threadIDs);
	free(_prods);
	
	return;
}







static void* ProducersRoutine(void* _prods)
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
	
	for(index = 0; index < ((Producers*)_prods)->m_numOfMsgs; ++index)
	{
		ProQueueInsert(((Producers*)_prods)->m_P2C, ((Producers*)_prods)->m_msgArr[index]);
		ProQueueRemove(((Producers*)_prods)->m_C2P, &rcvMsg);
	}
	
	return NULL;
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
		if (pthread_create(_prods->m_threadIDs[index], NULL, ProducersRoutine, _prods))
		{
			return 1;
		}
	}
	
	return 0;
}







void ProducersJoin(Producers* _prods)
{

}







