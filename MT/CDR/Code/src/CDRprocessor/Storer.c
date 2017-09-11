#include "Storer.c"
#include "HashMap.h"
#include "Transceiver.h"
#include "Logger.h"

#define	STORER_MAGIC 0x0C111111


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
	pthread_t			m_threadIDs;
	Subscriber* 		m_subscriberStorage;
	Operator* 			m_operatorStorage;
};

Storer* StorerCreate(Subscriber* _subStorage, Operator* _opStorage)
{
	if (!_subStorage || !_opStorage)
	{
		return NULL;
	}
	
	
}


















