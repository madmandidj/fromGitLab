/*
Filename: 		TESTSortFunctions.c 
Description:	TEST Implementation of sort functions and performance
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	24/07/17
Modified by:	Eyal Alon
*/
#include "SortFunctions.h"
#include <stdio.h>
#include <stdlib.h> /* size_t, rand, srand */
#include <time.h>   /* time used to initialize srand */
#include <string.h>		

static Vector* InitVec(size_t _numOfItems)
{
    Vector* vec;
	int index;
	int randNum;
	size_t initBlockSize = 2;
	srand(time(NULL));
	vec = VectorCreate(_numOfItems, initBlockSize);
	for (index = 0; index < _numOfItems; ++index)
	{
		randNum = rand() % 1000 + 1;
		VectorAdd(vec, randNum);
	}
    return vec;
}

static int CheckIfSortedAscend(Vector* _vec)
{
	int index;
	int isSorted = 1;
	int numOfItems;
	int curVal;
	int nextVal;
	VectorItemsNum(_vec, &numOfItems);
	for (index = 0; index < numOfItems - 1; ++index)
	{
        VectorGet(_vec, index + 1, &curVal);
        VectorGet(_vec, index + 2, &nextVal);
		if (curVal > nextVal)
		{
			isSorted = 0;
			return isSorted;
		}
	}
	return isSorted;
}

static int CheckIfSortedDescend(Vector* _vec)
{
	int index;
	int isSorted = 1;
	int numOfItems;
	int curVal;
	int nextVal;
	VectorItemsNum(_vec, &numOfItems);
	for (index = 0; index < numOfItems - 1; ++index)
	{
        VectorGet(_vec, index + 1, &curVal);
        VectorGet(_vec, index + 2, &nextVal);
		if (curVal < nextVal)
		{
			isSorted = 0;
			return isSorted;
		}
	}
	return isSorted;
}

static int SortAscend(int _vecValL, int _vecValR)
{
	if (_vecValL > _vecValR)
	{
		return 1;
	}
	return 0;
}

static int SortDescend(int _vecValL, int _vecValR)
{
	if (_vecValR > _vecValL)
	{
		return 1;
	}
	return 0;
}

static void PrintErrResult(char* _testName, ADTErr _err, ADTErr _passErr)
{
    char errString[32];
    if (_err == _passErr)
    {
        printf("PASSED: %s\n", _testName);
    }
    else
    {
        if (_err == ERR_OK)
        {
            strcpy(errString, "ERR_OK");
        }
        else if (_err == ERR_GENERAL)
        {
           strcpy(errString, "ERR_GENERAL");
        }
        else if (_err == ERR_NOT_INITIALIZED)
        {
           strcpy(errString, "ERR_NOT_INITIALIZED");
        }
        else if (_err == ERR_ALLOCATION_FAILED)
        {
           strcpy(errString, "ERR_ALLOCATION_FAILED");
        }
        else if (_err == ERR_REALLOCATION_FAILED)
        {
           strcpy(errString, "ERR_REALLOCATION_FAILED"); 
        }
        else if (_err == ERR_UNDERFLOW)
        {
           strcpy(errString, "ERR_UNDERFLOW"); 
        }
        else if (_err == ERR_OVERFLOW)
        {
           strcpy(errString, "ERR_OVERFLOW");
        }
        else if (_err == ERR_WRONG_INDEX)
        {
           strcpy(errString, "ERR_WRONG_INDEX"); 
        }
        else if (_err == ERR_EMPTY)
        {
           strcpy(errString, "ERR_EMPTY"); 
        }
        else if (_err == ERR_FULL)
        {
           strcpy(errString, "ERR_FULL"); 
        }
        else if (_err == ERR_EMPTY_LIST)
        {
           strcpy(errString, "ERR_EMPTY_LIST"); 
        }
        else if (_err == ERR_EMPTY_HEAP)
        {
           strcpy(errString, "ERR_EMPTY_HEAP"); 
        }
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAILED: %s %s\n", _testName, errString);
    }
    return;
}

