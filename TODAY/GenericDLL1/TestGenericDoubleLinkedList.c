/*
Filename: 		TestGenericDoubleLinkedList.c 
Description:	Tests for generic DLL API
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	06/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <stdlib.h>
#include "GenericDoubleLinkedList.h"

/*
	LISTE ERRORS PRINT FUNCTION
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
int DestroyElementPerson(void* _element, void* _context)
{
    return 1;
}


/******
LIST CREATE TESTS
******/
void TestListCreate()
{
    List* list;
    list = TestListCreate();
    if (NULL != list)
    {
        printf("PASS: TestListCreate\n");
    }
    else
    {
        printf("FAIL: TestListCreate\n");
    }
    return;
}

/******
LIST DESTROY TESTS
******/


/******
LIST PUSH HEAD TESTS
******/


/******
LIST PUSH TAIL TESTS
******/


/******
LIST POP HEAD TESTS
******/


/******
LIST POP TAIL TESTS
******/


/******
LIST COUNT ITEMS TESTS
******/


/******
LIST IS EMPTY TESTS
******/


/******
LIST FIND FIRST FORWARD TESTS
******/


/******
LIST FIND FIRST BACKWARD TESTS
******/

int main()
{
    TestListCreate();
    return 0;
}


