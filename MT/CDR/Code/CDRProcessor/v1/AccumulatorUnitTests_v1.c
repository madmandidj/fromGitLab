#include "../../../../../../inc/mu_test.h"
#include "../../../inc/Accumulator.h"
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
									34578,
									1,
									2,
									3,
									4,
									5,
									6
	};
	Accumulator* accum;
	
	accum = AccumulatorCreate(&subscriber, &operator);
	ASSERT_THAT(accum);
	AccumulatorDestroy(accum);
	
END_UNIT






UNIT(AccumulatorGetOperatorCheckValue)

	Subscriber retrievedSubscriber;
	
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
									34578,
									1,
									2,
									3,
									4,
									5,
									6
	};
	Accumulator* accum;
	
	accum = AccumulatorCreate(&subscriber, &operator);
	retrievedSubscriber = AccumulatorGetSubscriber(accum);
	ASSERT_THAT(retrievedSubscriber.m_outVoiceWithinOp == subscriber.m_outVoiceWithinOp);
	AccumulatorDestroy(accum);
	
END_UNIT





UNIT(AccumulatorUpdateSubscriberCheckValue)

	Subscriber retrievedSubscriber;
	
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
									34578,
									1,
									2,
									3,
									4,
									5,
									6
	};
	Accumulator* accum;
	
	accum = AccumulatorCreate(&subscriber, &operator);
	AccumulatorUpdateSubscriber(accum, &subscriber);
	retrievedSubscriber = AccumulatorGetSubscriber(accum);
	ASSERT_THAT(retrievedSubscriber.m_outVoiceWithinOp == 2);
	AccumulatorDestroy(accum);
	
END_UNIT








TEST_SUITE(Accumulator unit tests v1)

	TEST(AccumulatorCreateAndDestroy)
	TEST(AccumulatorGetOperatorCheckValue)
	TEST(AccumulatorUpdateSubscriberCheckValue)

END_SUITE

