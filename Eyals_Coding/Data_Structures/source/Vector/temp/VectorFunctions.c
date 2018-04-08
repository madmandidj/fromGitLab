#include "../../inc/Vector.h"
#include "../../inc/ADTErr.h"
#include <stdlib.h>

static int* CreateRandomIntArray(size_t _size, int _maxVal)
{
	size_t index;
	int* intArr;
	intArr = malloc(_size * sizeof(int));
	if (!intArr)
	{
		return NULL;
	}
	for (index = 0; index < _size; ++index)
	{
		intArr[index] = rand() % _maxVal;
	}
	return intArr;
}

Vector* CreateRandomIntVector(size_t _numOfInts, int _maxVal, size_t _blockSize, int** _intArrResult)
{
	size_t index;
	int* intArr;
	Vector* vector;
	
	intArr = CreateRandomIntArray(_numOfInts, _maxVal);
	*_intArrResult = intArr;
	
	vector = VectorCreate(_numOfInts + 1, _blockSize);
	if (!vector)
	{
		return NULL;
	}
	for (index = 0; index < _numOfInts; ++index)
	{
		VectorAppend(vector, intArr + index);
	}
	return vector;
}

void DestroyRandomIntVector(Vector* _vector, int* _intArr)
{
	if (!_vector)
	{
		return;
	}
	VectorDestroy(_vector, NULL);
	free(_intArr);
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

void FlipVector(Vector* _vector)
{
	int* LeftInt;
	int* RightInt;
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

int AreVectorsEqual(Vector* _isSortedVector, Vector* _sortedVector)
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
		if (*item_L != *item_R) /*TODO: replace this condition with user shouldswap func */
		{
			return 0;
		}
	}	
	return 1;
}





















































