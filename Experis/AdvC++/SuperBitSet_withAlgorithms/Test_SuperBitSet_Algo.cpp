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
	
	ASSERT_THAT(bs1.GetNumOfBits() == size);
	ASSERT_THAT(bs1.GetNumOfElements() == numOfElements);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorAND)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,1};
	bool boolArr2[size] = {0,1,0,0,0,0,0,1,1};
	bool boolResult[size] = {0,1,0,0,0,0,0,1,1};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3(boolResult, size);
	advcpp::BitSet<size, unsigned char> bs4;
	
	bs4 = bs1 & bs2;
	
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
UNIT(OperatorOR)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};
	bool boolArr2[size] = {0,1,0,0,0,0,1,1,1};
	bool boolResu[size] = {0,1,0,1,0,1,1,1,1};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3(boolResu, size);
	advcpp::BitSet<size, unsigned char> bs4;
	
	bs4 = bs1 | bs2;
	
	ASSERT_THAT(bs3 == bs4);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorShiftLeft)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,0,0,0,1};
	bool boolArr2[size] = {1,0,1,0,0,0,0,1,0};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	
	bs1 << 1;
	
	ASSERT_THAT(bs1 == bs2);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Flip)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};
	bool boolArr2[size] = {1,0,1,0,1,0,1,0,1};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3;
		
	bs3 = bs1.Flip();
	
	ASSERT_THAT(bs2 == bs3);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Any)
	const size_t size = 9;
	bool boolArr1[size] = {0,0,0,0,0,0,0,0,0};
	bool boolArr2[size] = {1,0,1,0,1,0,1,0,1};
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
		
	ASSERT_THAT(bs2.Any() == true && bs1.Any() == false);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Timed_And_100000_BitSet)
	srand(time(NULL));
	const size_t size = 100000; //TODO: This test passes when size is in the range of few thousands (~1000)
	clock_t t;
	bool boolArr1[size];
	bool boolArr2[size];
	for (size_t index = 0; index < size; ++index)
	{
		boolArr1[index] = (rand() % 2);
	}
	for (size_t index = 0; index < size; ++index)
	{
		boolArr2[index] = true;
	}
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3;
	
	t = clock();
	bs3 = (bs1 & bs2);
	t = clock() -t;
	std::cout << "bs1 & bs2; " << size << " bits: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << std::endl;
	ASSERT_THAT(bs1 == bs3);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Timed_And_100000_stdBitSet)

	srand(time(NULL));
	const size_t size = 100000;
	clock_t t;
	
	std::bitset<size> stdBS1;
	std::bitset<size> stdBS2;
	std::bitset<size> stdBS3;
	
	for (size_t index = 0; index < size; ++index)
	{
		stdBS1.set(index, (rand() % 2));
	}
	
	for (size_t index = 0; index < size; ++index)
	{
		stdBS2.set(index, true);
	}
	
	t = clock();
	stdBS3 = stdBS1 & stdBS2;
	t = clock() -t;
	std::cout << "stdBS1 & stdBS2; " << size << " bits: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << std::endl;
	ASSERT_THAT(stdBS1 == stdBS3);
END_UNIT
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
TEST_SUITE(BitSet)
	TEST(Default_CTOR_with_type)
	TEST(Default_CTOR_without_type)
	TEST(OperatorAND)
	TEST(OperatorAND_EQUALS)
	TEST(OperatorOR)
	TEST(OperatorShiftLeft)
	TEST(Flip)
	TEST(Any)
//	TEST(OperatorSUBSCRIPT_returns_bool)
//	TEST(OperatorSUBSCRIPT_returns_BitRef)
//	TEST(OperatorLEFT_SHIFT)
//	TEST(OperatorRIGHT_SHIFT)
//	TEST(Timed_Create_100000_BitSet)
	TEST(Timed_And_100000_BitSet)
	TEST(Timed_And_100000_stdBitSet)
END_SUITE






