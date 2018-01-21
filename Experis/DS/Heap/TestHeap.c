
/*
Filename: 		TestHeap.c 
Description:	Unit tests for implementation of generic heap API.
Created: 		10/08/17
Created by:		Eyal Alon
Last modified: 	12/08/17
Modified by:	Eyal Alon
COMMENTS:		First element in vector is index 1
*/

#define TRUE 			1
#define FALSE 			0
#define INVALID 		-1

#include <stdio.h>      /* printf */
#include <stdlib.h>     /* malloc */
#include <string.h>     /* strcpy */
#include <assert.h>     /* assert */
#include <time.h>       /* srand */
#include "../../inc/Heap.h"

typedef struct Person Person;
struct Person
{
	size_t 		m_age;
	char 		m_name[64];
	size_t 		m_famSize;
	Person**	m_family;
};




/*****
PRINT HEAP ERROR FUNCTION
*****/
static void PrintErrResult(char* _testName, HeapResult _err, HeapResult _passErr)
{
    char errString[64];
    if (_err == _passErr)
    {
        printf("PASS: %s\n", _testName);
    }
    else
    {
        if (_err == HEAP_SUCCESS)
        {
            strcpy(errString, "HEAP_SUCCESS");
        }
        else if (_err == HEAP_NOT_INITIALIZED)
        {
           strcpy(errString, "HEAP_NOT_INITIALIZED");
        }
        else if (_err == HEAP_REALLOCATION_FAILED)
        {
           strcpy(errString, "HEAP_REALLOCATION_FAILED");
        }
        else if (_err == HEAP_INV_ARG)
        {
           strcpy(errString, "HEAP_INV_ARG");
        }
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAIL: %s %s\n", _testName, errString);
    }
    return;
}


/*****
INIT FUNCTIONS
*****/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    return arr;
}
/*******************************/
static int* InitRandIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = rand() % 100;
    }
    return arr;
}
/*******************************/
static void InitPersonArr(Person* _arr)
{
	size_t numOfPersons = 5;
	size_t numOfFamily = 2;
	size_t index;
	size_t indexDealloc;
	size_t indexFam;
	char* names[] = {"Eyal\0", "Yodo\0", "Erez\0", "Eli\0", "Hana\0"};
	size_t ages[] = {4, 7, 6, 8, 9};
	for (index = 0; index < numOfPersons; ++index)
	{
		_arr[index].m_famSize = numOfFamily;
		_arr[index].m_age = ages[index];
		strcpy(_arr[index].m_name, names[index]);
		_arr[index].m_family = malloc(numOfFamily * sizeof(Person));
		if (NULL == _arr[index].m_family)
		{
			for (indexDealloc = index - 1; indexDealloc > 0; --indexDealloc)
			{
				free(_arr[index].m_family);
			}
			free(_arr);
			return;
		}
		for (indexFam = 0; indexFam < numOfFamily; ++indexFam)
		{
			_arr[index].m_family[indexFam] = &_arr[indexFam];
		}
	}
	_arr[0].m_family[0] = &_arr[1];
	_arr[0].m_family[1] = &_arr[2];
	_arr[1].m_family[0] = &_arr[3];
	_arr[1].m_family[1] = &_arr[4];
	return;
}
/*******************************/
static void VecAppendIntElements(Vector* _vec, int* _arr, size_t _numOfElements)
{
    size_t index;

    for (index = 0; index < _numOfElements; ++index)
    {
        VecAppend(_vec, _arr + index);
    }
    return;
}
/*******************************/
static void VecAppendPersonElements(Vector* _vec, Person* _arr, size_t _numOfElements)
{
    size_t index;

    for (index = 0; index < _numOfElements; ++index)
    {
        VecAppend(_vec, _arr + index);
    }
    return;
}






