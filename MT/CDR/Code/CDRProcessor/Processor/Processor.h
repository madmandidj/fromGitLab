#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include "./ADTs/Record.h"
#include "./ADTs/Operator.h"
#include "./ADTs/Subscriber.h"

typedef struct Processor Processor;

Processor* 		ProcessorCreate(unsigned int _numOfThreads);

void			ProcessorDestroy(Processor* _processor);

int 			ProcessorRun(/*TODO: add parameters*/);

int 			ProcessorStop(/*TODO: add parameters*/);


#endif /* #ifndef __PROCESSOR_H__ */








