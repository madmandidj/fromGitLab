#ifndef __PQPRODUCERS_H__
#define __PQPRODUCERS_H__

#define _GNU_SOURCE

/* #include "ProtectedQueue.h" */
#include "../inc/ProtectedQueue.h"
#include <stdlib.h>


typedef struct Producers Producers;


/* typedef void (*ReadMsg)(void* _msg, char* _callerName, char* _comMode); */


Producers* ProducersCreate(size_t _numOfProds, size_t _numOfMsgs, void** _msgArr, ProQueue* _P2C, ProQueue* _C2P);


void ProducersDelete(Producers* _prods);	


int ProducersRun(Producers* _prods);


void ProducersJoin(Producers* _prods);








#endif /* #ifndef __PQPRODUCERS_H__ */
