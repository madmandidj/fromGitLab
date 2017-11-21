#include "TemplateSingleton.h"
#include<iostream>
#include<stdio.h>
#include "../../inc/mu_test.h"


////////////////////////////////////////////////////////////////////////////
UNIT(CreateAndDestroy)
	int* mySngPtr = advcpp::TemplateSingleton<int>::Create();
	
//	advcpp::TemplateSingleton* mySngPtr2 = advcpp::TemplateSingleton::Create();
	
	advcpp::TemplateSingleton<int>::Destroy();
//	advcpp::NormalSingleton* mySngPtr3 = advcpp::TemplateSingleton::Create();
//	advcpp::NormalSingleton::Destroy();

//	ASSERT_THAT(advcpp::TemplateSingleton<int>);
END_UNIT

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
TEST_SUITE(TemplateSingleton)
	TEST(CreateAndDestroy)

END_SUITE


