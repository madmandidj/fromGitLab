/*
Filename: 		SortFunctions.c 
Description:	Implementation of Sort Functions
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/
#include "SortFunctions.h"
#include "stack.h" /* Used in Quick Sort */
#include <stdio.h>
#define BUBBLE_MODE 0
#define SHAKE_MODE  1
#define DECIMAL_RADIX 10
/*
TODO:
* Make the use of index=0 with Vector API uniform for all functions in sort and DS
* Double check proper ERR messages for all functions
* 
*/






/********************	
BUBBLE SORT 
********************/


static int DoBubbleSwaps(Vector* _v, size_t* _bubbleLength)
{
	int swapOccured = 0;
	int leftVal;
	int rightVal;
	size_t bubbleIndex;
	for (bubbleIndex = 0; bubbleIndex < *_bubbleLength - 1; ++bubbleIndex)
	{
		VectorGet(_v, bubbleIndex + 1, &leftVal);
		VectorGet(_v, bubbleIndex + 2, &rightVal);
		if (leftVal > rightVal)
		{
			VectorSet(_v, bubbleIndex + 2, leftVal);
			VectorSet(_v, bubbleIndex + 1, rightVal);
			swapOccured = 1;
		}
	}
	return swapOccured;
}


ADTErr BubbleSort(Vector* _v)
{
	ADTErr errResult;
	int isSorted = 0;
	int swapOccured = 0;
	size_t bubbleLength = 0;
	if (NULL == _v)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		VectorItemsNum(_v, &bubbleLength);
		if (bubbleLength < 2)
		{
			errResult = ERR_OK;
		}
		else
		{
			while (!isSorted)
			{
				swapOccured = DoBubbleSwaps(_v, &bubbleLength);
				--bubbleLength;
				if (!swapOccured)
				{
					isSorted = 1;
				}
			}	
			errResult = ERR_OK;
		}
	}
	return errResult;
}



















/********************	
SHAKE SORT 
********************/


static int DoShakeSwaps(Vector* _v, size_t* _shakeLength, size_t* _indexOffset, size_t _vecItemsNum)
{
	int swapOccured = 0;
	int leftVal;
	int rightVal;
	size_t shakeIndexR = 0;
	size_t shakeIndexL = 0;
	/* Shake sort right */
	for (shakeIndexR = *_indexOffset; shakeIndexR < *_shakeLength - 1; ++shakeIndexR)
	{
		VectorGet(_v, shakeIndexR + 1, &leftVal);
		VectorGet(_v, shakeIndexR + 2, &rightVal);
		if (leftVal > rightVal)
		{
			VectorSet(_v, shakeIndexR + 2, leftVal);
			VectorSet(_v, shakeIndexR + 1, rightVal);
			swapOccured = 1;
		}
	}
	if (!swapOccured)
	{
		return swapOccured;
	}
	--(*_shakeLength);
	/* Shake sort left */
	for (shakeIndexL = shakeIndexR-1; shakeIndexL >= _vecItemsNum - *_shakeLength; --shakeIndexL)
	{
		VectorGet(_v, shakeIndexL, &leftVal);
		VectorGet(_v, shakeIndexL + 1, &rightVal);
		if (leftVal > rightVal)
		{
			VectorSet(_v, shakeIndexL, rightVal);
			VectorSet(_v, shakeIndexL + 1, leftVal);
			swapOccured = 1;
		}
	}
	++(*_indexOffset);
	return swapOccured;
}

