#ifndef __STORER_H__
#define __STORER_H__

#include "Operator.h"
#include "Subscriber.h"

typedef struct Storer Storer;

/*
FOR Storer.c FILE:
--------------------
#include "HashMap.h"
#include "Transceiver.h"
#include "Logger.h"



struct Storer
{
	unsigned int		m_magicNum;
	pthread_t			m_threadIDs;
	HashMap* 			m_subscriberStorage;
	HashMap* 			m_operatorStorage;
};
*/


Storer* 	StorerCreate(Subscriber* _subStorage, Operator* _opStorage);

void		StorerDestroy(Storer* _storer);

Subscriber* StorerGetSubscriber(Storer* _storer);

Operator*	StorerGetOperator(Storer* _storer);

int 		StorerUpdateSubscriber(Storer* _storer, Subscriber* _subscriber);

int 		StorerUpdateOperator(Storer* _storer, Operator* _operator);

/*
StorerCreateThreads();
StorerDestroyThreads();
*/



#endif /* #ifndef __STORER_H__ */