/*****
LESS THAN FUNCTIONS
*****/
int LessThanInt(int* _left, int* _right)
{
    if (!_left || !_right)
    {
        return INVALID;
    }
	if (*_left <= *_right)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
/*******************************/
int LessThanPersonAge(Person* _left, Person* _right)
{
    if (!_left || !_right)
    {
        return INVALID;
    }
	if (_left->m_age <= _right->m_age)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}







/*****
ACTION FUNCTIONS
*****/
int DummyElementIntAction(void* _element, void* _context)
{
    return TRUE;
}
/*******************************/
int	StopCountAtIntValFive(int* _element, int* _context)
{
    if (*_element == *_context)
    {
        return FALSE;
    }
	return TRUE;
}
/*******************************/
int	ElementIntPrint(void* _element, void* _context)
{
	printf("Value = %d\n", *(int*)_element);
	return TRUE;
}
/*******************************/
int	ElementPersonPrint(Person* _element, void* _context)
{
	printf("Name: %s, Age = %u\n", _element->m_name, _element->m_age);
	return TRUE;
}
/*******************************/
void VecElementDestroyPerson(void* _element)
{
	Person* perElement = (Person*) _element;
	if (NULL != perElement->m_family)
	{
		free(perElement->m_family);
	}
	return;
}








/*****
HEAP BUILD TESTS
*****/
static void TestHeapBuild_NULLVec()
{
    Heap* heap;

    heap = HeapBuild(NULL , (LessThanComparator) LessThanInt);
    NULL == heap ? printf("PASS: TestHeapBuild_NULLVec()\n") : printf("FAIL: TestHeapBuild_NULLVec()\n");
    return;
}
/*******************************/
static void TestHeapBuild_NULLPFLess()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;

    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , NULL);
    VecDestroy(&vec, NULL);
    NULL == heap ? printf("PASS: TestHeapBuild_NULLPFLess()\n") : printf("FAIL: TestHeapBuild_NULLPFLess()\n");
    return;
}
/*******************************/
static void TestHeapBuild_EmptyVec()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;

    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    NULL != heap ? printf("PASS: TestHeapBuild_EmptyVec()\n") : printf("FAIL: TestHeapBuild_EmptyVec()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;
}
/*******************************/
static void TestHeapBuild_OneElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 1;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfVecElements == HeapSize(heap) ? printf("PASS: TestHeapBuild_OneElement()\n") : printf("FAIL: TestHeapBuild_OneElement()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_TwoElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 2;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfVecElements == HeapSize(heap) ? printf("PASS: TestHeapBuild_TwoElement()\n") : printf("FAIL: TestHeapBuild_TwoElement()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_TenElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfVecElements == HeapSize(heap) ? printf("PASS: TestHeapBuild_TenElement()\n") : printf("FAIL: TestHeapBuild_TenElement()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_NULLElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    VecAppend(vec, NULL);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    NULL == heap ? printf("PASS: TestHeapBuild_NULLElement()\n") : printf("FAIL: TestHeapBuild_NULLElement()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_TenElementOrderCorrect()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;
    int correctIntOrder[10] = {9, 8, 6, 7, 4, 5, 2, 0, 3, 1};
    int* vecElement;
    size_t index;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    for (index = 0; index < numOfVecElements; ++index)
    {
        VecGet(vec, index + 1, (void**)&vecElement);
        if (*vecElement != correctIntOrder[index])
        {
            printf("FAIL: TestHeapBuild_TenElementOrderCorrect()\n");
            return;
        }
    }
    printf("PASS: TestHeapBuild_TenElementOrderCorrect()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_FivePersons()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    Person* arr;
    size_t numOfPersons = 5;
    size_t numOfVecElements = 5;

    arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
    InitPersonArr(arr);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendPersonElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanPersonAge);
    numOfVecElements == HeapSize(heap) ? printf("PASS: TestHeapBuild_FivePersons()\n") : printf("FAIL: TestHeapBuild_FivePersons()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, VecElementDestroyPerson);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_FivePersonsOrderCorrect()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    Person* arr;
    size_t numOfPersons = 5;
    size_t numOfVecElements = 5;
    size_t correctPersonAgeOrder[5] = {9, 8, 6, 4, 7};
    Person* vecElement;
    size_t index;

    arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
    InitPersonArr(arr);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendPersonElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanPersonAge);
    for (index = 0; index < numOfVecElements; ++index)
    {
        VecGet(vec, index + 1, (void**)&vecElement);
        if (vecElement->m_age != correctPersonAgeOrder[index])
        {
            printf("FAIL: TestHeapBuild_FivePersonsOrderCorrect()\n");
            return;
        }
    }
    printf("PASS: TestHeapBuild_FivePersonsOrderCorrect()\n");
    HeapDestroy(&heap);
    VecDestroy(&vec, VecElementDestroyPerson);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_1000ElementTypical()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 1000;
    size_t numOfVecElements = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;

    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    start_t = clock();
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestHeapBuild_1000ElementTypical:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_10000ElementTypical()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10000;
    size_t numOfVecElements = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;

    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    start_t = clock();
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestHeapBuild_10000ElementTypical:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuild_50000ElementTypical()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 50000;
    size_t numOfVecElements = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;

    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    start_t = clock();
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestHeapBuild_50000ElementTypical:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}




/*****
HEAP DESTROY TESTS
*****/
static void TestHeapDestroy_NULLHeap()
{
    HeapDestroy(NULL);
    printf("PASS: TestHeapDestroy_NULLHeap()\n");
    return;
}
/*******************************/
static void TestHeapDestroy_EmptyHeap()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;

    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    HeapDestroy(&heap);
    NULL == heap ? printf("PASS: TestHeapDestroy_EmptyHeap()\n") : printf("FAIL: TestHeapDestroy_EmptyHeap()\n");
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapDestroy_OK()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    HeapDestroy(&heap);
    NULL == heap ? printf("PASS: TestHeapDestroy_OK()\n") : printf("FAIL: TestHeapDestroy_OK()\n");
    VecDestroy(&vec, NULL);
    free(arr);
    return;

}
/*******************************/
static void TestHeapDestroy_StructOK()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    Person* arr;
    size_t numOfPersons = 5;
    size_t numOfVecElements = 5;

    arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
    InitPersonArr(arr);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendPersonElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanPersonAge);
    HeapDestroy(&heap);
    NULL == heap ? printf("PASS: TestHeapDestroy_StructOK()\n") : printf("FAIL: TestHeapDestroy_StructOK()\n");
    VecDestroy(&vec, VecElementDestroyPerson);
    free(arr);
    return;
}
/*******************************/
static void TestHeapDestroy_VecNotDestroyed()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    Person* arr;
    size_t numOfPersons = 5;
    size_t numOfVecElements = 5;
    size_t correctPersonAgeOrder[5] = {9, 8, 6, 4, 7};
    Person* vecElement;
    size_t index;

    arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
    InitPersonArr(arr);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendPersonElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanPersonAge);
    HeapDestroy(&heap);
    for (index = 0; index < numOfVecElements; ++index)
    {
        VecGet(vec, index + 1, (void**)&vecElement);
        if (vecElement->m_age != correctPersonAgeOrder[index])
        {
            printf("FAIL: TestHeapDestroy_VecNotDestroyed()\n");
            return;
        }
    }
    printf("PASS: TestHeapDestroy_VecNotDestroyed()\n");
    VecDestroy(&vec, VecElementDestroyPerson);
    free(arr);
    return;
}
/*******************************/
static void TestHeapDestroy_DoubleDestroy()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    HeapDestroy(&heap);
    HeapDestroy(&heap);
    NULL == heap ? printf("PASS: TestHeapDestroy_DoubleDestroy()\n") : printf("FAIL: TestHeapDestroy_DoubleDestroy()\n");
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}







