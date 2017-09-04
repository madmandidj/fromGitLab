#include "ProtectedQueue.h"
#include "../../inc/mu_test.h"
#include <stdio.h>
#include <time.h>
#include <assert.h>


/*****
Create int array
*****/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    return arr;
}


/*****
Create random int array
*****/
/*
static int* InitRandIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = rand() % 100;
    }
    return arr;
}
*/




UNIT(Test_ProtectedQueueCreateAndDestroy)
	
	ProQueue* q = NULL;
	size_t qSize = 10;
	
	q = ProQueueCreate(qSize);
	ASSERT_THAT(NULL != q);
	ProQueueDestroy(q);

END_UNIT



UNIT(Test_ProtectedQueueInsert)
	ProQueue* q = NULL;
	size_t qSize = 10;
	int* arr;
	size_t numOfInts = 20;
	
	arr = InitIntArr(numOfInts);

	q = ProQueueCreate(qSize);
	ProQueueInsert(q, arr);
	ProQueueInsert(q, arr + 1);
	ProQueueInsert(q, arr + 2);
	ProQueueInsert(q, arr + 3);	
	ASSERT_THAT(!ProQueueIsEmpty(q));
	ProQueuePrint(q);
	ProQueueDestroy(q);
	
	free(arr);

END_UNIT




UNIT(Test_ProtectedQueueRemove)
	ProQueue* q = NULL;
	size_t qSize = 10;
	int* arr;
	size_t numOfInts = 20;
	
	arr = InitIntArr(numOfInts);

	q = ProQueueCreate(qSize);
	ProQueueInsert(q, arr);
	ProQueueInsert(q, arr + 1);
	ProQueueInsert(q, arr + 2);
	ProQueueInsert(q, arr + 3);	
	ProQueueRemove(q, NULL);
	ProQueueRemove(q, NULL);
	ProQueueRemove(q, NULL);
	ProQueueRemove(q, NULL);
	ASSERT_THAT(ProQueueIsEmpty(q));
	ProQueueDestroy(q);
	
	free(arr);

END_UNIT




TEST_SUITE(Protected Queue)

	TEST(Test_ProtectedQueueCreateAndDestroy)
	TEST(Test_ProtectedQueueInsert)
	TEST(Test_ProtectedQueueRemove)
	
END_SUITE






