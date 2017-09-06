#include "../inc/PQConsumers.h"
#include "../inc/PCPQconfig.h"
#include "../inc/ProtectedQueue.h"
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
/* #include <stdio.h> */

#define ONE_SEC_USEC 1000000




struct Consumers
{
	ProQueue* 	m_P2C;
	ProQueue* 	m_C2P;
	pthread_t* 	m_threadIDs;
	sem_t*		m_eowFlag;
	size_t 		m_numOfCons;
	size_t		m_speed;
	size_t		m_verbosity;
	ReadMsg		m_readFunc;
};






/*Consumers* ConsumersCreate(size_t _numOfCons, ProQueue* _P2C, ProQueue* _C2P, ReadMsg _readFunc)*/
Consumers* ConsumersCreate(Params* _params, ProQueue* _P2C, ProQueue* _C2P, ReadMsg _readFunc)
{
	Consumers* cons;	
	
	if (NULL == _params || NULL == _P2C || NULL == _C2P)
	{
		return NULL;
	}
	
	cons = malloc(sizeof(Consumers));
	if (NULL == cons)
	{
		return NULL;
	}
	
	cons->m_numOfCons = GetNumOfCons(_params);
	cons->m_verbosity = GetVerbosity(_params);
	cons->m_speed = GetSpeed(_params);
	
	cons->m_threadIDs = malloc(cons->m_numOfCons * sizeof(pthread_t));
	if (NULL == cons->m_threadIDs)
	{
		free(cons);
		return NULL;
	}
	
	cons->m_P2C = _P2C;
	cons->m_C2P = _C2P;
	cons->m_eowFlag = sem_open(EOW_SEM, O_CREAT, 0666, 1);
	cons->m_readFunc = _readFunc;
	
	return cons;
}





void ConsumersDelete(Consumers* _cons)
{
	if (NULL == _cons)
	{
		return;
	}
	
	free(_cons->m_threadIDs);
	free(_cons);
	
	return;
}



int IsEndOfWorld(Consumers* _cons)
{
	int val;
	
	sem_getvalue(_cons->m_eowFlag, &val);
	
	if (1 == val)
	{
		return 0;
	}
	
	return 1;
}




static void* ConsumersRoutine(void* _cons)
{	
	void* rcvMsg;

	
	if (NULL == _cons)
	{
		return NULL;
	}
	
	while(ProQueueIsEmpty(((Consumers*)_cons)->m_P2C))
	{
		usleep(((Consumers*)_cons)->m_speed);
	}
	
	/* Rx msgs and Tx responses */
	while(!IsEndOfWorld((Consumers*)_cons))
	{
		if (!ProQueueIsEmpty(((Consumers*)_cons)->m_P2C))
		{
			ProQueueRemove(((Consumers*)_cons)->m_P2C, &rcvMsg);
			
			if (((Consumers*)_cons)->m_verbosity)
			{
				((Consumers*)_cons)->m_readFunc(rcvMsg, "Consumer", "Removed");
			}
			
			ProQueueInsert(((Consumers*)_cons)->m_C2P, rcvMsg);
			
			if (((Consumers*)_cons)->m_verbosity)
			{
				((Consumers*)_cons)->m_readFunc(rcvMsg, "Consumer", "Inserted");
			}
			
			usleep(((Consumers*)_cons)->m_speed);
		}
	}

	pthread_exit(NULL);
	
	return NULL;
}







int ConsumersRun(Consumers* _cons)
{
	size_t index;
	
	if (NULL == _cons)
	{
		return 1;
	}
	
	for (index = 0; index < _cons->m_numOfCons; ++index)
	{
		if (pthread_create(_cons->m_threadIDs + index, NULL, ConsumersRoutine, _cons))
		{
			return 1;
		}
	}
	
	return 0;
}







void ConsumersJoin(Consumers* _cons)
{
	size_t index;
	
	if (NULL == _cons)
	{
		return;
	}
	
	for (index = 0; index < _cons->m_numOfCons; ++index)
	{
		sem_close(_cons->m_eowFlag);
		pthread_join(_cons->m_threadIDs[index], NULL);
	}
	
	return;
}







