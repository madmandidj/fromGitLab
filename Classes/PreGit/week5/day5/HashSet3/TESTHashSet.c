/*
Filename: 		TESTHashSet.c 
Description:	Tests for Implementation of HashSet API given by Ronny
Created: 		19/07/17
Created by:		Eyal Alon
Last modified: 	19/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <string.h>
#include "HashSet.h"

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

void TestHashCreateZeroSize()
{
    Hash* hash;
    size_t size = 0;
    hash = HashCreate(size);
	if (NULL != hash)
    {
        printf("FAILED: TestHashCreateZeroSize\n");
    }
    else
    {
        printf("PASSED: TestHashCreateZeroSize\n");
    }
}

void TestHashCreate()
{
    Hash* hash;
    size_t size = 10;
    hash = HashCreate(size);
	if (NULL != hash)
    {
        printf("PASSED: TestHashCreate\n");
    }
    else
    {
        printf("FAILED: TestHashCreate\n");
    }
    HashDestroy(hash);
}

void TestHashInsertNULLHash()
{
	ADTErr errResult;
    int data = 100;
	errResult = HashInsert(NULL, data);
	PrintErrResult("TestHashInsertNULLHash", errResult, ERR_NOT_INITIALIZED);
}

void TestHashInsertEmptyHash()
{
	ADTErr errResult;
    int data = 100;
    Hash* hash;
    size_t size = 10;
    hash = HashCreate(size);
	errResult = HashInsert(hash, data);
	PrintErrResult("TestHashInsertEmptyHash", errResult, ERR_OK);
	HashDestroy(hash);
}

void TestHashInsertDataExists()
{
	ADTErr errResult;
    int data = 100;
    Hash* hash;
    size_t size = 10;
    hash = HashCreate(size);
	HashInsert(hash, data);
	errResult = HashInsert(hash, data);
	PrintErrResult("TestHashInsertDataExists", errResult, ERR_VAL_EXISTS);
	/*PrintHash(hash);*/
	HashDestroy(hash);
}

void TestHashInsertDataExistsOneCollision()
{
	ADTErr errResult;
    int data = 100;
    int data2 = 10;
    Hash* hash;
    size_t size = 10;
    hash = HashCreate(size);
	HashInsert(hash, data);
	errResult = HashInsert(hash, data2);
	PrintErrResult("TestHashInsertDataExistsOneCollision", errResult, ERR_OK);
	PrintHash(hash);
	HashDestroy(hash);
}

void TestHashInsertDataExistsTwoCollision()
{
	ADTErr errResult;
    int data = 100;
    int data2 = 10;
    int data3 = 1000;
    Hash* hash;
    size_t size = 10;
    hash = HashCreate(size);
	HashInsert(hash, data);
	HashInsert(hash, data2);
	errResult = HashInsert(hash, data3);
	PrintErrResult("TestHashInsertDataExistsTwoCollision", errResult, ERR_OK);
	PrintHash(hash);
	HashDestroy(hash);
}



int main()
{
	printf("\n");
	/* Tests to Implement */
	TestHashCreateZeroSize();
	TestHashCreate();
	TestHashInsertNULLHash();
	TestHashInsertEmptyHash();
	TestHashInsertDataExists();
	TestHashInsertDataExistsOneCollision();
	TestHashInsertDataExistsTwoCollision();
	/*
	TestHashInsertDataExistsTwice();
	TestHashInsertFullHash();
	TestHashRemoveNULLHash();
	TestHashRemoveEmptyHash();
	TestHashRemoveDataExists();
	TestHashRemoveDataExistsTwice();
	TestHashRemoveFullHash();
	TestHashIsFoundNULLHash();
	TestHashIsFoundEmptyHash();
	TestHashIsFoundDataExists();
	TestHashIsFoundDataNotExists();
	TestHashCapacityNULLHash();
	TestHashCapacity();
	TestHashAverageCollisionsNULLHash();
	TestHashAverageCollisionsOneCollisionOneItem();
	TestHashAverageCollisionsOneCollisionTenItems();
	TestHashMaxCollisionsNULLHash();
	TestHashMaxCollisions();
	TestHashMaxCollisionsOffsetBiggerThanSize();	
	TestHashDestroyTwice();
	*/
    printf("\n");
	return 0;
}