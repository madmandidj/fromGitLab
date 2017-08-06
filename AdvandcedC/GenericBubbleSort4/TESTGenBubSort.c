/*
Filename: 		TESTGenBubSort.c 
Description:	Tests for Generic bubble sort
Created: 		02/08/17
Created by:		Eyal Alon
Last modified: 	02/08/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include <string.h>
#include "GenBubSort.h"


typedef struct Person Person;

struct Person
{
	size_t m_age;
	char m_name[64];
};









/*
	PRINT FUNCTIONS
*/

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
		else if (_err == ERR_INVALID_ITEMSIZE)
        {
           strcpy(errString, "ERR_INVALID_ITEMSIZE"); 
        }
		else if (_err == ERR_ZERO_ITEMS)
        {
           strcpy(errString, "ERR_ZERO_ITEMS"); 
        }
		else if (_err == ERR_INVALID_SORTMETHOD)
        {
           strcpy(errString, "ERR_INVALID_SORTMETHOD"); 
        }
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAILED: %s %s\n", _testName, errString);
    }
    return;
}


static void PrintIntArr(int* _arr, size_t _size)
{
	size_t index;
	for (index = 0; index < _size; ++index)
	{
		printf("index: %lu, value: %d\n", index, _arr[index]);
	}
	printf("\n");
	return;
}
/*
static void PrintCharArr(char* _arr, size_t _size)
{
	size_t index;
	for (index = 0; index < _size; ++index)
	{
		printf("index: %lu, character: %c\n", index, _arr[index]);
	}
	printf("\n");
	return;
}

static void PrintPersonArr(Person* _arr, size_t _size)
{
	size_t index;
	for (index = 0; index < _size; ++index)
	{
		printf("index: %lu, person age: %lu person name: %s\n", index, _arr[index].m_age, _arr[index].m_name);
	}
	printf("\n");
	return;
}

*/













/*
	SORT METHOD FUNCTIONS
*/

static int SortAscendingLSDInt(const void* _item1, const void* _item2)
{
	if(*(int*)_item1 % 10 > *(int*)_item2 % 10)
	{
		return 1;
	}
	return 0;
}

static int SortAscendingInt(const void* _item1, const void* _item2)
{
	if(*(int*)_item1 > *(int*)_item2)
	{
		return 1;
	}
	return 0;
}

static int SortAscendingChar(const void* _item1, const void* _item2)
{
	if(*(char*)_item1 > *(char*)_item2)
	{
		return 1;
	}
	return 0;
}

static int SortAscendingPersonaAge(const void* _item1, const void* _item2)
{
	Person* person1 = (Person*) _item1;
	Person* person2 = (Person*) _item2;
	if(person1->m_age > person2->m_age)
	{
		return 1;
	}
	return 0;
}

static int SortAscendingPersonaName(const void* _item1, const void* _item2)
{
	Person* person1 = (Person*) _item1;
	Person* person2 = (Person*) _item2;
	if(person1->m_name[0] > person2->m_name[0])
	{
		return 1;
	}
	return 0;
}














/*
	TEST FUNCTIONS
*/

static void TESTGenBubSortIntNULLArr()
{
	ADTErr errResult;
	errResult = GenericBubbleSort(NULL, 8, sizeof(int), SortAscendingInt);
	PrintErrResult("TESTGenBubSortIntNULLArr", errResult, ERR_NOT_INITIALIZED);
	return;
}

static void TESTGenBubSortInt0Items()
{
	int arr[8] = {0};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 0, sizeof(int), SortAscendingInt);
	PrintErrResult("TESTGenBubSortInt0Items", errResult, ERR_ZERO_ITEMS);
	return;
}

static void TESTGenBubSortInt0Size()
{
	int arr[8] = {0};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 8, 0, SortAscendingInt);
	PrintErrResult("TESTGenBubSortInt0Size", errResult, ERR_INVALID_ITEMSIZE);
	return;
}

static void TESTGenBubSortIntNULLSortFunc()
{
	int arr[2] = {3,2};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 2, sizeof(int), NULL);
	PrintErrResult("TESTGenBubSortIntNULLSortFunc", errResult, ERR_INVALID_SORTMETHOD);
	return;
}

static void TESTGenBubSortInt1Item()
{
	int arr[1] = {3};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 1, sizeof(int), SortAscendingInt);
	PrintErrResult("TESTGenBubSortInt1Item", errResult, ERR_OK);
	return;
}

static void TESTGenBubSortInt2Item()
{
	int arr[2] = {7,3};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 2, sizeof(int), SortAscendingInt);
	PrintErrResult("TESTGenBubSortInt2Item", errResult, ERR_OK);
	return;
}

static void TESTGenBubSortInt()
{
	int arr[8] = {3,7,2,10,5,3,17,8};
	ADTErr errResult;
	PrintIntArr(arr, 8);
	errResult = GenericBubbleSort(arr, 8, sizeof(int), SortAscendingInt);
	PrintIntArr(arr, 8);
	PrintErrResult("TESTGenBubSortInt", errResult, ERR_OK);
	return;
}

static void TESTGenBubSortAscendingLSDInt()
{
	int arr[8] = {22,91,23,17,36,75,48,8};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 8, sizeof(int), SortAscendingLSDInt);
	PrintErrResult("TESTGenBubSortAscendingLSDInt", errResult, ERR_OK);
	return;
}

static void TESTGenBubSortChar()
{
	char arr[] = "zyxwa";
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 5, sizeof(char), SortAscendingChar);
	PrintErrResult("TESTGenBubSortChar", errResult, ERR_OK);
	return;
}

static void TESTGenBubSortPersonAge()
{
	Person arr[] = {{17,"Eyal"}, {40, "Erez"}, {32, "Hana"}, {67, "Eliyahu"}, {42, "Yodo"}};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 5, sizeof(Person), SortAscendingPersonaAge);
	PrintErrResult("TESTGenBubSortPersonAge", errResult, ERR_OK);
	return;
}

static void TESTGenBubSortPersonName()
{
	Person arr[] = {{17,"Eyal"}, {40, "Erez"}, {32, "Hana"}, {67, "Eliyahu"}, {42, "Yodo"}};
	ADTErr errResult;
	errResult = GenericBubbleSort(arr, 5, sizeof(Person), SortAscendingPersonaName);
	PrintErrResult("TESTGenBubSortPersonName", errResult, ERR_OK);
	return;
}














/*
	MAIN
*/


int main()
{
	TESTGenBubSortIntNULLArr();
	TESTGenBubSortInt0Items();
	TESTGenBubSortInt0Size();
	TESTGenBubSortIntNULLSortFunc();
	TESTGenBubSortInt1Item();
	TESTGenBubSortInt2Item();
	TESTGenBubSortInt();
	TESTGenBubSortAscendingLSDInt();
	TESTGenBubSortChar();
	TESTGenBubSortPersonAge();
	TESTGenBubSortPersonName();
	return 1;
}





