#include "Task.h"
#include "PriorityQ.h"
#include "../../inc/mu_test.h"
#include <stdio.h>
#include <time.h>


int DummyTaskFunc()
{
	return 1;
} 



UNIT(TestPQCreate)

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
	VecDestroy(&vec, (ElementDestroy)TaskDestroy);
	ASSERT_THAT(!vec);
	
END_UNIT



TEST_SUITE(PQ Tests)

	TEST(TestPQCreate)
	
END_SUITE






