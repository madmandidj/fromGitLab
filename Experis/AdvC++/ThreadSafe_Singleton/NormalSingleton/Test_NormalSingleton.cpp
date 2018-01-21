#include "NormalSingleton.h"
#include<iostream>
#include<stdio.h>
#include "../../inc/mu_test.h"


////////////////////////////////////////////////////////////////////////////
UNIT(CreateAndDestroy)
	advcpp::NormalSingleton* mySngPtr = advcpp::NormalSingleton::Create();
	advcpp::NormalSingleton* mySngPtr2 = advcpp::NormalSingleton::Create();
	
	advcpp::NormalSingleton::Destroy();
	advcpp::NormalSingleton* mySngPtr3 = advcpp::NormalSingleton::Create();
	advcpp::NormalSingleton::Destroy();
	//ASSERT_THAT();
END_UNIT

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
TEST_SUITE(NormalSingleton)
	TEST(CreateAndDestroy)

END_SUITE


