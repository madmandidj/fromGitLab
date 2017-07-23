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

/***** STATIC FUNCTIONS *****/
static ADTErr CheckPtrNotNull(void* _ptr)
{
	ADTErr result = ERR_OK;
	NULL == _ptr ? result = ERR_NOT_INITIALIZED : (result = ERR_OK);
	return result;
}

// static void SwapVecVals(Heap* _heap, int _index, int _largestInd, int* _swapVal1, int* _swapVal2)
// {
// 	if (NULL == _swapVal1 || NULL == _swapVal2)
// 	{
// 		return;
// 	}
// 		VectorGet(_heap->m_vec, _index, _swapVal1);
// 		VectorGet(_heap->m_vec, _largestInd, _swapVal2);
// 		VectorSet(_heap->m_vec, _largestInd, *_swapVal1);
// 		VectorSet(_heap->m_vec, _index, *_swapVal2);
// 		return;
// }

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

static void OneSonBiggerCheckMax(int _val1, int _val2, int _fatherVal, int _val1Ind, int _val2Ind, int* _largestInd)
{
	if (NULL == _largestInd)
	{
		return;
	}
	if (_val1 >= _fatherVal)
	{
		*_largestInd = _val1Ind;
	}
	else if (_val2 >= _fatherVal)
	{
		*_largestInd = _val2Ind;
	}
	return;
}

static void InitHeapifyIndexes(int _index, int* _leftInd, int* _rightInd, int* _largestInd)
{
	*_leftInd = 2 * _index;
	*_rightInd = 2 * _index + 1;
	*_largestInd = _index;
	return;
}

static void CheckIsValidAndBiggerSon(Heap* _heap, int _val1, int _largestVal, int _val1Ind, int _largestInd)
{
	if (_val1Ind <= _heap->m_heapSize && _val1 > _largestVal)
	{
		_largestInd = _val1Ind;
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
	int swapVal1;
	int swapVal2;
	if (_index > _heap->m_heapSize)
	{
		return;
	}
	InitHeapifyIndexes(_index, &leftInd, &rightInd, &largestInd);
	VectorGet(_heap->m_vec, leftInd, &leftVal);
	VectorGet(_heap->m_vec, rightInd, &rightVal);
	VectorGet(_heap->m_vec, largestInd, &largestVal);
	/* Check if both son indexes are valid */
	if (leftInd <= _heap->m_heapSize &&  rightInd <= _heap->m_heapSize)
	{
		/* Check if both son values are bigger than father value */
		if (leftVal > largestVal && rightVal > largestVal)
		{
			BothSonsBiggerCheckMax(leftVal, rightVal, leftInd, rightInd, &largestInd);
		}
		else
		{
			OneSonBiggerCheckMax(leftVal, rightVal, largestVal, leftInd, rightInd, &largestInd);
		}
	}
	else
	{
		/* Check which son index is valid and if son value is bigger than father val */
		CheckIsValidAndBiggerSon(_heap, leftVal, largestVal, leftInd, largestInd);
		CheckIsValidAndBiggerSon(_heap, rightVal, largestVal, rightInd, largestInd);
	}
	if (largestInd != _index)
	{
		// SwapVecVals(_heap, _index, largestInd, &swapVal1, &swapVal2);
		SwapVecVals(_heap, _index, largestInd);
		Heapify(_heap, largestInd);
	}
	else
	{
		return;
	}
}

/***** API FUNCTIONS *****/
Heap* HeapBuild(Vector* _vec)
{
	Heap* heap;
	int nItems;
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
	/* Find last father index */
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


ADTErr HeapInsert(Heap* _heap, int _data)
{
	ADTErr errResult;
	int curInd;
	int fatherInd;
	int fatherVal;
	errResult = CheckPtrNotNull(_heap);
	if (errResult != ERR_OK)
	{
		return errResult;
	}
	errResult = VectorAdd(_heap->m_vec, _data);
	if (errResult != ERR_OK)
	{
		return errResult;
	}
	_heap->m_heapSize = _heap->m_heapSize + 1;
	curInd = _heap->m_heapSize;
	fatherInd = curInd / 2;
	errResult = VectorGet(_heap->m_vec, fatherInd, &fatherVal);
	if (errResult != ERR_OK)
	{
		return errResult;
	}
	while (_data > fatherVal && fatherInd >= 1)
	{
		if (1 == fatherInd)
		{
			//SwapVecVals(_heap, curInd, fatherInd, swapVal1, int* _swapVal2)
		}
	}

	

	/*
	add element to end of list and set to cur element
	increment amount of items in heap
	while (curelement data > curFather data && cur father index >= 1)
	{
		if cur father index = 1, swap then break;
		swap between element and cur father
		set curelement to cur father
		set cur father to new father
	}
	return errResult;
	*/
}

/*
ADTErr HeapExtractMax(Heap* _heap, int* _data)
{
	get max value and place in data
	take last value and place in first index
	vector delete and decrement heap size
	heapify
	return errResult;
}
*/
