/*
Filename: 		TestQuickSort.c 
Description:	TEST Implementation of Quick Sort using Vector given by Ronny
Created: 		21/07/17
Created by:		Eyal Alon
Last modified: 	21/07/17
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
    // VectorAdd(vec, 27);
    // VectorAdd(vec, 36);
    // VectorAdd(vec, 75);
    // VectorAdd(vec, 27);
    // VectorAdd(vec, 52);
    // VectorAdd(vec, 61);
    return vec;
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

/*
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
    size_t numOfItems = 0;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    PrintErrResult("TestBubbleSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}
static void TestBubbleSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    PrintErrResult("TestBubbleSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestBubbleSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
    PrintErrResult("TestBubbleSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestBubbleSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = BubbleSort(vec);
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
    size_t numOfItems = 0;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    PrintErrResult("TestShakeSortEmptyVec", errResult, ERR_OK);
    VectorDestroy(vec);
}
static void TestShakeSort1Item()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 1;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    PrintErrResult("TestShakeSort1Item", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShakeSort10Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 10;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    PrintErrResult("TestShakeSort10Items", errResult, ERR_OK);
    VectorDestroy(vec);
}

static void TestShakeSort100Items()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 100;
    vec = InitVec(numOfItems);
    errResult = ShakeSort(vec);
    PrintErrResult("TestShakeSort100Items", errResult, ERR_OK);
    VectorDestroy(vec);
}
*/


static void TestQuickSortRec()
{
    ADTErr errResult;
	Vector* vec;
    size_t numOfItems = 6;
    vec = InitVec(numOfItems);
    printf("PreSort: \n");
    VectorPrint(vec);
    errResult = QuickSortRec(vec);
    printf("PostSort: \n");
    VectorPrint(vec);
    PrintErrResult("TestQuickSortRec", errResult, ERR_OK);
    VectorDestroy(vec);
}

int main()
{
    printf("\n");
	TestQuickSortRec();
    printf("\n");
	return 0;
}
