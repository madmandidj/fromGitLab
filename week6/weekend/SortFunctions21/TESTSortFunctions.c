/*
Filename: 		TESTSortFunctions.c 
Description:	TEST Implementation of sort functions and performance
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/
#include "SortFunctions.h"
#include <stdio.h>
#include <stdlib.h> /* size_t, rand, srand */
#include <time.h>   /* time used to initialize srand */
#include <string.h>	
#define MAX_RAND_NUM 20
#define MIN_RAND_NUM 1
#define DECIMAL_RADIX 10
/*
TODO:
* Add performance tests for worst and best case scenarios
*
*
*/

/*********	
AUX FUNCTIONS
*********/
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
		randNum = rand() % MAX_RAND_NUM + MIN_RAND_NUM;
		VectorAdd(vec, randNum);
	}
    return vec;
}

static int CheckIfSortedAscend(Vector* _vec)
{
	size_t index;
	int isSorted = 1;
	size_t numOfItems;
	int curVal;
	int nextVal;
	VectorItemsNum(_vec, &numOfItems);
    if (0 == numOfItems)
    {
        return isSorted;
    }
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
	size_t numOfItems;
	int curVal;
	int nextVal;
	VectorItemsNum(_vec, &numOfItems);
    if (0 == numOfItems)
    {
        return isSorted;
    }
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















/********************	
BUBBLE SORT FUNCTIONS
********************/


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
    printf("Time elapsed for TestBubbleSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestBubbleSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestBubbleSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}
















/********************	
SHAKE SORT FUNCTIONS
********************/


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
    printf("Time elapsed for TestShakeSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestShakeSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestShakeSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}
















/********************	
INSERT SORT FUNCTIONS
********************/


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
    printf("Time elapsed for TestInsertSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestInsertSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestInsertSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}















/********************	
SHELL SORT FUNCTIONS
********************/


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
    printf("Time elapsed for TestShellSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestShellSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    printf("Time elapsed for TestShellSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}















/********************	
SELECTION SORT FUNCTIONS
********************/


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
    printf("Time elapsed for TestSelectionSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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















/********************	
QUICK SORT FUNCTIONS
********************/


static void TestQuickSortRecNULLVec()
{
    ADTErr errResult;
    errResult = QuickSortRec(NULL);
    PrintErrResult("TestQuickSortRecNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestQuickSortRecEmptyVec()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 0;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortRecEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSortRec1Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 1;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortRec1Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSortRec10Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 10;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortRec10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSortRec50000()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    QuickSortRec(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestQuickSortRec50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestQuickSortNULLVec()
{
    ADTErr errResult;
    errResult = QuickSort(NULL);
    PrintErrResult("TestQuickSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestQuickSortEmptyVec()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 0;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSort1Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 1;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSort1Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 10;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSort50000()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    QuickSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestQuickSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}


















/********************	
MERGE SORT FUNCTIONS
********************/


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
    errResult = MergeSortRec(vec);
    isSorted = CheckIfSortedAscend(vec);
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

static void TestMergeSortNULLVec()
{
    ADTErr errResult;
    errResult = MergeSort(NULL);
    PrintErrResult("TestMergeSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestMergeSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = MergeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSort10Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = MergeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSort10Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSort100Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = MergeSort(vec);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestMergeSort100Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestMergeSortRec1000()
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
    printf("Time elapsed for TestMergeSortRec1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestMergeSortRec10000()
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
    printf("Time elapsed for TestMergeSortRec10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestMergeSortRec50000()
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
    printf("Time elapsed for TestMergeSortRec50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    MergeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestMergeSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    MergeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestMergeSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
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
    MergeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestMergeSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);  
}















/********************	
COUNTING SORT FUNCTIONS
********************/


static int CountingProcess(int _vecVal, int _digit)
{
	return _vecVal;
}

static int GetMaxVecVal(Vector* _vec, int _numOfItems)
{
	size_t index;
	int maxVal = 0;
	int vecVal;
	for (index = 1; index <= _numOfItems; ++index)
	{
		VectorGet(_vec, index, &vecVal);
		if (vecVal > maxVal)
		{
			maxVal = vecVal;
		}
	}
	maxVal += 1;
	return maxVal;
}

static void TestCountingSortNULLVec()
{
    ADTErr errResult;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    errResult = CountingSort(NULL, 1, fAK);
    PrintErrResult("TestCountingSortNULLVec", errResult, ERR_NOT_INITIALIZED);
}

static void TestCountingSort1Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    int maxVal;
    size_t numOfItems = 1;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxVal = GetMaxVecVal(vec, numOfItems);
    errResult = CountingSort(vec, maxVal, fAK);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestCountingSort1Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestCountingSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    int maxVal;
    size_t numOfItems = 10;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxVal = GetMaxVecVal(vec, numOfItems);
    errResult = CountingSort(vec, maxVal, fAK);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestCountingSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestCountingSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    int maxVal;
    size_t numOfItems = 100;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxVal = GetMaxVecVal(vec, numOfItems);
    errResult = CountingSort(vec, maxVal, fAK);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestCountingSort100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestCountingSort1000()
{
	Vector* vec;
	int maxVal;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxVal = GetMaxVecVal(vec, numOfItems);
    start_t = clock();
    CountingSort(vec, maxVal, fAK);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestCountingSort1000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec); 
}

static void TestCountingSort10000()
{
	Vector* vec;
	int maxVal;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxVal = GetMaxVecVal(vec, numOfItems);
    start_t = clock();
    CountingSort(vec, maxVal, fAK);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestCountingSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec); 
}

static void TestCountingSort50000()
{
	Vector* vec;
	int maxVal;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxVal = GetMaxVecVal(vec, numOfItems);
    start_t = clock();
    CountingSort(vec, maxVal, fAK);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestCountingSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec); 
}




















/********************	
RADIX SORT FUNCTIONS
********************/
static int FindMaxDigits(Vector* _vec, int _numOfItems)
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

static void TestRadixSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 1;
    int maxDigits = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    errResult = RadixSort(vec, maxDigits);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestRadixSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestRadixSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 10;
    int maxDigits = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    errResult = RadixSort(vec, maxDigits);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestRadixSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestRadixSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 100;
    int maxDigits = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    errResult = RadixSort(vec, maxDigits);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestRadixSort100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestRadixSort1000Items()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 1000;
    int maxDigits = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    errResult = RadixSort(vec, maxDigits);
    isSorted = CheckIfSortedAscend(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestRadixSort1000Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestRadixSort1000()
{
	Vector* vec;
    int maxDigits = 0;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    start_t = clock();
    RadixSort(vec, maxDigits);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestRadixSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec); 
}

static void TestRadixSort10000()
{
	Vector* vec;
    int maxDigits = 0;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    start_t = clock();
    RadixSort(vec, maxDigits);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestRadixSort10000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec); 
}

static void TestRadixSort50000()
{
	Vector* vec;
    int maxDigits = 0;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    FuncAndKey fAK;
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    vec = InitVec(numOfItems);
    maxDigits = FindMaxDigits(vec, numOfItems);
    start_t = clock();
    RadixSort(vec, maxDigits);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestRadixSort50000:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec); 
}














static void TestBubbleSort50000ItemsTEMP()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    // vec = VectorCreate(numOfItems, 2);
    // VectorAdd(vec, 7);
    // VectorAdd(vec, 3);
    // VectorAdd(vec, 1);
    // VectorAdd(vec, 7);
    // VectorAdd(vec, 19);
    // VectorAdd(vec, 12);
    // VectorAdd(vec, 17);
    // VectorAdd(vec, 14);
    // VectorAdd(vec, 4);
    // VectorAdd(vec, 12);
    // VectorPrint(vec);
    printf("\n");
    start_t = clock();
    errResult = BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    isSorted = CheckIfSortedAscend(vec);
    // VectorPrint(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestBubbleSort50000ItemsTEMP", errResult, ERR_OK);
    printf("Time elapsed for TestBubbleSort50000ItemsTEMP:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}


static void TestShakeSort50000ItemsTEMP()
{
    ADTErr errResult;
	Vector* vec;
    int isSorted;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    // vec = VectorCreate(numOfItems, 2);
    // VectorAdd(vec, 7);
    // VectorAdd(vec, 3);
    // VectorAdd(vec, 1);
    // VectorAdd(vec, 7);
    // VectorAdd(vec, 19);
    // VectorAdd(vec, 12);
    // VectorAdd(vec, 17);
    // VectorAdd(vec, 14);
    // VectorAdd(vec, 4);
    // VectorAdd(vec, 12);
    // VectorPrint(vec);
    printf("\n");
    start_t = clock();
    errResult = ShakeSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    isSorted = CheckIfSortedAscend(vec);
    // VectorPrint(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestShakeSort50000ItemsTEMP()", errResult, ERR_OK);
    printf("Time elapsed for TestShakeSort50000ItemsTEMP():\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

/*********	
MAIN
**********/

int main()
{
    TestBubbleSort50000ItemsTEMP();
    TestShakeSort50000ItemsTEMP();
    return 1;
}
int main1()
{
    printf("\n");
    printf("API TESTS:\n");
    /*
    BUBBLE TESTS
    */

	TestBubbleSortNULLVec();
	TestBubbleSortEmptyVec();
	TestBubbleSort1Item();
	TestBubbleSort10Items();
	TestBubbleSort100Items();
    /*
    SHAKE TESTS
    */

    TestShakeSortNULLVec();
	TestShakeSortEmptyVec();
	TestShakeSort1Item();
	TestShakeSort10Items();
	TestShakeSort100Items();
    /*
    INSERT TESTS
    */

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

    /*
    SHELL TESTS
    */
    TestShellSortNULLVec();
    TestShellSortEmptyVec();
    TestShellSort1Item();
    TestShellSort2Item();
    TestShellSort10Item();
    TestShellSort100Item();

    /*
    SELECTION TESTS
    */
    TestSelectionSortNULLVec();
    TestSelectionSortEmptyVec();
    TestSelectionSort10Items();
    TestSelectionSort100Items();

    /*
    QUICK TESTS
    */
    TestQuickSortRecNULLVec();
    TestQuickSortRecEmptyVec();
    TestQuickSortRec1Items();
    TestQuickSortRec10Items();
    TestQuickSortNULLVec();
    TestQuickSortEmptyVec();
    TestQuickSort1Items();
    TestQuickSort10Items();

    /*
    MERGE TESTS
    */
    TestMergeSortRecNULLVec();
    TestMergeSortRec1Item();
    TestMergeSortRec2Item();
    TestMergeSortRec10Item();
    TestMergeSortRec100Item();
    TestMergeSortNULLVec();
    TestMergeSort1Item();
    TestMergeSort10Item();
    TestMergeSort100Item();

    /*
    COUNTING TESTS
    */
    TestCountingSortNULLVec();
    TestCountingSort1Items();
    TestCountingSort10Items();
    TestCountingSort100Items();

    /*
    RADIX TESTS
    */
    TestRadixSort1Item();
	TestRadixSort10Items();
    TestRadixSort100Items();
    TestRadixSort1000Items();
    printf("\n");
    printf("PERFORMANCE TESTS:\n");

    /*
    1000 items
    */
    TestBubbleSort1000();
    TestShakeSort1000();
    TestInsertSort1000();
    TestShellSort1000();
    TestSelectionSort1000();
    TestMergeSortRec1000();
    TestMergeSort1000();
    TestCountingSort1000();
    TestRadixSort1000();

    /*
    10000 items
    */
    TestBubbleSort10000();
    TestShakeSort10000();
    TestInsertSort10000();
    TestShellSort10000();
    TestSelectionSort10000();
    TestMergeSortRec10000();
    TestMergeSort10000();
    TestCountingSort10000();
    TestRadixSort10000();

    /*
    50000 items
    */
    TestBubbleSort50000();
    TestShakeSort50000();
    TestInsertSort50000();
    TestShellSort50000();
    TestSelectionSort50000();
    TestQuickSortRec50000();
    TestQuickSort50000();
    TestMergeSortRec50000();
    TestMergeSort50000();
    TestCountingSort50000();
    TestRadixSort50000();
    printf("\n");
	return 0;
}
