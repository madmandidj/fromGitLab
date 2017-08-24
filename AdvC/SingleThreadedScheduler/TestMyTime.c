#include <stdio.h>
#include <string.h>
#include "MyTime.h" 
#include "../../inc/mu_test.h"



/*
	TIME CREATE TESTS
*/
UNIT(TestTimeCreate)
	Time* time;
	
	time = TimeCreate();
	ASSERT_THAT(time);
	TimeDestroy(time);
END_UNIT


UNIT(TestTimeCompareNULLTimes)
	int swapNeeded;
	
	swapNeeded = TimeCompare(NULL, NULL);
	ASSERT_THAT(-1 == swapNeeded);
END_UNIT


UNIT(TestTimeCompareNoSwapNeeded)
	Time* time1;
	Time* time2;
	int swapNeeded;
	
	time1 = TimeCreate();
	time2 = TimeCreate();
	TimeSetPeriod(time1, 100);
	TimeSetPeriod(time2, 10);
	swapNeeded = TimeCompare(time1, time2);
	ASSERT_THAT(0 == swapNeeded);
	TimeDestroy(time1);
	TimeDestroy(time2);
END_UNIT


UNIT(TestTimeCompareNoSwapNeededTimeEquals)
	Time* time1;
	Time* time2;
	int swapNeeded;
	
	time1 = TimeCreate();
	time2 = TimeCreate();
	TimeSetPeriod(time1, 100);
	TimeSetPeriod(time2, 100);
	swapNeeded = TimeCompare(time1, time2);
	ASSERT_THAT(0 == swapNeeded);
	TimeDestroy(time1);
	TimeDestroy(time2);
END_UNIT


UNIT(TestTimeCompareSwapNeeded)
	Time* time1;
	Time* time2;
	int swapNeeded;
	
	time1 = TimeCreate();
	time2 = TimeCreate();
	TimeSetPeriod(time1, 10);
	TimeSetPeriod(time2, 100);
	swapNeeded = TimeCompare(time1, time2);
	ASSERT_THAT(1 == swapNeeded);
	TimeDestroy(time1);
	TimeDestroy(time2);
END_UNIT


UNIT(TestTimeAdd)
	Time* time1;
	Time* time2;
	int swapNeeded;
	
	time1 = TimeCreate();
	time2 = TimeCreate();
	TimeSetPeriod(time1, 10);
	TimeSetPeriod(time2, 10);
	TimeAdd(time2, time1);
	swapNeeded = TimeCompare(time1, time2);
	ASSERT_THAT(1 == swapNeeded);
	TimeDestroy(time1);
	TimeDestroy(time2);
END_UNIT


TEST_SUITE(My Time tests)

	TEST(TestTimeCreate)
	TEST(TestTimeCompareNULLTimes)
	TEST(TestTimeCompareNoSwapNeeded)
	TEST(TestTimeCompareNoSwapNeededTimeEquals)
	TEST(TestTimeCompareSwapNeeded)
	TEST(TestTimeAdd)
	
END_SUITE

































