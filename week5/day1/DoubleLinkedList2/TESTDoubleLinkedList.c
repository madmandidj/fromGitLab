#include <stdio.h>
#include <string.h>
#include "DoubleLinkedList.h"

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

void TestListCreate()
{
	List* list;
	ADTErr result;
	list = ListCreate();
	if (NULL != list)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_ALLOCATION_FAILED;
	}
	PrintErrResult("TestListCreate", result, ERR_OK);
	ListDestroy(list);
	return;
}

void TestListDestroy()
{
	List* list;
	list = ListCreate();
	ListDestroy(list);
	/*
	if (list->m_magicNum == MAGIC_NUM)
	{
		result = ERR_MAGIC_NUM;
	}
	else
	{
		result = ERR_OK;
	}
	PrintErrResult("TestListDestroy", result, ERR_OK);
	*/
	return;
}

void TestListPushHeadNULLList()
{
	ADTErr result;
	int data = 12;
	result = ListPushHead(NULL, data);
	PrintErrResult("TestListPushHeadNULLList", result, ERR_NOT_INITIALIZED);
	return;
}

void TestListPushHeadOnce()
{
	List* list;
	ADTErr result;
	int data = 12;
	list = ListCreate();
	result = ListPushHead(list, data);
	PrintErrResult("TestListPushHeadOnce", result, ERR_OK);
	return;
}

void TestListPushHeadTwice()
{
	List* list;
	ADTErr result;
	int data = 12;
	list = ListCreate();
	result = ListPushHead(list, data);
	if (result == ERR_OK)
	{
		result = ListPushHead(list, data);
	}
	PrintErrResult("TestListPushHeadTwice", result, ERR_OK);
	return;
}

void TestListPopHeadNULLList()
{
	ADTErr result;
	int data;
	result = ListPopHead(NULL, &data);
	PrintErrResult("TestListPopHeadNULLList", result, ERR_NOT_INITIALIZED);
	return;
}

void TestListPopHeadNULLData()
{
	List* list;
	ADTErr result;
	list = ListCreate();
	result = ListPopHead(list, NULL);
	PrintErrResult("TestListPopHeadNULLData", result, ERR_NOT_INITIALIZED);
	return;
}

void TestListPopHeadEmptyList()
{
	List* list;
	ADTErr result;
	int data;
	list = ListCreate();
	result = ListPopHead(list, &data);
	PrintErrResult("TestListPopHeadEmptyList", result, ERR_EMPTY_LIST);
	return;
}

void TestListPopHeadOnce()
{
	List* list;
	ADTErr result;
	int data;
	list = ListCreate();
	ListPushHead(list, 12);
	result = ListPopHead(list, &data);
	PrintErrResult("TestListPopHeadOnce", result, ERR_OK);
	return;
}

void TestListPopHeadTwice()
{
	List* list;
	ADTErr result;
	int data;
	list = ListCreate();
	ListPushHead(list, 12);
	ListPushHead(list, 13);
	result = ListPopHead(list, &data);
	if (result == ERR_OK)
	{
		result = ListPopHead(list, &data);
	}
	PrintErrResult("TestListPopHeadTwice", result, ERR_OK);
	return;
}

void TestListPushTailNULLList()
{
	ADTErr result;
	int data = 12;
	result = ListPushHead(NULL, data);
	PrintErrResult("TestListPushTailNULLList", result, ERR_NOT_INITIALIZED);
	return;
}

void TestListPushTailOnce()
{
	List* list;
	ADTErr result;
	int data = 12;
	list = ListCreate();
	result = ListPushTail(list, data);
	PrintErrResult("TestListPushTailOnce", result, ERR_OK);
	return;
}

void TestListPushTailTwice()
{
	List* list;
	ADTErr result;
	int data = 12;
	list = ListCreate();
	result = ListPushTail(list, data);
	if (result == ERR_OK)
	{
		result = ListPushTail(list, data);
	}
	PrintErrResult("TestListPushTailTwice", result, ERR_OK);
	return;
}

void TestListPopTailNULLList()
{
	ADTErr result;
	int data;
	result = ListPopTail(NULL, &data);
	PrintErrResult("TestListPopTailNULLList", result, ERR_NOT_INITIALIZED);
	return;
}

void TestListPopTailNULLData()
{
	List* list;
	ADTErr result;
	list = ListCreate();
	result = ListPopTail(list, NULL);
	PrintErrResult("TestListPopTailNULLData", result, ERR_NOT_INITIALIZED);
	return;
}

