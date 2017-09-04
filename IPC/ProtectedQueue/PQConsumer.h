#ifndef __PQCONSUMERS_H__
#define __PQCONSUMERS_H__

#define _GNU_SOURCE

#include "ProtectedQueue.h"

typedef struct Consumers Consumers;

Consumers* ConsumersCreate(size_t _numOfCons, Queue* _P2C, Queue* _C2P);

void ConsumersDelete(Consumers* _cons);	

int ConsumersRun(Consumers* _cons);

void ConsumersJoin(Consumers* _cons);








#endif /* #ifndef __PQCONSUMERS_H__ */
