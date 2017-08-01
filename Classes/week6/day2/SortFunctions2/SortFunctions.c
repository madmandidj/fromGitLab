/*
Filename: 		SortFunctions.c 
Description:	Implementation of Sort Functions
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	24/07/17
Modified by:	Eyal Alon
*/
#define BUBBLE_MODE 0
#define SHAKE_MODE  1
#include "SortFunctions.h"
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

/*
static int SwapVecValsInsertSort(Vector* _v, int _index1, int _index2)
{
	int swapVal1;
	int swapVal2;
	VectorGet(_v, _index1, &swapVal1);
	VectorGet(_v, _index2, &swapVal2);
	VectorSet(_v, _index2, swapVal1);
	VectorSet(_v, _index1, swapVal2);
	return 1;
}
*/


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

static void InsertionSortWithGap(Vector* _vec, ShouldSwap _shouldSwapFunc, int _numOfItems, int _gapMode)
{
	size_t vecIndex = 0;
	size_t curIndex = 0;
	size_t gap = 0;
	int vecValL = 0;
	int vecValR = 0;
	int needSwap = 0;
	if (0 == _gapMode)
	{
		gap = 1;
	}
	else
	{
		gap = _numOfItems / 2;
	}
	while(1 <= gap)
	{
		for (vecIndex = 0; vecIndex < _numOfItems; vecIndex += gap)
		{
			curIndex = vecIndex;
			while (curIndex > 0)
			{
				VectorGet(_vec, curIndex + 1, &vecValR);
				VectorGet(_vec, curIndex - gap + 1, &vecValL);
				needSwap = _shouldSwapFunc(vecValL, vecValR);
				if (needSwap)
				{
					SwapVecVals(_vec, curIndex - gap, curIndex);
					curIndex -= gap;
				}
				else
				{
					break;
				}
			}
		}
		gap /= 2;
	}	
	return;
}

ADTErr InsertionSort(Vector* _vec, ShouldSwap _shouldSwapFunc)
{
	int numOfItems = 0;
	/*  Insertion sort when gapMode == 0 */
	int gapMode = 0; 
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	InsertionSortWithGap(_vec, _shouldSwapFunc, numOfItems, gapMode);
	return ERR_OK;
}

ADTErr ShellSort(Vector* _vec, ShouldSwap _shouldSwapFunc)
{
	int numOfItems = 0;
	/*  Shell sort when gapMode != 0 */
	int gapMode = 1; 
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	InsertionSortWithGap(_vec, _shouldSwapFunc, numOfItems, gapMode);
	return ERR_OK;
}


ADTErr SelectionSort(Vector* _vec)
{
	int numOfItems = 0;
	size_t vecIndL = 0;
	size_t vecIndR = 0;
	int vecValR = 0;
	size_t smallestInd = 0;
	int smallestVal = 0;
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (2 > numOfItems)
	{
		return ERR_OK;
	}
	for (vecIndL = 0; vecIndL < numOfItems - 1; ++vecIndL)
	{
		smallestInd = vecIndL;
		VectorGet(_vec, vecIndL + 1, &smallestVal);
		for (vecIndR = vecIndL + 1; vecIndR < numOfItems; ++vecIndR)
		{
			VectorGet(_vec, vecIndR + 1, &vecValR);
			if (vecValR < smallestVal)
			{
				smallestInd = vecIndR;
				VectorGet(_vec, vecIndR + 1, &smallestVal);
			}
		}
		if (smallestInd != vecIndL)
		{
			SwapVecVals(_vec, vecIndL, smallestInd);
		}
	}
	return ERR_OK;
}
