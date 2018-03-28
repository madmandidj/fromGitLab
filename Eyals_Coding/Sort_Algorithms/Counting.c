#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
#include <limits.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

static void FindMinAndMaxValues(Vector* _vector, size_t _numOfItems, unsigned int* _minVal, unsigned int* _maxVal)
{
	size_t index;
	unsigned int* element;
	for (index = 0; index < _numOfItems; ++index)
	{
		VectorGet(_vector, index, (void**)&element);
		*_maxVal = *element > *_maxVal ? *element : *_maxVal;
		*_minVal = *element < *_minVal ? *element : *_minVal;
	}
}

static void PopulateSet(Vector* _vector, size_t _numOfItems, unsigned int* _intSet)
{
	size_t index;
	int* element;
	for (index = 0; index < _numOfItems; ++index)
	{
		VectorGet(_vector, index, (void**)&element);
		++_intSet[*element];
	}
}

static void MovingSumSet(unsigned int* _intSet, unsigned int _minVal, unsigned int _maxVal)
{
	size_t index;
	
	for (index = _minVal + 1; index <= _maxVal; ++index)
	{
		_intSet[index] += _intSet[index - 1];
	}
}

static void	PopulateResultVec(Vector* _vector, Vector* _resultVec, unsigned int* _intSet, size_t _numOfItems)
{
	size_t index;
	int* element;
	
	for (index = 0; index < _numOfItems; ++index)
	{
		VectorGet(_vector, index, (void**)&element);
		VectorSet(_resultVec, _intSet[*element] - 1, (void*)element);
		--_intSet[*element];
	}
}

void CountingSort(Vector* _vector)
{
	size_t numOfItems;
	size_t index;
	unsigned int* intSet;
/*	size_t intSetSize;*/
	unsigned int minVal = UINT_MAX;
	unsigned int maxVal = 0;
	Vector* resultVec;
	int* element;
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
	}
	FindMinAndMaxValues(_vector, numOfItems, &minVal, &maxVal);
/*	intSetSize = maxVal - minVal + 1;*/
	intSet = calloc(maxVal + 1, sizeof(unsigned int));
	if (!intSet)
	{
		return;
	}
	PopulateSet(_vector, numOfItems, intSet);
	MovingSumSet(intSet, minVal, maxVal);
	resultVec = VectorCreate(numOfItems, 10);
	for(index = 0; index < numOfItems; ++index)
	{
		VectorGet(_vector, index, (void**)&element);
		VectorAppend(resultVec, (void*)element);
	}
	PopulateResultVec(_vector, resultVec, intSet, numOfItems);
	for(index = 0; index < numOfItems; ++index)
	{
		VectorGet(resultVec, index, (void**)&element);
		VectorSet(_vector, index, (void*)element);
	}
	free(intSet);
	VectorDestroy(resultVec, NULL);
}
