#include "../../inc/Accumulator.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
/*#include "HashMap.h"*/
/*#include "Transceiver.h"*/
/*#include "Logger.h"*/

#define	ACCUMULATOR_MAGIC 0x0CC00001


/*struct Accumulator*/
/*{*/
/*	unsigned int		m_magicNum;*/
/*	pthread_t			m_threadIDs;*/
/*	HashMap* 			m_subscriberStorage;*/
/*	HashMap* 			m_operatorStorage;*/
/*};*/




struct Accumulator
{
	unsigned int		m_magicNum;
	pthread_t*			m_threadIDs;
	Subscriber 			m_subscriberStorage;
	Operator 			m_operatorStorage;
};




Accumulator* AccumulatorCreate(Subscriber* _subStorage, Operator* _opStorage)
{
	Accumulator* accum;
	
	if (!_subStorage || !_opStorage)
	{
		return NULL;
	}
	
	accum = malloc(sizeof(Accumulator));
	if (!accum)
	{
		return NULL;
	}
	
	accum->m_magicNum = STORER_MAGIC;
	accum->m_threadIDs = NULL; /* TODO: Init this properly */
	
	accum->m_subscriberStorage = *_subStorage;
	
	
	
	
	
	/* 
									"123456789012345", 
									1, 
									2, 
									3, 
									4,
									5,
									6}; 
	accum->m_operatorStorage = {"EyalAlons MobilePhoneService", 
									34578,
									1,
									2,
									3,
									4,
									5,
									6};
									
									
									*/
									
/*	accum->m_subscriberStorage = {0};*/
/*	accum->m_operatorStorage = {0};		*/
	return accum;
}






void AccumulatorDestroy(Accumulator* _accum)
{
	if (!_accum)
	{
		return;
	}
	
	free(_accum);

	return;
}







Subscriber AccumulatorGetSubscriber(Accumulator* _accum)
{
	Subscriber sub;
	
	if (!_accum)
	{
		return sub;
	}
	
	return _accum->m_subscriberStorage;

}



int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _subscriber)
{
	if (!_accum || !_subscriber)
	{
		return 0;
	}
	
	
	_accum->m_subscriberStorage.m_outVoiceWithinOp += _subscriber->m_outVoiceWithinOp;
	_accum->m_subscriberStorage.m_inVoiceWithinOp += _subscriber->m_inVoiceWithinOp;
	_accum->m_subscriberStorage.m_outVoiceOutsideOp += _subscriber->m_outVoiceOutsideOp;
	_accum->m_subscriberStorage.m_inVoiceOutsideOp += _subscriber->m_inVoiceOutsideOp;
	_accum->m_subscriberStorage.m_outSmsWithinOp += _subscriber->m_outSmsWithinOp;
	_accum->m_subscriberStorage.m_inSmsWithinOp += _subscriber->m_inSmsWithinOp;
	_accum->m_subscriberStorage.m_outSmsOutsideOp += _subscriber->m_outSmsOutsideOp;
	_accum->m_subscriberStorage.m_inSmsOutsideOp += _subscriber->m_inSmsOutsideOp;
	_accum->m_subscriberStorage.m_downloadMB += _subscriber->m_downloadMB;
	_accum->m_subscriberStorage.m_uploadMB += _subscriber->m_uploadMB;
	
	return 1;
}














