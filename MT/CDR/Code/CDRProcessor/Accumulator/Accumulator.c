#include "Accumulator.h"
#include "./Container/Container.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

#define SUBSCRIBERS_HASH_CAPACITY 	1000000
#define OPERATORS_HASH_CAPACITY 	100000


struct Accumulator
{
/*	pthread_t*			m_threadIDs;*/
	Container*			m_contSub;
	Container*			m_contOp;
};



int ContainerDataEqualityFunc(const char* _key1, const char* _key2)
{
	int result = 1;
	
	result = strcmp(_key1, _key2);
	if (0 != result)
	{
		return 0;
	}
	
	return 1;
}



Accumulator* AccumulatorCreate()
{
	Accumulator* accum;
	
	accum = malloc(sizeof(Accumulator));
	if (!accum)
	{
		return NULL;
	}
	
/*	accum->m_threadIDs = NULL;*/
	
	accum->m_contSub = ContainerCreate(SUBSCRIBERS_HASH_CAPACITY, (EqualityFunction)ContainerDataEqualityFunc);
	if (!accum->m_contSub)
	{
		free(accum);
		return NULL;
	}
	
	accum->m_contOp = ContainerCreate(OPERATORS_HASH_CAPACITY, (EqualityFunction)ContainerDataEqualityFunc);
	if (!accum->m_contOp)
	{
		free(accum->m_contSub);
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
	
	ContainerDestroy(_accum->m_contSub);
	ContainerDestroy(_accum->m_contOp);
	free(_accum);

	return;
}



int AccumulatorGetSubscriber(Accumulator* _accum, char* _key, Subscriber** _subFound)
{
	int err;
	
	if (!_accum || !_key || !_subFound)
	{
		return 0;
	}
	
	err = ContainerGetElement(_accum->m_contSub, _key, (void**)_subFound);
	
	return err;
}



int AccumulatorGetOperator(Accumulator* _accum, char* _key, Operator* _operFound)
{
	int err;
	
	if (!_accum || !_key || !_operFound)
	{
		return 0;
	}
	
	err = ContainerGetElement(_accum->m_contOp, _key, (void**)&_operFound);
	
	return err;
}



int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _sub)
{
	int err;
	Subscriber* subFound;
	Subscriber* newSub;
	
	
	if (!_accum || !_sub)
	{
		return 0;
	}
	
	err = ContainerGetElement(_accum->m_contSub, _sub->m_msisdn, (void**)&subFound);
	printf("Finished container get element subscriber\n"); 
	if (0 == err)
	{
		newSub = malloc(sizeof(Subscriber));
		*newSub = *_sub;
		ContainerInsertElement(_accum->m_contSub, newSub->m_msisdn, newSub);
		printf("Finished container insert element subscriber\n");
		return 1;
	}
	
	subFound->m_outVoiceWithinOp += _sub->m_outVoiceWithinOp;
	subFound->m_inVoiceWithinOp += _sub->m_inVoiceWithinOp;
	subFound->m_outVoiceOutsideOp += _sub->m_outVoiceOutsideOp;
	subFound->m_inVoiceOutsideOp += _sub->m_inVoiceOutsideOp;
	subFound->m_outSmsWithinOp += _sub->m_outSmsWithinOp;
	subFound->m_inSmsWithinOp += _sub->m_inSmsWithinOp;
	subFound->m_outSmsOutsideOp += _sub->m_outSmsOutsideOp;
	subFound->m_inSmsOutsideOp += _sub->m_inSmsOutsideOp;
	subFound->m_downloadMB += _sub->m_downloadMB;
	subFound->m_uploadMB += _sub->m_uploadMB;
	
	return 1;
}



int AccumulatorUpdateOperator(Accumulator* _accum, Operator* _oper)
{
	int err;
	Operator* operFound;
	
	if (!_accum || !_oper)
	{
		return 0;
	}
	
	printf("Starting container get element operator\n"); 
	err = ContainerGetElement(_accum->m_contOp, _oper->m_operatorMCCMNC, (void**)&operFound);
	printf("Finished container get element operator\n"); 
	if (0 == err)
	{
		ContainerInsertElement(_accum->m_contOp,  _oper->m_operatorMCCMNC, _oper);
		printf("Finished container insert element operator\n"); 
		return 1;
	}
	
	operFound->m_outVoice += _oper->m_outVoice;
	operFound->m_inVoice += _oper->m_inVoice;
	operFound->m_outSms += _oper->m_outSms;
	operFound->m_inSms += _oper->m_inSms;
	operFound->m_downloadMB += _oper->m_downloadMB;
	operFound->m_uploadMB += _oper->m_uploadMB;
	
	return 1;
}














