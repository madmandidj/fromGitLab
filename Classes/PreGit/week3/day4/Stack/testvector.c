#include <stdio.h>
#include "vector.h"
#include <string.h>

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
        else 
        {
            strcpy(errString, "Undefined error");
        }
        printf("FAILED: %s %s", _testName, errString);
    }
    return;
}

void TestCreateParamatersAreZero()
{
	Vector* vec;
	size_t initSize = 0;
	size_t extBlockSize = 0;
	vec = VectorCreate(initSize, extBlockSize);
	if (NULL == vec)
	{
		printf("PASSED: TestCreateParamatersAreZero\n");
	}
	else
	{
		printf("FAILED: TestCreateParamatersAreZero\n");
	}
	VectorDestroy(vec);
	return;
}

void TestCreateBlockSizeZero()
{
	Vector* vec;
	size_t initSize = 10;
	size_t extBlockSize = 0;
	vec = VectorCreate(initSize, extBlockSize);
	if (NULL == vec)
	{
		printf("FAILED: TestCreateBlockSizeZero\n");
	}
	else
	{
		printf("PASSED: TestCreateBlockSizeZero\n");
	}
	VectorDestroy(vec);
	return;
}

void TestCreateInitialSizeZero()
{
	Vector* vec;
	size_t initSize = 0;
	size_t extBlockSize = 2;
	vec = VectorCreate(initSize, extBlockSize);
	if (NULL == vec)
	{
		printf("FAILED: TestCreateInitialSizeZero\n");
	}
	else
	{
		printf("PASSED: TestCreateInitialSizeZero\n");
	}
	VectorDestroy(vec);
	return;
}

void TestAddVectorNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 0;
	size_t extBlockSize = 0;
	int item = 64;
	vec = VectorCreate(initSize, extBlockSize);
	err = VectorAdd(NULL, item);
	PrintErrResult("TestAddVectorNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestAddVectorInitialSizeZero()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 0;
	size_t extBlockSize = 2;
	int item = 64;
	vec = VectorCreate(initSize, extBlockSize);
	err = VectorAdd(vec, item);
	PrintErrResult("TestAddVectorInitialSizeZero", err, ERR_OK);
	VectorDestroy(vec);
	return;
}

void TestAddItemEnoughCapacity()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		err = VectorAdd(vec, item);
		if (err != ERR_OK)
		{
			break;
		}
	}
	PrintErrResult("TestAddItemEnoughCapacity", err, ERR_OK);
	VectorDestroy(vec);
	return;
}

void TestAddItemNotEnoughCapacity()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		err = VectorAdd(vec, item);
		if (err != ERR_OK)
		{
			break;
		}
	}
	PrintErrResult("TestAddItemNotEnoughCapacity", err, ERR_OK);
	VectorDestroy(vec);
	return;
}

void TestItemsNumVectorNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int numOfItems;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	err = VectorItemsNum(NULL, &numOfItems);
	PrintErrResult("TestItemsNumVectorNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestItemsNumValNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	err = VectorItemsNum(vec, NULL);
	PrintErrResult("TestItemsNumValNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestItemsNumCorrectSizeZero()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 0;
	size_t extBlockSize = 2;
	int numOfItems;
	vec = VectorCreate(initSize, extBlockSize);
	err = VectorItemsNum(vec, &numOfItems);
	PrintErrResult("TestItemsNumCorrectSizeZero", err, ERR_OK);
	VectorDestroy(vec);
	return;
}

void TestItemsNumCorrect()
{
	Vector* vec;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int itemsNum;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	VectorItemsNum(vec, &itemsNum);
	if (7 == itemsNum)
	{
		printf("PASSED: TestItemsNumCorrect\n");
	}
    else
    {
        printf("PASSED: TestItemsNumCorrect number not correct\n");
    }
	VectorDestroy(vec);
	return;
}

void TestGetVectorNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int itemval;
	int indextofind = 3;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	err = VectorGet(NULL, indextofind, &itemval);
	PrintErrResult("TestGetVectorNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestGetItemNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextofind = 3;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	err = VectorGet(vec, indextofind, NULL);
	PrintErrResult("TestGetItemNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestGetIndexGreaterThanSize()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextofind = 10;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	err = VectorGet(vec, indextofind, &item);
	PrintErrResult("TestGetIndexGreaterThanSize", err, ERR_WRONG_INDEX);
	VectorDestroy(vec);
	return;
}

void TestGetIndexSmallerThanZero()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextofind = -4;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+2; ++index)
	{
		VectorAdd(vec, item);
	}
	err = VectorGet(vec, indextofind, &item);
	PrintErrResult("TestGetIndexSmallerThanZero", err, ERR_WRONG_INDEX);
	VectorDestroy(vec);
	return;
}

