/*
Filename: 		Heap.c 
Description:	Implementation of generic heap API.
Created: 		10/08/17
Created by:		Eyal Alon
Last modified: 	12/08/17
Modified by:	Eyal Alon
COMMENTS:		First element in vector is index 1
*/

/*****
DISABLE DEBUG
*****/
#define NDEBUG 1
/*****
GENERAL MACROS
*****/
#define TRUE 			1
#define FALSE 			0
#define FATHER			0
#define LEFT_SON		1
#define RIGHT_SON		2
#define IS_NULL(A) 		(NULL == (A))
/*****
HEAP MACROS
*****/
#define MAGIC_NUM 			0X0B0E0E0F
#define IS_A_HEAP(H) 		((H) &&  MAGIC_NUM == (H)->m_magicNum)
#define IS_HEAP_EMPTY(H) 	(!(H)->m_heapSize)

#include <stdlib.h>				/* malloc */
#include <assert.h>
#include "../../inc/Heap.h"


struct Heap
{
	int m_magicNum;
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator m_pfLess;
};



/*****
HEAP BUILD
*****/
static int HeapBuildCheckParams(Vector* _vector, LessThanComparator _pfLess)
{
	if (IS_NULL(_vector) || IS_NULL(_pfLess))
	{
		return FALSE;
	}
	return TRUE;
}
/*******************************/
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
/*******************************/
static void SetHeapifyIndeces(size_t _heapifyIndex, size_t* _indexArr)
{
	assert(_indexArr[FATHER] && _indexArr[LEFT_SON] && _indexArr[RIGHT_SON]);
	
	_indexArr[FATHER] = _heapifyIndex;
	_indexArr[LEFT_SON] = 2 * _heapifyIndex;
	_indexArr[RIGHT_SON] = 2 * _heapifyIndex + 1;
	return;
}
/*******************************/
/****
GetElementValues returns FALSE if any of the elements is NULL
****/
static int GetElementValues(Heap* _heap, size_t* _indexArr, void** _valueArr)
{
	assert(IS_A_HEAP(_heap) && _indexArr[FATHER] && _indexArr[LEFT_SON] && _indexArr[RIGHT_SON] && _valueArr);

	/* Get Father */
	if (_indexArr[FATHER] <= _heap->m_heapSize)
	{
		VecGet(_heap->m_vec, _indexArr[FATHER], _valueArr + FATHER);
		if (NULL == _valueArr[FATHER])
		{
			return FALSE;
		}
	}
	else
	{
		_valueArr[FATHER] = NULL;
	}

	/* Get Left Son */
	if (_indexArr[LEFT_SON] <= _heap->m_heapSize)
	{
		VecGet(_heap->m_vec, _indexArr[LEFT_SON], _valueArr + LEFT_SON);
		if (NULL == _valueArr[LEFT_SON])
		{
			return FALSE;
		}
	}
	else
	{
		_valueArr[LEFT_SON] = NULL;
	}

	/* Get Right Son */
	if (_indexArr[RIGHT_SON] <= _heap->m_heapSize)
	{
		VecGet(_heap->m_vec, _indexArr[RIGHT_SON], _valueArr + RIGHT_SON);
		if (NULL == _valueArr[RIGHT_SON])
		{
			return FALSE;
		}
	}
	else
	{
		_valueArr[RIGHT_SON] = NULL;
	}
	return TRUE;
}
/*******************************/
static void* GetLargest(LessThanComparator _pfLess, size_t* _indexArr, size_t* _largestInd, void** _valueArr, size_t _index1, size_t _index2)
{
	assert(_pfLess && _indexArr && _largestInd && _valueArr);

	if (_pfLess(_valueArr[_index1], _valueArr[_index2]))
	{
		*_largestInd = _indexArr[_index1];
		return _valueArr[_index1];
	}
	*_largestInd = _indexArr[_index2];
	return _valueArr[_index2];
}
/*******************************/
static void* FindLargestElementHeapify(LessThanComparator _pfLess, size_t* _indexArr, size_t* _largestInd, void** _valueArr)
{
	assert(_pfLess && _indexArr && _largestInd && _valueArr);

	/* If son index is invalid his value is set to NULL (in GetElementValues()) so check if both values are valid */
	if (_valueArr[LEFT_SON] && _valueArr[RIGHT_SON])
	{
		if ( _pfLess(_valueArr[LEFT_SON], _valueArr[FATHER]) && _pfLess(_valueArr[RIGHT_SON], _valueArr[FATHER]) )
		{
			return GetLargest(_pfLess, _indexArr, _largestInd, _valueArr, LEFT_SON, RIGHT_SON);
		}
		else if (_pfLess(_valueArr[LEFT_SON], _valueArr[FATHER]))
		{
			return GetLargest(_pfLess, _indexArr, _largestInd, _valueArr, LEFT_SON, FATHER);
		}
		return GetLargest(_pfLess, _indexArr, _largestInd, _valueArr, RIGHT_SON, FATHER);
	}
	/* Check left son value is valid */
	else if (_valueArr[LEFT_SON])
	{
		return GetLargest(_pfLess, _indexArr, _largestInd, _valueArr, LEFT_SON, FATHER);
	}
	/* If reached here then both son values are invalid */
	return _valueArr[FATHER];
}
/*******************************/
static void DoSwap(Heap* _heap, size_t _index1, size_t _index2, void* _element1, void* _element2)
{
	if (_element1 != NULL && _element2 != NULL)
	{
		VecSet(_heap->m_vec, _index1, _element2);
		VecSet(_heap->m_vec, _index2, _element1);
	}
	return;
}
/*******************************/
static int Heapify(Heap* _heap, size_t _heapifyIndex)
{
	size_t indexArr[3];
	void* valueArr[3];
	size_t largestIndex = FATHER;
	void* largestVal = NULL;
	
	assert(IS_A_HEAP(_heap));

	if (_heapifyIndex >= _heap->m_heapSize || 0 >= _heapifyIndex)
	{
		return TRUE;
	}

	SetHeapifyIndeces(_heapifyIndex, indexArr);
	if (!GetElementValues(_heap, indexArr, valueArr))
	{
		return FALSE;
	}

	largestVal = FindLargestElementHeapify(_heap->m_pfLess, indexArr, &largestIndex, valueArr);
	if (largestIndex != indexArr[FATHER])
	{
		DoSwap(_heap, largestIndex, indexArr[FATHER], largestVal, valueArr[FATHER]);
		Heapify(_heap, largestIndex);
	}
	return TRUE;
}
/*******************************/
static int HeapifyAllFathers(Heap* _heap)
{
	size_t heapifyIndex;
	
	assert(IS_A_HEAP(_heap));

	for (heapifyIndex = _heap->m_heapSize / 2; heapifyIndex >= 1; --heapifyIndex)
	{
		if (!Heapify(_heap, heapifyIndex))
		{
			return FALSE;
		}
	}
	return TRUE;
}
/*******************************/
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
	if (!HeapifyAllFathers(heap))
	{
		return NULL;
	}
	return heap;
}







