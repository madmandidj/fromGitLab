/*
Filename: 		BubbleAndShakeSortVec.c 
Description:	Implementation of Bubble And Shake Sort using Vector API given by Ronny
Created: 		20/07/17
Created by:		Eyal Alon
Last modified: 	21/07/17
Modified by:	Eyal Alon
*/
#include "BubbleAndShakeSortVec.h"
#include <stdio.h>

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

static int GetVectorItemsNum(Vector* _v)
{
	int numOfItems;
	VectorItemsNum(_v, &numOfItems);
	return numOfItems;
}

static int CheckIfNeedSwap(Vector* _v, int _leftInd, int _rightInd)
{
	int leftVal;
	int rightVal;
	int isSwapNeeded = 0;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
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
	int isSorted = 0;
	int stopSort = 0;
	int swapOccured = 0;
	int bubbleIndex = 0;
	int bubbleLength = 0;
	if (NULL == _v)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		bubbleLength = GetVectorItemsNum(_v);
		while (!isSorted)
		{
			stopSort = 1;
			for (bubbleIndex = 0; bubbleIndex < bubbleLength - 1; ++bubbleIndex)
			{
				swapOccured = CheckAndPerformSwap(_v, bubbleIndex, BUBBLE_MODE);
				if (1 == swapOccured)
				{
					stopSort = 0;
				}
			}
			--bubbleLength;
			if (stopSort)
			{
				isSorted = 1;
			}
		}
		errResult = ERR_OK;
	}
	return errResult;
}

ADTErr ShakeSort(Vector* _v)
{
	ADTErr errResult;
	int isSorted = 0;
	int stopSort = 0;
	int swapOccured = 0;
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
			if (stopSort)
			{
				isSorted = 1;
			}
			--shakeLength;
			/* Shake sort left */
			for (shakeIndexL = shakeIndexR-1; shakeIndexL >= vecItemsNum - shakeLength; --shakeIndexL)
			{
				swapOccured = CheckAndPerformSwap(_v, shakeIndexL, SHAKE_MODE);
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
