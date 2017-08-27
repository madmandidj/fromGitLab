#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__


#include "../../../inc/Heap.h"

/*
TODO: Add documentation for this module and functions
*/


typedef enum PQResult 
{
	PQ_SUCCESS = 0,
	PQ_NOT_INITIALIZED,
	PQ_REALLOCATION_FAILED,
	PQ_INV_ARG
}PQResult;



/*
TODO:
change this to: typedef PQ PQ
to avoid exposing implementation (Heap) to user
*/
typedef Heap PQ;

PQ* 			PQBuild(Vector* _vector, LessThanComparator _pfLess);

Vector* 		PQDestroy(PQ** _pq);

PQResult 		PQInsert(PQ* _pq, void* _element);

const void*		PQPeek(const PQ* _pq);

void* 			PQExtract(PQ* _pq);

size_t			PQSize(const PQ* _pq);


#endif /* __PRIORITY_QUEUE_H__ */

