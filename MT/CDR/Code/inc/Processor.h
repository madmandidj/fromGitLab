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
	unsigned int m_magicNum;
	TODO: add relevant struct members
};
*/


Processor* 		ProcessorCreate(/*TODO: add parameters*/);

void			ProcessorDestroy(Processor* _processor);

Subscriber*		ProcessorSubscriber(/*TODO: add parameters*/);

Operator* 		ProcessorOperator(/*TODO: add parameters*/);



#endif /* #ifndef __PROCESSOR_H__ */








