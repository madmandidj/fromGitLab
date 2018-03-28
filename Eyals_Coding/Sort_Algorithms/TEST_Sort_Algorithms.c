#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <math.h>

#define INIT_VEC_CAP 10000
#define VEC_BLOCK_SIZE 10000
#define MAX_INT_VAL 100
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

/*	VectorPrint(vector, PrintInt); */









/*
BUBBLE TESTS
*/
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
	QuickSort(vector);
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
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Bubble %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}


/*
SHAKE TESTS
*/
void Test_Shake_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
    printf("Time elapsed for Shake %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(ShakeSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Shake_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
    printf("Time elapsed for Shake %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(ShakeSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Shake_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Shake %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(ShakeSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

/*
INSERTION TESTS
*/
void Test_Insertion_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
    printf("Time elapsed for Insertion %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(InsertionSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Insertion_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
    printf("Time elapsed for Insertion %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(InsertionSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Insertion_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Insertion %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(InsertionSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}


/*
SHELL TESTS
*/
void Test_Shell_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
    printf("Time elapsed for Shell %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(ShellSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Shell_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
    printf("Time elapsed for Shell %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(ShellSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Shell_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Shell %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(ShellSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}


/*
SELECTION TESTS
*/
void Test_Selection_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
    printf("Time elapsed for Selection %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(SelectionSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Selection_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
    printf("Time elapsed for Selection %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(SelectionSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Selection_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Selection %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(SelectionSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

/*
QUICK TESTS
NOTE: best,worst and average case scenarios are setup different for quick sort than previous sort algorithms
*/

void Test_Quick_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
/*	VectorPrint(vector, PrintInt);*/
    printf("Time elapsed for Quick %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(QuickSort, vector)) / CLOCKS_PER_SEC);
/*	VectorPrint(vector, PrintInt);*/
/*	printf("*************************\n");*/
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Quick_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
    printf("Time elapsed for Quick %u SortedAscending:\t %f\n", _numOfInts,((float)ExecuteTest(QuickSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Quick_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Quick %u SortedDescending:\t %f\n", _numOfInts,((float)ExecuteTest(QuickSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}


/*
MERGE TESTS
*/
void Test_Merge_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
/*	VectorPrint(vector, PrintInt);*/
    printf("Time elapsed for Merge %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(MergeSort, vector)) / CLOCKS_PER_SEC);
/*  VectorPrint(vector, PrintInt);*/
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Merge_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
    printf("Time elapsed for Merge %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(MergeSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Merge_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Merge %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(MergeSort, vector)) / CLOCKS_PER_SEC);
	VectorDestroy(vector,NULL);
	free(intArr);
}


/*
COUNTING TESTS
*/
void Test_Counting_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
    printf("Time elapsed for Counting %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(CountingSort, vector)) / CLOCKS_PER_SEC);
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Counting_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
	QuickSort(vector);
    printf("Time elapsed for Counting %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(CountingSort, vector)) / CLOCKS_PER_SEC);
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Counting_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
	QuickSort(vector);
	FlipVector(vector);
    printf("Time elapsed for Counting %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(CountingSort, vector)) / CLOCKS_PER_SEC);
/*	VectorPrint(vector, (ElementFunc)PrintInt);*/
	VectorDestroy(vector,NULL);
	free(intArr);
}


/*
RADIX TESTS
*/
void Test_Radix_Average(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	VectorPrint(vector, (ElementFunc)PrintInt);
    printf("Time elapsed for Radix %u Average:\t %f\n", _numOfInts,((float)ExecuteTest(RadixSort, vector)) / CLOCKS_PER_SEC);
	VectorPrint(vector, (ElementFunc)PrintInt);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Radix_Best(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	VectorPrint(vector, (ElementFunc)PrintInt);
    printf("Time elapsed for Radix %u Best:\t %f\n", _numOfInts,((float)ExecuteTest(RadixSort, vector)) / CLOCKS_PER_SEC);
	VectorPrint(vector, (ElementFunc)PrintInt);
	VectorDestroy(vector,NULL);
	free(intArr);
}

void Test_Radix_Worst(size_t _numOfInts)
{
	int* intArr;
	Vector* vector;
	intArr = CreateRandomIntArray(_numOfInts, MAX_INT_VAL);
	vector = CreateRandomIntVector(intArr, _numOfInts, INIT_VEC_CAP, VEC_BLOCK_SIZE);
	QuickSort(vector);
	FlipVector(vector);
	VectorPrint(vector, (ElementFunc)PrintInt);
    printf("Time elapsed for Radix %u Worst:\t %f\n", _numOfInts,((float)ExecuteTest(RadixSort, vector)) / CLOCKS_PER_SEC);
	VectorPrint(vector, (ElementFunc)PrintInt);
	VectorDestroy(vector,NULL);
	free(intArr);
}


int main()
{
	size_t numOfInts = 9;
	Vector* dummyVec;
	dummyVec = VectorCreate(10,10);
	VectorPrint(dummyVec, (ElementFunc)PrintInt); /* This is to silence warning of not using PrintInt())*/
	
	srand ((unsigned int)time(NULL));
	
	/*
	AVERAGE
	*/
	printf("********************************************************AVERAGE CASE\n");
/*	Test_Bubble_Average(numOfInts);*/
/*	Test_Shake_Average(numOfInts);*/
/*	Test_Insertion_Average(numOfInts);*/
/*	Test_Shell_Average(numOfInts);*/
/*	Test_Selection_Average(numOfInts);*/
/*	Test_Quick_Average(numOfInts);*/
/*	Test_Merge_Average(numOfInts);*/
/*	Test_Counting_Average(numOfInts);*/
	Test_Radix_Average(numOfInts);
	
	/*
	BEST
	*/
	printf("********************************************************BEST CASE\n");
/*	Test_Bubble_Best(numOfInts);*/
/*	Test_Shake_Best(numOfInts);*/
/*	Test_Insertion_Best(numOfInts);*/
/*	Test_Shell_Best(numOfInts);*/
/*	Test_Selection_Best(numOfInts);*/
/*	Test_Quick_Best(numOfInts);*/
/*	Test_Merge_Best(numOfInts);*/
/*	Test_Counting_Best(numOfInts);*/
	Test_Radix_Best(numOfInts);
	
	/*
	WORST
	*/
	printf("********************************************************WORST CASE\n");
/*	Test_Bubble_Worst(numOfInts);*/
/*	Test_Shake_Worst(numOfInts);*/
/*	Test_Insertion_Worst(numOfInts);*/
/*	Test_Shell_Worst(numOfInts);*/
/*	Test_Selection_Worst(numOfInts);*/
/*	Test_Quick_Worst(numOfInts);*/
/*	Test_Merge_Worst(numOfInts);*/
/*	Test_Counting_Worst(numOfInts);*/
	Test_Radix_Worst(numOfInts);
	
	
	VectorDestroy(dummyVec,NULL);
	return 0;
}


