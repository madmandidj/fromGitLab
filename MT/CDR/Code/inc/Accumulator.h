#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "./ADTs/Operator.h"
#include "./ADTs/Subscriber.h"

typedef struct Accumulator Accumulator;


Accumulator* AccumulatorCreate(Subscriber* _subStorage, Operator* _opStorage);


void AccumulatorDestroy(Accumulator* _accum);


Subscriber AccumulatorGetSubscriber(Accumulator* _accum);


Operator* AccumulatorGetOperator(Accumulator* _accum);


int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _subscriber);


int AccumulatorUpdateOperator(Accumulator* _accum, Operator* _operator);


/*
AccumulatorCreateThreads();
AccumulatorDestroyThreads();
*/



#endif /* #ifndef __ACCUMULATOR_H__ */







