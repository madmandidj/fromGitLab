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
#include "mu_test.h"

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

int	VectorElementPersonPrint(Person* _prs, size_t _index, void* _context)
{
	printf("Index = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_name, _prs->m_age);
	printf("Family1 = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_family[0]->m_name, _prs->m_family[0]->m_age);
	printf("Family2 = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_family[1]->m_name, _prs->m_family[1]->m_age);
	return 1;
}

int	VectorElementPersonYodofy(Person* _prs, size_t _index, char* _context)
{
	if (!strcmp(_prs->m_name, "Yodo"))
	{
		strcpy(_prs->m_name, _context);
	}
	return 1;
}







/*
	INIT PERSON STRUCT ARRAY FUNCTION
*/
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







/*
	VECTOR CREATE TESTS
*/
UNIT(TestVecCreateZeroSizeZeroExtBlock)
	Vector* vec;
	vec = VecCreate(0, 0);
	ASSERT_THAT(NULL == vec);
END_UNIT


UNIT(TestVecCreateSizeZero)
	Vector* vec;
	size_t blockSize = 2;
	vec = VecCreate(0, blockSize);
	ASSERT_THAT(NULL != vec);
	VecDestroy(&vec, NULL);
END_UNIT


UNIT(TestVecCreateExtBlockZero)
	Vector* vec;
	size_t blockSize = 2;
	vec = VecCreate(0, blockSize);
	ASSERT_THAT(NULL != vec);
	VecDestroy(&vec, NULL);
END_UNIT


UNIT(TestVecCreateSizeTenExtBlockTwo)
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	ASSERT_THAT(NULL != vec);
	VecDestroy(&vec, NULL);
END_UNIT







/*
	VECTOR DESTROY TESTS
*/
UNIT(TestVecDestroyWithOutElementDestroy)
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	VecDestroy(&vec, NULL);
	ASSERT_THAT(1);
END_UNIT


UNIT(TestVecDestroyWithElementDestroy)
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
	ASSERT_THAT(1);
END_UNIT


UNIT(TestVecDestroyDoubleDestroy)
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	VecDestroy(&vec, NULL);
	VecDestroy(&vec, NULL);
	ASSERT_THAT(1);
END_UNIT







/*
	VECTOR APPEND TESTS
*/
UNIT(TestVecAppendNULLVec)
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
	ASSERT_THAT(errResult == ERR_NOT_INITIALIZED);
	free(arr);
END_UNIT


UNIT(TestVecAppendNULLItem)
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	vec = VecCreate(initSize, extBlock);
	errResult = VecAppend(vec, NULL);
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
END_UNIT


UNIT(TestVecAppendOneItem)
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
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecAppendTwoItem)
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
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecAppendExtendBlock)
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
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecAppendOverflow)
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
	ASSERT_THAT(errResult == ERR_OVERFLOW);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecAppendPersonsWithoutElementDestroy)
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	size_t index;
	Person* arr;
	void* itemRemoved;
	arr = malloc(numOfPersons * sizeof(Person));
	/*
	if (NULL == arr)
	{
		return;
	}
	*/
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	errResult = VecGet(vec, 1, &itemRemoved);
	ASSERT_THAT(errResult == ERR_OK);
	for (index = 0; index < numOfPersons; ++index)
	{
		free(arr[index].m_family);
	}
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecAppendPersonsWithElementDestroy)
	Vector* vec;
	ADTErr errResult;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	Person* arr;
	void* itemRemoved;
	arr = malloc(numOfPersons * sizeof(Person));
	/*
	if (NULL == arr)
	{
		return;
	}
	*/
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	errResult = VecGet(vec, 1, &itemRemoved);
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
END_UNIT







/*
	VECTOR REMOVE TESTS
*/
UNIT(TestVecRemoveNULLVec)
	ADTErr errResult;
	void* itemRemoved;
	errResult = VecRemove(NULL, &itemRemoved);
	ASSERT_THAT(errResult == ERR_NOT_INITIALIZED);
END_UNIT


UNIT(TestVecRemoveNULLPValue)
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
	ASSERT_THAT(errResult == ERR_NOT_INITIALIZED);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecRemoveOneItem)
	Vector* vec;
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
	ASSERT_THAT(25 == *(int*)itemRemoved);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecRemoveUnderflow)
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
	ASSERT_THAT(errResult == ERR_UNDERFLOW);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecRemoveExtBlock)
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
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT








/*
	VECTOR ITEMS NUM TESTS
*/
UNIT(TestVecSizeNULLVec)
	size_t result;
	result = VecSize(NULL);
	ASSERT_THAT(0 == result);
END_UNIT


UNIT(TestVecSizeTenItems)
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
	ASSERT_THAT(10 == numOfItems);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT







/*
	VECTOR CAPACITY TESTS
*/
UNIT(TestVecCapacityNULLVec)
	size_t capacity;
	capacity = VecCapacity(NULL);
	ASSERT_THAT(0 == capacity);
END_UNIT


UNIT(TestVecCapacityTenItems)
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
	ASSERT_THAT(10 == capacity);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecCapacityExtUp)
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
	ASSERT_THAT(12 == capacity);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecCapacityExtDown)
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
	ASSERT_THAT(10 == capacity);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT







