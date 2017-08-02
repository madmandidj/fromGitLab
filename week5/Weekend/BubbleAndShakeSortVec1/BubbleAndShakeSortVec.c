/*
Filename: 		BubbleAndShakeSortVec.c 
Description:	Implementation of Bubble And Shake Sort using Vector API given by Ronny
Created: 		20/07/17
Created by:		Eyal Alon
Last modified: 	21/07/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include "vector.h"
#include "BubbleAndShakeSortVec.h"


/*************** 
STATIC FUNCTIONS 
***************/
static void SwapVecVals(Vector* _v, int _index1, int _index2)
{
	int swapVal1;
	int swapVal2;
	VectorGet(_v, _index1+1, &swapVal1);
	VectorGet(_v, _index2+1, &swapVal2);
	VectorSet(_v, _index2+1, swapVal1);
	VectorSet(_v, _index1+1, swapVal2);
	return;
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
	VectorGet(_v, _leftInd+1, &leftVal);
	VectorGet(_v, _rightInd+1, &rightVal);
	if (leftVal > rightVal)
	{
		isSwapNeeded = 1;
	}
	return isSwapNeeded;
}

/************ 
API FUNCTIONS 
************/
ADTErr BubbleSort(Vector* _v)
{
	ADTErr errResult;
	int isSorted = 0;
	int swapOccured = 0;
	int	isSwapNeeded = 0;
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
			swapOccured = 0;
			for (bubbleIndex = 0; bubbleIndex < bubbleLength-1; ++bubbleIndex)
			{
				isSwapNeeded = CheckIfNeedSwap(_v, bubbleIndex, bubbleIndex+1);
				if (isSwapNeeded)
				{
					SwapVecVals(_v, bubbleIndex, bubbleIndex+1); 
					swapOccured = 1;
				}
			}
			--bubbleLength;
			if (!swapOccured)
			{
				isSorted = 1;
			}
		}
	}
	errResult = ERR_OK;
	return errResult;
}
