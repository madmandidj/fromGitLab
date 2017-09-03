#ifndef __PQPRODUCERS_H__
#define __PQPRODUCERS_H__

#define _GNU_SOURCE

#include "ProtectedQueue.h"

typedef struct Producers Producers;

Producers* ProducersCreate(size_t _numOfProds, size_t _numOfMsgs, void** _msgArr, Queue* _P2C, Queue* _C2P);

void ProducersDelete(Producers* _prods);	

int ProducersRun(Producers* _prods);

void ProducersJoin(Producers* _prods);








#endif /* #ifndef __PQPRODUCERS_H__ */
