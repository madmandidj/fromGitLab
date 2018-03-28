#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
#include <limits.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define DEC_DIGIT_NUM 10

static Vector** CreateVectorArray(size_t _numOfItems) 
{
	size_t index = 0;
	Vector** vecArray;
	
	if(!(vecArray = malloc(DEC_DIGIT_NUM *sizeof(Vector*))))
	{
		return NULL;
	}
	while (index < DEC_DIGIT_NUM)
	{
		if (!(vecArray[index] = VectorCreate(_numOfItems, 5)))
		{
			while (0 < index)
			{
				--index;
				VectorDestroy(vecArray[index], NULL);
			}
			VectorDestroy(vecArray[0], NULL);
			return NULL;
		}
		++index;
	}
	return vecArray;
}

static size_t CalculateMaxNumOfDigits(Vector* _vector, size_t _numOfItems)
{
	size_t maxNumOfDigits = 0;
	size_t index;
	size_t curNumOfDigits;
	int* elementPtr;
	int elementVal;
	
	for (index = 0; index < _numOfItems; ++index)
	{
		curNumOfDigits = 1;
		VectorGet(_vector, index, (void**)&elementPtr);
		elementVal = *elementPtr;
		while ((elementVal / DEC_DIGIT_NUM) > 0)
		{
			elementVal /= DEC_DIGIT_NUM;
			++curNumOfDigits;
		}
		maxNumOfDigits = maxNumOfDigits < curNumOfDigits ? curNumOfDigits : maxNumOfDigits;
	}
	return maxNumOfDigits;
}

static void DoRadixSort(Vector* _vector, Vector** _vecArray, size_t _numOfItems, int _curDigit, size_t _maxNumOfDigits)
{
	size_t index;
	int* elementPtr;
	int elementVal;
	int digitVal;
	size_t vecNumOfItems;
	size_t vecItemIndex;
	size_t curNumOfItems = 0;
	int preModDivFactor = 1;
	int counter = 1;
	
	while (counter < _curDigit)
	{
		preModDivFactor *= DEC_DIGIT_NUM;
		++counter;
	}
	
	for (index = 0; index < _numOfItems; ++index)
	{
		VectorGet(_vector, index, (void**)&elementPtr);
		elementVal = *elementPtr;
		elementVal /= preModDivFactor;
		if (elementVal <= 0)
		{
			VectorAppend(_vecArray[0], (void*)elementPtr);
			continue;
		}
		digitVal = elementVal % DEC_DIGIT_NUM;
		VectorAppend(_vecArray[digitVal], (void*)elementPtr);
	}
	
	for (index = 0; index < DEC_DIGIT_NUM; ++index)
	{
		vecNumOfItems = VectorItemsNum(_vecArray[index]);
		for (vecItemIndex = 0; vecItemIndex < vecNumOfItems; ++vecItemIndex)
		{
			VectorGet(_vecArray[index], vecItemIndex, (void**)&elementPtr);
			VectorSet(_vector, curNumOfItems, (void*)elementPtr);
			++curNumOfItems;
		}
		for (vecItemIndex = 0; vecItemIndex < vecNumOfItems; ++vecItemIndex)
		{
			VectorRemove(_vecArray[index], (void**)&elementPtr);
		}
	}
}


void RadixSort(Vector* _vector)
{
	size_t numOfItems;
	int curDigit;
	size_t maxNumOfDigits;
	Vector** vecArray;
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
	}
	if (!(vecArray = CreateVectorArray(numOfItems)))
	{
		return;
	}
	maxNumOfDigits = CalculateMaxNumOfDigits(_vector, numOfItems);
	for (curDigit = 1; curDigit <= maxNumOfDigits; ++curDigit)
	{
		DoRadixSort(_vector, vecArray, numOfItems, curDigit, maxNumOfDigits);
	}
}
