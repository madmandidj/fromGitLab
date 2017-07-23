/*
Filename: 		Heap.c 
Description:	Implementation of heap API given by Izik.
Created: 		18/07/17
Created by:		Eyal Alon
Last modified: 	18/07/17
Modified by:	Eyal Alon
COMMENTS:		Note: Vector index starts from 1, not 0
*/

#include <stdio.h>
#include "Heap.h"

static ADTErr CheckPtrNotNull(void* _ptr)
{
	ADTErr result = ERR_OK;
	if (NULL == _ptr)
	{
		result = ERR_NOT_INITIALIZED;
	}
	// NULL == _ptr ? return ERR_NOT_INITIALIZED : return ERR_OK;
	return result;
}
static void Swap(int* num1, int* num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}

// static void Heapify(Heap* _heap, int _index)
// {
// 	int leftInd;
// 	int leftVal;
// 	int rightInd;
// 	int rightVal;
// 	int largestInd;
// 	int largestVal;
// 	int swapVal1;
// 	int swapVal2;
// 	if (_index > _heap->m_heapSize)
// 	{
// 		return;
// 	}
// 	leftInd = 2 * _index;
// 	rightInd = 2 * _index + 1;
// 	largestInd = _index;
// 	VectorGet(_heap->m_vec, leftInd, &leftVal);
// 	VectorGet(_heap->m_vec, rightInd, &rightVal);
// 	VectorGet(_heap->m_vec, largestInd, &largestVal);
// 	// if (leftInd <= _heap->m_heapSize && leftVal > largestVal && rightInd <= _heap->m_heapSize && rightVal > largestVal)
// 	// {
// 	// 	if (leftVal > rightVal)
// 	// 	{
// 	// 		largestInd = rightVal;
// 	// 	}
// 	// 	if (rightVal > leftVal)
// 	// 	{
// 	// 		largestInd = leftInd;
// 	// 	}
		
// 	// 	VectorGet(_heap->m_vec, _index, &swapVal1);
// 	// 	VectorGet(_heap->m_vec, largestInd, &swapVal2);
// 	// 	VectorSet(_heap->m_vec, largestInd, swapVal1);
// 	// 	VectorSet(_heap->m_vec, _index, swapVal2);
// 	// 	Heapify(_heap, largestInd);
// 	// }
// 	if (leftInd <= _heap->m_heapSize && leftVal > largestVal)
// 	{
// 		largestInd = leftInd;
// 	}
// 	if (rightInd <= _heap->m_heapSize && rightVal > largestVal)
// 	{
// 		largestInd = rightInd;
// 	}
// 	if (largestInd != _index)
// 	{
// 		VectorGet(_heap->m_vec, _index, &swapVal1);
// 		VectorGet(_heap->m_vec, largestInd, &swapVal2);
// 		VectorSet(_heap->m_vec, largestInd, swapVal1);
// 		VectorSet(_heap->m_vec, _index, swapVal2);
// 		Heapify(_heap, largestInd);
// 		// Heapify(_heap, _index);
// 	}
// 	else
// 	{
// 		return;
// 	}
// }


static void Heapify(Heap* _heap, int _index)
{
	int leftInd;
	int leftVal;
	int rightInd;
	int rightVal;
	int largestInd;
	int largestVal;
	int curInd;
	int curVal;
	int swapVal1;
	int swapVal2;
	curInd =_index;
	// leftInd = 2 * _index;
	// rightInd = 2 * _index + 1;
	// VectorGet(_heap->m_vec, leftInd, &leftVal);
	// VectorGet(_heap->m_vec, rightInd, &rightVal);
	// VectorGet(_heap->m_vec, curIndex, &curVal);
	leftInd = 2 * _index;
	rightInd = 2 * _index + 1;
	while (curInd <= _heap->m_heapSize)
	{
		VectorGet(_heap->m_vec, leftInd, &leftVal);
		VectorGet(_heap->m_vec, rightInd, &rightVal);
		VectorGet(_heap->m_vec, curInd, &curVal);
		if (leftInd <= _heap->m_heapSize && leftVal > curVal)
		{
			swapVal1 = curVal;
			VectorSet(_heap->m_vec, curInd, leftVal);
			VectorSet(_heap->m_vec, leftInd, swapVal1);
			curVal = leftVal;
		}
		if (rightInd <= _heap->m_heapSize && rightInd > curVal)
		{
			swapVal1 = curVal;
			VectorSet(_heap->m_vec, curInd, rightVal);
			VectorSet(_heap->m_vec, rightInd, swapVal1);
		}
		curInd = 2 * curInd;
	}
}

Heap* HeapBuild(Vector* _vec)
{
	ADTErr errResult;
	Heap* heap;
	int nItems;
	int curIndex;
	errResult = CheckPtrNotNull((void*)_vec);
	if (errResult != ERR_OK)
	{
		return NULL;
	}
	heap = malloc(sizeof(Heap));
	errResult = CheckPtrNotNull((void*)heap);
	if (errResult != ERR_OK)
	{
		return NULL;
	}
	heap->m_vec = _vec;
	VectorItemsNum(_vec, &nItems);
	heap->m_heapSize = nItems;
	heap->m_magicNum = MAGIC_NUM;
	curIndex = nItems / 2;
	for (curIndex = nItems / 2; curIndex >= 1; --curIndex)
	{
		Heapify(heap, curIndex);
	}
	return heap;
}

void HeapDestroy(Heap* _heap)
{
	if (NULL != _heap && _heap->m_magicNum == MAGIC_NUM)
	{
		free(_heap);
	}
	return;
}

void HeapPrint(Heap* _heap)
{
	int index;
	int val;
	for (index = 1; index <= _heap->m_heapSize; ++index)
	{
		VectorGet(_heap->m_vec, index, &val);
		printf("%d\n", val);
	}
	return;
}

size_t HeapItemsNum(Heap* _heap)
{
	if (NULL == _heap)
	{
		return 0;
	}
	return _heap->m_heapSize;
}

ADTErr	HeapMax(Heap* _heap, int* _data)
{
	ADTErr errResult;
	errResult = CheckPtrNotNull((void*)_heap);
	if (errResult != ERR_OK)
	{
		return errResult;
	}
	if (_heap->m_heapSize > 0)
	{
		VectorGet(_heap->m_vec, 1, _data);
		errResult = ERR_OK;
	}
	else
	{
		errResult = ERR_EMPTY_HEAP;
	}
	return errResult;
}

/*
ADTErr HeapInsert(Heap* _heap, int _data)
{
	add element to end of list and set to cur element
	increment amount of items in heap
	while (curelement data > curFather data && cur element index > 1)
	{
		swap between element and cur father
	}
	return errResult;
}

ADTErr HeapExtractMax(Heap* _heap, int* _data)
{
	get max value and place in data
	take last value and place in first index
	vector delete and decrement heap size
	heapify
	return errResult;
}
*/
