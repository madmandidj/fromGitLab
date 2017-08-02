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
	NULL == _ptr ? ERR_NOT_INITIALIZED : ERR_OK;
}
static void Swap(int* num1, int* num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}

static void Heapify(Heap* _heap, int _index)
{
	int leftInd;
	int leftVal;
	int rightInd;
	int rightVal;
	int largestInd;
	int largestVal;
	int swapVal1;
	int swapVal2;
	if (_index > _heap->m_heapSize)
	{
		return;
	}
	leftInd = 2 * _index;
	rightInd = 2 * _index + 1;
	largestInd = _index;
	VectorGet(_heap->m_vec, leftInd, &leftVal);
	VectorGet(_heap->m_vec, rightInd, &rightVal);
	VectorGet(_heap->m_vec, largestInd, &largestVal);
	if (leftInd <= _heap->m_heapSize && leftVal > largestVal)
	{
		largestInd = leftInd;
	}
	if (rightInd <= _heap->m_heapSize && rightVal > largestVal)
	{
		largestInd = rightInd;
	}
	if (largestInd != _index)
	{
		VectorGet(_heap->m_vec, _index, &swapVal1);
		VectorGet(_heap->m_vec, largestInd, &swapVal2);
		VectorSet(_heap->m_vec, largestInd, swapVal1);
		VectorSet(_heap->m_vec, _index, swapVal2);
	}
	else
	{
		return;
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
	if (heap == NULL)
	{
		return NULL;
	}
	//errResult = CheckPtrNotNull((void*)heap);
	//if (errResult != ERR_OK)
	//{
	//	return NULL;
	//}
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

