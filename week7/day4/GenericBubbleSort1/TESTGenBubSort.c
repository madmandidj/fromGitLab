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
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAILED: %s %s\n", _testName, errString);
    }
    return;
}

/*
static void PrintIntArr(int* _arr, size_t _size)
{
	size_t index;
	for (index = 0; index < _size; ++index)
	{
		printf("index: %d, value: %d\n", index, _arr[index]);
	}
	printf("\n");
	return;
}

static void PrintCharArr(char* _arr, size_t _size)
{
	size_t index;
	for (index = 0; index < _size; ++index)
	{
		printf("index: %d, character: %c\n", index, _arr[index]);
	}
	printf("\n");
	return;
}

static void PrintPersonAge(Person* _arr, size_t _size)
{
	size_t index;
	for (index = 0; index < _size; ++index)
	{
		printf("index: %d, person age: %u person name: %s\n", index, _arr[index].m_age, _arr[index].m_name);
	}
	printf("\n");
	return;
}

*/












/*
	SORT METHOD FUNCTIONS
*/


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















/*
	TEST FUNCTIONS
*/

static void TESTGenBubSortInt()
{
	int arr[8] = {3,7,2,10,5,3,4,8};
	ADTErr errResult;
/*	PrintIntArr(arr, 8);*/
	errResult = GenericBubbleSort(arr, 8, sizeof(int), SortAscendingInt);
	PrintErrResult("TESTGenBubSortInt", errResult, ERR_OK);
/*	PrintIntArr(arr, 8);*/
	return;
}

static void TESTGenBubSortChar()
{
	char arr[] = "zyxwa";
	ADTErr errResult;
/*	PrintCharArr(arr, 5);*/
	errResult = GenericBubbleSort(arr, 5, sizeof(char), SortAscendingChar);
	PrintErrResult("TESTGenBubSortChar", errResult, ERR_OK);
/*	PrintCharArr(arr, 5);*/
	return;
}

static void TESTGenBubSortPersonAge()
{
	Person arr[] = {{17,"Eyal"}, {40, "Erez"}, {32, "Hana"}, {67, "Eliyahu"}, {42, "Yodo"}};
	ADTErr errResult;
/*	PrintPersonAge(arr, 5);*/
	errResult = GenericBubbleSort(arr, 5, sizeof(Person), SortAscendingPersonaAge);
	PrintErrResult("TESTGenBubSortPersonAge", errResult, ERR_OK);
/*	PrintPersonAge(arr, 5);*/
	return;
}














/*
	MAIN
*/


int main()
{
	TESTGenBubSortInt();
	TESTGenBubSortChar();
	TESTGenBubSortPersonAge();
	return 1;
}





