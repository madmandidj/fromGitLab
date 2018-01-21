
#include "../inc/PQProducers.h"
#include "../inc/PCPQconfig.h"
#include "../inc/ProtectedQueue.h"

#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>



struct Producers
{
	int			m_id;
	ProQueue* 	m_P2C;
	ProQueue* 	m_C2P;
	void**		m_msgArr;
	pthread_t* 	m_threadIDs;
	size_t 		m_numOfProds;
	size_t		m_numOfMsgs;
	size_t		m_speed;
	size_t 		m_verbosity;
	ReadMsg		m_readFunc;
};




Producers* ProducersCreate(Params* _params, void** _msgArr, ProQueue* _P2C, ProQueue* _C2P, ReadMsg _readFunc)
{
	Producers* prods;	
	
	if (NULL == _params || NULL == _msgArr || NULL == _P2C || NULL == _C2P)
	{
		return NULL;
	}
	
	prods = malloc(sizeof(Producers));
	if (NULL == prods)
	{
		return NULL;
	}
	
	prods->m_numOfProds = GetNumOfProds(_params);
	prods->m_numOfMsgs = GetNumOfMsgs(_params);
	prods->m_speed = GetSpeed(_params);
	prods->m_verbosity = GetVerbosity(_params);
	
	prods->m_threadIDs = malloc(prods->m_numOfProds * sizeof(pthread_t));
	if (NULL == prods->m_threadIDs)
	{
		free(prods);
		return NULL;
	}
	
	prods->m_P2C = _P2C;
	prods->m_C2P = _C2P;
	prods->m_msgArr = _msgArr;
	prods->m_readFunc = _readFunc;
	
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




static int GetProducerID(void)
{
	static int id = 0;
	
	return ++id;
}


/*void GetProducerID(Producers* _prod)*/
/*{*/
/*	static int id = 0;*/
/*	*/
/*	_prod->m_id = ++id;*/
/*	*/
/*	return;*/
/*}*/




static void* ProducersRoutine(Producers* _prods)
{	
	size_t index;
	void* rcvMsg; 
	int producerID;

	
	if (NULL == _prods)
	{
		return NULL;
	}
	
	producerID = GetProducerID();
/*	GetProducerID(_prods);*/

	for(index = 0; index < _prods->m_numOfMsgs; ++index)
	{
		ProQueueInsert(_prods->m_P2C, _prods->m_msgArr + index);
		
		if (_prods->m_verbosity)
		{
			_prods->m_readFunc(_prods->m_msgArr + index, "Producer", "Inserted", producerID);
		}
		
		 ProQueueRemove(_prods->m_C2P, &rcvMsg); 
		
		if (_prods->m_verbosity)
		{
			_prods->m_readFunc(rcvMsg, "Producer", "Removed", producerID);
		}
		
		usleep(_prods->m_speed + (size_t)(rand() % 10000 + 10));
	}

	pthread_exit(_prods);
	
	return NULL;
}






typedef void* (*ThreadRoutine)(void*);





int ProducersRun(Producers* _prods)
{
	size_t index;
	
	if (NULL == _prods)
	{
		return 1;
	}
	
	for (index = 0; index < _prods->m_numOfProds; ++index)
	{
		if (pthread_create(_prods->m_threadIDs + index, NULL, (ThreadRoutine)ProducersRoutine, _prods))
		{
			return 1;
		}
	}
	
	return 0;
}







void ProducersJoin(Producers* _prods)
{
	size_t index;
	int joinErr;
	Producers* returnedPro;
	
	if (NULL == _prods)
	{
		return;
	}
	
	for (index = 0; index < _prods->m_numOfProds; ++index)
	{
/*		printf("ThreadID %d, joinErr = %d\n", _prods->m_id, joinErr);*/
		joinErr = pthread_join(_prods->m_threadIDs[index], (void**)&returnedPro);
		printf("ThreadID %d, joinErr = %d\n", returnedPro->m_id, joinErr);
	}
	
	return;
}







