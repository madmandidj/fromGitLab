/*
Filename: 		TESTGenericVector.c 
Description:	Tests for Generic vector 
Created: 		03/08/17
Created by:		Eyal Alon
Last modified: 	05/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenericVector.h"

typedef struct Person Person;
struct Person
{
	size_t 		m_age;
	char 		m_name[64];
	size_t 		m_famSize;
	Person**	m_family;
};











/*
	ELEMENT DESTROY FUNCTIONS
*/
void ElementDestroyInt(void* _item)
{
	free(_item);
	return;
}

void ElementDestroyPerson(void* _item)
{
	Person* perItem = (Person*) _item;
	if (NULL != perItem->m_family)
	{
		free(perItem->m_family);
	}
	return;
}











/*
	VECTOR ELEMENT ACTION FUNCTIONS
*/
int	VectorElementIntPrint(void* _element, size_t _index, void* _context)
{
	printf("Index = %u, Value = %d\n", _index, *(int*)_element);
	return 1;
}

/*
TODO: can change void* _element to Person* _prs
and then when calling vecforeach do cast to VectorElementAction
*/
/*
int	VectorElementPersonPrint(void* _element, size_t _index, void* _context)
{
	printf("Index = %u, \tName = %s, \tAge = %u\n", _index, ((Person*)_element)->m_name, ((Person*)_element)->m_age);
	printf("Family1 = %u, \tName = %s, \tAge = %u\n", _index, ((Person*)_element)->m_family[0]->m_name, ((Person*)_element)->m_family[0]->m_age);
	printf("Family2 = %u, \tName = %s, \tAge = %u\n", _index, ((Person*)_element)->m_family[1]->m_name, ((Person*)_element)->m_family[1]->m_age);
	return 1;
}
*/

int	VectorElementPersonPrint(Person* _prs, size_t _index, void* _context)
{
	printf("Index = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_name, _prs->m_age);
	printf("Family1 = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_family[0]->m_name, _prs->m_family[0]->m_age);
	printf("Family2 = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_family[1]->m_name, _prs->m_family[1]->m_age);
	return 1;
}

/*
int	VectorElementPersonYodofy(void* _element, size_t _index, void* _context)
{
	if (!strcmp(((Person*)_element)->m_name, "Yodo"))
	{
		strcpy(((Person*)_element)->m_name, (char*)_context);
	}
	return 1;
}
*/

int	VectorElementPersonYodofy(Person* _prs, size_t _index, char* _context)
{
	if (!strcmp(_prs->m_name, "Yodo"))
	{
		strcpy(_prs->m_name, _context);
	}
	return 1;
}









/*
	ADTERR PRINT FUNCTION
*/
static void PrintErrResult(char* _testName, ADTErr _err, ADTErr _passErr)
{
    char errString[64];
    if (_err == _passErr)
    {
        printf("PASS: %s\n", _testName);
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
		else if (_err == ERR_INVALID_ITEMSIZE)
        {
           strcpy(errString, "ERR_INVALID_ITEMSIZE"); 
        }
		else if (_err == ERR_ZERO_ITEMS)
        {
           strcpy(errString, "ERR_ZERO_ITEMS"); 
        }
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAIL: %s %s\n", _testName, errString);
    }
    return;
}











/*
	VECTOR CREATE TESTS
*/
static void TestVecCreateZeroSizeZeroExtBlock()
{
	Vector* vec;
	vec = VecCreate(0, 0);
	if (NULL == vec)
	{
		printf("PASS: TestVecCreateZeroSizeZeroExtBlock\n");
	}
	else
	{
		printf("FAIL: TestVecCreateZeroSizeZeroExtBlock\n");
	}
	VecDestroy(&vec, NULL);
	return;
}

static void TestVecCreateSizeZero()
{
	Vector* vec;
	size_t blockSize = 2;
	vec = VecCreate(0, blockSize);
	if (NULL != vec)
	{
		printf("PASS: TestVecCreateSizeZero\n");
	}
	else
	{
		printf("FAIL: TestVecCreateSizeZero\n");
	}
	VecDestroy(&vec, NULL);
	return;
}

static void TestVecCreateExtBlockZero()
{
	Vector* vec;
	size_t initSize = 2;
	vec = VecCreate(initSize, 0);
	if (NULL != vec)
	{
		printf("PASS: TestVecCreateExtBlockZero\n");
	}
	else
	{
		printf("FAIL: TestVecCreateExtBlockZero\n");
	}
	VecDestroy(&vec, NULL);
	return;
}

static void TestVecCreateSizeTenExtBlockTwo()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	if (NULL != vec)
	{
		printf("PASS: TestVecCreateSizeTenExtBlockTwo\n");
	}
	else
	{
		printf("FAIL: TestVecCreateSizeTenExtBlockTwo\n");
	}
	VecDestroy(&vec, NULL);
	return;
}











/*
	VECTOR DESTROY TESTS
*/
static void TestVecDestroyWithOutElementDestroy()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	VecDestroy(&vec, NULL);
	printf("PASS: TestVecDestroyWithOutElementDestroy\n");
	return;
}

static void TestVecDestroyWithElementDestroy()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecDestroy(&vec, ElementDestroyInt);
	printf("PASS: TestVecDestroyWithElementDestroy\n");
	return;
}

