/*
Filename: 		TESTHeap.c 
Description:	Tests for Implementation of heap API given by Izik.
Created: 		18/07/17
Created by:		Eyal Alon
Last modified: 	19/07/17
Modified by:	Eyal Alon
COMMENTS:		Note: Vector index starts from 1, not 0
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

Vector* InitVec0Vals(Vector* _vec)
{
    size_t initSize = 0;
	size_t extBlockSize = 2;
	Vector* vec;
    vec = VectorCreate(initSize, extBlockSize);
    return vec;
}

Vector* InitVec1Val(Vector* _vec)
{
    size_t initSize = 10;
	size_t extBlockSize = 2;
	Vector* vec;
    vec = VectorCreate(initSize, extBlockSize);
    VectorAdd(vec, 42);
    return vec;
}

Vector* InitVec2Vals(Vector* _vec)
{
    size_t initSize = 10;
	size_t extBlockSize = 2;
	Vector* vec;
    vec = VectorCreate(initSize, extBlockSize);
    VectorAdd(vec, 42);
    VectorAdd(vec, 34);
    return vec;
}

Vector* InitVec9Vals(Vector* _vec)
{
    size_t initSize = 10;
	size_t extBlockSize = 2;
	Vector* vec;
    vec = VectorCreate(initSize, extBlockSize);
    VectorAdd(vec, 0);
    VectorAdd(vec, -10);
    VectorAdd(vec, 22);
    VectorAdd(vec, 34);
    VectorAdd(vec, 1150);
    VectorAdd(vec, 16);
    VectorAdd(vec, 22);
    VectorAdd(vec, 290);
    VectorAdd(vec, -340);
    return vec;
}

Vector* InitVec10Vals(Vector* _vec)
{
    size_t initSize = 10;
	size_t extBlockSize = 2;
	Vector* vec;
    vec = VectorCreate(initSize, extBlockSize);
    VectorAdd(vec, 0);
    VectorAdd(vec, -1);
    VectorAdd(vec, -2);
    VectorAdd(vec, 3);
    VectorAdd(vec, 7);
    VectorAdd(vec, 10);
    VectorAdd(vec, 5);
    VectorAdd(vec, 0);
    VectorAdd(vec, 2);
    VectorAdd(vec, MAGIC_NUM);
    return vec;
}
void TestHeapBuildNULLVec()
{
    Heap* heap;
    heap = HeapBuild(NULL); 
    if (NULL != heap)
    {
        printf("FAILED: TestHeapBuildNULLVec\n");
    }
    else
    {
        printf("PASSED: TestHeapBuildNULLVec\n");
    }
   return;
}

void TestHeapBuildEmptyVec()
{
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec0Vals(vec);
    heap = HeapBuild(vec); 
    if (NULL == heap)
    {
        printf("FAILED: TestHeapBuildEmptyVec\n");
    }
    else
    {
        printf("PASSED: TestHeapBuildEmptyVec\n");
    }
    HeapDestroy(heap);
   return;
}

void TestHeapBuildOneElement()
{
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec1Val(vec);
    heap = HeapBuild(vec); 
    if (NULL == heap)
    {
        printf("FAILED: TestHeapBuildOneElement\n");
    }
    else
    {
        printf("PASSED: TestHeapBuildOneElement\n");
    }
    HeapDestroy(heap);
   return;
}

void TestHeapBuildTenElements()
{
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    if (NULL == heap)
    {
        printf("FAILED: TestHeapBuildTenElements\n");
    }
    else
    {
        printf("PASSED: TestHeapBuildTenElements\n");
    }
    HeapDestroy(heap);
   return;
}

void TestHeapInsertNULLHeap()
{
    ADTErr errResult;
    errResult = HeapInsert(NULL, 200);
    PrintErrResult("TestHeapInsertNULLHeap", errResult, ERR_NOT_INITIALIZED);
   return;
}

void TestHeapInsertEmptyHeap()
{
    ADTErr errResult;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec0Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapInsert(heap, 200);
    PrintErrResult("TestHeapInsertEmptyHeap", errResult, ERR_OK);
    HeapDestroy(heap);
    return;
}

void TestHeapInsertElement()
{
    ADTErr errResult;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapInsert(heap, 200);
    PrintErrResult("TestHeapInsertElement", errResult, ERR_OK);
    HeapDestroy(heap);
    return;
}

void TestHeapMaxNULLHeapNULLData()
{
    ADTErr errResult;
    errResult = HeapMax(NULL, NULL);
    PrintErrResult("TestHeapMaxNULLHeapNULLData", errResult, ERR_NOT_INITIALIZED);
    return;
}

void TestHeapMaxNULLHeap()
{
    ADTErr errResult;
    int data;
    errResult = HeapMax(NULL, &data);
    PrintErrResult("TestHeapMaxNULLHeap", errResult, ERR_NOT_INITIALIZED);
    return;
}

void TestHeapMaxNULLData()
{
    ADTErr errResult;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapMax(heap, NULL);
    PrintErrResult("TestHeapMaxNULLData", errResult, ERR_NOT_INITIALIZED);
    HeapDestroy(heap);
    return;
}

void TestHeapMaxEmptyHeap()
{
    ADTErr errResult;
    int data;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec0Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapMax(heap, &data);
    PrintErrResult("TestHeapMaxEmptyHeap", errResult, ERR_EMPTY_HEAP);
    HeapDestroy(heap);
    return;
}

void TestHeapMax()
{
    ADTErr errResult;
    int data;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapMax(heap, &data);
    if (MAGIC_NUM == data)
    {
        PrintErrResult("TestHeapMax", errResult, ERR_OK);
    }
    else
    {
        printf("FAILED: TestHeapMax HeapMax value incorrect\n");
    }
    HeapDestroy(heap);
   return;
}

void TestHeapExtractMaxNULLHeapNULLData()
{
    ADTErr errResult;
    errResult = HeapExtractMax(NULL, NULL);
    PrintErrResult("TestExtractMaxNULLHeapNULLData", errResult, ERR_NOT_INITIALIZED);
    return;
}

void TestHeapExtractMaxNULLHeap()
{
    ADTErr errResult;
    int data;
    errResult = HeapExtractMax(NULL, &data);
    PrintErrResult("TestHeapExtractMaxNULLHeap", errResult, ERR_NOT_INITIALIZED);
    return;
}

void TestHeapExtractMaxNULLData()
{
    ADTErr errResult;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapExtractMax(heap, NULL);
    PrintErrResult("TestHeapExtractMaxNULLData", errResult, ERR_NOT_INITIALIZED);
    HeapDestroy(heap);
    return;
}

void TestHeapExtractMaxEmptyHeap()
{
    ADTErr errResult;
    int data;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec0Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapExtractMax(heap, &data);
    PrintErrResult("TestHeapExtractMaxEmptyHeap", errResult, ERR_EMPTY_HEAP);
    HeapDestroy(heap);
    return;
}

void TestHeapExtractMax()
{
    ADTErr errResult;
    int data;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    errResult = HeapExtractMax(heap, &data);
    if (MAGIC_NUM == data)
    {
        PrintErrResult("TestHeapExtractMax", errResult, ERR_OK);
    }
    else
    {
        printf("FAILED: TestHeapExtractMax value incorrect\n");
    }
    HeapDestroy(heap);
   return;
}

void TestHeapItemsNumNULLHeap()
{
    int intResult;
    intResult = HeapItemsNum(NULL);
    if (intResult == 0)
    {
        printf("PASSED: TestHeapItemsNumNULLHeap\n");
    }
    else
    {
        printf("FAILED: TestHeapItemsNumNULLHeap\n");
    }
    return;
}

void TestHeapItemsNumEmptyHeap()
{
    int intResult;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec0Vals(vec);
    heap = HeapBuild(vec); 
    intResult = HeapItemsNum(heap);
    if (intResult == 0)
    {
        printf("PASSED: TestHeapItemsNumEmptyHeap\n");
    }
    else
    {
        printf("FAILED: TestHeapItemsNumEmptyHeap\n");
    }
    HeapDestroy(heap);
    return;
}

void TestHeapItemsNum()
{
    int intResult;
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec); 
    intResult = HeapItemsNum(heap);
    if (intResult == 10)
    {
        printf("PASSED: TestHeapItemsNum\n");
    }
    else
    {
        printf("FAILED: TestHeapItemsNum\n");
    }
    HeapDestroy(heap);
    return;
}

void TestHeapDoubleDestroy()
{
    Heap* heap;
    Vector* vec = NULL;
    vec = InitVec10Vals(vec);
    heap = HeapBuild(vec);
    HeapDestroy(heap);
    HeapDestroy(heap);
    printf("PASSED: TestHeapDoubleDestroy\n");
    return; 
}

int main()
{
    printf("\n");
	TestHeapBuildNULLVec();
    TestHeapBuildEmptyVec();
    TestHeapBuildOneElement();
    TestHeapBuildTenElements();
    TestHeapInsertNULLHeap();
    TestHeapInsertEmptyHeap();
    TestHeapInsertElement();
    TestHeapMaxNULLHeapNULLData();
    TestHeapMaxNULLHeap();
    TestHeapMaxNULLData();
    TestHeapMaxEmptyHeap();
    TestHeapMax();
    TestHeapExtractMaxNULLHeapNULLData();
    TestHeapExtractMaxNULLHeap();
    TestHeapExtractMaxNULLData();
    TestHeapExtractMaxEmptyHeap();
    TestHeapExtractMax();
    TestHeapItemsNumNULLHeap();
    TestHeapItemsNumEmptyHeap();
    TestHeapItemsNum();
    TestHeapDoubleDestroy();
    printf("\n");
	return 0;
}