/*****
HEAP DESTROY
*****/
Vector* HeapDestroy(Heap** _heap)
{
	Vector* vec = NULL;

	if (!IS_NULL(_heap) && IS_A_HEAP(*_heap))
	{
		vec = (*_heap)->m_vec;
		(*_heap)->m_magicNum = 0;
		free(*_heap);
		*_heap = NULL;
	}
	return vec;	
}







/*****
HEAP INSERT
*****/
static HeapResult HeapInsertCheckParams(Heap* _heap, void* _element)
{
	if(!IS_A_HEAP(_heap))
	{
		return HEAP_NOT_INITIALIZED;
	}
	if (IS_NULL(_element))
	{
		return HEAP_INV_ARG;
	}
	return HEAP_SUCCESS;
}
/*******************************/
static void BubbleUp(Heap* _heap)
{

	size_t fatherIndex;
	size_t sonIndex;
	void* fatherVal = NULL;
	void* sonVal = NULL;

	assert(IS_A_HEAP(_heap));

	sonIndex = _heap->m_heapSize;
	fatherIndex = _heap->m_heapSize / 2;
	while (fatherIndex >= 1)
	{
		VecGet(_heap->m_vec, fatherIndex, &fatherVal);
		VecGet(_heap->m_vec, sonIndex, &sonVal);
		if (_heap->m_pfLess(sonVal, fatherVal))
		{
			DoSwap(_heap, fatherIndex, sonIndex, fatherVal, sonVal);
		}
		sonIndex = fatherIndex;
		fatherIndex = sonIndex /2;
	}
	return;
}
/*******************************/
HeapResult HeapInsert(Heap* _heap, void* _element)
{
	HeapResult err;

	err = HeapInsertCheckParams(_heap, _element);
	if (HEAP_SUCCESS != err)
	{
		return err;
	}

	if (ERR_REALLOCATION_FAILED == VecAppend(_heap->m_vec, _element))
	{
		return HEAP_REALLOCATION_FAILED;
	}
	++(_heap->m_heapSize);
	BubbleUp(_heap);
	return HEAP_SUCCESS;
}







