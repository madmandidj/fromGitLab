/*
Filename: 		Heap.c 
Description:	Implementation of heap API given by Izik.
Created: 		18/07/17
Created by:		Eyal Alon
Last modified: 	29/07/17
Modified by:	Eyal Alon
COMMENTS:		Note: Vector index starts from 1, not 0
*/
#define MAGIC_NUM 17
#include <stdio.h>
#include "Heap.h"

/*************** 
STATIC FUNCTIONS 
***************/
static void SwapVecVals(Heap* _heap, int _index, int _largestInd)
{
	int swapVal1;
	int swapVal2;
	VectorGet(_heap->m_vec, _index, &swapVal1);
	VectorGet(_heap->m_vec, _largestInd, &swapVal2);
	VectorSet(_heap->m_vec, _largestInd, swapVal1);
	VectorSet(_heap->m_vec, _index, swapVal2);
	return;
}

static void BothSonsBiggerCheckMax(int _val1, int _val2, int _val1Ind, int _val2Ind, int* _largestInd)
{
	if (NULL == _largestInd)
	{
		return;
	}
	if (_val1 > _val2)
	{
		*_largestInd = _val1Ind;
	}
	else if (_val2 >= _val1)
	{
		*_largestInd = _val2Ind;
	}
	return;
}

static void InitHeapifyIndexes(int _index, int* _leftInd, int* _rightInd, int* _largestInd)
{
	if (NULL == _largestInd)
	{
		return;
	}
	*_leftInd = 2 * _index;
	*_rightInd = 2 * _index + 1;
	*_largestInd = _index;
	return;
}

static void CheckSonIsValidAndBigger(Heap* _heap, int _val1, int _largestVal, int _val1Ind, int* _largestInd)
{
	if (_val1Ind <= _heap->m_heapSize && _val1 > _largestVal)
	{
		*_largestInd = _val1Ind;
	}
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
	if (NULL == _heap || _index > _heap->m_heapSize || _index <= 0)
	{
		return;
	}
	InitHeapifyIndexes(_index, &leftInd, &rightInd, &largestInd);
	if (leftInd <= _heap->m_heapSize &&  rightInd <= _heap->m_heapSize)
	{
		VectorGet(_heap->m_vec, leftInd, &leftVal);
		VectorGet(_heap->m_vec, rightInd, &rightVal);
		VectorGet(_heap->m_vec, largestInd, &largestVal);
		if (leftVal > largestVal && rightVal > largestVal)
		{
			BothSonsBiggerCheckMax(leftVal, rightVal, leftInd, rightInd, &largestInd);
		}
	}
	else if (leftInd <= _heap->m_heapSize)
	{
		VectorGet(_heap->m_vec, leftInd, &leftVal);
		VectorGet(_heap->m_vec, largestInd, &largestVal);
		CheckSonIsValidAndBigger(_heap, leftVal, largestVal, leftInd, &largestInd);
	}
	else if (rightInd <= _heap->m_heapSize)
	{
		VectorGet(_heap->m_vec, rightInd, &rightVal);
		VectorGet(_heap->m_vec, largestInd, &largestVal);
		CheckSonIsValidAndBigger(_heap, rightVal, largestVal, rightInd, &largestInd);
	}
	if (largestInd != _index)
	{
		SwapVecVals(_heap, _index, largestInd);
		Heapify(_heap, largestInd);
	}
	else
	{
		return;
	}
}



/************ 
API FUNCTIONS 
************/
Heap* HeapBuild(Vector* _vec)
{
	Heap* heap;
	size_t nItems;
	int curIndex;
	if (NULL == _vec)
	{
		return NULL;
	}
	heap = malloc(sizeof(Heap));
	if (NULL == heap)
	{
		return NULL;
	}
	heap->m_vec = _vec;
	VectorItemsNum(_vec, &nItems);
	heap->m_heapSize = nItems;
	heap->m_magicNum = MAGIC_NUM;
	/* Find last father index  TODO: Remove this, is redundant*/
	curIndex = nItems / 2;
	/* Heapify all fathers */
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
		_heap->m_magicNum = 71;
		free(_heap);
	}
	return;
}

void HeapPrint(Heap* _heap)
{
	int index;
	int val;
	if (NULL == _heap)
	{
		return;
	}
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
	if (NULL == _heap || NULL == _data)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else if (_heap->m_heapSize > 0)
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


ADTErr HeapInsert(Heap* _heap, int _data)
{
	ADTErr errResult;
	int curInd;
	int fatherInd;
	int fatherVal;
	if (NULL == _heap)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		VectorAdd(_heap->m_vec, _data);
		_heap->m_heapSize = _heap->m_heapSize + 1;
		curInd = _heap->m_heapSize;
		fatherInd = curInd / 2;
		VectorGet(_heap->m_vec, fatherInd, &fatherVal);
		while (_data > fatherVal && fatherInd >= 1)
		{
			if (1 == fatherInd)
			{
				SwapVecVals(_heap, curInd, fatherInd);
				break;
			}
			else
			{
				SwapVecVals(_heap, curInd, fatherInd);
				curInd = fatherInd;
				fatherInd = fatherInd / 2;
				VectorGet(_heap->m_vec, fatherInd, &fatherVal);
			}
		}
		errResult = ERR_OK;
	}
	return errResult;
}

ADTErr HeapExtractMax(Heap* _heap, int* _data)
{
	ADTErr errResult;
	int curInd;
	int lastVal;
	if (NULL == _heap || NULL == _data)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		if (_heap->m_heapSize == 0)
		{
			errResult = ERR_EMPTY_HEAP;
		}
		else
		{
			VectorGet(_heap->m_vec, 1, _data);
			VectorGet(_heap->m_vec, _heap->m_heapSize, &lastVal);
			VectorSet(_heap->m_vec, 1, lastVal);
			VectorDelete(_heap->m_vec, &lastVal);
			--(_heap->m_heapSize);
			for (curInd = _heap->m_heapSize/2; curInd >= 1; --curInd)
			{
				Heapify(_heap, curInd);
			}
			errResult = ERR_OK;
		}
	}
	return errResult;
}