ADTErr ShakeSort(Vector* _v)
{
	ADTErr errResult;
	/*
	TODO: add comments for what each parameter does
	*/
	int isSorted = 0;
	int swapOccured = 0;
	/*
	TODO: change indexes to size_t
	*/
	size_t indexOffset = 0;
	size_t shakeLength = 0;
	size_t vecItemsNum = 0;
	if (NULL == _v)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		VectorItemsNum(_v, &vecItemsNum);
		if (vecItemsNum < 2)
		{
			return ERR_OK;
		}
		shakeLength = vecItemsNum;
		while (!isSorted)
		{
			swapOccured = DoShakeSwaps(_v, &shakeLength, &indexOffset, vecItemsNum);
			if (!swapOccured)
			{
				isSorted = 1;
			}
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
	VectorSet(_v, _index2, swapVal1);
	VectorSet(_v, _index1, swapVal2);
	return 1;
}

static void InsertionSortWithGap(Vector* _vec, ShouldSwap _shouldSwapFunc, int _numOfItems, int _gapMode)
{
	size_t curIndex = 1;
	size_t shellIndex;
	size_t gap = 0;
	size_t backCurInd;
	int vecValL = 0;
	int vecValR = 0;
	int curValR;
	int curValL;
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
		curIndex = 1;
		while (curIndex <= gap)
		{
			shellIndex = curIndex;
			while (shellIndex <= _numOfItems - gap)
			{
				VectorGet(_vec, shellIndex , &vecValL);
				VectorGet(_vec, shellIndex + gap , &vecValR);
				needSwap = _shouldSwapFunc(vecValL, vecValR);
				if (needSwap)
				{
					SwapVecValsInsertion(_vec, shellIndex, shellIndex + gap, vecValL, vecValR);
					curValR = vecValR;
					curValL = vecValL;
					for (backCurInd = shellIndex; backCurInd >= 1; NULL)
					{
						if (backCurInd - gap >= 1 && backCurInd <100000)
						{
							backCurInd -= gap;												
							VectorGet(_vec, backCurInd , &curValL);
							VectorGet(_vec, backCurInd + gap, &curValR);
							if (!_shouldSwapFunc(curValL, curValR))	
							{
								break;
							}
							else 
							{
								SwapVecValsInsertion(_vec, backCurInd, backCurInd + gap, curValL, curValR );
							}
						}
						else
						{
							break;
						}
					}
				}
				shellIndex += gap;
			}
			++curIndex;
		}
		gap /= 2;
	}	
	return;
}

ADTErr InsertionSort(Vector* _vec, ShouldSwap _shouldSwapFunc)
{
	size_t numOfItems = 0;
	/*  Insertion sort when gapMode == 0 */
	int gapMode = 0; 
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
	InsertionSortWithGap(_vec, _shouldSwapFunc, numOfItems, gapMode);
	return ERR_OK;
}















/********************	
SHELL SORT 
********************/


ADTErr ShellSort(Vector* _vec, ShouldSwap _shouldSwapFunc)
{
	size_t numOfItems = 0;
	/*  Shell sort when gapMode != 0 */
	int gapMode = 1; 
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
	InsertionSortWithGap(_vec, _shouldSwapFunc, numOfItems, gapMode);
	return ERR_OK;
}















/********************	
SELECTION SORT 
********************/


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

