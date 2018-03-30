#include "../../inc/Heap.h"
#include <stdlib.h>

#define MIN_HEAP_CAPACITY 10
#define VEC_BLOCK_SIZE 100

struct Heap
{
	Vector* 		m_vector;
	IsLeftBigger 	m_isLeftBiggerFunc;
};

/*
STATIC FUNCTIONS
*/
static void Heapify(Heap* _heap, size_t _index, size_t _numOfItems)
{
	void* fatherPtr = NULL;
	void* leftSonPtr = NULL;
	void* rightSonPtr = NULL;
	void* biggestSonPtr = NULL;
	size_t leftSonIndex = (_index * 2) + 1;
	size_t rightSonIndex = (_index * 2) + 2;
	size_t biggestSonIndex;
	if (_index >= (_numOfItems/2))
	{
		return;
	}
	if (rightSonIndex < _numOfItems)
	{
		VectorGet(_heap->m_vector, rightSonIndex, &rightSonPtr);
	}
	VectorGet(_heap->m_vector, leftSonIndex, &leftSonPtr);	
	VectorGet(_heap->m_vector, _index, &fatherPtr);
	if (!rightSonPtr)
	{
		biggestSonPtr = leftSonPtr;
		biggestSonIndex = leftSonIndex;
	}
	else
	{
		if (_heap->m_isLeftBiggerFunc(leftSonPtr, rightSonPtr))
		{
			biggestSonPtr = leftSonPtr;
			biggestSonIndex = leftSonIndex;
		}
		else
		{
			biggestSonPtr = rightSonPtr;
			biggestSonIndex = rightSonIndex;
		}
	}
	if (_heap->m_isLeftBiggerFunc(biggestSonPtr, fatherPtr))
	{
		VectorSet(_heap->m_vector, biggestSonIndex, fatherPtr);
		VectorSet(_heap->m_vector, _index, biggestSonPtr);
		Heapify(_heap, (_index * 2) + 1, _numOfItems);
		Heapify(_heap, (_index * 2) + 2, _numOfItems);
	}
	return;
}

static void BubbleUp(Heap* _heap, size_t _index)
{
	void* sonPtr = NULL;
	void* fatherPtr = NULL;
	size_t fatherIndex;
		
	if (_index == 0 || _index >= HeapItemsNum(_heap))
	{
		return;
	}
	fatherIndex = (_index % 2 == 1) ? (_index-1)/2 : (_index-2)/2;
	VectorGet(_heap->m_vector, _index, &sonPtr);	
	VectorGet(_heap->m_vector, fatherIndex, &fatherPtr);
	if (_heap->m_isLeftBiggerFunc(sonPtr, fatherPtr))
	{
		VectorSet(_heap->m_vector, _index, fatherPtr);
		VectorSet(_heap->m_vector, fatherIndex, sonPtr);
		BubbleUp(_heap, fatherIndex);		
	}
}



/*
API
*/
Heap* HeapBuild(Vector* _vector, IsLeftBigger _isLeftBigger)
{
	size_t numOfItems;
	Heap* heap;
	size_t index;
	void* element;
	
	if (!_vector || !_isLeftBigger)
	{
		return NULL;
	}
	numOfItems = VectorItemsNum(_vector);
	if (0 == numOfItems)
	{
		return NULL;
	}
	if (!(heap = malloc(sizeof(Heap))))
	{
		return NULL;
	}
	if (!(heap->m_vector = VectorCreate(numOfItems + MIN_HEAP_CAPACITY, VEC_BLOCK_SIZE))) /*TODO: add element destroy and isleftbig to vector*/
	{
		free(heap);
		return NULL;
	}
	heap->m_isLeftBiggerFunc = _isLeftBigger;
	for (index = 0; index < numOfItems; ++index)
	{
		VectorGet(_vector, index, &element);
		VectorAppend(heap->m_vector, element);
	}
	if (1 == numOfItems)
	{
		return heap;
	}
	for (index = (numOfItems/2)-1; index > 0; --index)
	{
		Heapify(heap, index, numOfItems);
	}
	Heapify(heap, 0, numOfItems);
	return heap;
}

void HeapDestroy(Heap* _heap, ElementFunc _elementDestroyFunc)
{
	if (!_heap)
	{
		return;
	}
	VectorDestroy(_heap->m_vector, _elementDestroyFunc);
	free(_heap);
}

ADTErr HeapInsert(Heap* _heap, void* _element)
{
	if (!_heap || !_element)
	{
		return ERR_INVARG;
	}
	VectorAppend(_heap->m_vector, _element);
	BubbleUp(_heap, HeapItemsNum(_heap) - 1);
	return ERR_OK;
}


ADTErr HeapMax(Heap* _heap, void** _maxElement)
{
	if (!_heap || !_maxElement)
	{
		return ERR_INVARG;
	}
	VectorGet(_heap->m_vector, 0, _maxElement);
	return ERR_OK;
}

ADTErr HeapExtractMax(Heap* _heap, void** _maxElement)
{
	void* lastElement;
	if (!_heap || !_maxElement)
	{
		return ERR_INVARG;
	}
	VectorGet(_heap->m_vector, 0, _maxElement);
	VectorRemove(_heap->m_vector, &lastElement);
	VectorSet(_heap->m_vector, 0, lastElement);
	Heapify(_heap, 0, VectorItemsNum(_heap->m_vector));
	return ERR_OK;
}






size_t HeapItemsNum(Heap* _heap)
{
	if (!_heap)
	{
		return 0;
	}
	return VectorItemsNum(_heap->m_vector);
}





void HeapPrint(Heap* _heap, ElementFunc _printFunc)
{
	size_t numOfItems;
	void* element;
	size_t index;
	
	if (!_heap)
	{
		return;
	}
	numOfItems = VectorItemsNum(_heap->m_vector);
	
	for (index = 0 ; index < numOfItems; ++index)
	{
		VectorGet(_heap->m_vector, index, &element);
		_printFunc(element);
	}
}



