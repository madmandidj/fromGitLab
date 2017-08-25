#include <stdio.h>
#include "Task.h"
#include "MyTime.h" 
#include "../../inc/mu_test.h"

int DummyTaskFunc()
{
	return 1;
} 


UNIT(TestTaskCreate)

	Task* task;
	
	task = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	ASSERT_THAT(task);
	TaskDestroy(task);
	
END_UNIT

UNIT(TestTaskExecute)

	Task* task;
	int result;
	
	task = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	result = TaskExecute(task, CLOCK_REALTIME);
	ASSERT_THAT(1 == result);
	TaskDestroy(task);
	
END_UNIT


UNIT(TestTaskCompareSwapNeeded)

	Task* task1;
	Task* task2;
	int result;
	
	task1 = TaskCreate(DummyTaskFunc, NULL, 100, CLOCK_REALTIME);
	task2 = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	result = TaskCompare(task1, task2);
	ASSERT_THAT(1 == result);
	TaskDestroy(task1);
	TaskDestroy(task2);
	
END_UNIT


UNIT(TestTaskCompareNoSwapNeeded)

	Task* task1;
	Task* task2;
	int result;
	
	task1 = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	task2 = TaskCreate(DummyTaskFunc, NULL, 100, CLOCK_REALTIME);
	result = TaskCompare(task1, task2);
	ASSERT_THAT(0 == result);
	TaskDestroy(task1);
	TaskDestroy(task2);
	
END_UNIT

/*
UNIT(TestTaskGetNextRunTime)

	Task* task1;
	struct timespec start_t;
	struct timespec end_t;

	task1 = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	

	TaskGetNextRunTime(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(start_t));
	printf("start sec:\t%lu, nsec:\t%lu\n", start_t.tv_sec, start_t.tv_nsec);
	TaskExecute(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(end_t));
	printf("end sec:\t%lu, nsec:\t%lu\n", end_t.tv_sec, end_t.tv_nsec);
	
	printf("run time sec:\t%lu, microsecs:\t%lu\n", end_t.tv_sec - start_t.tv_sec, (end_t.tv_nsec - start_t.tv_nsec) / 1000 );

	ASSERT_THAT(1);
	TaskDestroy(task1);
	
END_UNIT
*/

UNIT(TestTaskExecute1000ms)

	Task* task1;
	struct timespec start_t;
	struct timespec end_t;

	task1 = TaskCreate(DummyTaskFunc, NULL, 1000, CLOCK_REALTIME);
	

	TaskGetNextRunTime(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(start_t));
	TaskExecute(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(end_t));
	
	/*printf("run time sec:\t%lu, microsecs:\t%lu\n", end_t.tv_sec - start_t.tv_sec, (end_t.tv_nsec - start_t.tv_nsec) / 1000 );*/

	ASSERT_THAT(end_t.tv_sec - start_t.tv_sec < 2);
	TaskDestroy(task1);
	
END_UNIT


UNIT(TestTaskExecute1ms)

	Task* task1;
	struct timespec start_t;
	struct timespec end_t;

	task1 = TaskCreate(DummyTaskFunc, NULL, 1789, CLOCK_REALTIME);
	

	TaskGetNextRunTime(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(start_t));
	TaskExecute(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(end_t));
	
	/*printf("run time sec:\t%lu, millisecs:\t%lu\n", end_t.tv_sec - start_t.tv_sec, (end_t.tv_nsec - start_t.tv_nsec) / 1000000 );*/

	ASSERT_THAT((end_t.tv_sec - start_t.tv_sec) < 3);
	TaskDestroy(task1);
	
END_UNIT


UNIT(TestTaskExecute0seconds)

	Task* task1;
	struct timespec start_t;
	struct timespec end_t;

	task1 = TaskCreate(DummyTaskFunc, NULL, 0, CLOCK_REALTIME);
	

	TaskGetNextRunTime(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(start_t));
	TaskExecute(task1, CLOCK_REALTIME);
	clock_gettime(CLOCK_REALTIME, &(end_t));
	
	/*printf("run time sec:\t%lu, millisecs:\t%lu\n", end_t.tv_sec - start_t.tv_sec, (end_t.tv_nsec - start_t.tv_nsec) / 1000000 );*/

	ASSERT_THAT((end_t.tv_nsec - start_t.tv_nsec) / 1000000 < 10);
	TaskDestroy(task1);
	
END_UNIT



TEST_SUITE(My Time tests)

	TEST(TestTaskCreate)
	TEST(TestTaskExecute)
	TEST(TestTaskCompareSwapNeeded)
	TEST(TestTaskCompareNoSwapNeeded)
	TEST(TestTaskExecute1000ms)
/*	TEST(TestTaskGetNextRunTime)*/
	TEST(TestTaskExecute1ms)
	TEST(TestTaskExecute0seconds)
	
END_SUITE

































