#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <math.h>

static void PrintInt(int* _elem)
{
	printf("%d\n", *_elem);
}

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

static Vector* CreateRandomIntVector(int* _intArr, size_t _numOfInts, size_t _cap, size_t _block)
{
	size_t index;
	Vector* vector;
	vector = VectorCreate(_cap, _block);
	if (!vector)
	{
		return NULL;
	}
	for (index = 0; index < _numOfInts; ++index)
	{
		VectorAppend(vector, _intArr + index);
	}
	return vector;
}




int main()
{
	int* intArr;
	size_t index;
	Vector* vector;
	size_t vecCap = 10;
	size_t vecBlock = 10;
	size_t numOfInts = 10000;
	size_t maxIntVal = 1000;
	
	srand (time(NULL));
	
	intArr = CreateRandomIntArray(numOfInts, maxIntVal);
	vector = CreateRandomIntVector(intArr, numOfInts, vecCap, vecBlock);
	VectorPrint(vector, (ElementFunc)PrintInt);
	BubbleSort(vector);
	printf("********************\n");
	VectorPrint(vector, (ElementFunc)PrintInt);
	VectorDestroy(vector,NULL);
	free(intArr);
	return 0;
}


