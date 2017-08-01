/*
Filename: 		TestQuickSort.c 
Description:	TEST Implementation of Quick Sort using Vector given by Ronny
Created: 		21/07/17
Created by:		Eyal Alon
Last modified: 	22/07/17
Modified by:	Eyal Alon
*/
#include "QuickSort.h"
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

static int CheckIfSorted(Vector* _vec)
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
    isSorted = CheckIfSorted(vec);
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
    isSorted = CheckIfSorted(vec);
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
    isSorted = CheckIfSorted(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortRec10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSortRec100Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 100;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSortRec(vec);
    isSorted = CheckIfSorted(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortRec100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestQuickSortRec1000Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 1000;
    int isSorted;
    vec = InitVec(numOfItems);
    errResult = QuickSortRec(vec);
    isSorted = CheckIfSorted(vec);
    printf("Sorted: %d, ", isSorted);
    PrintErrResult("TestQuickSortRec100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

int main()
{
    printf("\n");
    TestQuickSortRecNULLVec();
    TestQuickSortRecEmptyVec();
    TestQuickSortRec1Items();
	TestQuickSortRec10Items();
    TestQuickSortRec100Items();
    TestQuickSortRec1000Items();
    printf("\n");
	return 0;
}
