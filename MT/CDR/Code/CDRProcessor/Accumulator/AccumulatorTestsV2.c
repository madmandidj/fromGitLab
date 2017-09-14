#include "../../MU_TEST/mu_test.h"
#include "Accumulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





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









UNIT(AccumulatorAddSubscriberTest)

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
	ASSERT_THAT(err == 1);
	AccumulatorDestroy(accum);
	
END_UNIT














UNIT(AccumulatorGetSubscriberTest)

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
	Subscriber subFound;
	int err;
	
	accum = AccumulatorCreate();
	AccumulatorUpdateSubscriber(accum, &subscriber);
	err = AccumulatorGetSubscriber(accum, &subscriber, &subFound);
	ASSERT_THAT(err == 1);
	ASSERT_THAT(0 == (strcmp(subFound.m_msisdn, subscriber.m_msisdn)));
	AccumulatorDestroy(accum);
	
END_UNIT








UNIT(AccumulatorUpdateSubscriberTest)

	Subscriber subscriber = {"123456789012345", 
							"123456789012345", 
							1, 
							1, 
							1, 
							1,
							1,
							1,
							1,
							1,
							1,
							1
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
	Subscriber subFound;
	int err;
	
	Subscriber* testSub;
	
	
	testSub = malloc(sizeof(Subscriber));
	
	accum = AccumulatorCreate();
	AccumulatorUpdateSubscriber(accum, &subscriber);
	AccumulatorUpdateSubscriber(accum, &subscriber);
	err = AccumulatorGetSubscriber(accum, &subscriber, &subFound);
	ASSERT_THAT(err == 1);
	ASSERT_THAT(2 == subFound.m_outVoiceWithinOp);
	AccumulatorDestroy(accum);
	free(testSub);
	
END_UNIT









TEST_SUITE(Accumulator unit tests v1)

	TEST(AccumulatorCreateAndDestroy)
	TEST(AccumulatorAddSubscriberTest)
	TEST(AccumulatorGetSubscriberTest)
	TEST(AccumulatorUpdateSubscriberTest)
	
END_SUITE

