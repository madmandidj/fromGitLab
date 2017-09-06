#ifndef __PQPRODUCERS_H__
#define __PQPRODUCERS_H__

#define _GNU_SOURCE

#include "PQMsgUtils.h"
#include "PCPQconfig.h"
#include "ProtectedQueue.h"
#include <stdlib.h>


typedef struct Producers Producers;


/* Producers* ProducersCreate(size_t _numOfProds, size_t _numOfMsgs, void** _msgArr, ProQueue* _P2C, ProQueue* _C2P); */

Producers* ProducersCreate(Params* _params, void** _msgArr, ProQueue* _P2C, ProQueue* _C2P, ReadMsg _readFunc);

void ProducersDelete(Producers* _prods);	


int ProducersRun(Producers* _prods);


void ProducersJoin(Producers* _prods);



#endif /* #ifndef __PQPRODUCERS_H__ */
