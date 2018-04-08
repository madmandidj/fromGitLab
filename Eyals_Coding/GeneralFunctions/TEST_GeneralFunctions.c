#include "GeneralFunctions.h"
#include "../Data_Structures/inc/mu_test.h"
#include <stdio.h>
#include <limits.h>

UNIT(CreateAscendingIntArray_ZeroInts)
    int* intArr;
	intArr = CreateAscendingIntArray(0);
    ASSERT_THAT(NULL == intArr);
    DestroyIntArray(intArr);
END_UNIT

UNIT(CreateAscendingIntArray_1Int)
    int* intArr;
    size_t numOfInts = 1;
    size_t index;
	intArr = CreateAscendingIntArray(numOfInts);
    ASSERT_THAT(intArr);
    for (index = 0; index < numOfInts; ++index)
    {
    	ASSERT_THAT(intArr[index] == (int)index);
    }
    DestroyIntArray(intArr);
END_UNIT

UNIT(CreateAscendingIntArray_50000Int)
    int* intArr;
    size_t numOfInts = 50000;
    size_t index;
	intArr = CreateAscendingIntArray(numOfInts);
    ASSERT_THAT(intArr);
    for (index = 0; index < numOfInts; ++index)
    {
    	ASSERT_THAT(intArr[index] == (int)index);
    }
    DestroyIntArray(intArr);
END_UNIT


UNIT(CreateRandomIntArray_ZeroInts)
    int* intArr;
	intArr = CreateRandomIntArray(0,0,0);
    ASSERT_THAT(NULL == intArr);
    DestroyIntArray(intArr);
END_UNIT

UNIT(CreateRandomIntArray_1Int_minus10TOplus10)
    int* intArr;
    size_t numOfInts = 1;
    int minVal = -10;
    int maxVal = 10;
    size_t index;
	intArr = CreateRandomIntArray(numOfInts, minVal, maxVal);
	for (index = 0; index < numOfInts; ++index)
	{
	    ASSERT_THAT(intArr[index] >= minVal && intArr[index] <= maxVal);
	}
	DestroyIntArray(intArr);
END_UNIT

UNIT(CreateRandomIntArray_100Int_minus10TOplus10)
    int* intArr;
    size_t numOfInts = 100;
    int minVal = -10;
    int maxVal = 10;
    size_t index;
	intArr = CreateRandomIntArray(numOfInts, minVal, maxVal);
	for (index = 0; index < numOfInts; ++index)
	{
	    ASSERT_THAT(intArr[index] >= minVal && intArr[index] <= maxVal);
	}
	DestroyIntArray(intArr);
END_UNIT

UNIT(CreateRandomIntArray_100Int_minus10TOminus1)
    int* intArr;
    size_t numOfInts = 100;
    int minVal = -10;
    int maxVal = -1;
    size_t index;
	intArr = CreateRandomIntArray(numOfInts, minVal, maxVal);
	for (index = 0; index < numOfInts; ++index)
	{
	    ASSERT_THAT(intArr[index] >= minVal && intArr[index] <= maxVal);
	}
	DestroyIntArray(intArr);
END_UNIT

UNIT(CreateRandomIntArray_100Int_plus10TOplus14)
    int* intArr;
    size_t numOfInts = 100;
    int minVal = 10;
    int maxVal = 14;
    size_t index;
	intArr = CreateRandomIntArray(numOfInts, minVal, maxVal);
	for (index = 0; index < numOfInts; ++index)
	{
	    ASSERT_THAT(intArr[index] >= minVal && intArr[index] <= maxVal);
	}
	DestroyIntArray(intArr);
END_UNIT

UNIT(CreateRandomIntArray_100Int_Only0)
    int* intArr;
    size_t numOfInts = 100;
    int minVal = 0;
    int maxVal = 0;
    size_t index;
	intArr = CreateRandomIntArray(numOfInts, minVal, maxVal);
	for (index = 0; index < numOfInts; ++index)
	{
	    ASSERT_THAT(intArr[index] >= minVal && intArr[index] <= maxVal);
	}
	DestroyIntArray(intArr);
END_UNIT

