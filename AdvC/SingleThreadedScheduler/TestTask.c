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



TEST_SUITE(My Time tests)

	TEST(TestTaskCreate)
	TEST(TestTaskExecute)

END_SUITE

































