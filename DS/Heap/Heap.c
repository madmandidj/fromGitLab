/*
Filename: 		Heap.c 
Description:	Implementation of generic heap API.
Created: 		10/08/17
Created by:		Eyal Alon
Last modified: 	10/08/17
Modified by:	Eyal Alon
COMMENTS:		Note: Vector index starts from 1, not 0
*/
#define NDEBUG 1
#include <stdlib.h>
#include "Heap.h"
#include "assert.h"


struct Heap
{
	int m_magicNum;
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator m_pfLess;
};

/*****
GENERAL MACROS
*****/
#define TRUE 			1
#define FALSE 			0
#define INVALID 		-1
#define IS_NULL(A) 		(NULL == (A))
/*****
HEAP MACROS
*****/
#define MAGIC_NUM 		0X00004000
#define IS_A_HEAP(H) 	((H) &&  MAGIC_NUM == (H)->m_magicNum)





/*****
HEAP BUILD
*****/
static int HeapBuildCheckParams(Vector* _vector, LessThanComparator _pfLess)
{
	if (IS_NULL(_vector) || IS_NULL(_pfLess))
	{
		return 0;
	}
	return 1;
}

static Heap* InitHeap(Vector* _vector, LessThanComparator _pfLess)
{
	Heap* heap;
	
	assert(_vector && _pfLess);
	if (!(heap = malloc(sizeof(Heap))))
	{
		return NULL;
	}
	
	heap->m_magicNum = MAGIC_NUM;
	heap->m_vec = _vector;
	heap->m_heapSize = VecSize(_vector);
	heap->m_pfLess = _pfLess;
	return heap;
}

static void SetIndeces(size_t _heapifyIndex, size_t* _leftInd, size_t* _rightInd, size_t* _largestInd)
{
	assert(_leftInd && _rightInd && _largestInd);
	
	*_leftInd = 2 * _heapifyIndex;
	*_rightInd = 2 * _heapifyIndex + 1;
	*_largestInd = _heapifyIndex;
	return;
}

static void GetItemVals(Heap* _heap, size_t* _leftInd, size_t* _rightInd, size_t* _largestInd, void** _leftVal, void** _rightVal, void** _largestVal)
{
	assert(IS_A_HEAP(_heap) && _leftInd && _rightInd && _largestInd && _leftVal && _rightVal && _largestVal);
	
	VecGet(_heap->m_vec, *_leftInd, _leftVal);
	VecGet(_heap->m_vec, *_rightInd, _rightVal);
	VecGet(_heap->m_vec, *_largestInd, _largestVal);
	return;
}

/*
* returns: 0 father is largest, 1 left is largest, 2 right is largest
*/
static int FindLargest(LessThanComparator _pfLess, void* _leftVal, void* _rightVal, void* _largestVal)
{
	if (_leftVal && _rightVal)
	{
		if ((_pfLess(_leftVal, _largestVal)) && (_pfLess(_rightVal, _largestVal)))
		{
			if (_pfLess(_leftVal, _rightVal))
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	else
	{
		if (_leftVal)
		{
			if (_pfLess(_leftVal, _largestVal))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (_rightVal)
		{
			if (_pfLess(_rightVal, _largestVal))
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

static void DoSwap(Heap* _heap, size_t _index1, size_t _index2, void* _item1, void* _item2)
{
	void* swapVal;
	swapVal = _item1;
	VecSet(_heap->m_vec, _index1, _item2);
	VecSet(_heap->m_vec, _index2, swapVal);
	return;
}

static void Heapify(Heap* _heap, size_t _heapifyIndex)
{
	size_t leftInd;
	size_t rightInd;
	size_t largestInd;
	void* leftVal = NULL;
	void* rightVal = NULL;
	void* largestVal = NULL;
	int whoIsLargest = 0;
	
	if (!IS_A_HEAP(_heap) || _heapifyIndex > _heap->m_heapSize || 0 >= _heapifyIndex)
	{
		return;
	}
	
	SetIndeces(_heapifyIndex, &leftInd, &rightInd, &largestInd);
	GetItemVals(_heap, &leftInd, &rightInd, &largestInd, &leftVal, &rightVal, &largestVal);
	whoIsLargest = FindLargest(_heap->m_pfLess, leftVal, rightVal, largestVal);
	switch (whoIsLargest)
	{
		case 0:
		/* Father is largest */
			break;
		case 1:
		/* Left Son is largest */
			DoSwap(_heap, leftInd, largestInd, leftVal, largestVal);
			Heapify(_heap, leftInd);
			break;
		case 2:
		/* Right Son is largest */
			DoSwap(_heap, rightInd, largestInd, rightVal, largestVal);
			Heapify(_heap, rightInd);
			break;	
	}
	return;
}

static void HeapifyAllFathers(Heap* _heap)
{
	size_t heapifyIndex;
	
	assert(IS_A_HEAP(_heap));
	for (heapifyIndex = _heap->m_heapSize / 2; heapifyIndex >= 1; --heapifyIndex)
	{
		Heapify(_heap, heapifyIndex);
	}
	return;
}

Heap* HeapBuild(Vector* _vector, LessThanComparator _pfLess)
{
	Heap* heap;	
	
	if (!(HeapBuildCheckParams(_vector, _pfLess)))
	{
		return NULL;
	}
	if (!(heap = InitHeap(_vector, _pfLess)))
	{
		return NULL;
	}
	HeapifyAllFathers(heap);
	return heap;
}








/*****
HEAP DESTROY
*****/
Vector* HeapDestroy(Heap** _heap)
{
	Vector* vec;
	
	if (IS_A_HEAP(*_heap))
	{
		vec = (*_heap)->m_vec;
		(*_heap)->m_magicNum = 0;
		free(*_heap);
		*_heap = NULL;
	}
	return vec;
}



















