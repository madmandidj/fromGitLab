#include "PriorityQ.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>


PQ* PQBuild(Vector* _vector, LessThanComparator _pfLess)
{
	PQ* pq;
	if (!(pq = HeapBuild(_vector, _pfLess)))
	{
		return NULL;
	}
	
	return pq;
}



Vector* PQDestroy(PQ** _pq)
{
	return HeapDestroy(_pq);
}











