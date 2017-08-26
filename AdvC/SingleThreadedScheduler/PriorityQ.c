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
	if (!_pq)
	{
		return NULL;
	}
	return HeapDestroy(_pq);
}


PQResult PQInsert(PQ* _pq, void* _element)
{
	PQResult err;	
	
	if (!_pq)
	{
		err = PQ_NOT_INITIALIZED; 
	}
	else
	{
		err = HeapInsert(_pq, _element);
		switch (err)
		{
			case HEAP_SUCCESS:
				return PQ_SUCCESS;
				break;
			
			case HEAP_NOT_INITIALIZED:
				return PQ_NOT_INITIALIZED;
				break;
			
			case HEAP_REALLOCATION_FAILED:
				return PQ_REALLOCATION_FAILED;
				break;
			
			case HEAP_INV_ARG:
				return PQ_INV_ARG;
				break;
		}	
	}
	
	return err;
}



void* PQExtract(PQ* _pq)
{
	if (!_pq)
	{
		return NULL;
	}
	
	return HeapExtract(_pq);
}



size_t PQSize(const PQ* _pq)
{
	if (!_pq)
	{
		return 0;
	}
	
	return HeapSize(_pq);
}



const void*	PQPeek(const PQ* _pq)
{
	if (!_pq)
	{
		return NULL;
	}
	
	return HeapPeek(_pq);
}


