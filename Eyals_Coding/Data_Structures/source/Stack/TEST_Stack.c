#include "../../inc/Stack.h"
/*#include "../../inc/Vector.h"*/
#include "../../inc/ADTErr.h"
#include "../../inc/mu_test.h"
#include <stdlib.h>
#include <stdio.h>

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}


/**********************************/

UNIT(StackCreate_0_Capacity)
	Stack* stack;
	size_t initCapacity = 0;
	size_t blockSize = 10;
	stack = StackCreate(initCapacity, blockSize);
    ASSERT_THAT(!stack);
    StackDestroy(stack, NULL);
END_UNIT

UNIT(StackCreate_10_Capacity)
	Stack* stack;
	size_t initCapacity = 10;
	size_t blockSize = 10;
	stack = StackCreate(initCapacity, blockSize);
    ASSERT_THAT(stack);
    StackDestroy(stack, NULL);
END_UNIT

UNIT(StackPush_EmptyStack)
	Stack* stack;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t initCapacity = 10;
	size_t blockSize = 10;
	int* element = intArr + 9;
	stack = StackCreate(initCapacity, blockSize);
	ASSERT_THAT(StackIsEmpty(stack));
	StackPush(stack, (void*)element);
	ASSERT_THAT(!StackIsEmpty(stack));
	StackPop(stack, (void**)&element);
	ASSERT_THAT(StackIsEmpty(stack));
	ASSERT_THAT(9 == *element);
    StackDestroy(stack, NULL);
END_UNIT

UNIT(StackPush_NonEmptyStack)
	Stack* stack;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t initCapacity = 10;
	size_t blockSize = 10;
	int* element = intArr + 9;
	stack = StackCreate(initCapacity, blockSize);
	ASSERT_THAT(StackIsEmpty(stack));
	StackPush(stack, (void*)element);
	element = intArr + 8;
	StackPush(stack, (void*)element);
	StackPop(stack, (void**)&element);
	ASSERT_THAT(8 == *element);
	StackPop(stack, (void**)&element);
	ASSERT_THAT(9 == *element);
	StackPop(stack, (void**)&element);
	ASSERT_THAT(NULL == element);
    StackDestroy(stack, NULL);
END_UNIT

UNIT(StackPush_FullStack)
	Stack* stack;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t initCapacity = 2;
	size_t blockSize = 0;
	int* element = intArr + 9;
	stack = StackCreate(initCapacity, blockSize);
	ASSERT_THAT(StackIsEmpty(stack));
	StackPush(stack, (void*)element);
	element = intArr + 8;
	StackPush(stack, (void*)element);
	element = intArr + 7;
	StackPush(stack, (void*)element);
	StackPop(stack, (void**)&element);
	ASSERT_THAT(8 == *element);
	StackPop(stack, (void**)&element);
	ASSERT_THAT(9 == *element);
	StackPop(stack, (void**)&element);
	ASSERT_THAT(NULL == element);
    StackDestroy(stack, NULL);
END_UNIT

UNIT(StackTop_test)
	Stack* stack;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t initCapacity = 2;
	size_t blockSize = 0;
	int* element = intArr + 9;
	stack = StackCreate(initCapacity, blockSize);
	ASSERT_THAT(StackIsEmpty(stack));
	StackPush(stack, (void*)element);
	element = intArr + 8;
	StackPush(stack, (void*)element);
	element = intArr + 7;
	StackPush(stack, (void*)element);
	StackTop(stack, (void**)&element);
	ASSERT_THAT(8 == *element);
    StackDestroy(stack, NULL);
END_UNIT


TEST_SUITE(HEAP TESTS)
	
	TEST(StackCreate_0_Capacity)
	
	TEST(StackCreate_10_Capacity)
	
	TEST(StackPush_EmptyStack)
	
	TEST(StackPush_NonEmptyStack)
	
	TEST(StackPush_FullStack)
	
	TEST(StackTop_test)
	
END_SUITE














