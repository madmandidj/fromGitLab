/*
Filename: 		QuickSort.c 
Description:	Implementation of Quick Sort using Vector API given by Ronny
Created: 		21/07/17
Created by:		Eyal Alon
Last modified: 	22/07/17
Modified by:	Eyal Alon
Comments: 
*/
#include "QuickSort.h"
#include <stdio.h>
#include <stdlib.h> /* size_t, rand, srand */

/*************** 
STATIC FUNCTIONS 
***************/
/* Define QuickRec prototype in order to use in static functions below */
static void QuickRec(Vector* _vec, size_t _begin, size_t _end);

static int GetVectorItemsNum(Vector* _vec)
{
	int numOfItems;
	VectorItemsNum(_vec, &numOfItems);
	return numOfItems;
}

static int GetVecVal(Vector* _vec, size_t _index)
{
	int vecVal;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	VectorGet(_vec, _index + 1, &vecVal);
	return vecVal;
}

static int SwapVecVals(Vector* _vec, int _index1, int _index2)
{
	int swapVal1;
	int swapVal2;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	VectorGet(_vec, _index1 + 1, &swapVal1);
	VectorGet(_vec, _index2 + 1, &swapVal2);
	VectorSet(_vec, _index2 + 1, swapVal1);
	VectorSet(_vec, _index1 + 1, swapVal2);
	return 1;
}

static void FindNextBigOrEnd(Vector* _vec, int _pivotVal, int* _leftVal, size_t* _leftInd, size_t _end)
{
	while(_pivotVal >= *_leftVal && *_leftInd < _end)
	{
		++(*_leftInd);
		*_leftVal = GetVecVal(_vec, *_leftInd);
	}
	return;
}

static void FindNextSmallOrBegin(Vector* _vec, int _pivotVal, int* _rightVal, size_t* _rightInd, size_t _begin)
{
	while(_pivotVal < *_rightVal && *_rightInd > _begin)
	{
		--(*_rightInd);
		*_rightVal = GetVecVal(_vec, *_rightInd);
	}
	return;
}

static void SwapBigAndSmallThenIcrement(Vector* _vec, int* _rightVal, size_t* _rightInd, int* _leftVal, size_t* _leftInd)
{
	SwapVecVals(_vec, *_rightInd, *_leftInd);
	++(*_leftInd);
	--(*_rightInd);
	*_leftVal = GetVecVal(_vec, *_leftInd);
	*_rightVal = GetVecVal(_vec, *_rightInd);
	return;
}

static void BeginRecWithSwap(Vector* _vec, size_t _begin, size_t _rightInd)
{
	if (_rightInd > _begin)
	{
		QuickRec(_vec, _begin, _rightInd - 1);
	}
	return;
}

static void EndRecWithSwap(Vector* _vec, size_t _end, size_t _rightInd, size_t _leftInd)
{
	if (_leftInd < _end)
	{
		QuickRec(_vec, _rightInd + 1, _end);
	}
	return;
}

static void BeginRecWithOutSwap(Vector* _vec, size_t _begin, size_t _end, size_t _rightInd)
{
	if (_rightInd > _begin)
	{
		QuickRec(_vec, _begin + 1, _end);
	}
	return;
}

static void EndRecWithOutSwap(Vector* _vec, size_t _begin, size_t _end, size_t _leftInd)
{
	if (_leftInd < _end)
	{
		QuickRec(_vec, _begin, _end - 1);
	}
	return;
}

static void QuickRec(Vector* _vec, size_t _begin, size_t _end)
{
	size_t pivotInd;
	int pivotVal;
	size_t leftInd = _begin + 1;
	int	leftVal;
	size_t rightInd = _end;
	int	rightVal;
	if (_end - _begin < 1)
	{
		return;
	}
	else
	{
		pivotInd = _begin;
		pivotVal = GetVecVal(_vec, pivotInd);
		leftVal = GetVecVal(_vec, leftInd);
		rightVal = GetVecVal(_vec, rightInd);
		while (leftInd <= rightInd && leftInd <= _end && rightInd >= _begin)
		{
			FindNextBigOrEnd(_vec, pivotVal, &leftVal, &leftInd, _end);
			FindNextSmallOrBegin(_vec, pivotVal, &rightVal, &rightInd, _begin);
			if (leftInd < rightInd)
			{
				SwapBigAndSmallThenIcrement(_vec, &rightVal, &rightInd, &leftVal, &leftInd);
			}
			if (leftInd >= rightInd)
			{
				if (pivotVal >= rightVal)
				{
					SwapVecVals(_vec, pivotInd, rightInd);
					BeginRecWithSwap(_vec, _begin, rightInd);
					EndRecWithSwap(_vec, _end, rightInd, leftInd);
				}
				else
				{
					BeginRecWithOutSwap(_vec, _begin, _end, rightInd);
					EndRecWithOutSwap(_vec, _begin, _end, leftInd);
				}
				break;
			}
		}
	}
	return;
}

/************ 
API FUNCTIONS 
************/

ADTErr 	QuickSortRec(Vector* _vec)
{
	ADTErr errResult;
	int numOfItems;
	if (NULL == _vec)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		numOfItems = GetVectorItemsNum(_vec);
		if (numOfItems > 2)
		{
			QuickRec(_vec, 0, numOfItems-1);
		}
		errResult = ERR_OK;
	}
	return errResult;
}

ADTErr 	QuickSort(Vector* _vec)
{
	ADTErr errResult;
	int numOfItems;
	
	if (NULL == _vec)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		numOfItems = GetVectorItemsNum(_vec);
		if (numOfItems > 2)
		{

		}
		errResult = ERR_OK;
	}
	return errResult;
}



