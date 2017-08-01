/*
Filename: 		TESTBinaryTree.c 
Description:	Tests for Implementation of binary tree API given by Izik.
Created: 		17/07/17
Created by:		Eyal Alon
Last modified: 	18/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"

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

void TestTreeCreate()
{
	Tree* tree;
	ADTErr result;
	tree = TreeCreate();
	if (NULL != tree)
	{
		result = ERR_OK;
	}
	else
	{
		result = ERR_ALLOCATION_FAILED;
	}
	PrintErrResult("TestTreeCreate", result, ERR_OK);
	TreeDestroy(tree);
	return;
}

void TestTreeDestroyTwice()
{
	Tree* tree;
	tree = TreeCreate();
	TreeDestroy(tree);
	TreeDestroy(tree);
	return;
}

void TestInsertNULLTree()
{
	ADTErr result;
	int data = 5;
	result = TreeInsert(NULL, data);
	PrintErrResult("TestInsertNULLTree", result, ERR_NOT_INITIALIZED);
	return;
}

void TestInsertEmptyTree()
{
    Tree* tree;
	ADTErr result;
	int data = 5;
    tree = TreeCreate();
	result = TreeInsert(tree, data);
	PrintErrResult("TestInsertEmptyTree", result, ERR_OK);
	TreeDestroy(tree);
	return;
}

void TestInsertTreeTwice()
{
    Tree* tree;
	ADTErr result;
	int data = 5;
    tree = TreeCreate();
	TreeInsert(tree, data);
    data = 11;
    result = TreeInsert(tree, data);
    PrintErrResult("TestInsertTreeTwice", result, ERR_OK);
	TreeDestroy(tree);
	return;
}

void TestInsertExistingVal()
{
    Tree* tree;
	ADTErr result;
	int data = 5;
    tree = TreeCreate();
	result = TreeInsert(tree, data);
    result = TreeInsert(tree, data);
    PrintErrResult("TestInsertExistingVal", result, ERR_VALUE_EXISTS);
	TreeDestroy(tree);
	return;
}

void TestIsDataFoundNULLTree()
{
	int result;
	int data = 5;
    result = TreeIsDataFound(NULL, data);
    if (result == 0)
    {
        printf("PASSED: TestIsDataFoundNULLTree\n");
    }
    else
    {
        printf("FAILED: TestIsDataFoundNULLTree\n");
    }
	return;
}

void TestIsDataFoundEmptyTree()
{
    Tree* tree;
	int result;
	int data = 5;
    tree = TreeCreate();
    result = TreeIsDataFound(tree, data);
    if (result == 0)
    {
        printf("PASSED: TestIsDataFoundEmptyTree\n");
    }
    else
    {
        printf("FAILED: TestIsDataFoundEmptyTree\n");
    }
	TreeDestroy(tree);
	return;
}

void TestIsDataFoundExists()
{
    Tree* tree;
	int result;
	int data = 5;
    tree = TreeCreate();
    TreeInsert(tree, data);
    result = TreeIsDataFound(tree, data);
    if (result == 1)
    {
        printf("PASSED: TestIsDataFoundExists\n");
    }
    else
    {
        printf("FAILED: TestIsDataFoundExists\n");
    }
	TreeDestroy(tree);
	return;
}

void TestIsDataFoundNotExists()
{
    Tree* tree;
	int result;
	int data = 5;
    tree = TreeCreate();
    TreeInsert(tree, data);
    result = TreeIsDataFound(tree, 10);
    if (result == 0)
    {
        printf("PASSED: TestIsDataFoundNotExists\n");
    }
    else
    {
        printf("FAILED: TestIsDataFoundNotExists\n");
    }
	TreeDestroy(tree);
	return;
}

int main()
{
	TestTreeCreate();
    TestInsertNULLTree();
    TestInsertEmptyTree();
    TestInsertTreeTwice();
    TestInsertExistingVal();
    TestIsDataFoundNULLTree();
    TestIsDataFoundEmptyTree();
    TestIsDataFoundExists();
    TestIsDataFoundNotExists();
    TestTreeDestroyTwice();
	return 0;
}
