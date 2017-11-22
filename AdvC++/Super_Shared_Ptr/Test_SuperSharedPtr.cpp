#include "../../inc/mu_test.h"
#include "SuperSharedPtr.h"
#include<stdio.h>
#include<stdlib.h>



////////////////////////////////////////////////////////////////////////////
UNIT(Default_CTOR)
	advcpp::SharedPtr<int> sp1;
	ASSERT_THAT(0 == sp1.GetPtr());
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(CTOR_From_Tptr)
	advcpp::SharedPtr<int> sp1(new int);
	ASSERT_THAT(0 != sp1.GetPtr());
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Copy_CTOR)
	advcpp::SharedPtr<int> sp1(new int);
	advcpp::SharedPtr<int> sp2 = sp1;
	ASSERT_THAT(sp1.GetPtr() == sp2.GetPtr());
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Assignment_Op)
	advcpp::SharedPtr<int> sp1(new int);
	advcpp::SharedPtr<int> sp2;
	sp2 = sp1;
	ASSERT_THAT(sp1.GetPtr() == sp2.GetPtr());
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Operator_Dereference)
	advcpp::SharedPtr<int> sp1(new int);
	advcpp::SharedPtr<int> sp2;
	sp2 = sp1;
	ASSERT_THAT(&(*sp1) == &(*sp2));
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Operator_Arrow)
	advcpp::SharedPtr<int> sp1(new int);
	advcpp::SharedPtr<int> sp2;
	sp2 = sp1;
//	ASSERT_THAT(sp1->GetPtr() == sp2->GetPtr());
	ASSERT_THAT(sp1->GetPtr());
END_UNIT
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
TEST_SUITE(SuperSharedPtr)
	TEST(Default_CTOR)
	TEST(CTOR_From_Tptr)
	TEST(Copy_CTOR)
	TEST(Assignment_Op)
	TEST(Operator_Dereference)
END_SUITE






