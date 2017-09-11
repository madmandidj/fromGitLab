#include "../../inc/Storer.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
/*#include "HashMap.h"*/
/*#include "Transceiver.h"*/
/*#include "Logger.h"*/

#define	STORER_MAGIC 0x0CC00001


/*struct Storer*/
/*{*/
/*	unsigned int		m_magicNum;*/
/*	pthread_t			m_threadIDs;*/
/*	HashMap* 			m_subscriberStorage;*/
/*	HashMap* 			m_operatorStorage;*/
/*};*/




struct Storer
{
	unsigned int		m_magicNum;
	pthread_t*			m_threadIDs;
	Subscriber 			m_subscriberStorage;
	Operator 			m_operatorStorage;
};




Storer* StorerCreate(Subscriber* _subStorage, Operator* _opStorage)
{
	Storer* storer;
	
	if (!_subStorage || !_opStorage)
	{
		return NULL;
	}
	
	storer = malloc(sizeof(Storer));
	if (!storer)
	{
		return NULL;
	}
	
	storer->m_magicNum = STORER_MAGIC;
	storer->m_threadIDs = NULL; /* TODO: Init this properly */
	
	storer->m_subscriberStorage = *_subStorage;
	
	
	
	
	
	/* 
									"123456789012345", 
									1, 
									2, 
									3, 
									4,
									5,
									6}; 
	storer->m_operatorStorage = {"EyalAlons MobilePhoneService", 
									34578,
									1,
									2,
									3,
									4,
									5,
									6};
									
									
									*/
									
/*	storer->m_subscriberStorage = {0};*/
/*	storer->m_operatorStorage = {0};		*/
	return storer;
}






void StorerDestroy(Storer* _storer)
{
	if (!_storer)
	{
		return;
	}
	
	free(_storer);

	return;
}







Subscriber StorerGetSubscriber(Storer* _storer)
{
	Subscriber sub;
	
	if (!_storer)
	{
		return sub;
	}
	
	return _storer->m_subscriberStorage;

}



int StorerUpdateSubscriber(Storer* _storer, Subscriber* _subscriber)
{
	if (!_storer || !_subscriber)
	{
		return 0;
	}
	
	
	_storer->m_subscriberStorage.m_outVoiceWithinOp += _subscriber->m_outVoiceWithinOp;
	_storer->m_subscriberStorage.m_inVoiceWithinOp += _subscriber->m_inVoiceWithinOp;
	_storer->m_subscriberStorage.m_outVoiceOutsideOp += _subscriber->m_outVoiceOutsideOp;
	_storer->m_subscriberStorage.m_inVoiceOutsideOp += _subscriber->m_inVoiceOutsideOp;
	_storer->m_subscriberStorage.m_outSmsWithinOp += _subscriber->m_outSmsWithinOp;
	_storer->m_subscriberStorage.m_inSmsWithinOp += _subscriber->m_inSmsWithinOp;
	_storer->m_subscriberStorage.m_outSmsOutsideOp += _subscriber->m_outSmsOutsideOp;
	_storer->m_subscriberStorage.m_inSmsOutsideOp += _subscriber->m_inSmsOutsideOp;
	_storer->m_subscriberStorage.m_downloadMB += _subscriber->m_downloadMB;
	_storer->m_subscriberStorage.m_uploadMB += _subscriber->m_uploadMB;
	
	return 1;
}














