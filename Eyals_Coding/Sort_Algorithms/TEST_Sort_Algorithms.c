#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <math.h>

#define INIT_VEC_CAP 10000
#define VEC_BLOCK_SIZE 10000
#define MAX_INT_VAL 10000
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

static void FlipVector(Vector* _vector)
{
	int* LeftInt;
	int* RightInt;
	size_t index = 0;
	size_t itemsNum;
	size_t numOfSwaps;
	
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

clock_t ExecuteTest(void(*TestMethod)(Vector*), Vector* _vector)
{
	clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    start_t = clock();
	TestMethod(_vector);
    end_t = clock();
    total_t = (end_t - start_t);
	PrintIsVectorSorted(_vector);
	return total_t;
}


void Test_Bubble_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
    printf("Time elapsed for Bubble %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Bubble_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	BubbleSort(vector);
    printf("Time elapsed for Bubble %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Bubble_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	BubbleSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Bubble %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

/*	VectorPrint(vector, PrintInt);*/

int main()
{
	srand ((unsigned int)time(NULL));
	
	Test_Bubble_Average(10000);
	Test_Bubble_Best(10000);
	Test_Bubble_Worst(10000);
	
	return 0;
}


