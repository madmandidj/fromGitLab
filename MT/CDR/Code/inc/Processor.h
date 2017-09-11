#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include "Record.h"
#include "Operator.h"
#include "Subscriber.h"

typedef struct Processor Processor;


/*
For Processor.c FILE:
---------------------
TODO: add relevant includes


struct Processor
{
	unsigned int 		m_magicNum;
	unsigned int		m_numOfThreads;
	pthread_t*			m_threadIDs;
	Subscriber*			m_subscriber;
	Operator*			m_operator;
	TODO: add relevant struct members
};
*/


Processor* 		ProcessorCreate(/*TODO: add parameters*/);

void			ProcessorDestroy(Processor* _processor);

/*TODO: add return*/		ProcessorCreateThreads(/*TODO: add parameters*/);

/*TODO: add return*/		ProcessorDestroyThreads(/*TODO: add parameters*/);

Subscriber*		ProcessorFormatSubscriber(/*TODO: add parameters*/);

Operator* 		ProcessorFormatOperator(/*TODO: add parameters*/);		


#endif /* #ifndef __PROCESSOR_H__ */