static void TestVecDestroyDoubleDestroy()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	VecDestroy(&vec, NULL);
	VecDestroy(&vec, NULL);
	printf("PASS: TestVecDestroyDoubleDestroy\n");
	return;
}











/*
	VECTOR APPEND TESTS
*/
static void TestVecAppendNULLVec()
{
	ADTErr errResult;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	errResult = VecAppend(NULL, (void*)(arr + 25));
	PrintErrResult("TestVecAppendNULLVec", errResult, ERR_NOT_INITIALIZED);
	free(arr);
	return;
}

static void TestVecAppendNULLItem()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	errResult = VecAppend(vec, NULL);
	PrintErrResult("TestVecAppendNULLItem", errResult, ERR_OK);
	VecDestroy(&vec, NULL);
	return;
}

static void TestVecAppendOneItem()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	errResult = VecAppend(vec, (void*)(arr + 25));
	PrintErrResult("TestVecAppendOneItem", errResult, ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecAppendTwoItem()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	errResult = VecAppend(vec, (void*)(arr + 26));
	PrintErrResult("TestVecAppendTwoItem", errResult, ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecAppendExtendBlock()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 1;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	errResult = VecAppend(vec, (void*)(arr + 26));
	PrintErrResult("TestVecAppendExtendBlock", errResult, ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecAppendOverflow()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 1;
	size_t extBlock = 0;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	errResult = VecAppend(vec, (void*)(arr + 26));
	PrintErrResult("TestVecAppendOverflow", errResult, ERR_OVERFLOW);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void InitPersArr(Person* _arr)
{
	size_t numOfPersons = 5;
	size_t numOfFamily = 2;
	size_t index;
	size_t indexDealloc;
	size_t indexFam;
	char* names[] = {"Eyal\0", "Yodo\0", "Erez\0", "Eli\0", "Hana\0"};
	size_t ages[] = {101, 999, 23, 21, 17};
	for (index = 0; index < numOfPersons; ++index)
	{
		_arr[index].m_famSize = numOfFamily;
		_arr[index].m_age = ages[index];
		strcpy(_arr[index].m_name, names[index]);
		_arr[index].m_family = malloc(numOfFamily * sizeof(Person));
		if (NULL == _arr[index].m_family)
		{
			for (indexDealloc = index-1; indexDealloc > 0; --indexDealloc)
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

static void TestVecAppendPersonsWithoutElementDestroy()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	size_t index;
	Person* arr;
	void* itemRemoved;
	arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	errResult = VecGet(vec, 1, &itemRemoved);
	PrintErrResult("TestVecAppendPersonsWithoutElementDestroy", errResult, ERR_OK);
	for (index = 0; index < numOfPersons; ++index)
	{
		free(arr[index].m_family);
	}
	free(arr);
	VecDestroy(&vec, NULL);
	return;
}

static void TestVecAppendPersonsWithElementDestroy()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	Person* arr;
	void* itemRemoved;
	arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	errResult = VecGet(vec, 1, &itemRemoved);
	PrintErrResult("TestVecAppendPersonsWithElementDestroy", errResult, ERR_OK);
	VecDestroy(&vec, ElementDestroyPerson);
	return;
}











/*
	VECTOR REMOVE TESTS
*/
static void TestVecRemoveNULLVec()
{
	ADTErr errResult;
	void* itemRemoved;
	errResult = VecRemove(NULL, &itemRemoved);
	PrintErrResult("TestVecRemoveNULLVec", errResult, ERR_NOT_INITIALIZED);
	return;
}

static void TestVecRemoveNULLPValue()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemRemoved;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecRemove(vec, &itemRemoved);
	errResult = VecRemove(vec, NULL);
	PrintErrResult("TestVecRemoveNULLPValue", errResult, ERR_NOT_INITIALIZED);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecRemoveOneItem()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemRemoved;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	errResult = VecRemove(vec, &itemRemoved);
	if (25 == *(int*)itemRemoved)
	{
		PrintErrResult("TestVecRemoveOneItem, Value CORRECT", errResult, ERR_OK);
	}
	else
	{
		PrintErrResult("TestVecRemoveOneItem, Value INCORRECT", errResult, ERR_OK);
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecRemoveUnderflow()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemRemoved;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecRemove(vec, &itemRemoved);
	errResult = VecRemove(vec, &itemRemoved);
	PrintErrResult("TestVecRemoveUnderflow", errResult, ERR_UNDERFLOW);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecRemoveExtBlock()
{
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 1;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemRemoved;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecRemove(vec, &itemRemoved);
	VecRemove(vec, &itemRemoved);
	errResult = VecRemove(vec, &itemRemoved);
	PrintErrResult("TestVecRemoveExtBlock", errResult, ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}











/*
	VECTOR ITEMS NUM TESTS
*/
static void TestVecSizeNULLVec()
{
	size_t result;
	result = VecSize(NULL);
	if (0 == result)
	{
		printf("PASS: TestVecSizeNULLVec\n");
	}
	else
	{
		printf("FAIL: TestVecSizeNULLVec\n");
	}
	return;
}

static void TestVecSizeTenItems()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	size_t numOfItems;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	numOfItems = VecSize(vec);
	if (10 == numOfItems)
	{
		printf("PASS: TestVecSizeTenItems\n");
	}
	else
	{
		printf("FAIL: TestVecSizeTenItems\n");
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}











/*
	VECTOR CAPACITY TESTS
*/
static void TestVecCapacityNULLVec()
{
	size_t capacity;
	capacity = VecCapacity(NULL);
	if (0 == capacity)
	{
		printf("PASS: TestVecCapacityNULLVec\n");
	}
	else
	{
		printf("FAIL: TestVecCapacityNULLVec\n");
	}
	return;
}

static void TestVecCapacityTenItems()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	size_t capacity;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	capacity = VecCapacity(vec);
	if (10 == capacity)
	{
		printf("PASS: TestVecCapacityTenItems\n");
	}
	else
	{
		printf("FAIL: TestVecCapacityTenItems\n");
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecCapacityExtUp()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	size_t capacity;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 5));
	VecAppend(vec, (void*)(arr + 6));
	capacity = VecCapacity(vec);
	if (12 == capacity)
	{
		printf("PASS: TestVecCapacityExtUp\n");
	}
	else
	{
		printf("FAIL: TestVecCapacityExtUp\n");
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecCapacityExtDown()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	size_t capacity;
	void* removedItem;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 5));
	VecAppend(vec, (void*)(arr + 6));
	VecRemove(vec, &removedItem);
	VecRemove(vec, &removedItem);
	VecRemove(vec, &removedItem);
	VecRemove(vec, &removedItem);
	capacity = VecCapacity(vec);
	if (10 == capacity)
	{
		printf("PASS: TestVecCapacityExtDown\n");
	}
	else
	{
		printf("FAIL: TestVecCapacityExtDown\n");
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}











/*
	VECTOR GET TESTS
*/
static void TestVecGetNULLVec()
{
	ADTErr errResult;
	void* itemVal;
	errResult = VecGet(NULL, 5, &itemVal);
	PrintErrResult("TestVecGetNULLVec", errResult, ERR_NOT_INITIALIZED);
	return;
}

static void TestVecGetNULLPVal()
{
	ADTErr errResult;
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 49));
	errResult = VecGet(vec, 10, NULL);
	PrintErrResult("TestVecGetNULLPVal", errResult, ERR_NOT_INITIALIZED);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecGetVal()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemVal;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 49));
	VecGet(vec, 10, &itemVal);
	if (49 == *(int*)itemVal)
	{
		printf("PASS: TestVecGetVal\n");
	}
	else
	{
		printf("FAIL: TestVecGetVal\n");
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecGetWrongIndex()
{
	ADTErr errResult;
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemVal;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 49));
	errResult = VecGet(vec, 11, &itemVal);
	PrintErrResult("TestVecGetWrongIndex", errResult, ERR_WRONG_INDEX);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}











