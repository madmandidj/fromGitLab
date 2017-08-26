#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__


#include "../../../inc/Heap.h"

typedef enum PQResult 
{
	PQ_SUCCESS = 0,
	PQ_NOT_INITIALIZED,
	PQ_REALLOCATION_FAILED,
	PQ_INV_ARG
}PQResult;

typedef Heap PQ;

//typedef int	(*LessThanComparator)(const void *_left, const void *_right);


PQ* 			PQBuild(Vector* _vector, LessThanComparator _pfLess);

Vector* 		PQDestroy(PQ** _pq);

PQResult 		PQInsert(PQ* _pq, void* _element);

const void*		PQPeek(const PQ* _pq);

void* 			PQExtract(PQ* _pq);

size_t			PQSize(const PQ* _pq);


#endif /* __PRIORITY_QUEUE_H__ */

