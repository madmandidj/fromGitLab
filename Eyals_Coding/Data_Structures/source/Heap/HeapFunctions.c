#include "../../inc/Heap.h"
#include "../../inc/ADTErr.h"
#include "../../inc/VectorFunctions.h"
#include <stdlib.h>



int IsHeapSortedAscending(Heap* _heap, Vector* _sortedVector)
{
	Vector* vector;
	size_t index;
	size_t numOfItems;
	int* curElem;
	
	if (!_heap)
	{
		return 0;
	}
	
	numOfItems = HeapItemsNum(_heap);
	if (1 >= numOfItems)
	{
		return 1;
	}
	vector = VectorCreate(numOfItems, numOfItems/2);
	for (index = 0; index < numOfItems; ++index)
	{
		HeapExtractMax(_heap, (void**)&curElem);
		VectorAppend(vector, (void*)curElem);
	}
	FlipVector(vector);
	return AreVectorsEqual(vector, _sortedVector);
}








