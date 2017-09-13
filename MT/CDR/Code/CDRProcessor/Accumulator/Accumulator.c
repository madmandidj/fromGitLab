#include "../../inc/Accumulator.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define SUBSCRIBERS_HASH_CAPACITY 	1000000
#define OPERATORS_HASH_CAPACITY 	100000
/*#include "HashMap.h"*/
/*#include "Transceiver.h"*/
/*#include "Logger.h"*/


struct Accumulator
{
	pthread_t*			m_threadIDs;
	Container*			m_cont;
};




Accumulator* AccumulatorCreate()
{
	Accumulator* accum;
	
	accum = malloc(sizeof(Accumulator));
	if (!accum)
	{
		return NULL;
	}
	
	accum->m_threadIDs = NULL; /* TODO: Init this properly */
	accum->m_cont = ContainerCreate(SUBSCRIBERS_HASH_CAPACITY, OPERATORS_HASH_CAPACITY);
	if (!accum->m_cont)
	{
		free(accum);
		return NULL;
	}
	
	return accum;
}






void AccumulatorDestroy(Accumulator* _accum)
{
	if (!_accum)
	{
		return;
	}
	
	ContainerDestroy(_accum->m_cont);
	free(_accum);

	return;
}







int AccumulatorGetSubscriber(Accumulator* _accum, Subscriber* _sub, Subscriber* _subFound)
{
	int err;
	
	if (!_accum || !_sub || !_subFound)
	{
		return 0;
	}
	
	err = ContainerFindSubscriber(_accum->m_cont, _sub, _subFound);
	
	return err;
}





int AccumulatorGetOperator(Accumulator* _accum, Operator* _oper, Operator* _operFound)
{
	int err;
	
	if (!_accum || !_oper || !_operFound)
	{
		return 0;
	}
	
	err = ContainerFindSubscriber(_accum->m_cont, _oper, _operFound);
	
	return err;
}






int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _sub)
{
	int err;
	
	if (!_accum || !_sub)
	{
		return 0;
	}
	
	err = ContainerUpdateSubscriber(_accum->m_cont, _sub);
	if (0 == err)
	{
		return 0;
	}
	
	return 1;
}







int AccumulatorUpdateOperator(Accumulator* _accum, Operator* _oper)
{
	int err;
	
	if (!_accum || !_oper)
	{
		return 0;
	}
	
	err = ContainerUpdateOperator(_accum->m_cont, _oper);
	if (0 == err)
	{
		return 0;
	}
	
	return 1;
}














