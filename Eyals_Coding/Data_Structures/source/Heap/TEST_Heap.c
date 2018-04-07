#include "../../inc/Vector.h"
#include "../../inc/VectorFunctions.h"
#include "../../inc/Heap.h"
#include "../../inc/HeapFunctions.h"
#include "../../../Sort_Algorithms/Sort_Algorithms.h"
#include "../../inc/mu_test.h"
#include "../../inc/ADTErr.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int IsIntLeftBigger(int* _leftInt, int* _rightInt)
{
	return *_leftInt > *_rightInt;
}

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}

UNIT(Heap_Build_NULLVec)
	Heap* heap;
	heap = HeapBuild(NULL, (IsLeftBigger)IsIntLeftBigger);
    ASSERT_THAT(!heap);
END_UNIT

UNIT(Heap_Build_EmptyVec)
	Vector* vector;
	Heap* heap;
	size_t numOfInts = 10;
	size_t blockSize = 10;
	
	vector = VectorCreate(numOfInts, blockSize);
	heap = HeapBuild(vector, (IsLeftBigger)IsIntLeftBigger);
    ASSERT_THAT(!heap);
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(Heap_Build_1_item)
	int* intArr;
	Vector* vector;
	Heap* heap;
	size_t numOfInts = 1;
	int maxVal = 100;
	size_t blockSize = 10;

	srand ((unsigned int)time(NULL));
	vector = CreateRandomIntVector(numOfInts, maxVal, blockSize, &intArr); 
	heap = HeapBuild(vector, (IsLeftBigger)IsIntLeftBigger);
    ASSERT_THAT(heap);
	HeapDestroy(heap, NULL);
	DestroyRandomIntVector(vector, intArr);
END_UNIT

UNIT(Heap_Build_10_item)
	int* intArr;
	Vector* vector;
	Heap* heap;
	size_t numOfInts = 10;
	int maxVal = 100;
	size_t blockSize = 10;

	srand ((unsigned int)time(NULL));
	vector = CreateRandomIntVector(numOfInts, maxVal, blockSize, &intArr); 
	heap = HeapBuild(vector, (IsLeftBigger)IsIntLeftBigger);
    ASSERT_THAT(heap);
	HeapDestroy(heap, NULL);
	DestroyRandomIntVector(vector, intArr);
END_UNIT

UNIT(Heap_Build_100_item)
	int* intArr;
	Vector* vector;
	Heap* heap;
	size_t numOfInts = 100;
	int maxVal = 100;
	size_t blockSize = 10;

	srand ((unsigned int)time(NULL));
	vector = CreateRandomIntVector(numOfInts, maxVal, blockSize, &intArr); 
	heap = HeapBuild(vector, (IsLeftBigger)IsIntLeftBigger);
    ASSERT_THAT(heap);
	HeapDestroy(heap, NULL);
	DestroyRandomIntVector(vector, intArr);
END_UNIT

UNIT(Heap_Build_100_item_Is_Sorted_Ascending)
	int* intArr;
	Vector* vector;
	Vector* sortedVector;
	Heap* heap;
	size_t numOfInts = 100;
	int maxVal = 100;
	size_t blockSize = 10;

	srand ((unsigned int)time(NULL));
	vector = CreateRandomIntVector(numOfInts, maxVal, blockSize, &intArr);
	sortedVector = CopyCreateVector(vector);
	MergeSort(sortedVector); 
	heap = HeapBuild(vector, (IsLeftBigger)IsIntLeftBigger);
    ASSERT_THAT(IsHeapSortedAscending(heap, sortedVector));
	HeapDestroy(heap, NULL);
	DestroyRandomIntVector(vector, intArr);
	VectorDestroy(sortedVector, NULL);
END_UNIT

TEST_SUITE(HEAP TESTS)
	
	TEST(Heap_Build_NULLVec)
	TEST(Heap_Build_EmptyVec)
	TEST(Heap_Build_1_item)
	TEST(Heap_Build_10_item)
	TEST(Heap_Build_100_item)
	TEST(Heap_Build_100_item_Is_Sorted_Ascending)
END_SUITE
