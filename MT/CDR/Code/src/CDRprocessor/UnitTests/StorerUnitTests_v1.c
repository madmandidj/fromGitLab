#include "../../../../../../inc/mu_test.h"
#include "../../../inc/Storer.h"
#include <stdio.h>





UNIT(StorerCreateAndDestroy)

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
	Storer* storer;
	
	storer = StorerCreate(&subscriber, &operator);
	ASSERT_THAT(storer);
	StorerDestroy(storer);
	
END_UNIT






UNIT(StorerGetOperatorCheckValue)

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
	Storer* storer;
	
	storer = StorerCreate(&subscriber, &operator);
	retrievedSubscriber = StorerGetSubscriber(storer);
	ASSERT_THAT(retrievedSubscriber.m_outVoiceWithinOp == subscriber.m_outVoiceWithinOp);
	StorerDestroy(storer);
	
END_UNIT





UNIT(StorerUpdateSubscriberCheckValue)

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
	Storer* storer;
	
	storer = StorerCreate(&subscriber, &operator);
	StorerUpdateSubscriber(storer, &subscriber);
	retrievedSubscriber = StorerGetSubscriber(storer);
	ASSERT_THAT(retrievedSubscriber.m_outVoiceWithinOp == 2);
	StorerDestroy(storer);
	
END_UNIT








TEST_SUITE(Storer unit tests v1)

	TEST(StorerCreateAndDestroy)
	TEST(StorerGetOperatorCheckValue)
	TEST(StorerUpdateSubscriberCheckValue)

END_SUITE