/*****
HEAP INSERT TESTS
*****/
static void TestHeapInsert_NULLHeap()
{
    int* arr;
    size_t numOfInts = 10;
    HeapResult err;

    arr = InitIntArr(numOfInts);
    err = HeapInsert(NULL, arr + 5);
    PrintErrResult("TestHeapInsert_NULLHeap", err, HEAP_NOT_INITIALIZED);
    free(arr);
    return;
}
/*******************************/
static void TestHeapInsert_NULLElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;
    HeapResult err;


    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    err = HeapInsert(heap, NULL);
    PrintErrResult("TestHeapInsert_NULLElement", err, HEAP_INV_ARG);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapInsert_EmptyHeap()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    HeapResult err;


    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    err = HeapInsert(heap, arr + 5);
    PrintErrResult("TestHeapInsert_EmptyHeap", err, HEAP_SUCCESS);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapInsert_TwoElements()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    HeapResult err;


    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    HeapInsert(heap, arr + 5);
    err = HeapInsert(heap, arr + 9);
    PrintErrResult("TestHeapInsert_TwoElements", err, HEAP_SUCCESS);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapInsert_TenElements()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;
    size_t index;
    HeapResult err;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    for (index = 0; index < numOfVecElements; ++index)
    {
        err = HeapInsert(heap, arr + index);
        if (HEAP_SUCCESS != err)
        {
            printf("FAIL: TestHeapInsert_TenElements()\n");
        }
    }
    if (HEAP_SUCCESS == err)
    {
        printf("PASS: TestHeapInsert_TenElements()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuildTenElements_ThenInsert()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;
    HeapResult err;


    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    err = HeapInsert(heap, arr + 9);
    PrintErrResult("TestHeapBuildTenElements_ThenInsert", err, HEAP_SUCCESS);
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapBuildFiveElements_ThenInsertMax()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    int* extractVal;
    size_t numOfInts = 10;
    size_t numOfVecElements = 5;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    HeapInsert(heap, arr + 9);
    extractVal = HeapExtract(heap);
    if (arr[9] ==  *extractVal)
    {
        printf("PASS: TestHeapBuildFiveElements_ThenInsertMax()\n");
    }
    else
    {
        printf("FAIL: TestHeapBuildFiveElements_ThenInsertMax()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}









/*****
HEAP PEEK TESTS
*****/
static void TestHeapPeek_NULLHeap()
{
    const int* element;
    element = HeapPeek(NULL);
    if (NULL == element)
    {
        printf("PASS: TestHeapPeek_NULLHeap()\n");
    }
    else
    {
        printf("FAIL: TestHeapPeek_NULLHeap()\n");
    }
    return;
}
/*******************************/
static void TestHeapPeek_EmptyHeap()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    const int* element;

    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    element = HeapPeek(heap);
    if (NULL == element)
    {
        printf("PASS: TestHeapPeek_EmptyHeap()\n");
    }
    else
    {
        printf("FAIL: TestHeapPeek_EmptyHeap()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapPeek_OneElement()
{
    Heap* heap;
    Vector* vec;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 1;
    const int* element;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    element = HeapPeek(heap);
    if (arr[0] == *element)
    {
        printf("PASS: TestHeapPeek_OneElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapPeek_OneElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapPeek_TwoElement()
{
    Heap* heap;
    Vector* vec;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 2;
    const int* element;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    element = HeapPeek(heap);
    if (arr[1] == *element)
    {
        printf("PASS: TestHeapPeek_TwoElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapPeek_TwoElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapPeek_TenElement()
{
    Heap* heap;
    Vector* vec;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 10;
    const int* element;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    element = HeapPeek(heap);
    if (arr[9] == *element)
    {
        printf("PASS: TestHeapPeek_TenElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapPeek_TenElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}







/*****
HEAP SIZE TESTS
*****/
static void TestHeapSize_NULLHeap()
{
    size_t size;
    size = HeapSize(NULL);
    if (FALSE == size)
    {
        printf("PASS: TestHeapSize_NULLHeap()\n");
    }
    else
    {
        printf("FAIL: TestHeapSize_NULLHeap()\n");
    }
    return;
}
/*******************************/
static void TestHeapSize_EmptyHeap()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t size;

    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    size = HeapSize(heap);
    if (FALSE == size)
    {
        printf("PASS: TestHeapSize_EmptyHeap()\n");
    }
    else
    {
        printf("FAIL: TestHeapSize_EmptyHeap()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapSize_OneElement()
{
    Heap* heap;
    Vector* vec;
    size_t size;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 1;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    size = HeapSize(heap);
    if (1 == size)
    {
        printf("PASS: TestHeapSize_OneElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapSize_OneElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapSize_TwoElement()
{
    Heap* heap;
    Vector* vec;
    size_t size;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 2;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    size = HeapSize(heap);
    if (2 == size)
    {
        printf("PASS: TestHeapSize_TwoElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapSize_TwoElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapSize_TenElement()
{
    Heap* heap;
    Vector* vec;
    size_t size;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    size = HeapSize(heap);
    if (10 == size)
    {
        printf("PASS: TestHeapSize_TenElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapSize_TenElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapSize_AfterInsert()
{
    Heap* heap;
    Vector* vec;
    size_t size;
    int* arr;
    size_t numOfInts = 10;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    HeapInsert(heap,  arr + 5);
    size = HeapSize(heap);
    if (11 == size)
    {
        printf("PASS: TestHeapSize_AfterInsert()\n");
    }
    else
    {
        printf("FAIL: TestHeapSize_AfterInsert()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}







/*****
HEAP FOR EACH TESTS
*****/
static void TestHeapForEach_NULLHeap()
{
    size_t numOfActions;
    numOfActions = HeapForEach(NULL, (ActionFunction) DummyElementIntAction, NULL);
    if (FALSE == numOfActions)
    {
        printf("PASS: TestHeapForEach_NULLHeap()\n");
    }
    else
    {
        printf("FAIL: TestHeapForEach_NULLHeap()\n");
    }
    return;
}
/*******************************/
static void TestHeapForEach_EmptyHeap()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfActions;

    vec = VecCreate(initialCapacity, blockSize);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfActions = HeapForEach(heap, (ActionFunction) DummyElementIntAction, NULL);
    if (FALSE == numOfActions)
    {
        printf("PASS: TestHeapForEach_EmptyHeap()\n");
    }
    else
    {
        printf("FAIL: TestHeapForEach_EmptyHeap()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapForEach_OneElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfActions;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 1;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfActions = HeapForEach(heap, (ActionFunction) DummyElementIntAction, NULL);
    if (numOfVecElements == numOfActions)
    {
        printf("PASS: TestHeapForEach_OneElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapForEach_OneElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapForEach_TwoElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfActions;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 2;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfActions = HeapForEach(heap, (ActionFunction) DummyElementIntAction, NULL);
    if (numOfVecElements == numOfActions)
    {
        printf("PASS: TestHeapForEach_TwoElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapForEach_TwoElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapForEach_TenElement()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfActions;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfActions = HeapForEach(heap, (ActionFunction) DummyElementIntAction, NULL);
    if (numOfVecElements == numOfActions)
    {
        printf("PASS: TestHeapForEach_TenElement()\n");
    }
    else
    {
        printf("FAIL: TestHeapForEach_TenElement()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}
/*******************************/
static void TestHeapForEach_ActionFunctionStop()
{
    Heap* heap;
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t numOfActions;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;
    int stopVal = 5;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    heap = HeapBuild(vec , (LessThanComparator) LessThanInt);
    numOfActions = HeapForEach(heap, (ActionFunction) StopCountAtIntValFive, (void*)&stopVal);
    if (5 == numOfActions)
    {
        printf("PASS: TestHeapForEach_ActionFunctionStop()\n");
    }
    else
    {
        printf("FAIL: TestHeapForEach_ActionFunctionStop()\n");
    }
    HeapDestroy(&heap);
    VecDestroy(&vec, NULL);
    return;    
}








/*****
HEAP SORT TESTS
*****/
/*
TODO: compare results of heapsort to bubble sorted version of vector
*/
static void TestHeapSort_NULLVec()
{
    HeapSort(NULL, (LessThanComparator) LessThanInt);
    printf("PASS: TestHeapSort_NULLVec()\n");
    return;
}
/*******************************/
static void TestHeapSort_NULLPFLESS()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;

    vec = VecCreate(initialCapacity, blockSize);
    HeapSort(vec, NULL);
    VecDestroy(&vec, NULL);
    printf("PASS: TestHeapSort_NULLPFLESS()\n");
    return;
}
/*******************************/
static void TestHeapSort_EmptyVec()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;

    vec = VecCreate(initialCapacity, blockSize);
    HeapSort(vec, (LessThanComparator) LessThanInt);
    VecDestroy(&vec, NULL);
    printf("PASS: TestHeapSort_EmptyVec()\n");
    return;
}
/*******************************/
static void TestHeapSort_OneElement()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 1;

    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    HeapSort(vec, (LessThanComparator) LessThanInt);
    VecDestroy(&vec, NULL);
    free(arr);
    printf("PASS: TestHeapSort_OneElement()\n");
    return;
}
/*******************************/
static void TestHeapSort_TwoElement()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 2;

    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    HeapSort(vec, (LessThanComparator) LessThanInt);
    VecDestroy(&vec, NULL);
    free(arr);
    printf("PASS: TestHeapSort_TwoElement()\n");
    return;
}
/*******************************/
static void TestHeapSort_TenElement()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;

    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    HeapSort(vec, (LessThanComparator) LessThanInt);
    VecDestroy(&vec, NULL);
    free(arr);
    printf("PASS: TestHeapSort_TenElement()\n");
    return;
}
/*******************************/
static void TestHeapSort_OrderCorrectTenElement()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10;
    size_t numOfVecElements = 10;
    size_t index;
    int newVal = (int)numOfVecElements;
    int correctIntOrder[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* element;

    arr = InitRandIntArr(numOfInts);
    for (index = 0; index < numOfVecElements; ++index)
    {
        arr[index] = newVal;
        --newVal;
    }
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    HeapSort(vec, (LessThanComparator) LessThanInt);
    
    for (index = 0; index < numOfVecElements; ++index)
    {
        VecGet(vec, index + 1, (void**)&element);
        if (correctIntOrder[index] != *element)
        {
            VecDestroy(&vec, NULL);
            free(arr);
            printf("FAIL: TestHeapSort_OrderCorrectTenElement()\n");
            return;
        }
    }
    VecDestroy(&vec, NULL);
    free(arr);
    printf("PASS: TestHeapSort_OrderCorrectTenElement()\n");
    return;
}
/*******************************/
static void TestHeapSort_1000ElementTypical()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 1000;
    size_t numOfVecElements = 1000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    start_t = clock();
    HeapSort(vec, (LessThanComparator) LessThanInt);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestHeapSort_1000ElementTypical:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapSort_10000ElementTypical()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 10000;
    size_t numOfVecElements = 10000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    start_t = clock();
    HeapSort(vec, (LessThanComparator) LessThanInt);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestHeapSort_10000ElementTypical:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}
/*******************************/
static void TestHeapSort_50000ElementTypical()
{
    Vector* vec;
    size_t initialCapacity = 10;
    size_t blockSize = 2;
    int* arr;
    size_t numOfInts = 50000;
    size_t numOfVecElements = 50000;
    clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    arr = InitRandIntArr(numOfInts);
    vec = VecCreate(initialCapacity, blockSize);
    VecAppendIntElements(vec, arr, numOfVecElements);
    start_t = clock();
    HeapSort(vec, (LessThanComparator) LessThanInt);
    end_t = clock();
    total_t = (end_t - start_t);
    printf("Time elapsed for TestHeapSort_50000ElementTypical:\t %f\n", ((float)total_t) / CLOCKS_PER_SEC);
    VecDestroy(&vec, NULL);
    free(arr);
    return;
}







int main()
{
    srand((unsigned int)time(NULL));
    printf("\n");
    
    /****
    ILLEGAL INPUT TESTS
    ****/
    printf("\nILLEGAL INPUT TESTS:\n");
    TestHeapBuild_NULLVec();
    TestHeapBuild_NULLPFLess();
    TestHeapDestroy_NULLHeap();
    TestHeapInsert_NULLHeap();
    TestHeapInsert_NULLElement();
    TestHeapPeek_NULLHeap();
    TestHeapSize_NULLHeap();
    TestHeapForEach_NULLHeap();
    TestHeapSort_NULLVec();
    TestHeapSort_NULLPFLESS();
    
    /****
    SANITY TESTS
    ****/
    printf("\nSANITY TESTS:\n");
    TestHeapBuild_OneElement();
    TestHeapBuild_TwoElement();
    TestHeapBuild_TenElement();
    TestHeapBuild_TenElementOrderCorrect();
    TestHeapBuild_FivePersons();
    TestHeapBuild_FivePersonsOrderCorrect();
    TestHeapDestroy_OK();
    TestHeapDestroy_StructOK();
    TestHeapDestroy_VecNotDestroyed();
    TestHeapInsert_TwoElements();
    TestHeapInsert_TenElements();
    TestHeapPeek_OneElement();
    TestHeapPeek_TwoElement();
    TestHeapPeek_TenElement();
    TestHeapSize_OneElement();
    TestHeapSize_TwoElement();
    TestHeapSize_TenElement();
    TestHeapForEach_OneElement();
    TestHeapForEach_TwoElement();
    TestHeapForEach_TenElement();
    TestHeapForEach_ActionFunctionStop();
    TestHeapSort_OneElement();
    TestHeapSort_TwoElement();
    TestHeapSort_TenElement();
    /****
    SPECIAL CASES TESTS
    ****/
    printf("\nSPECIAL CASES TESTS:\n");
    TestHeapBuild_EmptyVec();
    TestHeapBuild_NULLElement();
    TestHeapDestroy_EmptyHeap();
    TestHeapDestroy_DoubleDestroy();
    TestHeapInsert_EmptyHeap();
    TestHeapPeek_EmptyHeap();
    TestHeapSize_EmptyHeap();
    TestHeapForEach_EmptyHeap();
    TestHeapSort_EmptyVec();
    /****
    PERFORMANCE TESTS
    ****/
    printf("\nPERFORMANCE TESTS:\n");
    TestHeapBuild_1000ElementTypical();
    TestHeapBuild_10000ElementTypical();
    TestHeapBuild_50000ElementTypical();
    TestHeapSort_1000ElementTypical();
    TestHeapSort_10000ElementTypical();
    TestHeapSort_50000ElementTypical();
    /****
    STRESS TESTS
    ****/
    printf("\nSTRESS TESTS:\n");
    TestHeapBuildTenElements_ThenInsert();
    TestHeapBuildFiveElements_ThenInsertMax();
    TestHeapSize_AfterInsert();
    TestHeapSort_OrderCorrectTenElement();
    
    printf("\n");
	return 1;
}




















