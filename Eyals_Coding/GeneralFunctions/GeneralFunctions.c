#include "GeneralFunctions.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>


/******
Integer Array Functions
******/
int* CreateAscendingIntArray(size_t _numOfInts)
{
	int* intArr;
	size_t index;
	if (0 == _numOfInts || _numOfInts > INT_MAX)
	{
		return NULL;
	}
	intArr = malloc(_numOfInts * sizeof(int));
	if (!intArr)
	{
		return NULL;
	}
	for (index = 0; index < _numOfInts; ++index)
	{
		intArr[index] = (int)index;
	}
	return intArr;
}

int* CreateRandomIntArray(size_t _numOfInts, int _minIntVal, int _maxIntVal)
{
	size_t index;
	int* intArr;
	int range;
	int normalisedRandNum;
	if (0 == _numOfInts || _minIntVal > _maxIntVal)
	{
		return NULL;
	}
	intArr = malloc(_numOfInts * sizeof(int));
	if (!intArr)
	{
		return NULL;
	}
	range = 1 + _maxIntVal - _minIntVal;
	srand((unsigned int)time(NULL));
	for (index = 0; index < _numOfInts; ++index)
	{
		normalisedRandNum = rand() % range;
		intArr[index] = _maxIntVal - normalisedRandNum;
	}
	return intArr;
}

void DestroyIntArray(int* _intArr)
{
	if (_intArr)
	{
		free(_intArr);
	}
	
	return;
}




/******
Vector Functions
******/
Vector* CreateAscendingIntVector(size_t _numOfInts, size_t _blockSize, int** _intArr)
{
	Vector* vector;
	size_t index;
	if (0 == _numOfInts || !_intArr)
	{
		return NULL;
	}
	
	if (!(*_intArr = CreateAscendingIntArray(_numOfInts)))
	{
		return NULL;
	}
	if (!(vector = VectorCreate(_numOfInts, _blockSize)))
	{
		DestroyIntArray(*_intArr);
		return NULL;
	}
	for (index = 0; index < _numOfInts; ++index)
	{
		VectorAppend(vector, (*_intArr) + index);
	}
	return vector;
}

Vector* CreateRandomIntVector(size_t _numOfInts, int _minVal, int _maxVal, size_t _blockSize, int** _intArr)
{
	Vector* vector;
	size_t index;
	if (0 == _numOfInts || _minVal > _maxVal || !_intArr)
	{
		return NULL;
	}
	
	if (!(*_intArr = CreateRandomIntArray(_numOfInts, _minVal, _maxVal)))
	{
		return NULL;
	}
	if (!(vector = VectorCreate(_numOfInts, _blockSize)))
	{
		DestroyIntArray(*_intArr);
		return NULL;
	}
	for (index = 0; index < _numOfInts; ++index)
	{
		VectorAppend(vector, (*_intArr) + index);
	}
	return vector;
}

void DestroyIntVector(Vector* _vector, int* _intArr)
{
	if (!_vector || !_intArr)
	{
		return;
	}
	DestroyIntArray(_intArr);
	VectorDestroy(_vector, NULL);
}

Vector* CopyCreateVector(Vector* _vector)
{
	Vector* newVector;
	size_t numOfItems;
	size_t index;
	void* element;
	
	if (!_vector)
	{
		return NULL;
	}
	numOfItems = VectorItemsNum(_vector);
	newVector = VectorCreate(numOfItems, 10 > numOfItems ? 10 : numOfItems/2);
	for (index = 0; index < numOfItems; ++index)
	{
		VectorGet(_vector, index, &element);
		VectorAppend(newVector, element);
	}
	return newVector;
}

int AreVectorsEqual(Vector* _isSortedVector, Vector* _sortedVector, IsEqualFunc _isEqualFunc)
{
	size_t index;
	int* item_L;
	int* item_R;
	size_t isSortedItemsNum;
	size_t sortedItemsNum;
	
	if (!_isSortedVector || !_sortedVector)
	{
		return 0;
	}
	
	isSortedItemsNum = VectorItemsNum(_isSortedVector);
	sortedItemsNum = VectorItemsNum(_sortedVector);
	
	if (isSortedItemsNum != sortedItemsNum)
	{
		return 0;
	}
	
	for (index = 0; index < isSortedItemsNum; ++index)
	{
		VectorGet(_isSortedVector, index, (void**)&item_L);
		VectorGet(_sortedVector, index, (void**)&item_R);
		if (!_isEqualFunc(item_L, item_R))
		{
			return 0;
		}
	}	
	return 1;
}

void FlipVector(Vector* _vector)
{
	void* LeftInt;
	void* RightInt;
	size_t index = 0;
	size_t itemsNum;
	size_t numOfSwaps;
	
	if (!_vector)
	{
		return;
	}
	
	itemsNum = VectorItemsNum(_vector);
	numOfSwaps = itemsNum/2;
	if (1 >= itemsNum)
	{
		return;
	}
	for (index = 0; index < numOfSwaps; ++index)
	{
		VectorGet(_vector, index, (void**)&LeftInt);
		VectorGet(_vector, itemsNum - 1 - index, (void**)&RightInt);
		VectorSet(_vector, index, (void*)RightInt);
		VectorSet(_vector, itemsNum - 1 - index, (void*)LeftInt);
	}
	return;
}


/******
Comparison Functions
******/
int IsIntEqual(int* _int1, int* _int2)
{
	return *_int1 == *_int2;
}

int IsIntLeftBigger(int* _leftInt, int* _rightInt)
{
	return *_leftInt > *_rightInt;
}

/******
Print Functions
******/
void PrintSingleInt(int _int)
{
	printf("%d\n", _int);
}















