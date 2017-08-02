/*
Filename: 		BubbleShakeInsert.c 
Description:	Implementation of Bubble shake and insert sort using Vector
Created: 		20/07/17
Created by:		Eyal Alon
Last modified: 	23/07/17
Modified by:	Eyal Alon
*/
#define BUBBLE_MODE 0
#define SHAKE_MODE  1
#include "BubbleShakeInsert.h"
/* #include <stdio.h> */

/*************** 
STATIC FUNCTIONS 
***************/
static int SwapVecVals(Vector* _v, int _index1, int _index2)
{
	int swapVal1;
	int swapVal2;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	VectorGet(_v, _index1 + 1, &swapVal1);
	VectorGet(_v, _index2 + 1, &swapVal2);
	VectorSet(_v, _index2 + 1, swapVal1);
	VectorSet(_v, _index1 + 1, swapVal2);
	return 1;
}

static int SwapVecValsInsertSort(Vector* _v, int _index1, int _index2)
{
	int swapVal1;
	int swapVal2;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	VectorGet(_v, _index1, &swapVal1);
	VectorGet(_v, _index2, &swapVal2);
	VectorSet(_v, _index2, swapVal1);
	VectorSet(_v, _index1, swapVal2);
	return 1;
}

/*
 This is redundant
*/
static int GetVectorItemsNum(Vector* _v)
{
	int numOfItems;
	VectorItemsNum(_v, &numOfItems);
	return numOfItems;
}

/* Parameters of this function should be values and not indices */
static int CheckIfNeedSwap(Vector* _v, int _leftInd, int _rightInd)
{
	int leftVal;
	int rightVal;
	int isSwapNeeded = 0;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	/* Do the VectorGets outside of this function */
	VectorGet(_v, _leftInd+1, &leftVal);
	VectorGet(_v, _rightInd+1, &rightVal);
	if (leftVal > rightVal)
	{
		isSwapNeeded = 1;
	}
	return isSwapNeeded;
}

static int CheckAndPerformSwap(Vector* _v, int _curIndex, int _mode)
{
	int isSwapNeeded = 0;
	int swapOccured = 0;
	/* Bubble sort mode */
	if (!_mode)
	{
		isSwapNeeded = CheckIfNeedSwap(_v, _curIndex, _curIndex + 1);
		if (isSwapNeeded)
		{
			swapOccured = SwapVecVals(_v, _curIndex, _curIndex + 1); 
		}
	}
	/* Shake sort mode */
	if (_mode)
	{
		isSwapNeeded = CheckIfNeedSwap(_v, _curIndex - 1, _curIndex);
		if (isSwapNeeded)
		{
			swapOccured = SwapVecVals(_v, _curIndex - 1, _curIndex); 
		}
	}
	return swapOccured;
}

/************ 
API FUNCTIONS 
************/
ADTErr BubbleSort(Vector* _v)
{
	ADTErr errResult;
	/*
		add comments for what each parameter does
	*/
	
	int isSorted = 0;
	int swapOccured = 0;
	/*
	change bubbleIndex to size_t
	*/
	int bubbleIndex = 0;
	int bubbleLength = 0;
	if (NULL == _v)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		bubbleLength = GetVectorItemsNum(_v);
		/*
		Add condition to exit if bubblelength is < 2
		*/
		while (!isSorted)
		{
			isSorted = 1;
			for (bubbleIndex = 0; bubbleIndex < bubbleLength - 1; ++bubbleIndex)
			{
				swapOccured = CheckAndPerformSwap(_v, bubbleIndex, BUBBLE_MODE);
				if (1 == swapOccured)
				{
					isSorted = 0;
				}
			}
			--bubbleLength;
		}
		errResult = ERR_OK;
	}
	return errResult;
}

ADTErr ShakeSort(Vector* _v)
{
	ADTErr errResult;
	/*
	add comments for what each parameter does
	*/
	int isSorted = 0;
	int stopSort = 0;
	int swapOccured = 0;
	/*
		change indexes to size_t
	*/
	int shakeIndexR = 0;
	int shakeIndexL = 0;
	int indexOffset = 0;
	int shakeLength = 0;
	int vecItemsNum = 0;
	if (NULL == _v)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		vecItemsNum = GetVectorItemsNum(_v);
		shakeLength = vecItemsNum;
		while (!isSorted)
		{
			stopSort = 1;
			/* Shake sort right */
			for (shakeIndexR = indexOffset; shakeIndexR < shakeLength - 1; ++shakeIndexR)
			{
				swapOccured = CheckAndPerformSwap(_v, shakeIndexR, BUBBLE_MODE);
				if (1 == swapOccured)
				{
					stopSort = 0;
				}
			}
			/* stop sort is redundant */
			if (stopSort)
			{
				/*isSorted = 1;*/
				/* add break here */
				break;
			}
			--shakeLength;
			/* Shake sort left */
			for (shakeIndexL = shakeIndexR-1; shakeIndexL >= vecItemsNum - shakeLength; --shakeIndexL)
			{
				swapOccured = CheckAndPerformSwap(_v, shakeIndexL, SHAKE_MODE);
				/* stop sort is redundant */
				if (1 == swapOccured)
				{
					stopSort = 0;
				}
			}
			if (stopSort)
			{
				isSorted = 1;
			}
			++indexOffset;
		}
		errResult = ERR_OK;
	}
	return errResult;
}

ADTErr InsertionSort(Vector* _vec, ShouldSwap _shouldSwapFunc)
{
	size_t vecIndex = 0;
	size_t curIndex = 0;
	int numOfItems = 0;
	int vecValL = 0;
	int vecValR = 0;
	int needSwap = 0;
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	for (vecIndex = 1; vecIndex <= numOfItems; ++vecIndex)
	{
		curIndex = vecIndex;
		while (curIndex > 1)
		{
			VectorGet(_vec, curIndex, &vecValR);
			VectorGet(_vec, curIndex - 1, &vecValL);
			needSwap = _shouldSwapFunc(vecValL, vecValR);
			if (needSwap)
			{
				SwapVecValsInsertSort(_vec, curIndex, curIndex - 1);
				--curIndex;
			}
			else
			{
				break;
			}
		}
	}
	return ERR_OK;
}
