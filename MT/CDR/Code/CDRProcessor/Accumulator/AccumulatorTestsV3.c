#include "../../MU_TEST/mu_test.h"
#include "Accumulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





UNIT(AccumulatorGetSubscriberTest)

	Subscriber subscriber = {"123456789012345", 
							"123456789012345", 
							9, 
							9, 
							9, 
							9,
							9,
							9
	}; 

	Accumulator* accum;
	Subscriber* subFound;
	int err;
	
	accum = AccumulatorCreate();
	AccumulatorUpdateSubscriber(accum, &subscriber);
	err = AccumulatorGetSubscriber(accum, "123456789012345", &subFound);
	ASSERT_THAT(err == 1);
	ASSERT_THAT(0 == (strcmp(subFound->m_msisdn, subscriber.m_msisdn)));
	AccumulatorDestroy(accum);
	
END_UNIT




UNIT(AccumulatorGetSubscriberAfterUpdated)

	Subscriber subscriber = {"123456789012345", 
							"123456789012345", 
							9, 
							9, 
							9, 
							9,
							9,
							9
	}; 

	Accumulator* accum;
	Subscriber* subFound;
	int err;
	
	accum = AccumulatorCreate();
	AccumulatorUpdateSubscriber(accum, &subscriber);
	AccumulatorUpdateSubscriber(accum, &subscriber);
	err = AccumulatorGetSubscriber(accum, "123456789012345", &subFound);
	ASSERT_THAT(err == 1);
	ASSERT_THAT(18 == subFound->m_outVoiceWithinOp);
	AccumulatorDestroy(accum);
	
END_UNIT




UNIT(AccumulatorGetSubscriberAfterMultipleUpdated)

	Subscriber subscriber1 = {"123456789012345", 
							"111111111111111", 
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
	
	Subscriber subscriber2 = {"123456789012345", 
							"222222222222222", 
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
	
	Subscriber subscriber3 = {"123456789012345", 
							"333333333333333", 
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
	
	Subscriber subscriber4 = {"123456789012345", 
							"444444444444444", 
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

	Accumulator* accum;
	Subscriber* subFound;
	int err;
	
	accum = AccumulatorCreate();
	AccumulatorUpdateSubscriber(accum, &subscriber1);
	AccumulatorUpdateSubscriber(accum, &subscriber2);
	AccumulatorUpdateSubscriber(accum, &subscriber3);
	err = AccumulatorGetSubscriber(accum, "111111111111111", &subFound);
	ASSERT_THAT(err == 1);
	err = AccumulatorGetSubscriber(accum, "222222222222222", &subFound);
	ASSERT_THAT(err == 1);
	err = AccumulatorGetSubscriber(accum, "333333333333333", &subFound);
	ASSERT_THAT(err == 1);
	err = AccumulatorGetSubscriber(accum, "444444444444444", &subFound);
	ASSERT_THAT(err == 0);
	
	AccumulatorUpdateSubscriber(accum, &subscriber2);
	err = AccumulatorGetSubscriber(accum, "222222222222222", &subFound);
	
	ASSERT_THAT(2 == subFound->m_outVoiceWithinOp);
	AccumulatorDestroy(accum);
	
END_UNIT





TEST_SUITE(Accumulator unit tests v2)

	TEST(AccumulatorGetSubscriberTest)
	TEST(AccumulatorGetSubscriberAfterUpdated)
	TEST(AccumulatorGetSubscriberAfterMultipleUpdated)
	
END_SUITE

