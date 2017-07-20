#include <stdio.h>
#include <string.h>
#include "queue.h"

void PrintErrResult(char* _testName, ADTErr _err, ADTErr _passErr)
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
        else 
        {
            strcpy(errString, "Undefined error");
        }
        printf("FAILED: %s %s\n", _testName, errString);
    }
    return;
}

void TestQueueCreateSizeNotZero()
{
	size_t size = 10;
	Queue* queue;
	queue = QueueCreate(size);
	if(NULL == queue)
	{
		printf("FAILED: TestQueueCreateSizeNotZero\n");
		return;
	}
	else
	{
		printf("PASSED: TestQueueCreateSizeNotZero\n");
	}
	QueueDestroy(queue);
	return;
}

void TestQueueCreateSizeZero()
{
	size_t size = 0;
	Queue* queue;
	queue = QueueCreate(size);
	if(NULL == queue)
	{
		printf("PASSED: TestQueueCreateSizeZero\n");
		return;
	}
	else
	{
		printf("FAILED: TestQueueCreateSizeZero ERR_ALLOCATION_FAILED\n");
	}
	QueueDestroy(queue);
	return;
}

void TestQueueInsertQueueNull()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	ADTErr err;
	queue = QueueCreate(size);
	err = QueueInsert(NULL, item);
	PrintErrResult("TestQueueInsertQueueNull", err, ERR_NOT_INITIALIZED);
	QueueDestroy(queue);
	return;
}

void TestQueueInsertQueueEmpty()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	ADTErr err;
	queue = QueueCreate(size);
	err = QueueInsert(queue, item);
	PrintErrResult("TestQueueInsertQueueEmpty", err, ERR_OK);
	QueueDestroy(queue);
	return;
}

void TestQueueInsertQueueFull()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int index = 0;
	ADTErr err;
	queue = QueueCreate(size);
	for(index = 0; index <= size; ++index)
	{
		err = QueueInsert(queue, item);
		if(err != ERR_OK)
		{
			break;
		}
	}
	PrintErrResult("TestQueueInsertQueueFull", err, ERR_FULL);
	QueueDestroy(queue);
	return;
}

void TestQueueRemoveQueueNull()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int index = 0;
	int val = 0;
	ADTErr err;
	queue = QueueCreate(size);
	for(index = 0; index < size; ++index)
	{
		QueueInsert(queue, item);
	}
	err = QueueRemove(NULL, &val);
	PrintErrResult("TestQueueRemoveQueueNull", err, ERR_NOT_INITIALIZED);
	QueueDestroy(queue);
	return;
}

void TestQueueRemoveItemNull()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int index = 0;
	ADTErr err;
	queue = QueueCreate(size);
	for(index = 0; index < size; ++index)
	{
		QueueInsert(queue, item);
	}
	err = QueueRemove(queue, NULL);
	PrintErrResult("TestQueueRemoveItemNull", err, ERR_OK);
	QueueDestroy(queue);
	return;
}

void TestQueueRemoveInitialQueueEmpty()
{
	size_t size = 10;
	Queue* queue;
	int val = 0;
	ADTErr err;
	queue = QueueCreate(size);
	err = QueueRemove(queue, &val);
	PrintErrResult("TestQueueRemoveInitialQueueEmpty", err, ERR_EMPTY);
	QueueDestroy(queue);
	return;
}

void TestQueueRemoveQueueEmpty()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int index = 0;
	int val = 0;
	ADTErr err;
	queue = QueueCreate(size);
	for(index = 0; index < size-1; ++index)
	{
		QueueInsert(queue, item);
	}
	for(index = 0; index < size; ++index)
	{
		err = QueueRemove(queue, &val);
		if(err != ERR_OK)
		{
			break;
		}
	}
	PrintErrResult("TestQueueRemoveQueueEmpty", err, ERR_EMPTY);
	QueueDestroy(queue);
	return;
}

void TestQueueRemoveQueueFull()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int index = 0;
	int val = 0;
	ADTErr err;
	queue = QueueCreate(size);
	for(index = 0; index < size; ++index)
	{
		QueueInsert(queue, item);
	}
	err = QueueRemove(queue, &val);
	PrintErrResult("TestQueueRemoveQueueFull", err, ERR_OK);
	QueueDestroy(queue);
	return;
}

