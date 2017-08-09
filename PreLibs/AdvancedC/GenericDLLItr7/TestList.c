/*
Filename: 		TestGenericDoubleLinkedList.c 
Description:	Tests for generic DLL API
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	07/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>      /* printf */
#include <string.h>     /* strcpy */
#include "list_functions.h"
#define TRUE 1
#define FALSE 0




/*
	INITIALIZE FUNCTIONS
*/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;

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
	LIST ERRORS PRINT FUNCTION
*/
static void PrintErrResult(char* _testName, ListErrors _err, ListErrors _passErr)
{
    char errString[64];
    if (_err == _passErr)
    {
        printf("PASS: %s\n", _testName);
    }
    else
    {
        if (_err == LIST_OK)
        {
            strcpy(errString, "LIST_OK");
        }
        else if (_err == LIST_UNINITIALIZED)
        {
           strcpy(errString, "LIST_UNINITIALIZED");
        }
        else if (_err == LIST_ALLOCATION_FAILED)
        {
           strcpy(errString, "LIST_ALLOCATION_FAILED");
        }
        else if (_err == LIST_IS_EMPTY)
        {
           strcpy(errString, "LIST_IS_EMPTY");
        }
        else if (_err == LIST_ITEM_NOT_FOUND)
        {
           strcpy(errString, "LIST_ITEM_NOT_FOUND"); 
        }
        else if (_err == LIST_INV_ARG)
        {
           strcpy(errString, "LIST_INV_ARG"); 
        }
		else
		{
			strcpy(errString, "LIST_ERR_UNDEFINED");
		}
        printf("FAIL: %s %s\n", _testName, errString);
    }
    return;
}









/******
LIST CREATE TESTS
******/
/*
TODO: add test to check that magic num changed to correct value
*/
static void TestListCreate()
{
    List* list;

    list = ListCreate();
    if (NULL != list)
    {
        printf("PASS: TestListCreate\n");
    }
    else
    {
        printf("FAIL: TestListCreate\n");
    }
    ListDestroy(&list, NULL);
    return;
}







/******
LIST DESTROY TESTS
******/
static void TestListDestroyNULLList()
{
    ListDestroy(NULL, NULL);
    printf("PASS: TestListDestroyNULLList\n");
    return;
}

static void TestListDestroyNULLAction()
{
    List* list;

    list = ListCreate();
    ListDestroy(&list, NULL);
    if (NULL == list)
    {
        printf("PASS: TestListDestroyNULLAction\n");
    }
    else
    {
        printf("FAIL: TestListDestroyNULLAction\n");
    }
    return;
}

static void TestListDestroyDoubleDestroy()
{
    List* list;

    list = ListCreate();
    ListDestroy(&list, NULL);
    ListDestroy(&list, NULL);
    if (NULL == list)
    {
        printf("PASS: TestListDestroyDoubleDestroy\n");
    }
    else
    {
        printf("FAIL: TestListDestroyDoubleDestroy\n");
    }
    return;
}



/******
LIST PUSH HEAD TESTS
******/
static void TestListPushHeadIntNULLList()
{
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    err = ListPushHead(NULL, arr + 5);
    PrintErrResult("TestListPushHeadNULLList", err, LIST_UNINITIALIZED);
    free(arr);
    return;
}

