#include "PeriodicExecutor.h"
#include "../../inc/mu_test.h"
#include <stdio.h>
#include <time.h>


int NumOfRepsTaskFunc(unsigned int* _numOfReps)
{
	if (*_numOfReps > 1)
	{
		--*_numOfReps;
		return 0;
	}
	return 1;
} 

int PauseTaskFunc(PE* _pe)
{
	PeriodicExecutor_Pause(_pe);
	return 1;
} 



UNIT(TestPeriodicExecutor_Create)

	PE* pe;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	ASSERT_THAT(pe);
	PeriodicExecutor_Destroy(pe);
	
END_UNIT


UNIT(TestPeriodicExecutor_Add)

	PE* pe;
	int result;
	unsigned int* rep1;
	unsigned int reps = 1;
	rep1 = &reps;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	result = PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 500);
	ASSERT_THAT(0 == result);
	PeriodicExecutor_Destroy(pe);
	
END_UNIT


UNIT(TestPeriodicExecutor_Run)

	PE* pe;
	size_t result;
	int* rep1;
	
	rep1 = malloc(sizeof(int));
	*rep1 = 1;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 147);
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(1 == result);
	PeriodicExecutor_Destroy(pe);
	free(rep1);
	
END_UNIT



UNIT(TestPeriodicExecutor_RunTwoTasks)

	PE* pe;
	size_t result;
	int* rep1;
	
	rep1 = malloc(sizeof(int));
	*rep1 = 1;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 500);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 750);
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(2 == result);
	PeriodicExecutor_Destroy(pe);
	free(rep1);
	
END_UNIT

UNIT(TestPeriodicExecutor_RunTwoTasksWithPause)

	PE* pe;
	size_t result;
	int* rep1;
	
	rep1 = malloc(sizeof(int));
	*rep1 = 1;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 250);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 700);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 500);
	PeriodicExecutor_Run(pe);
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(3 == result);
	PeriodicExecutor_Destroy(pe);
	free(rep1);
	
END_UNIT


UNIT(TestPeriodicExecutor_RunTwoTasksWithFiveReps)

	PE* pe;
	size_t result;
	int* rep1;
	int* rep2;
	
	rep1 = malloc(sizeof(int));
	*rep1 = 1;
	
	rep2 = malloc(sizeof(int));
	*rep2 = 5;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep2, 2000);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 4500);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 1000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 3000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 5500);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 7000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 9000);


	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(1 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(3 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(6 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(8 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(10 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(11 == result);
	
	
	
	
	PeriodicExecutor_Destroy(pe);
	free(rep1);
	free(rep2);
END_UNIT





UNIT(TestPeriodicExecutor_RunFiveTasks)

	PE* pe;
	size_t result;
	int* rep1;
	int* rep2;
	int* rep3;
	
	rep1 = malloc(sizeof(int));
	*rep1 = 1;
	
	rep2 = malloc(sizeof(int));
	*rep2 = 3;
	
	rep3 = malloc(sizeof(int));
	*rep3 = 3;
	
	pe = PeriodicExecutor_Create("testname.txt", CLOCK_REALTIME);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep2, 2000);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep3, 5000);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 12000);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 17000);
	PeriodicExecutor_Add(pe, (TaskFunction)NumOfRepsTaskFunc, rep1, 20000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 1000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 3000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 8000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 14000);
	PeriodicExecutor_Add(pe, (TaskFunction)PauseTaskFunc, pe, 18000);


	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(1 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(3 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(7 == result);
	

	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(10 == result);
	
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(13 == result);
	
	/*
	clock_gettime(CLOCK_REALTIME, &(start_t));
	result = PeriodicExecutor_Run(pe);
	clock_gettime(CLOCK_REALTIME, &(end_t));
	printf("run time sec:\t%lu, millisecs:\t%lu\n", end_t.tv_sec - start_t.tv_sec, (end_t.tv_nsec - start_t.tv_nsec) / 1000000 );
	*/
	result = PeriodicExecutor_Run(pe);
	ASSERT_THAT(14 == result);
	
	PeriodicExecutor_Destroy(pe);
	free(rep1);
	free(rep2);
	free(rep3);
END_UNIT





TEST_SUITE(PQ Tests)

	TEST(TestPeriodicExecutor_Create)
	TEST(TestPeriodicExecutor_Add)
	TEST(TestPeriodicExecutor_Run)
	TEST(TestPeriodicExecutor_RunTwoTasks)
	TEST(TestPeriodicExecutor_RunTwoTasksWithPause)
	TEST(TestPeriodicExecutor_RunTwoTasksWithFiveReps)
	TEST(TestPeriodicExecutor_RunFiveTasks)
	
END_SUITE






