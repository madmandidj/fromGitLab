/*
Filename: 		Heap.h 
Description:	Contains Heap API given by Izik.
Created: 		18/07/17
Created by:		Eyal Alon
Last modified: 	18/07/17
Modified by:	Eyal Alon
*/

#ifndef __HEAP_H__
#define __HEAP_H__
#define MAGIC_NUM 17
#include "ADTDefs.h"
#include <stdlib.h>
#include "vector.h"


typedef struct Heap Heap;

struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	int m_magicNum;
};

/*
Desc:		
In:				
Out:	
Err: 	
*/
Heap*	HeapBuild(Vector* _vec); /* O(n) */
void	HeapDestroy(Heap* _heap); /* O(n) */
ADTErr	HeapInsert(Heap* _heap, int _data); /* O(log n) */
ADTErr	HeapMax(Heap* _heap, int* _data);
ADTErr	HeapExtractMax(Heap* _heap, int* _data); /* O(log n) */
size_t	HeapItemsNum(Heap* _heap);
void	HeapPrint(Heap* _heap);

#endif /* #ifndef __HEAP_H__ */