/*
	VECTOR GET TESTS
*/
UNIT(TestVecGetNULLVec)
	ADTErr errResult;
	void* itemVal;
	errResult = VecGet(NULL, 5, &itemVal);
	ASSERT_THAT(errResult == ERR_NOT_INITIALIZED);
END_UNIT


UNIT(TestVecGetNULLPVal)
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
	ASSERT_THAT(errResult == ERR_NOT_INITIALIZED);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecGetVal)
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
	ASSERT_THAT(49 == *(int*)itemVal);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecGetWrongIndex)
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
	ASSERT_THAT(errResult == ERR_WRONG_INDEX);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT







/*
	VECTOR SET TESTS
*/
UNIT(TestVecSetNULLVec)
	int itemVal = 10;
	ADTErr errResult;
	errResult = VecSet(NULL, 11, &itemVal);
	ASSERT_THAT(errResult == ERR_NOT_INITIALIZED);
END_UNIT


UNIT(TestVecSetNULLValue)
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
	ASSERT_THAT(errResult == ERR_OK);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecSetVal)
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
	ASSERT_THAT(666 == *(int*)itemVal);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT


UNIT(TestVecSetWrongIndex)
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
	ASSERT_THAT(errResult == ERR_WRONG_INDEX);
	VecDestroy(&vec, NULL);
	free(arr);
END_UNIT







/*
	VECTOR ELEMENT ACTION TESTS
*/
UNIT(TestVectorElementNULLVec)
	size_t actionCalledCount;
	char yodoString[] = "YODO";
	actionCalledCount = VecForEach(NULL, (VectorElementAction)VectorElementPersonYodofy, yodoString);
	ASSERT_THAT(0 == actionCalledCount);
END_UNIT


UNIT(TestVectorElementNULLFunc)
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	Person* arr;
	size_t actionCalledCount = 0;
	char yodoString[] = "YODO";
	arr = malloc(numOfPersons * sizeof(Person));
	/*
	if (NULL == arr)
	{
		return;
	}
	*/
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	actionCalledCount = VecForEach(vec, NULL, yodoString);
	ASSERT_THAT(0 == actionCalledCount);
	VecDestroy(&vec, ElementDestroyPerson);
END_UNIT


UNIT(TestVectorElementPersonYodofy)
	Vector* vec;
	size_t initSize = 10;
	size_t extBlock = 2;
	size_t numOfPersons = 5;
	Person* arr;
	size_t actionCalledCount = 0;
	char yodoString[] = "YODO";
	arr = malloc(numOfPersons * sizeof(Person));
	/*
	if (NULL == arr)
	{
		return;
	}
	*/
	InitPersArr(arr);
	vec = VecCreate(initSize, extBlock);
	VecAppend(vec, (void*)&arr[0]);
	VecAppend(vec, (void*)&arr[1]);
	VecAppend(vec, (void*)&arr[2]);
	VecAppend(vec, (void*)&arr[3]);
	VecAppend(vec, (void*)&arr[4]);
	actionCalledCount = VecForEach(vec, (VectorElementAction) VectorElementPersonYodofy, yodoString);
	VecForEach(vec, (VectorElementAction) VectorElementPersonPrint, NULL);
	ASSERT_THAT(5 == actionCalledCount);
	VecDestroy(&vec, ElementDestroyPerson);
END_UNIT









TEST_SUITE(framework test)

	TEST(TestVecCreateZeroSizeZeroExtBlock)
	TEST(TestVecCreateSizeZero)
	TEST(TestVecCreateExtBlockZero)
	TEST(TestVecCreateSizeTenExtBlockTwo)

	TEST(TestVecDestroyWithOutElementDestroy)
	TEST(TestVecDestroyWithElementDestroy)
	TEST(TestVecDestroyDoubleDestroy)

	TEST(TestVecAppendNULLVec)
	TEST(TestVecAppendNULLItem)
	TEST(TestVecAppendOneItem)
	TEST(TestVecAppendTwoItem)
	TEST(TestVecAppendExtendBlock)
	TEST(TestVecAppendOverflow)
	TEST(TestVecAppendPersonsWithoutElementDestroy)
	TEST(TestVecAppendPersonsWithElementDestroy)

	TEST(TestVecRemoveNULLVec)
	TEST(TestVecRemoveNULLPValue)
	TEST(TestVecRemoveOneItem)
	TEST(TestVecRemoveUnderflow)
	TEST(TestVecRemoveExtBlock)

	TEST(TestVecRemoveExtBlock)
	TEST(TestVecSizeTenItems)

	TEST(TestVecCapacityNULLVec)
	TEST(TestVecCapacityTenItems)
	TEST(TestVecCapacityExtUp)
	TEST(TestVecCapacityExtDown)

	TEST(TestVecGetNULLVec)
	TEST(TestVecGetNULLPVal)
	TEST(TestVecGetVal)
	TEST(TestVecGetWrongIndex)

	TEST(TestVecSetNULLVec)
	TEST(TestVecSetNULLValue)
	TEST(TestVecSetVal)
	TEST(TestVecSetWrongIndex)
	
	TEST(TestVectorElementNULLVec)
	TEST(TestVectorElementNULLFunc)
	TEST(TestVectorElementPersonYodofy)

END_SUITE