ADTErr SelectionSort(Vector* _vec)
{
	size_t numOfItems = 0;
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
QUICK SORT 
********************/

/*
TODO: get rid of GetVectorItemsNum and GetVecVal. they are redundant
*/
static int GetVectorItemsNum(Vector* _vec)
{
	size_t numOfItems;
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

static void FindNextBigOrEnd(Vector* _vec, int _pivotVal, int* _leftVal, size_t* _leftInd, size_t _end)
{
	while(_pivotVal >= *_leftVal && *_leftInd <= _end)
	{
		++(*_leftInd);
		if (*_leftInd <= _end)
		{
			*_leftVal = GetVecVal(_vec, *_leftInd);
		}
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

static int Partition(Vector* _vec, size_t _begin, size_t _end)
{
	size_t pivotInd;
	int pivotVal;
	size_t leftInd = _begin + 1;
	int	leftVal;
	size_t rightInd = _end;
	int	rightVal;
	pivotInd = _begin;
	pivotVal = GetVecVal(_vec, pivotInd);
	leftVal = GetVecVal(_vec, leftInd);
	rightVal = GetVecVal(_vec, rightInd);
	while (leftInd <= rightInd)
	{
		FindNextBigOrEnd(_vec, pivotVal, &leftVal, &leftInd, _end);
		FindNextSmallOrBegin(_vec, pivotVal, &rightVal, &rightInd, _begin);
		if (leftInd <= rightInd)
		{
				SwapBigAndSmallThenIcrement(_vec, &rightVal, &rightInd, &leftVal, &leftInd);
		}
		if (leftInd > rightInd)
		{
				SwapVecVals(_vec, pivotInd, rightInd);
			break;
		}
	}
	return rightInd;
}

static void SwapTwoValsIfNeeded(Vector* _vec, size_t _begin, size_t _end)
{
	int swapVal1;
	int swapVal2;
	/* index + 1 because Vector implementation starts from index = 1, not index = 0 */
	VectorGet(_vec, _begin + 1, &swapVal1);
	VectorGet(_vec, _end + 1, &swapVal2);
	if (swapVal1 > swapVal2)
	{
		VectorSet(_vec, _end + 1, swapVal1);
		VectorSet(_vec, _begin + 1, swapVal2);
	}
	return;
}


static void QuickRec(Vector* _vec, size_t _begin, size_t _end)
{
	size_t pInd;
	if (_end <= _begin)
	{
		return;
	}
	else if (_end - _begin == 1)
	{
		SwapTwoValsIfNeeded(_vec, _begin, _end);
	}
	else
	{
		pInd = Partition(_vec, _begin, _end);
		if (pInd > _begin && pInd <_end)
		{
			QuickRec(_vec, _begin, pInd-1);
			QuickRec(_vec, pInd+1, _end);
		}
		if (pInd == _begin)
		{
			QuickRec(_vec, _begin+1, _end);
		}
		if (pInd == _end)
		{
			QuickRec(_vec, _begin, _end-1);
		}
	}
	return;
}

ADTErr 	QuickSortRec(Vector* _vec)
{
	ADTErr errResult;
	size_t numOfItems;
	if (NULL == _vec)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		numOfItems = GetVectorItemsNum(_vec);
		if (numOfItems >= 2)
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
	size_t numOfItems;
	size_t begin;
	size_t end;
	int leftInd;
	int rightInd;
	size_t pInd;
	size_t blockSize = 2;
	Stack* stack;
	if (NULL == _vec)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		numOfItems = GetVectorItemsNum(_vec);
		if (numOfItems >= 2)
		{
			stack = StackCreate(numOfItems, blockSize);
			StackPush(stack, 0);
			StackPush(stack, numOfItems - 1);
			begin = 0;
			end = numOfItems - 1;
			while (!StackIsEmpty(stack))
			{
				StackPop(stack, &rightInd);
				StackPop(stack, &leftInd);
				if (rightInd <= leftInd)
				{
					continue;
				}
				else if (rightInd - leftInd == 1)
				{
					SwapTwoValsIfNeeded(_vec, leftInd, rightInd);
					continue;
				}
				else
				{
					pInd = Partition(_vec, leftInd, rightInd);
					if (pInd > leftInd && pInd < rightInd)
					{
						StackPush(stack, leftInd);
						StackPush(stack, pInd - 1);
						StackPush(stack, pInd + 1);
						StackPush(stack, rightInd);
					}
					else if (pInd == begin)
					{
						StackPush(stack, begin + 1);
						StackPush(stack, rightInd);
					}
					else if (pInd == leftInd)
					{
						StackPush(stack, leftInd + 1);
						StackPush(stack, rightInd);
					}
					else if (pInd == end)
					{
						StackPush(stack, leftInd);
						StackPush(stack, end - 1);
					}
					else
					{
						StackPush(stack, leftInd);
						StackPush(stack, rightInd - 1);
					}
				}
			}
		}
		errResult = ERR_OK;
	}
	return errResult;
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
	size_t end;
	
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
	size_t numOfItems;
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

static void FillAndProcessRangeArray(Vector* _vec, int* _rangeArr, int _maxRange, int _numOfItems, FuncAndKey _fAK)
{
	size_t index;
	int vecVal;
	for (index = 1; index <= _numOfItems; ++index)
	{
		VectorGet(_vec, index, &vecVal);
		vecVal = _fAK.m_fPRArrfFunc(vecVal, _fAK.m_digit);
		++_rangeArr[vecVal];
	}
	for (index = 0; index < _maxRange - 1; ++index)
	{
		_rangeArr[index + 1] += _rangeArr[index];
	}
	return;
}

static void FillSortedArray(Vector* _vec, int* _rangeArr, int* _sortedArr, int _numOfItems, FuncAndKey _fAK)
{
	size_t origIndex;
	int vecVal;
	size_t vecValInd;
	for (origIndex = _numOfItems; origIndex >= 1; --origIndex)
	{
		VectorGet(_vec, origIndex, &vecVal);
		vecValInd = _fAK.m_fPRArrfFunc(vecVal, _fAK.m_digit);
		_sortedArr[_rangeArr[vecValInd]-1] = vecVal;
		--_rangeArr[vecValInd];
	}
	return;
}

static void CopySortedArrToVector(Vector* _vec, int* sortedArr, int _numOfItems)
{
	size_t index;
	for (index = 0; index < _numOfItems; ++index)
	{
		VectorSet(_vec, index + 1, sortedArr[index]);
	}
	return;
}

ADTErr CountingSort(Vector* _vec, int _maxValue, FuncAndKey _fAK)
{
	int* sortedArr;
	int* rangeArr; 
	size_t numOfItems;
	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
	rangeArr = calloc(_maxValue, sizeof(int));
	if (NULL == rangeArr)
	{
		return ERR_ALLOCATION_FAILED;
	}
	FillAndProcessRangeArray(_vec, rangeArr, _maxValue, numOfItems, _fAK);
	sortedArr = malloc((numOfItems) * sizeof(int));
	if (NULL == sortedArr)
	{
		free(rangeArr);
		return ERR_ALLOCATION_FAILED;
	}
	FillSortedArray(_vec, rangeArr, sortedArr, numOfItems, _fAK);
	CopySortedArrToVector(_vec, sortedArr, numOfItems);
	free(sortedArr);
	free(rangeArr);
	return ERR_OK;
}















/********************	
RADIX SORT 
********************/


static int FindMaxDigits(Vector* _vec, size_t _numOfItems)
{
	int vecIndex;
	int maxDigits = 0;
	int curDigits = 1;
	int curVal;
	for (vecIndex = 1; vecIndex <= _numOfItems; ++vecIndex)
	{
		curDigits = 1;
		VectorGet(_vec, vecIndex, &curVal);
		while (curVal / DECIMAL_RADIX > 0)
		{
			++curDigits;
			curVal /= DECIMAL_RADIX;
		}
		if (curDigits > maxDigits)
		{
			maxDigits = curDigits;
		}
	}
	return maxDigits;
}

static int RadixProcess(int _vecVal, int _digit)
{
	size_t index;

	for (index = 1; index <= _digit; ++index)
	{
		if(index == _digit)
		{
			_vecVal %= DECIMAL_RADIX;
		}
		else
		{
			_vecVal /= DECIMAL_RADIX;
		}
		
	}
	return _vecVal;
}


ADTErr RadixSort(Vector* _vec, int _nDigits)
{
	size_t numOfItems;
	int curDigit = 1;
	int maxDigits;
/*	int* rangeArr;*/
/*	int* sortedArr;*/
	FuncAndKey fAK;
    fAK.m_fPRArrfFunc = RadixProcess;

	if (NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numOfItems);
	if (numOfItems < 2)
	{
		return ERR_OK;
	}
/*	rangeArr = calloc(DECIMAL_RADIX, sizeof(int));*/
/*	if (NULL == rangeArr)*/
/*	{*/
/*		return ERR_ALLOCATION_FAILED;*/
/*	}*/
/*	sortedArr = malloc(numOfItems * sizeof(int));*/
/*	if (NULL == sortedArr)*/
/*	{*/
/*		free(rangeArr);*/
/*		return ERR_ALLOCATION_FAILED;*/
/*	}*/
	while (curDigit <= _nDigits)
	{
		maxDigits = FindMaxDigits(_vec, numOfItems);
		fAK.m_digit = curDigit;
		CountingSort(_vec, DECIMAL_RADIX, fAK);
		++curDigit;
	}
/*	free(rangeArr);*/
/*	free(sortedArr);*/
	return ERR_OK;
}




