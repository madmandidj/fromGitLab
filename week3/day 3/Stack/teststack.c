#include <stdio.h>
#include "stack.h"

/**********
StackCreate tests
***********/

void TestStackCreateAlloc()
{
	size_t size = 10;
	size_t blockSize = 2;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateAlloc ERR_ALLOCATION_FAILED");
	}
	else
	{
		printf("PASSED: TestStackCreateAlloc");
	}
	StackDestroy(myStack);
	return;
}

void TestStackCreateParamatersAreZero()
{
	size_t size = 0;
	size_t blockSize = 0;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateParamatersAreZero ERR_ALLOCATION_FAILED");
	}
	else
	{
		printf("PASSED: TestStackCreateParamatersAreZero");
	}
	StackDestroy(myStack);
	return;
}

void TestStackCreateBlockSizeZero()
{
	size_t size = 10;
	size_t blockSize = 0;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateBlockSizeZero ERR_ALLOCATION_FAILED");
	}
	else
	{
		printf("PASSED: TestStackCreateBlockSizeZero");
	}
	StackDestroy(myStack);
	return;
}

void TestStackCreateInitialSizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateBlockSizeZero ERR_ALLOCATION_FAILED");
	}
	else
	{
		printf("PASSED: TestStackCreateBlockSizeZero");
	}
	StackDestroy(myStack);
	return;
}

/***********
StackPush tests
************/

void TestStackPushNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int item = 64;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	err = StackPush(NULL, item);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPushNotNull ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushNotNull ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackPushNotNull");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPushNotNull ERR_OK");	
	}
	else 
	{
		(printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;	
}

void TestStackPushInitialSizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	int item = 64;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	err = StackPush(myStack, item);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPushInitialSizeZero ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushInitialSizeZero ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPushInitialSizeZero ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPushInitialSizeZero");	
	}
	else
	{
		(printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;	
}

void TestStackPushEnoughCapacity()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		err = StackPush(myStack, index);
		if (err != ERR_OK)
		{
			break;
		}
	}
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPushEnoughCapacity ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushEnoughCapacity ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPushEnoughCapacity ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPushEnoughCapacity");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;	
}

void TestStackPushNotEnoughCapacity()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size+4; ++index)
	{
		err = StackPush(myStack, index);
		if (err != ERR_OK)
		{
			break;
		}
	}
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPushNotEnoughCapacity ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushNotEnoughCapacity ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPushNotEnoughCapacity ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPushNotEnoughCapacity");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;		
}

/*********
StackTop tests
**********/

void TestStackTopNotNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int topval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
		err = StackTop(NULL, &topval);
		if (err != ERR_OK)
		{
			break;
		}
	}
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackTopNotNull ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopNotNull ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackTopNotNull");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopNotNull ERR_OK");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;	
}

void TestStackTopItemNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int topval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
		err = StackTop(myStack, NULL);
		if (err != ERR_OK)
		{
			break;
		}
	}
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackTopNotNull ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopNotNull ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackTopNotNull");	
		
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopNotNull ERR_OK");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackTopSizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	int index;
	int topval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	err = StackTop(myStack, &topval);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackTopSizeZero ERR_OVERFLOW");	
	}
	if (err == ERR_UNDERFLOW)
	{
		printf("FAILED: TestStackTopSizeZero ERR_UNDERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopSizeZero ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackTopSizeZero ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackTopSizeZero");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackTopItemValueAfterRealloc()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int topval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size+1; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackTop(myStack, &topval);
	if (topval == 10)
	{
		printf("PASSED: TestStackTopItemValueAfterRealloc");
	}
	else if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_OK");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

/*********
StackPop tests
**********/

void TestStackPopNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int topval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(NULL, &topval);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopNull ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopNull ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackPopNull");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPopNull ERR_OK");		
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackPopItemNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int topval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(myStack, NULL);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopItemNull ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopItemNull ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackPopItemNull");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPopItemNull ERR_OK");		
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackPopSizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	int index;
	int popval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(myStack, &popval);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopSizeZero ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopSizeZero ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPopSizeZero ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPopSizeZero");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackPopThenRealloc()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int popval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size+4; ++index)
	{
		StackPush(myStack, index);
	}
	for(index = 0; index < 6; ++index)
	{
		err = StackPop(myStack, &popval);
	}
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopThenRealloc ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopThenRealloc ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPopThenRealloc ERR_NOT_INITIALIZED");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPopThenRealloc");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackPopCorrectValue()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int popval;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size+4; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(myStack, &popval);
	if (popval == 13)
	{
		printf("PASSED: TestStackPopCorrectValue");
	}
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopCorrectValue ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopCorrectValue ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPopCorrectValue ERR_NOT_INITIALIZED");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

/*********
StackIsEmpty tests
**********/

void TestStackIsEmptyNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int popval;
	int isEmpty;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	isEmpty = StackIsEmpty(NULL);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackIsEmptyNull ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackIsEmptyNull ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackIsEmptyNull");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackIsEmptyNull ERR_OK");		
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackIsEmptySizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	int index;
	int popval;
	int isEmpty;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	isEmpty = StackIsEmpty(myStack);
	if (isEmpty == 1)
	{
		printf("PASSED: TestStackIsEmptySizeZero");
	}
	else if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackIsEmptySizeZero ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackIsEmptySizeZero ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackIsEmptySizeZero ERR_NOT_INITIALIZED");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

void TestStackIsEmptySizeNotZero()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int popval;
	int isEmpty;
	ADTErr err;
	stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	isEmpty = StackIsEmpty(myStack);
	if (isEmpty == 0)
	{
		printf("PASSED: TestStackIsEmptySizeNotZero");
	}
	else if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackIsEmptySizeNotZero ERR_OVERFLOW");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackIsEmptySizeNotZero ERR_REALLOCATION_FAILED");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackIsEmptySizeNotZero ERR_NOT_INITIALIZED");	
	}
	else
	{
		printf("ERROR UNDEFINED");
	}
	StackDestroy(myStack);
	return;
}

int main()
{
	
	return 0;
}
