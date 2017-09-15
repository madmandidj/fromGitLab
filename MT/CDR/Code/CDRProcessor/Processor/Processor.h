#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include "../../CDRDataTypes/Record.h"
#include "../../CDRDataTypes/Operator.h"
#include "../../CDRDataTypes/Subscriber.h"
#include "../Accumulator/Accumulator.h"
#include "../../Comms/Receiver/Receiver.h"

typedef struct Processor Processor;

Processor* 		ProcessorCreate(Accumulator* _accum, Receiver* _rcvr, unsigned int _numOfThreads);

void			ProcessorDestroy(Processor* _processor);

int 			ProcessorRun(Processor* _proc);

int 			ProcessorStop(/*TODO: add parameters*/);


#endif /* #ifndef __PROCESSOR_H__ */








