#include "../../../../../../inc/mu_test.h"
#include "../../../inc/Processor.h"
#include <stdio.h>





UNIT(ProcessorCreateAndDestroy)
	
	Processor* proc;
	
	proc = ProcessorCreate(1);
	ASSERT_THAT(proc);
	ProcessorDestroy(proc);
	
END_UNIT


UNIT(ProcessorRunTest)
	int result;
	
	Processor* proc;
	
	proc = ProcessorCreate(1);
	result = ProcessorRun(proc);
	ASSERT_THAT(0 == result);
	ProcessorDestroy(proc);
	
END_UNIT



TEST_SUITE(Processor unit tests v1)

	TEST(ProcessorCreateAndDestroy)
	TEST(ProcessorRunTest)

END_SUITE

