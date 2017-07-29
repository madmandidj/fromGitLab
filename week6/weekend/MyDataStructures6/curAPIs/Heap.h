/*
Filename: 		Heap.h 
Description:	Contains Heap API given by Izik.
Created: 		18/07/17
Created by:		Eyal Alon
Last modified: 	19/07/17
Modified by:	Eyal Alon
COMMENTS:		Note: Vector index starts from 1, not 0
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
Desc:	Create heap from input vector (including heapify)	
In:		Vector pointer		
Out:	Heap pointer
Err: 	Returns NULL if vector pointer == NULL or heap memory allocation failed
*/
Heap*	HeapBuild(Vector* _vec); /* O(n) */
/*		
Desc:	Destroy input heap	
In:		Heap pointer		
Out:	Void
Err: 	If heap pointer == NULL, returns. Protected against double-destroy.
*/
void	HeapDestroy(Heap* _heap); /* O(n) */
/*
Desc:	Insert new value to Heap and bubble up to correct position	
In:		Heap pointer, integer data value
Out:	ERR_OK if succeed
Err: 	ERR_NOT_INITIALIZED 
*/
ADTErr	HeapInsert(Heap* _heap, int _data); /* O(log n) */
/*
Desc:	Retreive heap max value	
In:		Heap pointer, integer pointer for retreived value
Out:	ERR_OK / ERR_EMPTY_HEAP
Err: 	ERR_NOT_INITIALIZED
*/
ADTErr	HeapMax(Heap* _heap, int* _data);
/*
Desc:	Extract max value from heap, then heapify	
In:		Heap pointer, integer pointer for extracted value
Out:	ERR_OK / ERR_EMPTY_HEAP
Err: 	ERR_NOT_INITIALIZED
*/
ADTErr	HeapExtractMax(Heap* _heap, int* _data); /* O(log n) */
/*
Desc:	Retrieve number of items in heap	
In:		Heap pointer
Out:	size_t number of items
Err: 	If heap pointer == NULL, 0 returned
*/
size_t	HeapItemsNum(Heap* _heap);
/*
Desc:	Print heap items (from root to last leaf)	
In:		Heap pointer		
Out:	Void
Err: 	If heap pointer == NULL, return
*/
void	HeapPrint(Heap* _heap);

#endif /* #ifndef __HEAP_H__ */
