#include "Accumulator.h"
#include "./Container/Container.h"
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
	Container*			m_contSub;
	Container*			m_contOp;
};






int SubscriberEqualityFunc(const Subscriber* _sub1, const Subscriber* _sub2)
{
	int result = 1;
	
	result = strcmp(_sub1->m_msisdn, _sub2->m_msisdn);
	if (0 != result)
	{
		return 0;
	}
	
	return 1;
}






int OperatorEqualityFunc(const Operator* _oper1, const Operator* _oper2)
{
	if (_oper1->m_operatorMCCMNC != _oper2->m_operatorMCCMNC)
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
	
	accum->m_threadIDs = NULL; /* TODO: Init this properly */
	
	accum->m_contSub = ContainerCreate(SUBSCRIBERS_HASH_CAPACITY, (EqualityFunction)SubscriberEqualityFunc);
	if (!accum->m_contSub)
	{
		free(accum);
		return NULL;
	}
	
	accum->m_contOp = ContainerCreate(OPERATORS_HASH_CAPACITY, (EqualityFunction)OperatorEqualityFunc);
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







int AccumulatorGetSubscriber(Accumulator* _accum, Subscriber* _sub, Subscriber* _subFound)
{
	int err;
	
	if (!_accum || !_sub || !_subFound)
	{
		return 0;
	}
	
	err = ContainerGetElement(_accum->m_contSub, _sub->m_msisdn, (void**)&_subFound);
	
	return err;
}





int AccumulatorGetOperator(Accumulator* _accum, Operator* _oper, Operator* _operFound)
{
	int err;
	
	if (!_accum || !_oper || !_operFound)
	{
		return 0;
	}
	
	err = ContainerGetElement(_accum->m_contOp, _oper->m_operatorMCCMNC, (void**)&_operFound);
	
	return err;
}






int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _sub)
{
	int err;
	Subscriber* subFound;
	
	
	if (!_accum || !_sub)
	{
		return 0;
	}
	
	err = ContainerGetElement(_accum->m_contSub, _sub->m_msisdn, (void**)&subFound);
	if (0 == err)
	{
		ContainerInsertElement(_accum->m_contSub, _sub->m_msisdn, _sub);
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
	
	
/*	err = ContainerUpdateSubscriber(_accum->m_cont, _sub);*/
/*	if (0 == err)*/
/*	{*/
/*		return 0;*/
/*	}*/
	
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
	
	
	err = ContainerGetElement(_accum->m_contOp, _oper->m_operatorMCCMNC, (void**)&operFound);
	if (0 == err)
	{
		ContainerInsertElement(_accum->m_contOp,  _oper->m_operatorMCCMNC, _oper);
		return 1;
	}
	
	operFound->m_outVoice += _oper->m_outVoice;
	operFound->m_inVoice += _oper->m_inVoice;
	operFound->m_outSms += _oper->m_outSms;
	operFound->m_inSms += _oper->m_inSms;
	operFound->m_downloadMB += _oper->m_downloadMB;
	operFound->m_uploadMB += _oper->m_uploadMB;
	
/*	err = ContainerUpdateOperator(_accum->m_cont, _oper);*/
/*	if (0 == err)*/
/*	{*/
/*		return 0;*/
/*	}*/
	
	return 1;
}














