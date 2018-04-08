#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
/*#include "../Data_Structures/inc/VectorFunctions.h"*/
#include "../GeneralFunctions/GeneralFunctions.h"
#include "../Data_Structures/inc/Heap.h"
#include "../Data_Structures/inc/HeapFunctions.h"
#include "../Data_Structures/inc/mu_test.h"
#include "../Data_Structures/inc/ADTErr.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <math.h>

#define NUM_OF_INTS 10000
#define VEC_BLOCK_SIZE 10000
#define MAX_INT_VAL 1000
#define MIN_INT_VAL 0

Vector* g_vector;
int* g_intArr;

static void PrintInt(int* _elem)
{
	printf("%d\n", *_elem);
}

static clock_t ExecuteTest(void(*TestMethod)(Vector*), Vector* _vector)
{
	clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    start_t = clock();
	TestMethod(_vector);
    end_t = clock();
    total_t = (end_t - start_t);
	return total_t;
}

/*static int IsIntLeftBigger(int* _leftInt, int* _rightInt)*/
/*{*/
/*	return *_leftInt > *_rightInt;*/
/*}*/

static clock_t ExecuteHeapSortTest(Heap*(*TestMethod)(Vector*, IsLeftBigger), Vector* _vector, Heap** _heap)
{
	clock_t start_t;
    clock_t end_t;
    clock_t total_t;
    start_t = clock();
	*_heap = TestMethod(_vector, (IsLeftBigger)IsIntLeftBigger);
    end_t = clock();
    total_t = (end_t - start_t);
	return total_t;
}



/*******************
*******************
AUX TESTS TO SETUP PROGRAM
*******************
*******************/
UNIT(Initialize_Test)
	printf("Sort Tests for %d elements\n", NUM_OF_INTS);
	printf("*********************\n");
	srand ((unsigned int)time(NULL));
	g_vector = CreateRandomIntVector(NUM_OF_INTS, MIN_INT_VAL, MAX_INT_VAL, VEC_BLOCK_SIZE, &g_intArr);
	ASSERT_THAT(1);
END_UNIT

UNIT(End_Test)
	printf("*********************\n");
	DestroyIntVector(g_vector, g_intArr);	
	ASSERT_THAT(1);
END_UNIT

/*******************
*******************
BUBBLE
*******************
*******************/

UNIT(Bubble_Average)
	Vector* vector = NULL;
	Vector* sortedVector;
	VectorPrint(vector, (ElementFunc)PrintInt);
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Bubble_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Bubble_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(BubbleSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

/*******************
*******************
SHAKE
*******************
*******************/

UNIT(Shake_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(ShakeSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Shake_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(ShakeSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Shake_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(ShakeSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT


/*******************
*******************
INSERT
*******************
*******************/

UNIT(Insert_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(InsertionSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Insert_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(InsertionSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Insert_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(InsertionSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

/*******************
*******************
SHELL
*******************
*******************/
UNIT(Shell_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(ShellSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Shell_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(ShellSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Shell_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(ShellSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

/*******************
*******************
SELECTION
*******************
*******************/
UNIT(Selection_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(SelectionSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Selection_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(SelectionSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Selection_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(SelectionSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

/*******************
*******************
QUICK
*******************
*******************/
UNIT(Quick_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(QuickSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Quick_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(QuickSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Quick_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(QuickSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT


/*******************
*******************
MERGE
*******************
*******************/
UNIT(Merge_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	QuickSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(MergeSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Merge_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	QuickSort(sortedVector); 
	QuickSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(MergeSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Merge_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	QuickSort(sortedVector); 
	QuickSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(MergeSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

/*******************
*******************
COUNTING
*******************
*******************/
UNIT(Counting_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(CountingSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Counting_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(CountingSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Counting_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(CountingSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

/*******************
*******************
RADIX
*******************
*******************/
UNIT(Radix_Average)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteTest(RadixSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Radix_Best)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(RadixSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Radix_Worst)
	Vector* vector;
	Vector* sortedVector;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector); 
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteTest(RadixSort, vector)) / CLOCKS_PER_SEC);
	ASSERT_THAT(AreVectorsEqual(vector, sortedVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT


/*******************
*******************
HEAP
*******************
*******************/
UNIT(Heap_Average)
	Vector* vector;
	Vector* sortedVector;
	Heap* heap;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	printf("*********************\n"); 
	printf("Total sort time = %f\n", ((float)ExecuteHeapSortTest(HeapBuild, vector, &heap)) / CLOCKS_PER_SEC);
	ASSERT_THAT(IsHeapSortedAscending(heap, sortedVector));
	HeapDestroy(heap, NULL);
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Heap_Best)
	Vector* vector;
	Vector* sortedVector;
	Heap* heap;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	MergeSort(vector);
	printf("Total sort time = %f\n", ((float)ExecuteHeapSortTest(HeapBuild, vector, &heap)) / CLOCKS_PER_SEC);
	ASSERT_THAT(IsHeapSortedAscending(heap, sortedVector));
	HeapDestroy(heap, NULL);
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT

UNIT(Heap_Worst)
	Vector* vector;
	Vector* sortedVector;
	Heap* heap;
	vector = CopyCreateVector(g_vector);
	sortedVector = CopyCreateVector(g_vector);
	MergeSort(sortedVector);
	MergeSort(vector);
	FlipVector(vector);
	printf("Total sort time = %f\n", ((float)ExecuteHeapSortTest(HeapBuild, vector, &heap)) / CLOCKS_PER_SEC);
	ASSERT_THAT(IsHeapSortedAscending(heap, sortedVector));
	HeapDestroy(heap, NULL);
	VectorDestroy(vector, NULL);
	VectorDestroy(sortedVector, NULL);
END_UNIT




/*******************
*******************
MAIN SUITE
*******************
*******************/
TEST_SUITE(SORT ALGORITHM TESTS)

	TEST(Initialize_Test)
	
	TEST(Bubble_Average)
	TEST(Bubble_Best)
	TEST(Bubble_Worst)
	
	TEST(Shake_Average)
	TEST(Shake_Best)
	TEST(Shake_Worst)
	
	TEST(Insert_Average)
	TEST(Insert_Best)
	TEST(Insert_Worst)
	
	TEST(Shell_Average)
	TEST(Shell_Best)
	TEST(Shell_Worst)
	
	TEST(Selection_Average)
	TEST(Selection_Best)
	TEST(Selection_Worst)
	
	TEST(Quick_Average)
	TEST(Quick_Best)
	TEST(Quick_Worst)
	
	TEST(Merge_Average)
	TEST(Merge_Best)
	TEST(Merge_Worst)
	
	TEST(Counting_Average)
	TEST(Counting_Best)
	TEST(Counting_Worst)
	
	TEST(Radix_Average)
	TEST(Radix_Best)
	TEST(Radix_Worst)
	
	TEST(Heap_Average)
	TEST(Heap_Best)
	TEST(Heap_Worst)
	
	TEST(End_Test)

END_SUITE