/*****
HEAP PEEK
*****/
const void* HeapPeek(const Heap* _heap)
{
	void* element;

	if (!IS_A_HEAP(_heap) || IS_HEAP_EMPTY(_heap))
	{
		return NULL;
	}

	VecGet(_heap->m_vec, 1, &element);
	return element;
}







/*****
HEAP EXTRACT
*****/
void* HeapExtract(Heap* _heap)
{
	void* element;
	void* newRootElement;

	if (!IS_A_HEAP(_heap) || IS_HEAP_EMPTY(_heap))
	{
		return NULL;
	}

	VecGet(_heap->m_vec, 1, &element);
	VecRemove(_heap->m_vec, &newRootElement);
	--(_heap->m_heapSize);
	VecSet(_heap->m_vec, 1, newRootElement);
	Heapify(_heap, 1);
	return element;
}







/*****
HEAP SIZE
*****/
size_t HeapSize(const Heap* _heap)
{
	if (!IS_A_HEAP(_heap) || IS_HEAP_EMPTY(_heap))
	{
		return 0;
	}
	return _heap->m_heapSize;
}







/*****
HEAP FOR EACH
*****/
size_t HeapForEach(const Heap* _heap, ActionFunction _act, void* _context)
{
	size_t index;
	size_t actionCount = 0;
	void* element;

	if(!IS_A_HEAP(_heap) || IS_HEAP_EMPTY(_heap) || !_act)
	{
		return 0;
	}

	for (index = 1; index <= _heap->m_heapSize; ++index)
	{
		VecGet(_heap->m_vec, index, &element);
		if(!_act(element, _context))
		{
			break;
		}
		++actionCount;
	}
	return actionCount;
}







/*****
HEAP SORT
*****/
static void HeapSortExtractAndSet(Heap* _heap, size_t _setIndex)
{
	void* element;
	void* newRootElement;

	assert(IS_A_HEAP(_heap));

	VecGet(_heap->m_vec, 1, &element);
	VecGet(_heap->m_vec, _setIndex, &newRootElement);
	VecSet(_heap->m_vec, _setIndex, element);
	VecSet(_heap->m_vec, 1, newRootElement);
	--(_heap->m_heapSize);
	Heapify(_heap, 1);
	return;
}
/*******************************/
void HeapSort(Vector* _vec, LessThanComparator _pfLess)
{
	Heap* heap = NULL;
	size_t index;
	
	if (NULL == _vec || 2 > VecSize(_vec) || NULL == _pfLess)
	{
		return;
	}

	heap = HeapBuild(_vec, _pfLess);
	if (IS_A_HEAP(heap))
	{
		for (index = heap->m_heapSize; index > 1; --index)
		{
			HeapSortExtractAndSet(heap, index);
		}
		HeapDestroy(&heap);
	}
	return;
}








