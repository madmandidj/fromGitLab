#include "../../inc/Stack.h"
#include "../../inc/Vector.h"
#include "../../inc/ADTErr.h"
#include "../../inc/mu_test.h"
#include <stdlib.h>
#include <stdio.h>

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}




UNIT(StackCreate_0_Capacity)
	Stack* stack;
	stack = StackCreate(0, 0);
    ASSERT_THAT(!stack);
END_UNIT


TEST_SUITE(HEAP TESTS)
	
	TEST(StackCreate_0_Capacity)

END_SUITE