void TestQueueRemoveValCorrect()
{
	size_t size = 10;
	Queue* queue;
	int index = 0;
	int val = 0;
	queue = QueueCreate(size);
	for(index = 0; index < size; ++index)
	{
		QueueInsert(queue, index);
	}
	QueueRemove(queue, &val);
	if(0 == val)
	{
		printf("PASSED: TestQueueRemoveValCorrect\n");
	}
	else
	{
		printf("FAILED: TestQueueRemoveValCorrect\n");
	}
	QueueDestroy(queue);
	return;
}

void TestQueueIsEmptyQueueNull()
{
	size_t size = 10;
	Queue* queue;
	int isEmpty = 0;
	queue = QueueCreate(size);
	isEmpty = QueueIsEmpty(NULL);
	if(isEmpty)
	{
		printf("PASSED: TestQueueIsEmptyQueueNull\n");
	}
	else
	{
		printf("FAILED: TestQueueIsEmptyQueueNull\n");
	}
	QueueDestroy(queue);
	return;
}

void TestQueueIsEmptyQueueEmpty()
{
	size_t size = 10;
	Queue* queue;
	int isEmpty = 0;
	queue = QueueCreate(size);
	isEmpty = QueueIsEmpty(queue);
	if(isEmpty)
	{
		printf("PASSED: TestQueueIsEmptyQueueEmpty\n");
	}
	else
	{
		printf("FAILED: TestQueueIsEmptyQueueEmpty\n");
	}
	QueueDestroy(queue);
	return;
}

void TestQueueIsEmptyQueueEmptyInsertRemove()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int isEmpty = 0;
	int val = 0;
	queue = QueueCreate(size);
	QueueInsert(queue, item);
	QueueRemove(queue, &val);
	isEmpty = QueueIsEmpty(queue);
	if(isEmpty)
	{
		printf("PASSED: TestQueueIsEmptyQueueEmptyInsertRemove\n");
	}
	else
	{
		printf("FAILED: TestQueueIsEmptyQueueEmptyInsertRemove\n");
	}
	QueueDestroy(queue);
	return;
}

void TestQueueIsEmptyQueueFull()
{
	size_t size = 10;
	Queue* queue;
	int item = 10;
	int index = 0;
	int isEmpty = 0;
	queue = QueueCreate(size);
	for(index = 0; index < size; ++index)
	{
		QueueInsert(queue, item);
	}
	isEmpty = QueueIsEmpty(queue);
	if(isEmpty)
	{
		printf("FAILED: TestQueueIsEmptyQueueFull\n");
	}
	else
	{
		printf("PASSED: TestQueueIsEmptyQueueFull\n");
	}
	QueueDestroy(queue);
	return;
}

void PrintQueueResults()
{
	size_t size = 10;
	Queue* queue;
	int index = 0;
	queue = QueueCreate(size);
	printf("\nFill queue then print\n");
	for(index = 0; index < size; ++index)
	{
		QueueInsert(queue, index);
	}
	QueuePrint(queue);
	printf("Remove two items then print\n");
	QueueRemove(queue, NULL);
	QueueRemove(queue, NULL);
	QueuePrint(queue);
}

int main()
{
	
	/*
	QueueCreate tests
	*/
	TestQueueCreateSizeNotZero();
	TestQueueCreateSizeZero();
	/*TestCreateMultiple*/
	/*
	QueueInsert tests
	*/
	TestQueueInsertQueueNull();
	TestQueueInsertQueueEmpty();
	TestQueueInsertQueueFull();
	/*
	QueueRemove tests
	*/
	TestQueueRemoveQueueNull();
	TestQueueRemoveItemNull();
	TestQueueRemoveInitialQueueEmpty();
	TestQueueRemoveQueueEmpty();
	TestQueueRemoveQueueFull();
	TestQueueRemoveValCorrect();
	/*
	QueueIsEmpty tests
	*/
	TestQueueIsEmptyQueueNull();
	TestQueueIsEmptyQueueEmpty();
	TestQueueIsEmptyQueueEmptyInsertRemove();
	TestQueueIsEmptyQueueFull();
	/*
	Print queue
	*/
	PrintQueueResults();
	return 0;
}