/*
	VECTOR SET TESTS
*/
static void TestVecSetNULLVec()
{
	int itemVal = 10;
	ADTErr errResult;
	errResult = VecSet(NULL, 11, &itemVal);
	PrintErrResult("TestVecSetNULLVec", errResult, ERR_NOT_INITIALIZED);
	return;
}

static void TestVecSetNULLValue()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	ADTErr errResult;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 49));
	errResult = VecSet(vec, 8, NULL);
	PrintErrResult("TestVecSetNULLValue", errResult, ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecSetVal()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	int item = 666;
	void* itemVal;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 49));
	VecSet(vec, 9, (void*)&item);
	VecGet(vec, 9, &itemVal);
	if (666 == *(int*)itemVal)
	{
		printf("PASS: TestVecSetVal\n");
	}
	else
	{
		printf("FAIL: TestVecSetVal\n");
	}
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}

static void TestVecSetWrongIndex()
{
	ADTErr errResult;
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfInts = 50;
	size_t index;
	int* arr;
	void* itemVal;
	arr = malloc(numOfInts * sizeof(int));
	for (index = 0; index < numOfInts; ++index)
	{
		arr[index] = (int)index;
	}
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 26));
	VecAppend(vec, (void*)(arr + 27));
	VecAppend(vec, (void*)(arr + 25));
	VecAppend(vec, (void*)(arr + 49));
	errResult = VecSet(vec, 11, &itemVal);
	PrintErrResult("TestVecSetWrongIndex", errResult, ERR_WRONG_INDEX);
	VecDestroy(&vec, NULL);
	free(arr);
	return;
}











