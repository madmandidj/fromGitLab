#ifndef __STORER_H__
#define __STORER_H__

#include "Operator.h"
#include "Subscriber.h"

typedef struct Storer Storer;

/*
FOR Storer.c FILE:
--------------------
#include "HashMap.h"
#include "Logger.h"



struct Storer
{
	unsigned int		m_magicNum;
	pthread_t			m_threadIDs;
	HashMap* 			m_Storage;
};
*/


Storer* StorerCreate(/*TODO: add parameters*/);

void	StorerDestroy();

/*TODO: Add return*/ StorerCreateThreads(/*TODO: add parameters*/);

/*TODO: Add return*/ StorerDestroyThreads(/*TODO: add parameters*/);

/*TODO: Add return*/ StorerGetSubscriber(/*TODO: add parameters*/);

/*TODO: Add return*/ StorerGetOperator(/*TODO: add parameters*/);

/*TODO: Add return*/ StorerUpdateSubscriber(/*TODO: add parameters*/);

/*TODO: Add return*/ StorerUpdateOperator(/*TODO: add parameters*/);






#endif /* #ifndef __STORER_H__ */