void TestGetCorrectItemValue()
{
	Vector* vec;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextofind = initSize-1;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	VectorGet(vec, indextofind, &item);
	if (4 == item)
	{
		printf("PASSED: TestGetCorrectItemValue\n");
	}
	else
	{
		printf("FAILED: TestGetCorrectItemValue Incorrect value\n");
	}
	VectorDestroy(vec);
	return;
}

void TestSetVectorNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextoset = initSize-1;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	err = VectorSet(NULL, indextoset, item);
	PrintErrResult("TestSetVectorNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestSetIndexGreaterThanSize()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextoset = initSize+4;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	err = VectorSet(vec, indextoset, item);
	PrintErrResult("TestSetIndexGreaterThanSize", err, ERR_WRONG_INDEX);
	VectorDestroy(vec);
	return;
}

void TestSetIndexSmallerThanZero()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	int indextoset = -4;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	err = VectorSet(vec, indextoset, item);
	PrintErrResult("TestSetIndexSmallerThanZero", err, ERR_WRONG_INDEX);
	VectorDestroy(vec);
	return;
}

void TestDeleteVectorNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int item = 64;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	err = VectorDelete(NULL, &item);
	PrintErrResult("TestDeleteVectorNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestDeleteItemNull()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	err = VectorDelete(vec, NULL);
	PrintErrResult("TestDeleteItemNull", err, ERR_NOT_INITIALIZED);
	VectorDestroy(vec);
	return;
}

void TestDeleteZeroItems()
{
	Vector* vec;
	ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int itemVal;
	vec = VectorCreate(initSize, extBlockSize);
	err = VectorDelete(vec, &itemVal);
	PrintErrResult("TestDeleteZeroItems", err, ERR_UNDERFLOW);
	VectorDestroy(vec);
	return;
}

void TestDeleteCorrectItemValue()
{
	Vector* vec;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int itemVal;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize; ++index)
	{
		VectorAdd(vec, index);
	}
	VectorDelete(vec, &itemVal);
	if (4 == itemVal)
	{
	   printf("PASSED: TestDeleteCorrectItemValue\n");	 
	}
	else
	{
	   printf("FAILED: TestDeleteCorrectItemValue not correct value\n"); 
	}
	VectorDestroy(vec);
	return;
}

void TestDeleteItemWithRealloc()
{
    Vector* vec;
    ADTErr err;
	size_t initSize = 5;
	size_t extBlockSize = 2;
	int itemVal;
	int index;
	vec = VectorCreate(initSize, extBlockSize);
	for (index = 0; index < initSize+10; ++index)
	{
		VectorAdd(vec, index);
	}
	for (index = 0; index < initSize+10; ++index)
	{
		err = VectorDelete(vec, &itemVal);
		if (ERR_OK != err)
		{
		    break;
		}
	}
	PrintErrResult("TestDeleteItemWithRealloc", err, ERR_OK);
	VectorDestroy(vec);
	return;
}

int main()
{
	printf("\n");
	TestCreateParamatersAreZero();
	TestCreateBlockSizeZero();
	TestCreateInitialSizeZero();
	TestAddVectorNull();
	TestAddVectorInitialSizeZero();
	TestAddItemEnoughCapacity();
	TestAddItemNotEnoughCapacity();
	/*
	Addnullparameters
	Addexactlysize
	*/
	TestItemsNumVectorNull();
	TestItemsNumValNull();
	TestItemsNumCorrectSizeZero();
	TestItemsNumCorrect();
	TestGetVectorNull();
	TestGetItemNull();
	TestGetIndexGreaterThanSize();
	TestGetIndexSmallerThanZero();
	TestGetCorrectItemValue();
	TestSetVectorNull();
	TestSetIndexGreaterThanSize();
	TestSetIndexSmallerThanZero();
	TestDeleteVectorNull();
	TestDeleteItemNull();
	TestDeleteZeroItems();
	TestDeleteCorrectItemValue();
	TestDeleteItemWithRealloc();
	printf("\n");
	return 0;
}