void TestListPopTailEmptyList()
{
	List* list;
	ADTErr result;
	int data;
	list = ListCreate();
	result = ListPopTail(list, &data);
	PrintErrResult("TestListPopTailEmptyList", result, ERR_EMPTY_LIST);
	return;
}

void TestListPopTailOnce()
{
	List* list;
	ADTErr result;
	int data;
	list = ListCreate();
	ListPushHead(list, 12);
	result = ListPopTail(list, &data);
	PrintErrResult("TestListPopTailOnce", result, ERR_OK);
	return;
}

void TestListPopTailTwice()
{
	List* list;
	ADTErr result;
	int data;
	list = ListCreate();
	ListPushHead(list, 12);
	ListPushHead(list, 13);
	result = ListPopTail(list, &data);
	if (result == ERR_OK)
	{
		result = ListPopTail(list, &data);
	}
	PrintErrResult("TestListPopTailTwice", result, ERR_OK);
	return;
}

void TestListCountItemsNULLList()
{
	ADTErr result;
	size_t nItems;
	nItems = ListCountItems(NULL);
	if (0 == nItems)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListCountItemsNULLList", result, ERR_OK);
	return;
}

void TestListCountItemsEmptyList()
{
	ADTErr result;
	List* list;
	size_t nItems;
	list = ListCreate();
	nItems = ListCountItems(list);
	if (0 == nItems)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListCountItemsEmptyList", result, ERR_OK);
	return;
}

void TestListCountItemsOneItem()
{
	ADTErr result;
	List* list;
	size_t nItems;
	list = ListCreate();
	result = ListPushHead(list, 12);
	nItems = ListCountItems(list);
	if (1 == nItems)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListCountItemsOneItem", result, ERR_OK);
	return;
}

void TestListCountItemsTwoItems()
{
	ADTErr result;
	List* list;
	size_t nItems;
	list = ListCreate();
	result = ListPushHead(list, 12);
	result = ListPushHead(list, 15);
	nItems = ListCountItems(list);
	if (2 == nItems)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListCountItemsTwoItems", result, ERR_OK);
	return;
}

void TestListIsEmptyNULLList()
{
	ADTErr result;
	int isEmpty;
	isEmpty = ListIsEmpty(NULL);
	if (-1 == isEmpty)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListIsEmptyNULLList", result, ERR_OK);
	return;
}

void TestListIsEmptyEmptyList()
{
	ADTErr result;
	int isEmpty;
	List* list;
	list = ListCreate();
	isEmpty = ListIsEmpty(list);
	if (1 == isEmpty)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListIsEmptyEmptyList", result, ERR_OK);
	return;
}


void TestListIsEmptyOneItem()
{
	ADTErr result;
	int isEmpty;
	List* list;
	list = ListCreate();
	ListPushHead(list, 12);
	isEmpty = ListIsEmpty(list);
	if (0 == isEmpty)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListIsEmptyOneItem", result, ERR_OK);
	return;
}

void TestListIsEmptyTwoItems()
{
	ADTErr result;
	int isEmpty;
	List* list;
	list = ListCreate();
	ListPushHead(list, 12);
	ListPushHead(list, 15);
	isEmpty = ListIsEmpty(list);
	if (0 == isEmpty)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_GENERAL;
	}
	PrintErrResult("TestListIsEmptyTwoItems", result, ERR_OK);
	return;
}



int main()
{
	printf("\n");
	TestListCreate();
	TestListDestroy();

	TestListPushHeadNULLList();
	TestListPushHeadOnce();
	TestListPushHeadTwice();

	TestListPopHeadNULLList();
	TestListPopHeadNULLData();
	TestListPopHeadEmptyList();
	TestListPopHeadOnce();
	TestListPopHeadTwice();

	TestListPushTailNULLList();
	TestListPushTailOnce();
	TestListPushTailTwice();

	TestListPopTailNULLList();
	TestListPopTailNULLData();
	TestListPopTailOnce();
	TestListPopTailTwice();

	TestListCountItemsNULLList();
	TestListCountItemsEmptyList();
	TestListCountItemsOneItem();
	TestListCountItemsTwoItems();

	TestListIsEmptyNULLList();
	TestListIsEmptyEmptyList();
	TestListIsEmptyOneItem();
	TestListIsEmptyTwoItems();
	printf("\n");
	return 0;
}
