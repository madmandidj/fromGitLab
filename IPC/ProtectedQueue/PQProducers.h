#ifndef __PQPRODUCERS_H__
#define __PQPRODUCERS_H__

#define _GNU_SOURCE

#include "ProtectedQueue.h"

typedef struct Producers Producers;

Producers* CreateProducers(size_t _numOfProds, size_t _numOfMsgs, void** _msgArr, Queue* _P2C, Queue* _C2P);

void DeleteProducers(Producer* _prods);	

/*
void* ProducersRoutine(Producer* _prods);
*/

void ProducersRun(Producer* _prods);

void ProducersJoin(Producer* _prods);








#endif /* #ifndef __PQPRODUCERS_H__ */
