/*
Filename: 		QuickSort.c 
Description:	Implementation of Quick Sort using Vector API given by Ronny
Created: 		21/07/17
Created by:		Eyal Alon
Last modified: 	21/07/17
Modified by:	Eyal Alon
Comments: 
*/
#include "QuickSort.h"
#include <stdio.h>
#include <stdlib.h> /* size_t, rand, srand */
#include <time.h>   /* time used to initialize srand */

/*************** 
STATIC FUNCTIONS 
***************/
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

static void QuickRec(Vector* _vec, size_t _begin, size_t _end)
{
	size_t pivotInd;
	int pivotVal;
	size_t leftInd = _begin + 1;
	int	leftVal;
	size_t rightInd = _end;
	int	rightVal;

	// if (_end - _begin <= 1)
	if (_end - _begin < 1)
	{
		return;
	}
	else
	{
		srand (time(NULL));
		/*
		pivotInd = rand() % _end + _begin;
		*/
		pivotInd = _begin;
		pivotVal = GetVecVal(_vec, pivotInd);
		leftVal = GetVecVal(_vec, leftInd);
		rightVal = GetVecVal(_vec, rightInd);
		// while (leftInd <= rightInd && leftInd != _end && rightInd != _begin)
		while (leftInd <= rightInd && leftInd <= _end && rightInd >= _begin)
		{
			while(pivotVal >= leftVal && leftInd < _end)
			{
				++leftInd;
				leftVal = GetVecVal(_vec, leftInd);
			}
			// if (leftInd > rightInd)
			// {
			// 	SwapVecVals(_vec, pivotInd, rightInd);
			// 	QuickRec(_vec, _begin, pivotInd);
			// 	QuickRec(_vec, pivotInd, _end);
			// 	break;
			// }
			while(pivotVal < rightVal && rightInd > _begin)
			{
				--rightInd;
				rightVal = GetVecVal(_vec, rightInd);
			}
			// if (leftInd > rightInd)
			// {
			// 	SwapVecVals(_vec, pivotInd, rightInd);
			// 	QuickRec(_vec, _begin, pivotInd);
			// 	QuickRec(_vec, pivotInd, _end);
			// 	break;
			// }

			if (leftInd < rightInd)
			{
				SwapVecVals(_vec, rightInd, leftInd);
				++leftInd;
				--rightInd;
				leftVal = GetVecVal(_vec, leftInd);
				rightVal = GetVecVal(_vec, rightInd);
			}
			// if (leftInd > rightInd)
			// {
			// 	SwapVecVals(_vec, pivotInd, rightInd);
			// 	QuickRec(_vec, _begin, pivotInd);
			// 	QuickRec(_vec, pivotInd, _end);
			// 	break;
			// }

			if (leftInd >= rightInd)
			// if (leftInd > rightInd)
			// if (leftInd >= rightInd && pivotVal > rightVal)
			{
				if (pivotVal >= rightVal)
				{
					SwapVecVals(_vec, pivotInd, rightInd);
					if (rightInd > _begin)
					{
						QuickRec(_vec, _begin, rightInd - 1);
					}
					if (leftInd < _end)
					{
						QuickRec(_vec, rightInd + 1, _end);
					}
				}
				else
				{
					if (rightInd > _begin)
					{
						QuickRec(_vec, _begin + 1, _end);
					}
					if (leftInd < _end)
					{
						QuickRec(_vec, _begin, _end - 1);
					}
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
		QuickRec(_vec, 0, numOfItems-1);
		errResult = ERR_OK;
	}
	return errResult;
}



