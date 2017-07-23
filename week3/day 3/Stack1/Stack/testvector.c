#include <stdio.h>
#include "vector.h"

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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestAddVectorNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestAddVectorNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestAddVectorNull\n");	
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestAddVectorNull ERR_OK\n");	
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestAddVectorInitialSizeZero ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestAddVectorInitialSizeZero ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestAddVectorInitialSizeZero ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestAddVectorInitialSizeZero\n");	
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestAddItemEnoughCapacity ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestAddItemEnoughCapacity ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestAddItemEnoughCapacity ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestAddItemEnoughCapacity\n");	
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestAddItemNotEnoughCapacity ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestAddItemNotEnoughCapacity ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestAddItemNotEnoughCapacity ERR_NOT_INITIALIZED\n");	
	}
	else if (err == ERR_OK)
	{
		printf("PASSED: TestAddItemNotEnoughCapacity\n");	
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestItemsNumVectorNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestItemsNumVectorNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestItemsNumVectorNull\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestItemsNumVectorNull ERR_OK\n");		
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestItemsNumValNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestItemsNumValNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestItemsNumValNull\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestItemsNumValNull ERR_OK\n");		
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestItemsNumCorrectSizeZero ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestItemsNumCorrectSizeZero ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestItemsNumCorrectSizeZero ERR_NOT_INITIALIZED\n");
	}
	else if (err == ERR_OK)
	{	
		printf("PASSED: TestItemsNumCorrectSizeZero\n");	
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
	VectorDestroy(vec);
	return;
}

void TestItemsNumCorrect()
{
	Vector* vec;
	ADTErr err;
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
	err = VectorItemsNum(vec, &itemsNum);
	if (7 == itemsNum)
	{
		printf("PASSED: TestItemsNumCorrect\n");
	}
	else if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestItemsNumCorrect ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestItemsNumCorrect ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("FAILED: TestItemsNumCorrect ERR_NOT_INITIALIZED\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestItemsNumCorrect ERR_OK\n");		
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestGetVectorNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestGetVectorNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestGetVectorNull\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestGetVectorNull ERR_OK\n");		
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
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
	if (err == ERR_OVERFLOW)
	{
		printf("FAILED: TestGetItemNull ERR_OVERFLOW\n");	
	}
	else if (err == ERR_REALLOCATION_FAILED)
	{
		printf("FAILED: TestGetItemNull ERR_REALLOCATION_FAILED\n");	
	}
	else if (err == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: TestGetItemNull\n");
	}
	else if (err == ERR_OK)
	{
		printf("FAILED: TestGetItemNull ERR_OK\n");		
	}
	else 
	{
		printf("ERROR UNDEFINED\n");
	}
	VectorDestroy(vec);
	return;
}

void TestGetIndexGreaterThanSize()
{
	
}

void TestGetIndexSmallerThanZero()
{

}

void TestGetCorrectItemValue()
{

}

void TestSetVectorNull()
{

}

void TestSetArrayNull()
{

}

void TestSetIndexGreaterThanSize()
{

}

void TestSetIndexSmallerThanZero()
{

}

void TestDeleteVectorNull()
{

}
void TestDeleteArrayNull()
{

}

void TestDeleteItemNull()
{

}

void TestDeleteZeroItems()
{

}

void TestDeleteCorrectItemValue()
{

}

void TestDeleteItemWithoutRealloc()
{

}

void TestDeleteItemWithRealloc()
{

}

void TestDeleteItemRepeated()
{

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
	TestItemsNumVectorNull();
	TestItemsNumValNull();
	TestItemsNumCorrectSizeZero();
	TestItemsNumCorrect();
	TestGetVectorNull();
	TestGetItemNull();
	printf("\n");
	return 0;
}
