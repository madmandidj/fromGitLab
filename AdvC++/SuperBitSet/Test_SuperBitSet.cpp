#include "../inc/mu_test.h"
#include "./BitSet/BitSet.h"
#include "./BitRef/BitRef.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<bitset>



////////////////////////////////////////////////////////////////////////////
UNIT(Default_CTOR_with_type)
	const size_t size = 9;
	advcpp::BitSet<size, unsigned char> bs1;
	size_t numOfContainers;
	
	if (0 == (size % (sizeof(unsigned char)*CHAR_BIT)))
	{
		numOfContainers = (size / (sizeof(unsigned char)*CHAR_BIT));
	}
	else
	{
		numOfContainers = ceil((double)(size / (sizeof(unsigned char)*CHAR_BIT)));
	}
	
	ASSERT_THAT(bs1.None() == true);
	ASSERT_THAT(bs1.GetNumOfBits() == size);
	ASSERT_THAT(bs1.GetNumOfBitContainers() == numOfContainers);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Default_CTOR_without_type)
	const size_t size = 9;
	advcpp::BitSet<size> bs1;
	size_t numOfContainers;
	
	if (0 == (size % (sizeof(unsigned int)*CHAR_BIT)))
	{
		numOfContainers = (size / (sizeof(unsigned int)*CHAR_BIT));
	}
	else
	{
		numOfContainers = ceil((double)(size / (sizeof(unsigned int)*CHAR_BIT)));
	}
	
	ASSERT_THAT(bs1.None() == true);
	ASSERT_THAT(bs1.GetNumOfBits() == size);
	ASSERT_THAT(bs1.GetNumOfBitContainers() == numOfContainers);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorAND)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};
	bool boolArr2[size] = {0,1,0,0,0,0,0,1,0};
	bool boolResult[size] = {0,1,0,0,0,0,0,1,0};
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

	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	advcpp::BitSet<size, unsigned char> bs2(boolArr2, size);
	advcpp::BitSet<size, unsigned char> bs3;
	
	bs3 = bs1 & bs2;
	bs1 &= bs2;
	ASSERT_THAT(bs1 == bs3);
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorSUBSCRIPT_returns_bool)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};

	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	
	ASSERT_THAT((bs1[0] == false) && (bs1[1] == true));
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorSUBSCRIPT_returns_BitRef)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,0};

	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	
	ASSERT_THAT((bs1[0] == false) && (bs1[1] == true));
	bs1[0] = true;
	ASSERT_THAT((bs1[0] == true) && (bs1[1] == true));
	bs1[8] = bs1[0];
	ASSERT_THAT((bs1[0] == true) && (bs1[8] == true));
	bs1[0] = false;
	ASSERT_THAT((bs1[0] == false) && (bs1[8] == true));
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorLEFT_SHIFT)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,1};

	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	ASSERT_THAT((bs1[0] == false) && (bs1[1] == true));
	
	bs1 << 1;
	ASSERT_THAT((bs1[0] == true) && (bs1[size-1] == false));
	
	bs1 << 8;
	ASSERT_THAT(true == bs1.None());
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(OperatorRIGHT_SHIFT)
	const size_t size = 9;
	bool boolArr1[size] = {0,1,0,1,0,1,0,1,1};

	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	ASSERT_THAT((bs1[0] == false) && (bs1[1] == true));
	
	bs1 >> 1;
	ASSERT_THAT((bs1[0] == false) && (bs1[1] == false) && (bs1[2] == true) && (bs1[size-1] == true));
	
	bs1 >> 8;
	ASSERT_THAT(true == bs1.None());
END_UNIT
////////////////////////////////////////////////////////////////////////////
UNIT(Timed_Create_100000_BitSet)
	srand(time(NULL));
	const size_t size = 100000;
	clock_t t;
	
	bool boolArr1[size];
	for (size_t index = 0; index < size; ++index)
	{
		boolArr1[index] = (rand() % 2);
	}
	
	t = clock();
	advcpp::BitSet<size, unsigned char> bs1(boolArr1, size);
	t = clock() -t;
	std::cout << "advcpp::BitSet<size, unsigned char> bs1(boolArr1, size); " << size << " bits: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << std::endl;
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
	
	t = clock();
	bs1 & bs2;
	t = clock() -t;
	std::cout << "bs1 & bs2; " << size << " bits: " << ((float)t)/CLOCKS_PER_SEC << " seconds" << std::endl;
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
	TEST(OperatorSUBSCRIPT_returns_bool)
	TEST(OperatorSUBSCRIPT_returns_BitRef)
	TEST(OperatorLEFT_SHIFT)
	TEST(OperatorRIGHT_SHIFT)
	TEST(Timed_Create_100000_BitSet)
	TEST(Timed_And_100000_BitSet)
	TEST(Timed_And_100000_stdBitSet)
END_SUITE






