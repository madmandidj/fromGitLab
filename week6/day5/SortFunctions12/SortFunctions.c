/*
Filename: 		SortFunctions.c 
Description:	Implementation of Sort Functions
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	26/07/17
Modified by:	Eyal Alon
*/
#define BUBBLE_MODE 0
#define SHAKE_MODE  1
#include "SortFunctions.h"
#include <stdio.h>

/*
TODO:
*
* Make the use of index / index + 1 with Vector API uniform for all functions
*
*
*/


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
 TODO: This is redundant - remove
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
	/* TODO: Do the VectorGets outside of this function */
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


/********************	
BUBBLE SORT 
********************/


ADTErr BubbleSort(Vector* _v)
{
	ADTErr errResult;
	/*
	TODO: add comments for what each parameter does
	*/
	int isSorted = 0;
	int swapOccured = 0;
	/*
	TODO: change bubbleIndex to size_t in Vector API
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
		TODO: Add condition to exit if bubblelength is < 2
		*/
		while (!isSorted)
		{
			isSorted = 1;
			for (bubbleIndex = 0; bubbleIndex < bubbleLength - 1; ++bubbleIndex)
			{
				/* TODO: Adapt this function to receive as parameter shouldSwap func */
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


/********************	
SHAKE SORT 
********************/


ADTErr ShakeSort(Vector* _v)
{
	ADTErr errResult;
	/*
	TODO: add comments for what each parameter does
	*/
	int isSorted = 0;
	int stopSort = 0;
	int swapOccured = 0;
	/*
	TODO: change indexes to size_t
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
				/* TODO: Adapt this function to receive as parameter shouldSwap func */
				swapOccured = CheckAndPerformSwap(_v, shakeIndexR, BUBBLE_MODE);
				if (1 == swapOccured)
				{
					stopSort = 0;
				}
			}
			/* TODO: stop sort variable is redundant.. can use isSorted */
			if (stopSort)
			{
				/*isSorted = 1;*/
				/* TODO: add break here */
				break;
			}
			--shakeLength;
			/* Shake sort left */
			for (shakeIndexL = shakeIndexR-1; shakeIndexL >= vecItemsNum - shakeLength; --shakeIndexL)
			{
				/* TODO: Adapt this function to receive as parameter shouldSwap func */
				swapOccured = CheckAndPerformSwap(_v, shakeIndexL, SHAKE_MODE);
				/* TODO: stop sort is redundant */
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


/********************	
INSERTION SORT 
********************/


static int SwapVecValsInsertion(Vector* _v, int _index1, int _index2, int swapVal1, int swapVal2)
{
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	VectorSet(_v, _index2 + 1, swapVal1);
	VectorSet(_v, _index1 + 1, swapVal2);
	return 1;
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
					/*SwapVecVals(_vec, curIndex - gap, curIndex);*/
					SwapVecValsInsertion(_vec, curIndex - gap, curIndex, vecValL, vecValR);
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


/********************	
SHELL SORT 
********************/


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


/********************	
SELECTION SORT 
********************/


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


/********************	
MERGE SORT 
********************/


static void FillOriginalVector(Vector* _vec, int* _mergeArr, size_t _beginL, size_t _endR)
{
	size_t index;
	for (index = _beginL; index <= _endR; ++index)
	{
		VectorSet(_vec, index, _mergeArr[index - 1]);
	}
	return;
}

static void FillTail(Vector* _vec, int* _mergeArr, size_t _indexL, size_t _indexR, size_t _endL, size_t _endR, size_t _insertIndex, int* _leftVal, int* _rightVal)
{
	while(_indexL <= _endL)
	{
		_mergeArr[_insertIndex] = *_leftVal;
		++_insertIndex;
		++_indexL;
		VectorGet(_vec, _indexL, _leftVal);
	}
	while(_indexR <= _endR)
	{
		_mergeArr[_insertIndex] = *_rightVal;
		++_insertIndex;
		++_indexR;
		VectorGet(_vec, _indexR, _rightVal);
	}
	return;
}

static void DoMerge(Vector* _vec, int* _mergeArr, size_t* _indexL, size_t* _indexR, size_t _endL, size_t _endR, size_t* _insertIndex, int* _leftVal, int* _rightVal)
{
	while (*_indexL <= _endL && *_indexR <= _endR)
	{
		VectorGet(_vec, *_indexL, _leftVal);
		VectorGet(_vec, *_indexR, _rightVal);
		if (*_leftVal < *_rightVal)
		{
			_mergeArr[*_insertIndex] = *_leftVal;
			++*_insertIndex;
			++*_indexL;
		}
		else if (*_leftVal > *_rightVal)
		{
			_mergeArr[*_insertIndex] = *_rightVal;
			++*_insertIndex;
			++*_indexR;
		}
		else
		{
			_mergeArr[*_insertIndex] = *_leftVal;
			++*_insertIndex;
			++*_indexL;
			_mergeArr[*_insertIndex] = *_rightVal;
			++*_insertIndex;
			++*_indexR;
		}
	}
	return;
}

void Merge(Vector* _vec, int* _mergeArr, size_t _beginL, size_t _endL, size_t _beginR, size_t _endR)
{
	/* TODO: indexL and indexR are redundant? TRIED this and it ruined results */
	size_t indexL = _beginL;
	size_t indexR = _beginR;
	size_t insertIndex = _beginL - 1;
	int leftVal;
	int rightVal;
	DoMerge(_vec, _mergeArr, &indexL, &indexR, _endL, _endR, &insertIndex, &leftVal, &rightVal);
	FillTail(_vec, _mergeArr, indexL, indexR, _endL, _endR, insertIndex, &leftVal, &rightVal);
	FillOriginalVector(_vec, _mergeArr, _beginL, _endR);
	return;
}

void MergeRec(Vector* _vec, int* _mergeArr, size_t _begin, size_t _end)
{
	size_t endL;
	size_t beginR;
	/* Check _end < _begin because they are size_t so will be huge number when subtracted*/
	if (_end < _begin + 1)
	{
		return;
	}
	if (_end - _begin == 1)
	{
		endL = _begin;
		beginR = _end;
	}
	else
	{
		endL = (_begin + _end - 1) / 2;
		beginR = (_begin + _end + 1) / 2;
	}
	MergeRec(_vec, _mergeArr, _begin, endL);
	MergeRec(_vec, _mergeArr, beginR, _end);
	Merge(_vec, _mergeArr, _begin, endL, beginR, _end);
}

ADTErr MergeSortRec(Vector* _vec)
{
	/* TODO: Vector API still returns int here, although should be size_t*/
	int* mergeArr; 
	size_t begin = 1;
	int end;
	
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &end);
	if (end < 2)
	{
		return ERR_OK;
	}
	mergeArr = malloc(end * sizeof(int));
	if (NULL == mergeArr)
	{
		return ERR_NOT_INITIALIZED;
	}
	MergeRec(_vec, mergeArr, begin, end);
	free(mergeArr);
	return ERR_OK;
}


void MergeIter(Vector* _vec, int* _mergeArr, size_t _numOfItems)
{
	size_t beginL = 0;
	size_t endL = 0;
	size_t beginR = 0;
	size_t endR = 0;
	size_t curIndex = 0;
	size_t groupSize = 0;
	for (groupSize = 1; groupSize <= _numOfItems - 1; groupSize = 2 * groupSize)
	{
		for(curIndex = 0; curIndex < _numOfItems - 1; curIndex += 2 * groupSize)
		{
			beginL = curIndex;
			endL = curIndex + groupSize - 1;
			beginR = curIndex + groupSize;
			if (curIndex + 2 * groupSize - 1 < _numOfItems -1)
			{
				endR = curIndex + 2 * groupSize - 1;
			}
			else
			{
				endR = _numOfItems - 1;
			}
			if (beginL > _numOfItems-1 || endL > _numOfItems-1 || beginR > _numOfItems-1 || endR > _numOfItems-1)
			{
				break;
			}
			Merge(_vec, _mergeArr, beginL+1, endL+1, beginR+1, endR+1);
		}
	}
	return;
}


ADTErr MergeSort(Vector* _vec)
{

	int* mergeArr; 
	int numOfItems;
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
	mergeArr = malloc(numOfItems * sizeof(int));
	if (NULL == mergeArr)
	{
		return ERR_NOT_INITIALIZED;
	}
	MergeIter(_vec, mergeArr, numOfItems);
	free(mergeArr);
	return ERR_OK;
}


/********************	
COUNTING SORT 
********************/


static int GetMaxVecVal(Vector* _vec, int _numOfItems)
{
	size_t index;
	int maxVal = 0;
	int vecVal;
	for (index = 1; index <= _numOfItems; ++index)
	{
		VectorGet(_vec, index, &vecVal);
		if (vecVal > maxVal)
		{
			maxVal = vecVal;
		}
	}
	return maxVal;
}

static void FillAndProcessRangeArray(Vector* _vec, int* _rangeArr, int _maxRange, int numOfItems)
{
	size_t index;
	int vecVal;
	for (index = 1; index <= numOfItems; ++index)
	{
		VectorGet(_vec, index, &vecVal);
		++_rangeArr[vecVal];
	}
	for (index = 0; index < _maxRange; ++index)
	{
		_rangeArr[index + 1] += _rangeArr[index];
	}
	return;
}

static void FillSortedArray(Vector* _vec, int* _rangeArr, int* _sortedArr, int numOfItems)
{
	size_t origIndex;
	int vecVal;
	for (origIndex = numOfItems; origIndex >= 1; --origIndex)
	{
		VectorGet(_vec, origIndex, &vecVal);
		_sortedArr[_rangeArr[vecVal]-1] = vecVal;
		--_rangeArr[vecVal];
	}
	return;
}

static void CopySortedArrToVector(Vector* _vec, int* sortedArr, int numOfItems)
{
	size_t index;
	for (index = 0; index < numOfItems; ++index)
	{
		VectorSet(_vec, index + 1, sortedArr[index]);
	}
	return;
}

ADTErr CountingSort(Vector* _vec)
{
	int* sortedArr;
	int* rangeArr; 
	int numOfItems;
	int maxRange;
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
	maxRange = GetMaxVecVal(_vec, numOfItems);
	/*
		add 1 to max range to accomodate a vector element value of 0
	*/
	maxRange += 1;
	rangeArr = calloc(maxRange, sizeof(int));
	if (NULL == rangeArr)
	{
		return ERR_ALLOCATION_FAILED;
	}
	FillAndProcessRangeArray(_vec, rangeArr, maxRange, numOfItems);
	sortedArr = malloc(numOfItems * sizeof(int));
	if (NULL == sortedArr)
	{
		return ERR_ALLOCATION_FAILED;
	}
	FillSortedArray(_vec, rangeArr, sortedArr, numOfItems);
	CopySortedArrToVector(_vec, sortedArr, numOfItems);
	free(sortedArr);
	free(rangeArr);
	return ERR_OK;
}


/********************	
RADIX SORT 
********************/
static void ExtractCurDigit(Vector* _vec, int* digArr, int _numOfItems, int _nDigits, int _curDigit)
{
	size_t index;
	int divisor = 10;
	int vecVal;
	for (index = 1; index < _numOfItems; ++index)
	{
		VectorGet(_vec, index, &vecVal);
	}
	return;
}

ADTErr RadixSort(Vector* _vec, int _nDigits)
{
	int numOfItems;
	int radix;
	int* rangeArr;
	int* digArr;
	int* sortedArr;
	int curDigit;
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
	/* Assume decimal numbers */
	radix = 10;
	rangeArr = calloc(radix, sizeof(int));
	if (NULL == rangeArr)
	{
		return ERR_ALLOCATION_FAILED;
	}
	digArr = malloc(numOfItems * sizeof(int));
	if (NULL == digArr)
	{
		return ERR_ALLOCATION_FAILED;
	}
	sortedArr = malloc(numOfItems * sizeof(int));
	if (NULL == sortedArr)
	{
		return ERR_ALLOCATION_FAILED;
	}
	while (curDigit <= _nDigits)
	{
		
		/* extract LSD then FillAndProcessRange to rangeArr */
		/* populate sortedArr with sorted values according to index */
		/* replace contents of original vector */
	}
	/*
	algorithm:



	description:
	k is base (radix), d is number of digits
	For a d digit number, sort the least significant digit first
	continue sorting on the next least significant digit untill all digits have been sorted
	requires only d passes through the list
	*/


	return ERR_OK;
}




