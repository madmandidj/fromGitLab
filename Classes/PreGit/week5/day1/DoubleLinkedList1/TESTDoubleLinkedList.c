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
            strcpy(errString, "Undefined error");
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
	ADTErr result;
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

int main()
{

	TestListCreate();
	TestListDestroy();
	TestListPushHeadNULLList();
	TestListPushHeadOnce();
	
	
	/*
	TestListPushHeadOnce();
	TestListPushHeadTwice();
	TestListPopHeadNULLList();
	TestListPopHeadNULLData();
	TestListPopHeadOnce();
	TestListPopHeadTwice();
	TestListPushTailNULLList();
	TestListPushTailNULLData();
	TestListPushTailOnce();
	TestListPushTailTwice();
	TestListPopTailNULLList();
	TestListPopTailNULLData();
	TestListPopTailOnce();
	TestListPopTailTwice();
	TestListCountItemsNULLList();
	TestListCountItemsEmptyList();
	TestListCountItemsOneItem();
	TestListCountItemsFiveItems();
	TestListIsEmptyNULLList();
	TestListIsEmptyEmptyList();
	TestListIsEmptyOneItem();
	TestListIsEmptyFiveItems();
	*/
	return 0;
}
