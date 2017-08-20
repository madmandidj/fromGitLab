#include <stdio.h>
#include <stdlib.h>
#include "mu_test.h"


UNIT(will_pass)
	ASSERT_THAT( sizeof(char) == 1);
	ASSERT_THAT( sizeof('A') == 4);
	ASSERT_THAT( sizeof(int) == 4);
END_UNIT

UNIT(will_fail)
	ASSERT_THAT( sizeof(int*) == 8);
END_UNIT


UNIT(malloc_zero_will_alloc_something)
	int *p = malloc(0);
	ASSERT_THAT(p != NULL);
END_UNIT




TEST_SUITE(framework test)
	TEST(will_pass)
	TEST(will_fail)	
	TEST(malloc_zero_will_alloc_something)
END_SUITE

