#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <math.h>

/*
AUX FUNCTIONS
*/
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

int PrintIsVectorSorted(Vector* _vector)
{
	size_t vecItemsNum;
	size_t index;
	int* item_L;
	int* item_R;
	
	vecItemsNum = VectorItemsNum(_vector);
	for (index = 0; index < vecItemsNum - 1; ++index)
	{
		VectorGet(_vector, index, (void**)&item_L);
		VectorGet(_vector, index + 1, (void**)&item_R);
		if (*item_L > *item_R)
		{
			printf("Vector IS NOT sorted : ( \n");
			return 0;
		}
	}
	printf("Vector IS sorted : ) \n");
	return 1;
}

/*
TEST METHODS
*/


void Test_Bubble(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	size_t vecCap = 10;
	size_t vecBlock = 10;
/*	size_t numOfInts = 1000;*/
	int maxIntVal = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
	
	printf("Start Bubble\n");
	intArr = CreateRandomIntArray(_numOfInts, maxIntVal);
	vector = CreateRandomIntVector(intArr, _numOfInts, vecCap, vecBlock);
    start_t = clock();
	BubbleSort(vector);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for Bubble %u:\t %f\n", _numOfInts,((float)total_t) / CLOCKS_PER_SEC);
	PrintIsVectorSorted(vector);
	VectorDestroy(vector,NULL);
	free(intArr);
	printf("Finish Bubble\n");
}

int main()
{
/*	int* intArr;*/
/*	Vector* vector;*/
/*	size_t vecCap = 10;*/
/*	size_t vecBlock = 10;*/
/*	size_t numOfInts = 10000;*/
/*	int maxIntVal = 1000;*/
/*	*/
/*	srand ((unsigned int)time(NULL));*/
/*	*/
/*	intArr = CreateRandomIntArray(numOfInts, maxIntVal);*/
/*	vector = CreateRandomIntVector(intArr, numOfInts, vecCap, vecBlock);*/
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
/*	BubbleSort(vector);*/
/*	printf("********************\n");*/
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
/*	VectorDestroy(vector,NULL);*/
/*	free(intArr);*/
	srand ((unsigned int)time(NULL));
	Test_Bubble(1000);
	Test_Bubble(10000);
	return 0;
}


