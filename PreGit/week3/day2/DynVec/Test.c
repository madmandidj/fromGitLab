#include <stdio.h>
#include <stdlib.h>
#include "DynVec.h"


void TestVectorCreate()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	if (NULL == vec)
	{
		printf("FAILED: Vector create\n");
	}
	else
	{
		printf("PASSED: Vector create\n");
	}
	VectorDestroy(vec);
	return;
}

void TestVectorAdd()
{
	Vector* vec;
	size_t initSize = 2;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	int i;
	int size;
	for (i = 0; i < initSize+10; ++i)
	{
		result = VectorAdd(vec, i);
	}
	if (result == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: Vector add\n");
	}
	if (result == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: Vector add\n");
	}
	if (result == ERR_OK)
	{
		printf("PASSED: Vector add ERR_OK\n");
	}
	VectorDestroy(vec);
	return;
}

void TestVectorDelete()
{
	Vector* vec;
	size_t initSize = 6;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	int i;
	int num;
	int size;
	for (i = 0; i < initSize; ++i)
	{
		result = VectorAdd(vec, i);
		//printf("here\n");
	}
	for (i = 0; i < initSize; ++i)
	{
		result = VectorDelete(vec, &num);
		if (result == ERR_NOT_INITIALIZED)
		{
			printf("FAILED: Vector remove ERR_NOT_INITIALIZED\n");
		}
		if (result == ERR_REALLOCATION_FAILED)
		{
			printf("FAILED: Vector remove ERR_REALLOCATION_FAILED\n");
		}
		if (result == ERR_UNDERFLOW)
		{
			printf("FAILED: Vector remove ERR_UNDERFLOW\n");
		}
		if (result == ERR_GENERAL)
		{
			printf("FAILED: Vector remove ERR_GENERAL\n");
		}
		if (result == ERR_OK)
		{
			printf("PASSED: Vector remove ERR_OK\n");
		}
	}
	VectorDestroy(vec);
	return;
}

void TestVectorGet()
{
	Vector* vec;
	size_t initSize = 2;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	int i;
	int size;
	for (i = 0; i < initSize+10; ++i)
	{
		result = VectorAdd(vec, i);
	}
		result = VectorGet(vec, 20, &i);
	if (result == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: Vector get ERR_NOT_INITIALIZED\n");
	}
	if (result == ERR_WRONG_INDEX)
	{
		printf("FAILED: Vector get ERR_WRONG_INDEX\n");
	}
	if (result == ERR_OK)
	{
		printf("PASSED: Vector get ERR_OK\n");
	}
	VectorDestroy(vec);
	return;
}

void TestVectorSet()
{
	Vector* vec;
	size_t initSize = 2;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	int i;
	int size;
	for (i = 0; i < initSize+10; ++i)
	{
		result = VectorAdd(vec, i);
	}
		result = VectorSet(vec, 6, 6);
	if (result == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: Vector set ERR_NOT_INITIALIZED\n");
	}
	if (result == ERR_WRONG_INDEX)
	{
		printf("FAILED: Vector set ERR_WRONG_INDEX\n");
	}
	if (result == ERR_OK)
	{
		printf("PASSED: Vector set ERR_OK\n");
	}
	VectorDestroy(vec);
	return;
}

void TestVectorItemsNum()
{
	Vector* vec;
	size_t initSize = 2;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	int i;
	int size;
	for (i = 0; i < initSize+10; ++i)
	{
		result = VectorAdd(vec, i);
	}
		result = VectorItemsNum(vec, &i);
	if (result == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: Vector items num ERR_NOT_INITIALIZED\n");
	}
	if (result == ERR_OK)
	{
		printf("PASSED: Vector items num ERR_OK\n");
	}
	VectorDestroy(vec);
	return;
}

void TestVectorPrint()
{
	Vector* vec;
	size_t initSize = 2;
	size_t extBlockSize = 2;
	ADTErr result;
	vec = VectorCreate(initSize, extBlockSize);
	int i;
	int size;
	for (i = 0; i < initSize+10; ++i)
	{
		result = VectorAdd(vec, i);
	}
	VectorPrint(vec);
	VectorDestroy(vec);
	return;
}


int main()
{
	TestVectorCreate();
	TestVectorAdd();
	TestVectorDelete();
	TestVectorGet();
	TestVectorSet();
	TestVectorItemsNum();
	TestVectorPrint();
	return 0;
}
