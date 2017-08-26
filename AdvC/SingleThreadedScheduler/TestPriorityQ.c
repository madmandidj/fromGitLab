#include "Task.h"
#include "PriorityQ.h"
#include "../../inc/mu_test.h"
#include <stdio.h>
#include <time.h>


int DummyTaskFunc()
{
	return 1;
} 



UNIT(TestPQCreateReturnVector)

	PQ* pq;
	Vector* vec;
	Task* task1;
	Task* task2;
	size_t initialCapacity = 10;
    size_t blockSize = 2;
	
	task1 = TaskCreate(DummyTaskFunc, NULL, 100, CLOCK_REALTIME);
	task2 = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	
    vec = VecCreate(initialCapacity, blockSize);
    VecAppend(vec, task1);
    VecAppend(vec, task2);
	pq = PQBuild(vec, (LessThanComparator)TaskCompare);
	ASSERT_THAT(pq);
	vec = PQDestroy(&pq);
	ASSERT_THAT(vec);
	VecDestroy(&vec, (ElementDestroy)TaskDestroy);
	
END_UNIT


UNIT(TestPQOneInsertThenSize)

	PQ* pq;
	Vector* vec;
	Task* task1;
	size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t size;
	
	task1 = TaskCreate(DummyTaskFunc, NULL, 100, CLOCK_REALTIME);
	
    vec = VecCreate(initialCapacity, blockSize);
	pq = PQBuild(vec, (LessThanComparator)TaskCompare);
	PQInsert(pq, task1);
	size = PQSize(pq);
	ASSERT_THAT(1 == size);
	vec = PQDestroy(&pq);
	VecDestroy(&vec, (ElementDestroy)TaskDestroy);
	
	
END_UNIT



UNIT(TestPQCheckCorrectOrderOfTasks)

	PQ* pq;
	Vector* vec;
	Task* task1;
	Task* task2;
	Task* task3;
	const Task* peekedTask;
	size_t initialCapacity = 10;
    size_t blockSize = 2;
    size_t size;
	
	task1 = TaskCreate(DummyTaskFunc, NULL, 100, CLOCK_REALTIME);
	task2 = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	task3 = TaskCreate(DummyTaskFunc, NULL, 10, CLOCK_REALTIME);
	
    vec = VecCreate(initialCapacity, blockSize);
	pq = PQBuild(vec, (LessThanComparator)TaskCompare);
	PQInsert(pq, task1);
	PQInsert(pq, task2);
	PQInsert(pq, task3);
	size = PQSize(pq);
	ASSERT_THAT(3 == size);
	PQExtract(pq);
	peekedTask = PQPeek(pq);
	ASSERT_THAT(peekedTask == task1);
	vec = PQDestroy(&pq);
	VecDestroy(&vec, (ElementDestroy)TaskDestroy);
	
	
END_UNIT



TEST_SUITE(PQ Tests)

	TEST(TestPQCreateReturnVector)
	TEST(TestPQOneInsertThenSize)
	TEST(TestPQCheckCorrectOrderOfTasks)
	
END_SUITE






