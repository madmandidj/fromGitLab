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
#define MAX_RAND_NUM 100
#define MIN_RAND_NUM 2
#define DECIMAL_RADIX 10
/*
TODO:
* Add performance tests for worst and best case scenarios
* Make sure performance makes sense and produces good results
*
*/

/*********	
AUX FUNCTIONS
*********/
static int CountingProcess(int _vecVal, int _digit);
static int GetMaxVecVal(Vector* _vec, int _numOfItems);

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

static Vector* InitVecSorted(size_t _numOfItems)
{
    Vector* vec;
	int index;
	int randNum;
    int maxVal;
	size_t initBlockSize = 2;
    FuncAndKey fAK;
	srand(time(NULL));
	vec = VectorCreate(_numOfItems, initBlockSize);
	for (index = 0; index < _numOfItems; ++index)
	{
		randNum = rand() % MAX_RAND_NUM + MIN_RAND_NUM;
		VectorAdd(vec, randNum);
	}
    maxVal = GetMaxVecVal(vec, _numOfItems);
    fAK.m_fPRArrfFunc = CountingProcess;
    fAK.m_digit = 0;
    CountingSort(vec, maxVal, fAK);
    return vec;
}

static Vector* InitVecSmallAtEnd(size_t _numOfItems)
{
    Vector* vec;
	int index = 0;
	int randNum;
	size_t initBlockSize = 2;
	srand(time(NULL));
	vec = VectorCreate(_numOfItems, initBlockSize);
    while (index < _numOfItems)
    {
        randNum = rand() % MAX_RAND_NUM + MIN_RAND_NUM;
		VectorAdd(vec, randNum);
        VectorAdd(vec, _numOfItems - index);
        ++index;
        VectorItemsNum(vec, &index);
    }
/*    VectorItemsNum(vec, &index);*/
	VectorItemsNum(vec, &index);
    printf("%u\n", index);
	// for (index = 0; index < _numOfItems-1; ++index)
	// {
	// 	randNum = rand() % MAX_RAND_NUM + MIN_RAND_NUM;
	// 	VectorAdd(vec, randNum);
	// }
    // VectorAdd(vec, 1);
    return vec;
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

static int CountingProcess(int _vecVal, int _digit)
{
	return _vecVal;
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

static void TestBubbleSort1000Best()
{
	Vector* vec;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVecSorted(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort1000Best: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestBubbleSort1000Worst()
{
	Vector* vec;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVecSmallAtEnd(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort1000Worst:%f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}


static void TestBubbleSort10000Best()
{
	Vector* vec;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVecSorted(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort1000Best: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestBubbleSort10000Worst()
{
	Vector* vec;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVecSmallAtEnd(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort10000Worst:%f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}


static void TestBubbleSort50000Best()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVecSorted(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort5000Best: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestBubbleSort50000Worst()
{
	Vector* vec;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVecSmallAtEnd(numOfItems);
    start_t = clock();
    BubbleSort(vec);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestBubbleSort50000Worst:%f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}


















/*********	
MAIN
**********/

int main()
{
    printf("\n");
    printf("API TESTS:\n");
    /*
    BUBBLE TESTS
    */
    printf("\n");
    printf("BUBBLE TESTS:\n");
	TestBubbleSortNULLVec();
	TestBubbleSortEmptyVec();
	TestBubbleSort1Item();
	TestBubbleSort10Items();
	TestBubbleSort100Items();

    printf("\n");
    printf("PERFORMANCE TESTS:\n");
    /*
    1000 items
    */
    printf("\n");
    printf("1000 ITEMS:\n");
    TestBubbleSort1000Best();
    TestBubbleSort1000();
    TestBubbleSort1000Worst();

    /*
    10000 items
    */
    printf("\n");
    printf("10000 ITEMS TYPICAL:\n");
    TestBubbleSort10000Best();
    TestBubbleSort10000();
    TestBubbleSort10000Worst();

    /*
    50000 items
    */
    printf("\n");
    printf("50000 ITEMS TYPICAL:\n");
    TestBubbleSort50000Best();
    TestBubbleSort50000();
    TestBubbleSort50000Worst();
    printf("\n");
	return 0;
}
