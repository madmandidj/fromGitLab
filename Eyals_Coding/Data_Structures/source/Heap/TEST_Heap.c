#include <stdio.h>
#include "../../inc/Vector.h"
#include "../../inc/Heap.h"
#include "../../inc/mu_test.h"
#include "../../inc/ADTErr.h"

int IsIntLeftBigger(int* _leftInt, int* _rightInt)
{
	return *_leftInt > *_rightInt;
}

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}

UNIT(Heap_Create)
	int intArr[] = {70, 17, 20, 80, 30, 25, 100};
	int another1 = 45;
	int another2 = 800;
	int another3 = 16;
	Vector* vector;
	Heap* heap;
	size_t index;
	int* element;
	
	vector = VectorCreate(10, 2);
	for (index = 0; index < 7; ++index)
	{
		VectorAppend(vector, intArr + index);
	}
	heap = HeapBuild(vector, (IsLeftBigger)IsIntLeftBigger);
	HeapPrint(heap, (ElementFunc)PrintInt);
	printf("****\n");
	HeapExtractMax(heap, (void**)&element);
	HeapPrint(heap, (ElementFunc)PrintInt);
	printf("****\n");
	HeapExtractMax(heap, (void**)&element);
	HeapPrint(heap, (ElementFunc)PrintInt);
	printf("****\n");
	HeapInsert(heap, &another1);
	HeapPrint(heap, (ElementFunc)PrintInt);
	printf("****\n");
	HeapInsert(heap, &another2);
	HeapPrint(heap, (ElementFunc)PrintInt);
	printf("****\n");
	HeapInsert(heap, &another3);	
	HeapPrint(heap, (ElementFunc)PrintInt);
	
	HeapDestroy(heap);
    ASSERT_THAT(1);
END_UNIT



TEST_SUITE(HEAP TESTS)
	TEST(Heap_Create)
END_SUITE
