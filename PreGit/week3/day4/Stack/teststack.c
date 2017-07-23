#include <stdio.h>
#include "stack.h"

/**********
StackCreate tests
***********/

void TestStackCreateAlloc()
{
	size_t size = 10;
	size_t blockSize = 2;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateAlloc ERR_ALLOCATION_FAILED\n");
	}
	else
	{
		printf("PASSED: TestStackCreateAlloc\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackCreateParamatersAreZero()
{
	size_t size = 0;
	size_t blockSize = 0;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("PASSED: TestStackCreateParamatersAreZero\n");
	}
	else
	{
		printf("FAILED: TestStackCreateParamatersAreZero ERR_ALLOCATION_FAILED\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackCreateBlockSizeZero()
{
	size_t size = 10;
	size_t blockSize = 0;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateBlockSizeZero ERR_ALLOCATION_FAILED\n");
	}
	else
	{
		printf("PASSED: TestStackCreateBlockSizeZero\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackCreateInitialSizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	if (NULL == myStack)
	{
		printf("FAILED: TestStackCreateBlockSizeZero ERR_ALLOCATION_FAILED\n");
	}
	else
	{
		printf("PASSED: TestStackCreateBlockSizeZero\n");
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
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	err = StackPush(NULL, item);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPushNotNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushNotNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackPushNotNull\n");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPushNotNull ERR_OK\n");	
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	err = StackPush(myStack, item);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPushInitialSizeZero ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushInitialSizeZero ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPushInitialSizeZero ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPushInitialSizeZero\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
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
		printf("FAILED: TestStackPushEnoughCapacity ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushEnoughCapacity ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPushEnoughCapacity ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPushEnoughCapacity\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
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
		printf("FAILED: TestStackPushNotEnoughCapacity ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPushNotEnoughCapacity ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPushNotEnoughCapacity ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPushNotEnoughCapacity\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
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
		printf("FAILED: TestStackTopNotNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopNotNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackTopNotNull\n");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopNotNull ERR_OK\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
	}
	StackDestroy(myStack);
	return;	
}

void TestStackTopItemNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	ADTErr err;
	Stack* myStack;
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
		printf("FAILED: TestStackTopItemNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopItemNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackTopItemNull\n");	
		
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopItemNull ERR_OK\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackTopSizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	int topval=0;
	ADTErr err;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	err = StackTop(myStack, &topval);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackTopSizeZero ERR_OVERFLOW\n");	
	}
	if (err == ERR_UNDERFLOW)
	{
		printf("PASSED: TestStackTopSizeZero\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopSizeZero ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackTopSizeZero ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopSizeZero ERR_OK\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size+1; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackTop(myStack, &topval);
	if (topval == 10)
	{
		printf("PASSED: TestStackTopItemValueAfterRealloc\n");
	}
	else if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackTopItemValueAfterRealloc ERR_OK\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(NULL, &topval);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackPopNull\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPopNull ERR_OK\n");		
	}
	else
	{
		printf("ERROR UNDEFINED\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackPopItemNull()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	ADTErr err;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(myStack, NULL);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopItemNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopItemNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestStackPopItemNull\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPopItemNull ERR_OK\n");		
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	err = StackPop(myStack, &popval);
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestStackPopSizeZero ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopSizeZero ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPopSizeZero ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestStackPopSizeZero ERR_OK\n");	
	}
	else if (err == ERR_UNDERFLOW)
	{
		printf("PASSED: TestStackPopSizeZero\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
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
		printf("FAILED: TestStackPopThenRealloc ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestStackPopThenRealloc ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestStackPopThenRealloc ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestStackPopThenRealloc\n");	
	}
	else
	{
		printf("ERROR UNDEFINED\n");
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
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size+4; ++index)
	{
		StackPush(myStack, index);
	}
	StackPop(myStack, &popval);
	if (popval == 13)
	{
		printf("PASSED: TestStackPopCorrectValue\n");
	}
	else
	{
		printf("FAILED: TestStackPopCorrectValue is not correct value\n");
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
	int isEmpty;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	isEmpty = StackIsEmpty(NULL);
	if(0 != isEmpty)
	{
		printf("PASSED: TestStackIsEmptyNull\n");
	}
	else 
	{
		printf("FAILED: TestStackIsEmptyNull\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackIsEmptySizeZero()
{
	size_t size = 0;
	size_t blockSize = 2;
	int isEmpty;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	isEmpty = StackIsEmpty(myStack);
	if (isEmpty == 1)
	{
		printf("PASSED: TestStackIsEmptySizeZero\n");
	}
	else
	{
		printf("FAILED: TestStackIsEmptySizeZero\n");
	}
	StackDestroy(myStack);
	return;
}

void TestStackIsEmptySizeNotZero()
{
	size_t size = 10;
	size_t blockSize = 2;
	int index;
	int isEmpty;
	Stack* myStack;
	myStack = StackCreate(size, blockSize);
	for(index = 0; index < size; ++index)
	{
		StackPush(myStack, index);
	}
	isEmpty = StackIsEmpty(myStack);
	if (isEmpty == 0)
	{
		printf("PASSED: TestStackIsEmptySizeNotZero\n");
	}
	else
	{
		printf("FAILED: TestStackIsEmptySizeNotZero\n");
	}
	StackDestroy(myStack);
	return;
}

int main()
{
	TestStackCreateAlloc();
	TestStackCreateParamatersAreZero();
	TestStackCreateBlockSizeZero();
	TestStackCreateInitialSizeZero();
	TestStackPushNull();
	TestStackPushInitialSizeZero();
	TestStackPushEnoughCapacity();
	TestStackPushNotEnoughCapacity();
	TestStackTopNotNull();
	TestStackTopItemNull();
	TestStackTopSizeZero();
	TestStackTopItemValueAfterRealloc();
	TestStackPopNull();
	TestStackPopItemNull();
	TestStackPopSizeZero();
	TestStackPopThenRealloc();
	TestStackPopCorrectValue();
	TestStackIsEmptyNull();
	TestStackIsEmptySizeZero();
	TestStackIsEmptySizeNotZero();
	return 0;
}