/*
	VECTOR ELEMENT ACTION TESTS
*/
static void TestVectorElementNULLVec()
{
	size_t actionCalledCount;
	char yodoString[] = "YODO";
	actionCalledCount = VecForEach(NULL, (VectorElementAction)VectorElementPersonYodofy, yodoString);
	if (0 == actionCalledCount)
	{
		printf("PASS: TestVectorElementNULLVec\n");
	}
	else
	{
		printf("FAIL: TestVectorElementNULLVec\n");
	}
	return;
}

static void TestVectorElementNULLFunc()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	Person* arr;
	size_t actionCalledCount = 0;
	char yodoString[] = "YODO";
	arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	actionCalledCount = VecForEach(vec, NULL, yodoString);
	if (0 == actionCalledCount)
	{
		printf("PASS: TestVectorElementNULLFunc\n");
	}
	else
	{
		printf("FAIL: TestVectorElementNULLFunc\n");
	}
	VecDestroy(&vec, ElementDestroyPerson);
	return;
}

static void TestVectorElementPersonYodofy()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	Person* arr;
	size_t actionCalledCount = 0;
	char yodoString[] = "YODO";
	arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	actionCalledCount = VecForEach(vec, (VectorElementAction) VectorElementPersonYodofy, yodoString);
	VecForEach(vec, (VectorElementAction) VectorElementPersonPrint, NULL);
	if (5 == actionCalledCount)
	{
		printf("PASS: TestVectorElementPersonYodofy\n");
	}
	else
	{
		printf("FAIL: TestVectorElementPersonYodofy\n");
	}
	VecDestroy(&vec, ElementDestroyPerson);
	return;
}











int main()
{
	printf("\n");
	TestVecCreateZeroSizeZeroExtBlock();
	TestVecCreateSizeZero();
	TestVecCreateExtBlockZero();
	TestVecCreateSizeTenExtBlockTwo();
	TestVecDestroyWithOutElementDestroy();
	TestVecDestroyWithElementDestroy();
	TestVecDestroyDoubleDestroy();
	TestVecAppendNULLVec();
	TestVecAppendNULLItem();
	TestVecAppendOneItem();
	TestVecAppendTwoItem();
	TestVecAppendExtendBlock();
	TestVecAppendOverflow();
	TestVecAppendPersonsWithoutElementDestroy();
	TestVecAppendPersonsWithElementDestroy();
	TestVecRemoveNULLVec();
	TestVecRemoveNULLPValue();
	TestVecRemoveOneItem();
	TestVecRemoveUnderflow();
	TestVecRemoveExtBlock();
	TestVecSizeNULLVec();
	TestVecSizeTenItems();
	TestVecCapacityNULLVec();
	TestVecCapacityTenItems();
	TestVecCapacityExtUp();
	TestVecCapacityExtDown();
	TestVecGetNULLVec();
	TestVecGetNULLPVal();
	TestVecGetVal();
	TestVecGetWrongIndex();
	TestVecSetNULLVec();
	TestVecSetNULLValue();
	TestVecSetVal();
	TestVecSetWrongIndex();
	TestVectorElementNULLVec();
	TestVectorElementNULLFunc();
	TestVectorElementPersonYodofy();
	printf("\n");
	return 0;
}