static void TestListPushHeadIntNULLData()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    err = ListPushHead(list, NULL);
    PrintErrResult("TestListPushHeadIntNULLData", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPushHeadIntOneItem()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    err = ListPushHead(list, arr + 5);
    PrintErrResult("TestListPushHeadIntOneItem", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPushHeadIntFiveItem()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushHead(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushHead(list, arr + 1);
    err = ListPushHead(list, arr);
    PrintErrResult("TestListPushHeadIntFiveItem", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPushHeadPersonFiveItemWithDestroy()
{
	List* list;
	ListErrors err;
	size_t numOfPersons = 5;
	Person* arr;

	arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
	InitPersArr(arr);
	list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushHead(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushHead(list, arr + 1);
    err = ListPushHead(list, arr);
    PrintErrResult("TestListPushHeadPersonFiveItemWithDestroy", err, LIST_OK);
    ListDestroy(&list, (UserActionFunc) ElementDestroyPerson);
    free(arr);
	return;
}







/******
LIST PUSH TAIL TESTS
******/
static void TestListPushTailIntNULLList()
{
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    err = ListPushTail(NULL, arr + 5);
    PrintErrResult("TestListPushTailIntNULLList", err, LIST_UNINITIALIZED);
    free(arr);
    return;
}

static void TestListPushTailIntNULLData()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    err = ListPushTail(list, NULL);
    PrintErrResult("TestListPushTailIntNULLData", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPushTailIntOneItem()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    err = ListPushTail(list, arr + 5);
    PrintErrResult("TestListPushTailIntOneItem", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPushTailIntFiveItem()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    err = ListPushTail(list, arr);
    PrintErrResult("TestListPushTailIntFiveItem", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPushHeadTailHeadTailInt()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    err = ListPushTail(list, arr + 1);
    PrintErrResult("TestListPushHeadTailHeadTailInt", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST POP HEAD TESTS
******/
static void TestListPopHeadIntNULLList()
{
    List* list;
    ListErrors err;
    int* data = NULL;

    list = ListCreate();
    err = ListPopHead(NULL, (void**) &data);
    PrintErrResult("TestListPopHeadIntNULLList", err, LIST_UNINITIALIZED);
    ListDestroy(&list, NULL);
    return;
}

static void TestListPopHeadIntNULLData()
{
    List* list;
    ListErrors err;

    list = ListCreate();
    err = ListPopHead(list, NULL);
    PrintErrResult("TestListPopHeadIntNULLData", err, LIST_INV_ARG);
    ListDestroy(&list, NULL);
    return;
}

static void TestListPopHeadIntCheckVal()
{
    List* list;
    int* arr;
    int* data = NULL;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    ListPopHead(list, (void**) &data);
    if (2 == *data)
    {
        printf("PASS: TestListPopHeadIntCheckVal, value correct\n");
    }
    else
    {
        printf("FAIL: TestListPopHeadIntCheckVal, value incorrect\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPopHeadIntEmptyList()
{
    List* list;
    ListErrors err;
    int* data = NULL;

    list = ListCreate();
    err = ListPopHead(list, (void**) &data);
    PrintErrResult("TestListPopHeadIntEmptyList", err, LIST_IS_EMPTY);
    ListDestroy(&list, NULL);
    return;
}







/******
LIST POP TAIL TESTS
******/
static void TestListPopTailIntNULLList()
{
    List* list;
    ListErrors err;
    int* data = NULL;

    list = ListCreate();
    err = ListPopTail(NULL, (void**) &data);
    PrintErrResult("TestListPopTailIntNULLList", err, LIST_UNINITIALIZED);
    ListDestroy(&list, NULL);
    return;
}

static void TestListPopTailIntNULLData()
{
    List* list;
    ListErrors err;

    list = ListCreate();
    err = ListPopTail(list, NULL);
    PrintErrResult("TestListPopTailIntNULLData", err, LIST_INV_ARG);
    ListDestroy(&list, NULL);
    return;
}

static void TestListPopTailIntCheckVal()
{
    List* list;
    ListErrors err;
    int* arr;
    int* data = NULL;
    size_t numOfInts = 10;
    
    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    err = ListPopTail(list, (void**) &data);
    PrintErrResult("TestListPopTailIntCheckVal", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListPopTailIntEmptyList()
{
    List* list;
    ListErrors err;
    int* data = NULL;

    list = ListCreate();
    err = ListPopTail(list, (void**) &data);
    PrintErrResult("TestListPopTailIntEmptyList", err, LIST_IS_EMPTY);
    ListDestroy(&list, NULL);
    return;
}







/******
LIST COUNT ITEMS TESTS
******/
static void TestListCountItemsIntNULLList()
{
    size_t listNItems;

    listNItems = ListCountItems(NULL);
    if (0 == listNItems)
    {
        printf("PASS: TestListCountItemsIntNULLList\n");
    }
    else
    {
        printf("FAIL: TestListCountItemsIntNULLList\n");
    }
    return;
}

static void TestListCountItemsIntZeroItems()
{
    List* list;
    size_t listNItems;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    listNItems = ListCountItems(list);
    if (0 == listNItems)
    {
        printf("PASS: TestListCountItemsIntZeroItems\n");
    }
    else
    {
        printf("FAIL: TestListCountItemsIntZeroItems\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListCountItemsInt()
{
    List* list;
    size_t listNItems;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listNItems = ListCountItems(list);
    if (4 == listNItems)
    {
        printf("PASS: TestListCountItemsInt, value correct\n");
    }
    else
    {
        printf("FAIL: TestListCountItemsInt, value incorrect\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST IS EMPTY TESTS
******/
static void TestListIsEmptyIntNULLList()
{
    int listIsEmpty;

    listIsEmpty = ListIsEmpty(NULL);
    if (-1 == listIsEmpty)
    {
        printf("PASS: TestListIsEmptyIntNULLList\n");
    }
    else
    {
        printf("FAIL: TestListIsEmptyIntNULLList\n");
    }
    return;
}

static void TestListIsEmptyIntNotEmpty()
{
    List* list;
    int listIsEmpty;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listIsEmpty = ListIsEmpty(list);
    if (0 == listIsEmpty)
    {
        printf("PASS: TestListIsEmptyIntNotEmpty\n");
    }
    else
    {
        printf("FAIL: TestListIsEmptyIntNotEmpty\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListIsEmptyIntIsEmpty()
{
    List* list;
    int listIsEmpty;
    int* arr;
    size_t numOfInts = 10;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    listIsEmpty = ListIsEmpty(list);
    if (1 == listIsEmpty)
    {
        printf("PASS: TestListIsEmptyIntIsEmpty\n");
    }
    else
    {
        printf("FAIL: TestListIsEmptyIntIsEmpty\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST FIND FIRST FORWARD TESTS
******/
static void TestListFindFirstForwardIntFound()
{
    List* list;
    int* arr;
    int key = 3;
    size_t numOfInts = 10;
    int* item;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr);
    FindFirstForward(list, (PredicateFunc) IsIntFoundInElementData , &key, (void**) &item);
    if (3 == *item)
    {
        printf("PASS: TestListFindFirstForwardIntFound\n");
    }
    else
    {
        printf("FAIL: TestListFindFirstForwardIntFound\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListFindFirstForwardIntNotFound()
{
    List* list;
    int* arr;
    int key = 12;
    size_t numOfInts = 10;
    int* item;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr);
    FindFirstForward(list, (PredicateFunc) IsIntFoundInElementData , &key, (void**) &item);
    if (NULL == item)
    {
        printf("PASS: TestListFindFirstForwardIntNotFound\n");
    }
    else
    {
        printf("FAIL: TestListFindFirstForwardIntNotFound\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST FIND FIRST BACKWARD TESTS
******/
static void TestListFindFirstBackwardIntFound()
{
    List* list;
    int* arr;
    int key = 3;
    size_t numOfInts = 10;
    int* item;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr);
    FindFirstBackward(list, (PredicateFunc) IsIntFoundInElementData , &key, (void**) &item);
    if (3 == *item)
    {
        printf("PASS: TestListFindFirstBackwardIntFound\n");
    }
    else
    {
        printf("FAIL: TestListFindFirstBackwardIntFound\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListFindFirstBackwardIntNotFound()
{
    List* list;
    int* arr;
    int key = 12;
    size_t numOfInts = 10;
    int* item;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr);
    FindFirstBackward(list, (PredicateFunc) IsIntFoundInElementData , &key, (void**) &item);
    if (NULL == item)
    {
        printf("PASS: TestListFindFirstBackwardIntNotFound\n");
    }
    else
    {
        printf("FAIL: TestListFindFirstBackwardIntNotFound\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST FOR EACH TESTS
******/
static void TestListForEachPrintInt()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    size_t actionCount;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr);
    actionCount = ListForEach(list, (UserActionFunc) PrintElementInt, NULL);
    if (5 == actionCount)
    {
        printf("PASS: TestListForEachPrintInt\n");
    }
    else
    {
        printf("FAIL: TestListForEachPrintInt\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListForEachPrintPerson()
{
	List* list;
	size_t numOfPersons = 5;
	Person* arr;
    size_t actionCount;

	arr = malloc(numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return;
	}
	InitPersArr(arr);
	list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushHead(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushHead(list, arr + 1);
    ListPushHead(list, arr);
    actionCount = ListForEach(list, (UserActionFunc) ElementPersonPrint, NULL);
    if (5 == actionCount)
    {
        printf("PASS: TestListForEachPrintPerson\n");
    }
    else
    {
        printf("FAIL: TestListForEachPrintPerson\n");
    }
    ListDestroy(&list, (UserActionFunc) ElementDestroyPerson);
    free(arr);
	return;
}







/******
LIST ITERATOR BEGIN TESTS
******/
/*
TODO: do test for empty list
*/
static void TestListItrBeginNULLList()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr = ListItrBegin(NULL);
    if (NULL == listItr)
    {
        printf("PASS: TestListItrBeginNULLList\n");
    }
    else
    {
        printf("FAIL: TestListItrBeginNULLList\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR END TESTS
******/
/*
TODO: do test for empty list
*/
static void TestListItrEndNULLList()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr = ListItrEnd(NULL);
    if (NULL == listItr)
    {
        printf("PASS: TestListItrEndNULLList\n");
    }
    else
    {
        printf("FAIL: TestListItrEndNULLList\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR GET TESTS
******/
/*
TODO: do test for empty list
*/
static void TestListItrGetNULLItr()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    int* data;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    data = ListItrGet(NULL);
    if (NULL == data)
    {
        printf("PASS: TestListItrGetNULLItr\n");
    }
    else
    {
        printf("FAIL: TestListItrGetNULLItr\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListItrGetEndItr()
{
    List* list;
    int* arr;
    
    size_t numOfInts = 10;
    ListItr listItr;
    int* data;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr = ListItrEnd(list);
    data = ListItrGet(listItr);
    if (NULL == data)
    {
        printf("PASS: TestListItrGetEndItr\n");
    }
    else
    {
        printf("FAIL: TestListItrGetEndItr\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListItrGetValue()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr;
    int* data;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr = ListItrBegin(list);
    data = ListItrGet(listItr);
    if (2 == *data)
    {
        printf("PASS: TestListItrGetValue, correct value\n");
    }
    else
    {
        printf("FAIL: TestListItrGetValue, incorrect value\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR PREV TESTS
******/
/*
TODO: test NULL itr
TODO: test when itr is FIRST
*/
static void TestListItrPrevValue()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr;
    int* data;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr = ListItrEnd(list);
    listItr = ListItrPrev(listItr);
    data = ListItrGet(listItr);
    if (1 == *data)
    {
        printf("PASS: TestListItrPrevValue, correct value\n");
    }
    else
    {
        printf("FAIL: TestListItrPrevValue, incorrect value\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR NEXT TESTS
******/
/*
TODO: test NULL itr
TODO: test when itr is Tail
*/
static void TestListItrNextValue()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr;
    int* data;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr = ListItrBegin(list);
    listItr = ListItrNext(listItr);
    data = ListItrGet(listItr);
    if (4 == *data)
    {
        printf("PASS: TestListItrNextValue, correct value\n");
    }
    else
    {
        printf("FAIL: TestListItrNextValue, incorrect value\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR EQUALS TESTS
******/
/*
TODO: test NULL a, b
*/
static void TestListItrEqualsSame()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr1;
    ListItr listItr2;
    int isEqual = FALSE;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr1 = ListItrBegin(list);
    listItr1 = ListItrNext(listItr1);
    listItr2 = ListItrBegin(list);
    listItr2 = ListItrNext(listItr2);
    isEqual = ListItrEquals(listItr1, listItr2);
    if (TRUE == isEqual)
    {
        printf("PASS: TestListItrEqualsSame\n");
    }
    else
    {
        printf("FAIL: TestListItrEqualsSame\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}

static void TestListItrEqualsDifferent()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr1;
    ListItr listItr2;
    int isEqual = FALSE;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr1 = ListItrBegin(list);
    listItr1 = ListItrNext(listItr1);
    listItr2 = ListItrBegin(list);
    isEqual = ListItrEquals(listItr1, listItr2);
    if (FALSE == isEqual)
    {
        printf("PASS: TestListItrEqualsDifferent\n");
    }
    else
    {
        printf("FAIL: TestListItrEqualsDifferent\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR SET TESTS
******/
/*
TODO: test NULL itr, NULL data, Empty List
TODO: test set on FIRST, test set on tail
*/
static void TestListItrSetValue()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr1;
    int* data;
    int* getResult;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr1 = ListItrBegin(list);
    listItr1 = ListItrNext(listItr1);
    data = ListItrSet(listItr1, arr + 7);
    getResult = ListItrGet(listItr1);
    if (4 == *data  && 7 == *getResult)
    {
        printf("PASS: TestListItrSetValue, correct value\n");
    }
    else
    {
        printf("FAIL: TestListItrSetValue, incorrect value\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR INSERT BEFORE TESTS
******/
/*
TODO: test NULL itr
TODO: test when itr is Head
TODO: test on empty list when itr is on Tail
*/
static void TestListItrInsertBefore()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr1;
    int* getResult;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr1 = ListItrEnd(list);
    listItr1 = ListItrInsertBefore(listItr1, arr + 8);
    getResult = ListItrGet(listItr1);
    if (8 == *getResult)
    {
        printf("PASS: TestListItrInsertBefore, correct value\n");
    }
    else
    {
        printf("FAIL: TestListItrInsertBefore, incorrect value\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}







/******
LIST ITERATOR REMOVE TESTS
******/
/*
TODO: test NULL itr
TODO: test when itr is Head and Tail
TODO: test on empty list when itr is on Tail and Head
*/
static void TestListItrRemove()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr1;
    int* data;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    listItr1 = ListItrEnd(list);
    listItr1 = ListItrPrev(listItr1);
    listItr1 = ListItrPrev(listItr1);
    data = ListItrRemove(listItr1);
    if (3 == *data)
    {
        printf("PASS: TestListItrRemove, correct value\n");
    }
    else
    {
        printf("FAIL: TestListItrRemove, incorrect value\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}






/******
LIST ITERATOR COUNT IF
******/
static void TestListItrCountIf()
{
    List* list;
    int* arr;
    size_t numOfInts = 10;
    ListItr listItr1;
    ListItr listItr2;
    int data;
    size_t count;
    data = 1;

    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr + 7);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr + 1);
    listItr1 = ListItrBegin(list);
    listItr2 = ListItrEnd(list);
    listItr2 = ListItrPrev(listItr2);
    listItr2 = ListItrPrev(listItr2);
    count = ListItr_CountIf(listItr1, listItr2, (PredicateFunction) IsIntFoundInElementData, &data);
    if (3 == count)
    {
        printf("PASS: TestListItrCountIf\n");
    }
    else
    {
        printf("FAIL: TestListItrCountIf\n");
    }
    ListDestroy(&list, NULL);
    free(arr);
    return;
}









/******
LIST ITERATOR SORT
******/
static void TestListItrSort()
{
    List* list;
    int* arr;
    
    size_t numOfInts = 10;
    ListItr listItr1;
    ListItr listItr2;
    int data;
    data = 1;
    
    arr = InitIntArr(numOfInts);
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 1);
    ListPushTail(list, arr + 5);
    ListPushTail(list, arr + 7);
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 8);
    ListPushTail(list, arr + 9);
    ListForEach(list, (UserActionFunc) PrintElementInt, NULL);
    listItr1 = ListItrBegin(list);
    listItr2 = ListItrEnd(list);
    ListItr_Sort(listItr1, listItr2, (LessFunction) LessThanInt);
    printf("\n");
    ListForEach(list, (UserActionFunc) PrintElementInt, NULL);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}



int main()
{
    printf("\n");
    /* LIST CREATE */
    TestListCreate();

    /* LIST DESTROY */
    TestListDestroyNULLList();
    TestListDestroyNULLAction();
    TestListDestroyDoubleDestroy();

    /* LIST PUSH HEAD */
    TestListPushHeadIntNULLList();
    TestListPushHeadIntNULLData();
    TestListPushHeadIntOneItem();
    TestListPushHeadIntFiveItem();

    /* LIST PUSH TAIL */
    TestListPushTailIntNULLList();
    TestListPushTailIntNULLData();
    TestListPushTailIntOneItem();
    TestListPushTailIntFiveItem();
    TestListPushHeadTailHeadTailInt();

    /* LIST POP HEAD */
    TestListPopHeadIntNULLList();
    TestListPopHeadIntNULLData();
    TestListPopHeadIntCheckVal();
    TestListPopHeadIntEmptyList();

    /* LIST POP TAIL */
    TestListPopTailIntNULLList();
    TestListPopTailIntNULLData();
    TestListPopTailIntCheckVal();
    TestListPopTailIntEmptyList();

    /* LIST COUNT ITEMS */
    TestListCountItemsIntNULLList();
    TestListCountItemsIntZeroItems();
    TestListCountItemsInt();

    /* LIST IS EMPTY */
    TestListIsEmptyIntNULLList();
    TestListIsEmptyIntNotEmpty();
    TestListIsEmptyIntIsEmpty();

    /* LIST FIND FIRST FORWARD */
    TestListFindFirstForwardIntFound();
    TestListFindFirstForwardIntNotFound();

    /* LIST FIND FIRST BACKWARD */
    TestListFindFirstBackwardIntFound();
    TestListFindFirstBackwardIntNotFound();

    /* LIST PUSH HEAD */
    TestListPushHeadPersonFiveItemWithDestroy();

    /* LIST FOR EACH */
    TestListForEachPrintInt();
    TestListForEachPrintPerson();

    /* LIST ITR BEGIN */
    TestListItrBeginNULLList();

    /* LIST ITR END */
    TestListItrEndNULLList();

    /* LIST ITR GET */
    TestListItrGetNULLItr();
    TestListItrGetEndItr();
    TestListItrGetValue();

    /* LIST ITR PREV */
    TestListItrPrevValue();

    /* LIST ITR NEXT */
    TestListItrNextValue();

    /* LIST ITR EQUALS */
    TestListItrEqualsSame();
    TestListItrEqualsDifferent();

    /* LIST ITR SET */
    TestListItrSetValue();

    /* LIST ITR INSERT */
    TestListItrInsertBefore();

    /* LIST ITR REMOVE */
    TestListItrRemove();
    
    /* LIST ITR COUNT IF */
    TestListItrCountIf();

    /* LIST ITR SORT */
    TestListItrSort();

    printf("\n");
    return 0;
}