static void TestBubbleSortNULLVec()
{
    ADTErr errResult;
    errResult = BubbleSort(NULL);
    PrintErrResult("TestBubbleSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestBubbleSortEmptyVec()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 0;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestBubbleSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}
static void TestBubbleSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestBubbleSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestBubbleSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestBubbleSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestBubbleSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestBubbleSort100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShakeSortNULLVec()
{
    ADTErr errResult;
    errResult = ShakeSort(NULL);
    PrintErrResult("TestShakeSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestShakeSortEmptyVec()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 0;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShakeSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}
static void TestShakeSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShakeSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShakeSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShakeSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShakeSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShakeSort100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortNULLVec()
{
    ADTErr errResult;
    errResult = InsertionSort(NULL, NULL);
    PrintErrResult("TestInsertSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestInsertSortAscend1Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortAscend1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortAscend2Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 2;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortAscend2Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortAscend10Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortAscend10Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortAscend100Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortAscend100Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortAscend2IdenticalItem()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 2;
	size_t initBlockSize = 2;
    int isSorted;
	vec = VectorCreate(numOfItems, initBlockSize);
    VectorAdd(vec, 5);
    VectorAdd(vec, 5);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortAscend2IdenticalItem", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortDescend1Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortDescend;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedDescend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortDescend1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortDescend2Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortDescend;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedDescend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortDescend2Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortDescend10Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortDescend;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedDescend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortDescend10Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortDescend100Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortDescend;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedDescend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortDescend100Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestInsertSortDescend2IdenticalItem()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortDescend;
    size_t numOfItems = 2;
	size_t initBlockSize = 2;
    int isSorted;
	vec = VectorCreate(numOfItems, initBlockSize);
    VectorAdd(vec, 5);
    VectorAdd(vec, 5);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedDescend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestInsertSortDescend2IdenticalItem", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShellSortNULLVec()
{
    ADTErr errResult;
    errResult = InsertionSort(NULL, NULL);
    PrintErrResult("TestShellSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestShellSortEmptyVec()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 0;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShellSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShellSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShellSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShellSort2Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 2;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShellSort2Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShellSort10Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShellSort10Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShellSort100Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = InsertionSort(vec, func);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShellSort100Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestSelectionSortNULLVec()
{
    ADTErr errResult;
    errResult = SelectionSort(NULL);
    PrintErrResult("TestSelectionSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestSelectionSortEmptyVec()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 0;
    vec = InitVec(numOfItems);
    errResult = SelectionSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestSelectionSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestSelectionSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = SelectionSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestSelectionSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestSelectionSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = SelectionSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestSelectionSort100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestBubbleSort1000()
{
	Vector* vec;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort1000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestBubbleSort10000()
{
	Vector* vec;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort10000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestBubbleSort50000()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort50000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestShakeSort1000()
{
	Vector* vec;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    ShakeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestShakeSort1000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestShakeSort10000()
{
	Vector* vec;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    ShakeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestShakeSort10000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestShakeSort50000()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    ShakeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestShakeSort50000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestInsertSort1000()
{
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    InsertionSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestInsertSort1000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestInsertSort10000()
{
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    InsertionSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestInsertSort10000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestInsertSort50000()
{
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    InsertionSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestInsertSort50000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestShellSort1000()
{
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    ShellSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestShellSort1000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestShellSort10000()
{
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    ShellSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestShellSort10000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestShellSort50000()
{
	Vector* vec;
    ShouldSwap func = SortAscend;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    ShellSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestShellSort50000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestSelectionSort1000()
{
	Vector* vec;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    SelectionSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestSelectionSort1000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestSelectionSort10000()
{
	Vector* vec;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    SelectionSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestSelectionSort10000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestSelectionSort50000()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    SelectionSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestSelectionSort50000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestMergeSortRecNULLVec()
{
    ADTErr errResult;
    errResult = MergeSortRec(NULL);
    PrintErrResult("TestMergeSortRecNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestMergeSortRec1Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = MergeSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSortRec1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSortRec2Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 2;
    vec = InitVec(numOfItems);
    errResult = MergeSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSortRec2Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSortRec10Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    VectorPrint(vec);
    printf("\n");
    errResult = MergeSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    VectorPrint(vec);
    printf("\n");
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSortRec10Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSortRec100Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = MergeSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSortRec100Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSort1000()
{
	Vector* vec;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    MergeSortRec(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestMergeSort1000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestMergeSort10000()
{
	Vector* vec;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    MergeSortRec(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestMergeSort10000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestMergeSort50000()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    MergeSortRec(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestMergeSort50000: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}


int main()
{
	/*
    printf("\n");
    printf("API TESTS:\n");
	TestBubbleSortNULLVec();
	TestBubbleSortEmptyVec();
	TestBubbleSort1Item();
	TestBubbleSort10Items();
	TestBubbleSort100Items();
    TestShakeSortNULLVec();
	TestShakeSortEmptyVec();
	TestShakeSort1Item();
	TestShakeSort10Items();
	TestShakeSort100Items();
    TestInsertSortNULLVec();
    TestInsertSortAscend1Item();
    TestInsertSortAscend2Item();
    TestInsertSortAscend10Item();
    TestInsertSortAscend100Item();
    TestInsertSortAscend2IdenticalItem();
    TestInsertSortDescend1Item();
    TestInsertSortDescend2Item();
    TestInsertSortDescend10Item();
    TestInsertSortDescend100Item();
    TestInsertSortDescend2IdenticalItem();
    TestShellSortNULLVec();
    TestShellSortEmptyVec();
    TestShellSort1Item();
    TestShellSort2Item();
    TestShellSort10Item();
    TestShellSort100Item();
    TestSelectionSortNULLVec();
    TestSelectionSortEmptyVec();
    TestSelectionSort10Items();
    TestSelectionSort100Items();
    TestMergeSortRecNULLVec();
    TestMergeSortRec1Item();
    TestMergeSortRec2Item();
    */
    TestMergeSortRec10Item();
    /*
    TestMergeSortRec100Item();
    printf("\n");
    printf("PERFORMANCE TESTS:\n");
    TestBubbleSort1000();
    TestBubbleSort10000();
    TestBubbleSort50000();
    TestShakeSort1000();
    TestShakeSort10000();
    TestShakeSort50000();
    TestInsertSort1000();
    TestInsertSort10000();
    TestInsertSort50000();
    TestShellSort1000();
    TestShellSort10000();
    TestShellSort50000();
    TestSelectionSort1000();
    TestSelectionSort10000();
    TestSelectionSort50000();
    TestMergeSort1000();
    TestMergeSort10000();
    TestMergeSort50000();
    printf("\n");
    */
	return 0;
}
