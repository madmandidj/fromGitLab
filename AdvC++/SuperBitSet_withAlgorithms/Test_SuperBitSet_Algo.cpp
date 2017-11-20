#include "../inc/mu_test.h"
#include "./BitSet/BitSet.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<bitset>

using namespace std;

////////////////////////////////////////////////////////////////////////////
UNIT(Default_CTOR_with_type)
	const size_t size = 9;
	advcpp::BitSet<size, unsigned char> bs1;
	size_t numOfElements;
	
	if (0 == (size % (sizeof(unsigned char)*CHAR_BIT)))
	{
		numOfElements = (size / (sizeof(unsigned char)*CHAR_BIT));
	}
	else
	{
		numOfElements = ceil((double)size / (CHAR_BIT * sizeof(unsigned char)));
	}
	
//	ASSERT_THAT(bs1.None() == true);
	ASSERT_THAT(bs1.GetNumOfBits() == size);
	ASSERT_THAT(bs1.GetNumOfElements() == numOfElements);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Default_CTOR_without_type)
	const size_t size = 9;
	advcpp::BitSet<size> bs1;
	size_t numOfElements;
	
	if (0 == (size % (sizeof(unsigned int)*CHAR_BIT)))
	{
		numOfElements = (size / (sizeof(unsigned int)*CHAR_BIT));
	}
	else
	{
		numOfElements = ceil((double)size / (CHAR_BIT * sizeof(unsigned int)));
	}
	
//	ASSERT_THAT(bs1.None() == true);
	ASSERT_THAT(bs1.GetNumOfBits() == size);
	ASSERT_THAT(bs1.GetNumOfElements() == numOfElements);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorAND)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,1};
	bool boolArr2[size] = {0,1,0,0,0,0,0,1,0};
	bool boolResult[size] = {0,1,0,0,0,0,0,1,1};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3(boolResult, size);
	advcpp::BitSet<size, unsigned char> bs4;
	
	bs4 = bs1 & bs2;
	
	cout << bs1 << endl;
	cout << bs2 << endl;
	cout << bs3 << endl;
	cout << bs4 << endl;
	ASSERT_THAT(bs3 == bs4);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorAND_EQUALS)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};
	bool boolArr2[size] = {0,1,0,0,0,0,0,1,0};
	bool boolResult[size] = {0,1,0,0,0,0,0,1,0};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3(boolResult, size);
	advcpp::BitSet<size, unsigned char> bs4;
	
	bs4 = bs1;
	bs4 &= bs2;
	
	ASSERT_THAT(bs3 == bs4);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Timed_And_100000_BitSet)

	srand(time(NULL));
	const size_t size = 100000;
	clock_t t;
	
	bool boolArr1[size];
	for (size_t index = 0; index < size; ++index)
	{
		boolArr1[index] = (rand() % 2);
	}
	
	bool boolArr2[size];
	for (size_t index = 0; index < size; ++index)
	{
		boolArr2[index] = true;
	}
	
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3;
	
	t = clock();
	bs1 & bs2;
	t = clock() -t;
	std::cout << "bs1 & bs2; " << size << " bits: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << std::endl;
END_UNIT

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
TEST_SUITE(BitSet)
	TEST(Default_CTOR_with_type)
	TEST(Default_CTOR_without_type)
	TEST(OperatorAND)
	TEST(OperatorAND_EQUALS)
//	TEST(OperatorSUBSCRIPT_returns_bool)
//	TEST(OperatorSUBSCRIPT_returns_BitRef)
//	TEST(OperatorLEFT_SHIFT)
//	TEST(OperatorRIGHT_SHIFT)
//	TEST(Timed_Create_100000_BitSet)
	TEST(Timed_And_100000_BitSet)
//	TEST(Timed_And_100000_stdBitSet)
END_SUITE






