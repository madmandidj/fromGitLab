/*
Filename: 		TESTSortPerformance.c 
Description:	Tests for sort performance
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	24/07/17
Modified by:	Eyal Alon
*/
#include "SortPerformance.h"
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
	srand (time(NULL));
	vec = VectorCreate(_numOfItems, initBlockSize);
	for (index = 0; index < _numOfItems; ++index)
	{
		randNum = rand() % 100 + 1;
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

static void TestInsertSortAscend1000Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    errResult = InsertionSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestInsertSortAscend1000Item: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestInsertSortAscend10000Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    errResult = InsertionSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestInsertSortAscend10000Item: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}

static void TestInsertSortAscend50000Item()
{
    ADTErr errResult;
	Vector* vec;
    ShouldSwap func = SortAscend;
    int isSorted;
    size_t numOfItems = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    vec = InitVec(numOfItems);
    start_t = clock();
    errResult = InsertionSort(vec, func);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestInsertSortAscend50000Item: %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VectorDestroy(vec);
}



int main()
{
    printf("\n");
	TestInsertSortAscend1000Item();
	TestInsertSortAscend10000Item();
	TestInsertSortAscend50000Item();
    printf("\n");
	return 0;
}
