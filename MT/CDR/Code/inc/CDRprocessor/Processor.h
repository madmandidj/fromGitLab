#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include "Record.h"
#include "Operator.h"
#include "Subscriber.h"

typedef struct Processor Processor;


/*
For Processor.c FILE:
---------------------
#include "Processor.h"



struct Processor
{
	unsigned int 		m_magicNum;
	unsigned int		m_numOfThreads;
	pthread_t*			m_threadIDs;
	Record*				m_record;
	Subscriber*			m_subscriber;
	Operator*			m_operator;
};
*/


Processor* 		ProcessorCreate(Transmitter*  tx, Storer* stot, .../*TODO: add parameters*/);

void			ProcessorDestroy(Processor* _processor);

int 			ProcessorRun(/*TODO: add parameters*/);

int 			ProcessorStop(/*TODO: add parameters*/);

Subscriber*		ProcessorFormatSubscriber(Record* _record);

Operator* 		ProcessorFormatOperator(Record* _record);		


#endif /* #ifndef __PROCESSOR_H__ */








