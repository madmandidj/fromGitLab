#ifndef __PQCONSUMERS_H__
#define __PQCONSUMERS_H__

#define _GNU_SOURCE
#define EOW_SEM "eowSem"

#include "PQMsgUtils.h"
#include "PCPQconfig.h"
#include "ProtectedQueue.h"
#include <stdlib.h>

typedef struct Consumers Consumers;


/*Consumers* ConsumersCreate(size_t _numOfCons, ProQueue* _P2C, ProQueue* _C2P, ReadMsg _readFunc);*/
Consumers* ConsumersCreate(Params* _params, ProQueue* _P2C, ProQueue* _C2P, ReadMsg _readFunc);

void ConsumersDelete(Consumers* _cons);	


int ConsumersRun(Consumers* _cons);


void ConsumersJoin(Consumers* _cons);








#endif /* #ifndef __PQCONSUMERS_H__ */