UNIT(CreateRandomIntArray_100Int_OnlyMinus1)
    int* intArr;
    size_t numOfInts = 100;
    int minVal = -1;
    int maxVal = -1;
    size_t index;
	intArr = CreateRandomIntArray(numOfInts, minVal, maxVal);
	for (index = 0; index < numOfInts; ++index)
	{
	    ASSERT_THAT(intArr[index] >= minVal && intArr[index] <= maxVal);
	}
	DestroyIntArray(intArr);
END_UNIT

UNIT(CreateAscendingIntVector_100Int)
	Vector* vector;
	int* intArr;
	size_t numOfInts = 100;
	size_t index;
	int* curItem;
	vector = CreateAscendingIntVector(numOfInts, 0, &intArr);
	for (index = 0; index < numOfInts; ++index)
	{
		VectorGet(vector, index, (void**)&curItem);
		ASSERT_THAT(*curItem == index);
	}
	ASSERT_THAT(VectorItemsNum(vector) == numOfInts);
	DestroyIntVector(vector, intArr);
END_UNIT

UNIT(CreateRandomIntVector_100Int_minus10TOplus10)
	Vector* vector;
	int* intArr;
	size_t numOfInts = 100;
	int minVal = -10;
	int maxVal = 10;
	size_t index;
	int* curItem;
	vector = CreateRandomIntVector(numOfInts, minVal, maxVal, 0, &intArr);
	for (index = 0; index < numOfInts; ++index)
	{
		VectorGet(vector, index, (void**)&curItem);
		ASSERT_THAT(*curItem >= minVal && *curItem <= maxVal);
	}
	ASSERT_THAT(VectorItemsNum(vector) == numOfInts);
	DestroyIntVector(vector, intArr);
END_UNIT

UNIT(CopyCreateVector_100RandomInts)
	Vector* vector;
	Vector* copyVector;
	int* intArr;
	size_t numOfInts = 100;
	int minVal = -10;
	int maxVal = 10;
	vector = CreateRandomIntVector(numOfInts, minVal, maxVal, 0, &intArr);
	copyVector = CopyCreateVector(vector);
	ASSERT_THAT(1 == AreVectorsEqual(vector, copyVector, (IsEqualFunc)IsIntEqual));
	VectorDestroy(copyVector, NULL);
	DestroyIntVector(vector, intArr);
END_UNIT

UNIT(FlipVector_Ascending_100Int)
	Vector* vector;
	Vector* flippedVector;
	int* intArr;
	size_t numOfInts = 100;
	size_t indexVec = 0;
	size_t indexFlippedVec = numOfInts-1;
	int* curItem;
	int* curFlippedItem;
	vector = CreateAscendingIntVector(numOfInts, 0, &intArr);
	flippedVector = CopyCreateVector(vector);
	FlipVector(flippedVector);
	for (indexVec = 0; indexVec < numOfInts; ++indexVec)
	{
		VectorGet(vector, indexVec, (void**)&curItem);
		VectorGet(flippedVector, indexFlippedVec, (void**)&curFlippedItem);
		--indexFlippedVec;
		ASSERT_THAT(*curItem == *curFlippedItem);
	}
	DestroyIntVector(vector, intArr);
	VectorDestroy(flippedVector, NULL);
END_UNIT


TEST_SUITE(General Functions)

	TEST(CreateAscendingIntArray_ZeroInts)
    TEST(CreateAscendingIntArray_1Int)
    TEST(CreateAscendingIntArray_50000Int)
	TEST(CreateRandomIntArray_ZeroInts)
    TEST(CreateRandomIntArray_1Int_minus10TOplus10)
    TEST(CreateRandomIntArray_100Int_minus10TOplus10)
    TEST(CreateRandomIntArray_100Int_minus10TOminus1)
    TEST(CreateRandomIntArray_100Int_plus10TOplus14)
    TEST(CreateRandomIntArray_100Int_Only0)
    TEST(CreateRandomIntArray_100Int_OnlyMinus1)
    TEST(CreateAscendingIntVector_100Int)
    TEST(CreateRandomIntVector_100Int_minus10TOplus10)
    TEST(CopyCreateVector_100RandomInts)
    TEST(FlipVector_Ascending_100Int)
END_SUITE



