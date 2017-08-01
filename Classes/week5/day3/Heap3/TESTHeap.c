/*
Filename: 		Heap.c 
Description:	Tests for Implementation of heap API given by Izik.
Created: 		18/07/17
Created by:		Eyal Alon
Last modified: 	18/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <string.h>
#include "Heap.h"

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
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAILED: %s %s\n", _testName, errString);
    }
    return;
}


int main()
{
	size_t initSize = 10;
	size_t extBlockSize = 2;
	Vector* vec;
	int index;
	Heap* heap;
    int data;
	vec = VectorCreate(initSize, extBlockSize);

    VectorAdd(vec, 0);
    VectorAdd(vec, -10);
    VectorAdd(vec, 22);
    VectorAdd(vec, 34);
    VectorAdd(vec, 1150);
    VectorAdd(vec, 16);
    VectorAdd(vec, 42);
    VectorAdd(vec, 22);
    VectorAdd(vec, 290);
    VectorAdd(vec, -340);


	// for (index = 1; index <= 9; ++index)
	// {
	// 	VectorAdd(vec, index*10);
	// }
	VectorPrint(vec);
	printf("***\n");
	heap = HeapBuild(vec);
	HeapPrint(heap);

    HeapMax(heap, &data);
    printf("***%d\n", data);
	HeapDestroy(heap);
	

    /*
    TestBuildNULLVec();
    TestBuildEmptyVec();
    TestBuildOneElement();
    TestBuildTwoElements();
    TestBuildNineElements();
    TestBuildTenElements();
    TestHeapInsertNULLHeap();
    TestHeapInsertEmptyHeap();
    TestHeapInsertOneElement();
    TestHeapInsertTwoElements();
    TestHeapInsertNineElements();
    TestHeapInsertTenElements();
    TestHeapMaxNULLHeap();
    TestHeapMaxEmptyHeap();
    TestHeapMax();
    TestExtractMaxNULLHeap();
    TestExtractMaxEmptyHeap();

    */
	
	return 0;
}
