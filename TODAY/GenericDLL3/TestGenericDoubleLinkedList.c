/*
Filename: 		TestGenericDoubleLinkedList.c 
Description:	Tests for generic DLL API
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	06/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>      /* printf */
#include <string.h>     /* strcpy */
#include "GenericDoubleLinkedList.h"
#define TRUE 1
#define FALSE 0

typedef struct Person Person;
struct Person
{
	size_t 		m_age;
	char 		m_name[64];
	size_t 		m_famSize;
	Person**	m_family;
};

/* 
TODO: debug pop head and pop tail tests. according to debugger: free(arr) (line 419) is where the problem is.
TODO: add Person struct and appropriate tests. 
TODO: add test list destroy that uses action.
*/

/*
	INITIALIZE FUNCTIONS
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
		else
		{
			strcpy(errString, "LIST_ERR_UNDEFINED");
		}
        printf("FAIL: %s %s\n", _testName, errString);
    }
    return;
}









/******
USER ACTION FUNCTIONS
******/
int PrintElementInt(int* _intPtr, void* _context)
{
    if (NULL == _intPtr)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", *_intPtr);
    }
    return 1;
}

int	ElementPersonPrint(Person* _prs, size_t _index, void* _context)
{
	printf("Index = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_name, _prs->m_age);
	printf("Family1 = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_family[0]->m_name, _prs->m_family[0]->m_age);
	printf("Family2 = %u, \tName = %s, \tAge = %u\n", _index, _prs->m_family[1]->m_name, _prs->m_family[1]->m_age);
	return 1;
}

void ElementDestroyPerson(Person* _item, void* _context)
{
	// Person* perItem = (Person*) _item;
	if (NULL != _item && NULL != _item->m_family)
	{
		free(_item->m_family);
	}
	return;
}







/******
PREDICATE FUNCTIONS
******/
int IsIntFoundInElementData(int* _intPtr, int* _key)
{
    if (NULL == _intPtr || NULL == _key)
    {
        return FALSE;
    }
    if (*_intPtr == *_key)
    {
        return TRUE;
    }
    return FALSE;
}









/******
LIST CREATE TESTS
******/
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
    int* data;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    data = &arr[5];
    err = ListPushHead(NULL, data);
    PrintErrResult("TestListPushHeadNULLList", err, LIST_UNINITIALIZED);
    free(arr);
    return;
}

static void TestListPushHeadIntNULLData()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    int* data;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    data = &arr[5];
    err = ListPushTail(NULL, data);
    PrintErrResult("TestListPushTailIntNULLList", err, LIST_UNINITIALIZED);
    free(arr);
    return;
}

static void TestListPushTailIntNULLData()
{
    List* list;
    ListErrors err;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
static void TestListPopHeadInt()
{
    List* list;
    ListErrors err;
    int* arr;
    int data = 0;
    size_t index;
    size_t numOfInts = 10;
    arr = (int*) malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    err = ListPopHead(list, (void**) &data);
    PrintErrResult("TestListPopHeadInt", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}









/******
LIST POP TAIL TESTS
******/
static void TestListPopTailInt()
{
    List* list;
    ListErrors err;
    int* arr;
    int data = 0;
    size_t index;
    size_t numOfInts = 10;
    arr = (int*) malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    list = ListCreate();
    ListPushHead(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushHead(list, arr + 2);
    ListPushTail(list, arr + 1);
    err = ListPopTail(list, (void**) &data);
    ListForEach(list, (UserActionFunc) PrintElementInt, NULL);
    PrintErrResult("TestListPopTailInt", err, LIST_OK);
    ListDestroy(&list, NULL);
    free(arr);
    return;
}









/******
LIST COUNT ITEMS TESTS
******/
static void TestListCountItemsInt()
{
    List* list;
    size_t listNItems;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    arr = (int*) malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
static void TestListIsEmptyIntNotEmpty()
{
    List* list;
    int listIsEmpty;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    arr = (int*) malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    arr = (int*) malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    int* item;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    int* item;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    int* item;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    size_t index;
    size_t numOfInts = 10;
    int* item;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
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
    ListErrors err;
    int* arr;
    size_t index;
    size_t numOfInts = 10;
    size_t actionCount;
    arr = malloc(numOfInts * sizeof(int));
    for (index = 0; index < numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    list = ListCreate();
    ListPushTail(list, arr + 4);
    ListPushTail(list, arr + 3);
    ListPushTail(list, arr + 2);
    ListPushTail(list, arr + 1);
    err = ListPushTail(list, arr);
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






int main()
{
    printf("\n");
    TestListCreate();
    TestListDestroyNULLList();
    TestListDestroyNULLAction();
    TestListDestroyDoubleDestroy();
    TestListPushHeadIntNULLList();
    TestListPushHeadIntNULLData();
    TestListPushHeadIntOneItem();
    TestListPushHeadIntFiveItem();
    TestListPushTailIntNULLList();
    TestListPushTailIntNULLData();
    TestListPushTailIntOneItem();
    TestListPushTailIntFiveItem();
    TestListPushHeadTailHeadTailInt();
    /*
    TestListPopHeadInt();
    TestListPopTailInt();
    */
    TestListCountItemsInt();
    TestListIsEmptyIntNotEmpty();
    TestListIsEmptyIntIsEmpty();
    TestListFindFirstForwardIntFound();
    TestListFindFirstForwardIntNotFound();
    TestListFindFirstBackwardIntFound();
    TestListFindFirstBackwardIntNotFound();
    TestListPushHeadPersonFiveItemWithDestroy();




    TestListForEachPrintInt();
    TestListForEachPrintPerson();
    printf("\n");
    return 0;
}


