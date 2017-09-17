#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "../../CDRDataTypes/Operator.h"
#include "../../CDRDataTypes/Subscriber.h"

typedef struct Accumulator Accumulator;


Accumulator* AccumulatorCreate();


void AccumulatorDestroy(Accumulator* _accum); 


int AccumulatorGetSubscriber(Accumulator* _accum, char* _key, Subscriber** _subFound);


int AccumulatorGetOperator(Accumulator* _accum, char* _key, Operator** _operFound);


int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _sub);


int AccumulatorUpdateOperator(Accumulator* _accum, Operator* _oper);


#endif /* #ifndef __ACCUMULATOR_H__ */







