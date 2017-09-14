#include "../../MU_TEST/mu_test.h"
#include "Accumulator.h"
#include <stdio.h>





UNIT(AccumulatorCreateAndDestroy)

	Subscriber subscriber = {"123456789012345", 
							"123456789012345", 
							1, 
							2, 
							3, 
							4,
							5,
							6
	}; 
	Operator operator = {"EyalAlons MobilePhoneService", 
									"34578",
									1,
									2,
									3,
									4,
									5,
									6
	};
	Accumulator* accum;
	
	accum = AccumulatorCreate();
	ASSERT_THAT(accum);
	AccumulatorDestroy(accum);
	
END_UNIT









UNIT(AccumulatorUpdateSubscriberTest)

	Subscriber subscriber = {"123456789012345", 
							"123456789012345", 
							1, 
							2, 
							3, 
							4,
							5,
							6
	}; 
	Operator operator = {"EyalAlons MobilePhoneService", 
									"34578",
									1,
									2,
									3,
									4,
									5,
									6
	};
	Accumulator* accum;
	int err;
	
	accum = AccumulatorCreate();
	err = AccumulatorUpdateSubscriber(accum, &subscriber);
	ASSERT_THAT(accum);
	AccumulatorDestroy(accum);
	
END_UNIT












TEST_SUITE(Accumulator unit tests v1)

	TEST(AccumulatorCreateAndDestroy)
	TEST(AccumulatorUpdateSubscriberTest)
	
END_SUITE

