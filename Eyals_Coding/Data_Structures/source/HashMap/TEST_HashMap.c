#include "../../inc/HashMap.h"
#include "../../inc/mu_test.h"
#include "../../../GeneralFunctions/GeneralFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#define NDEBUG 1*/

typedef struct Person Person;
struct Person
{
    size_t m_age;
    size_t m_gender;
    Person* m_mother;  
};

void DeletePerson(Person* _personPtr)
{
    free(((Person*)_personPtr)->m_mother);
}

void PrintInt(int* _intPtr)
{
    printf("%u\n", *(size_t*)_intPtr);
}
/********************************
********************************/
unsigned long MyStringHashFunc(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + (long unsigned int)c; /* hash * 33 + c */
	}
    return hash;
}

int MyStringKeyEqualFunc(char* _keyL, char* _keyR)
{
	return !strcmp(_keyL, _keyR) ? 1 : 0;
}

size_t MySizetHashFunc(size_t* _num)
{
	return *_num;
}

int MySizetEqualFunc(size_t* _keyL, size_t* _keyR)
{
	return *_keyL == *_keyR;
}

#ifndef NDEBUG
static void GetAndPrintMapStats(HashMap* _hashMap)
{
	MapStats mapStats;
	if (!_hashMap)
	{
		return;
	}
	mapStats = HashMapGetStatistics(_hashMap);
	printf("Pairs: %u\n", mapStats.m_pairs);
	printf("Collisions: %u\n", mapStats.m_collisions);
	printf("Buckets: %u\n", mapStats.m_buckets);
	printf("Chains: %u\n", mapStats.m_chains);
	printf("Max Chain Length: %u\n", mapStats.m_maxChainLength);
	printf("Avg. Chain Length: %f\n", mapStats.m_averageChainLength);
}
#endif /* NDEBUG */

/********************************
********************************/




UNIT(HashMap_Create_InvalidArguments)
    HashMap* hashMap;
    
    hashMap = HashMapCreate(0, NULL, NULL);
    ASSERT_THAT(!hashMap);
    HashMapDestroy(hashMap, NULL, NULL);
     #ifndef NDEBUG
    GetAndPrintMapStats(NULL);
    #endif /* NDEBUG */
END_UNIT

UNIT(HashMap_Create_1Capacity)
    HashMap* hashMap;
    size_t capacity = 1;
    MapStats mapStats;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MyStringHashFunc, (EqualityFunc)MyStringKeyEqualFunc);
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(0 == mapStats.m_pairs);
    ASSERT_THAT(0 == mapStats.m_collisions);
    ASSERT_THAT(11 == mapStats.m_buckets);
    ASSERT_THAT(0 == mapStats.m_chains);
    ASSERT_THAT(0 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Create_32Capacity)
    HashMap* hashMap;
    size_t capacity = 32;
    MapStats mapStats;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MyStringHashFunc, (EqualityFunc)MyStringKeyEqualFunc);
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
	ASSERT_THAT(0 == mapStats.m_pairs);
    ASSERT_THAT(0 == mapStats.m_collisions);
    ASSERT_THAT(37 == mapStats.m_buckets);
    ASSERT_THAT(0 == mapStats.m_chains);
    ASSERT_THAT(0 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_1Pair_StrKey)
    HashMap* hashMap;
    size_t capacity = 32;
    char* key1 = "Eyal";
    int val1 = 10;
    char* returnedKey = NULL;
    int* returnedVal = NULL;
    MapStats mapStats;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MyStringHashFunc, (EqualityFunc)MyStringKeyEqualFunc);
	HashMapInsert(hashMap, (Key_t*)key1, (Value_t*)&val1);
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(1 == mapStats.m_pairs);
    ASSERT_THAT(0 == mapStats.m_collisions);
    ASSERT_THAT(37 == mapStats.m_buckets);
    ASSERT_THAT(1 == mapStats.m_chains);
    ASSERT_THAT(1 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapRemove(hashMap, (Key_t*)key1, (Key_t**)&returnedKey, (Value_t**)&returnedVal);
    ASSERT_THAT(0 == strcmp(key1, returnedKey));
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_1Pair_SizetKey)
    HashMap* hashMap;
    size_t capacity = 32;
    size_t key1 = 0;
    int val1 = 10;
    MapStats mapStats;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
	HashMapInsert(hashMap, (Key_t*)&key1, (Value_t*)&val1);
	    
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(1 == mapStats.m_pairs);
    ASSERT_THAT(0 == mapStats.m_collisions);
    ASSERT_THAT(37 == mapStats.m_buckets);
    ASSERT_THAT(1 == mapStats.m_chains);
    ASSERT_THAT(1 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_2Pair_SizetKey)
    HashMap* hashMap;
    size_t capacity = 32;
    size_t key1 = 0;
    size_t key2 = 1;
    int val1 = 10;
    int val2 = 20;
    MapStats mapStats;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
	HashMapInsert(hashMap, (Key_t*)&key1, (Value_t*)&val1);
	HashMapInsert(hashMap, (Key_t*)&key2, (Value_t*)&val2);
	
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(2 == mapStats.m_pairs);
    ASSERT_THAT(0 == mapStats.m_collisions);
    ASSERT_THAT(37 == mapStats.m_buckets);
    ASSERT_THAT(2 == mapStats.m_chains);
    ASSERT_THAT(1 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_3Pair_1Collision_SizetKey)
    HashMap* hashMap;
    size_t capacity = 32;
    size_t key1 = 0;
    size_t key2 = 1;
    size_t key3 = 37;
    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    MapStats mapStats;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
	HashMapInsert(hashMap, (Key_t*)&key1, (Value_t*)&val1);
	HashMapInsert(hashMap, (Key_t*)&key2, (Value_t*)&val2);
	HashMapInsert(hashMap, (Key_t*)&key3, (Value_t*)&val3);
	
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(3 == mapStats.m_pairs);
    ASSERT_THAT(1 == mapStats.m_collisions);
    ASSERT_THAT(37 == mapStats.m_buckets);
    ASSERT_THAT(2 == mapStats.m_chains);
    ASSERT_THAT(2 == mapStats.m_maxChainLength);
    ASSERT_THAT(1.5 == mapStats.m_averageChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_22Pair_11buckets_11Collisions_IntKey)
    HashMap* hashMap;
    size_t capacity = 10;
    size_t numOfPairs = 22;
    int* keyArr;
    int* valArr;
    size_t index;
    MapStats mapStats;
    
    keyArr = CreateAscendingIntArray(numOfPairs);
    valArr = CreateRandomIntArray(numOfPairs, -1000, 1000);
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
    for (index = 0; index < numOfPairs; ++index)
    {	
		HashMapInsert(hashMap, (Key_t*)(keyArr + index), (Value_t*)(valArr + index));
    }
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(22 == mapStats.m_pairs);
    ASSERT_THAT(11 == mapStats.m_collisions);
    ASSERT_THAT(11 == mapStats.m_buckets);
    ASSERT_THAT(11 == mapStats.m_chains);
    ASSERT_THAT(2 == mapStats.m_maxChainLength);
    ASSERT_THAT(2 == mapStats.m_averageChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
    DestroyIntArray(keyArr);
    DestroyIntArray(valArr);
END_UNIT

UNIT(HashMap_Remove_21Pair_11buckets_10Collisions_IntKey)
    HashMap* hashMap;
    size_t capacity = 10;
    size_t numOfPairs = 22;
    int* keyArr;
    int* valArr;
    size_t index;
    int* removedKey;
    int* removedVal;
    MapStats mapStats;
    
    keyArr = CreateAscendingIntArray(numOfPairs);
    valArr = CreateRandomIntArray(numOfPairs, -1000, 1000);
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
    for (index = 0; index < numOfPairs; ++index)
    {	
		HashMapInsert(hashMap, (Key_t*)(keyArr + index), (Value_t*)(valArr + index));
    }
    HashMapRemove(hashMap, (Key_t*)(keyArr + 14), (Key_t*)&removedKey, (Value_t*)&removedVal);
    ASSERT_THAT(14 == *removedKey);
    ASSERT_THAT(valArr[14] == *removedVal);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(21 == mapStats.m_pairs);
    ASSERT_THAT(10 == mapStats.m_collisions);
    ASSERT_THAT(11 == mapStats.m_buckets);
    ASSERT_THAT(11 == mapStats.m_chains);
    ASSERT_THAT(2 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
    DestroyIntArray(keyArr);
    DestroyIntArray(valArr);
END_UNIT

UNIT(HashMap_Remove_21Pair_11buckets_10Collisions_IntKey_NotFound)
    HashMap* hashMap;
    size_t capacity = 10;
    size_t numOfPairs = 22;
    int* keyArr;
    int* valArr;
    size_t index;
    int* removedKey;
    int* removedVal;
    int notFoundKey = 2345;
    ADTErr err;
    MapStats mapStats;
    
    keyArr = CreateAscendingIntArray(numOfPairs);
    valArr = CreateRandomIntArray(numOfPairs, -1000, 1000);
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
    for (index = 0; index < numOfPairs; ++index)
    {	
		HashMapInsert(hashMap, (Key_t*)(keyArr + index), (Value_t*)(valArr + index));
    }
    HashMapRemove(hashMap, (Key_t*)(keyArr + 14), (Key_t*)&removedKey, (Value_t*)&removedVal);
    ASSERT_THAT(14 == *removedKey);
    ASSERT_THAT(valArr[14] == *removedVal);
    err =HashMapRemove(hashMap, (Key_t*)(&notFoundKey), (Key_t*)&removedKey, (Value_t*)&removedVal);
    ASSERT_THAT(ERR_MAP_KEY_NOT_FOUND== err);
    ASSERT_THAT(NULL == removedKey);
    ASSERT_THAT(NULL == removedVal);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(21 == mapStats.m_pairs);
    ASSERT_THAT(10 == mapStats.m_collisions);
    ASSERT_THAT(11 == mapStats.m_buckets);
    ASSERT_THAT(11 == mapStats.m_chains);
    ASSERT_THAT(2 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapRemove(hashMap, (Key_t*)(keyArr + 11), (Key_t*)&removedKey, (Value_t*)&removedVal);
    ASSERT_THAT(11 == *removedKey);
    ASSERT_THAT(valArr[11] == *removedVal);
    HashMapRemove(hashMap, (Key_t*)(keyArr + 4), (Key_t*)&removedKey, (Value_t*)&removedVal);
    ASSERT_THAT(4 == *removedKey);
    ASSERT_THAT(valArr[4] == *removedVal);
    HashMapDestroy(hashMap, NULL, NULL);
    DestroyIntArray(keyArr);
    DestroyIntArray(valArr);
END_UNIT


UNIT(HashMap_Rehash_33Pair33_11buckets22_22Collisions11_IntKey)
    HashMap* hashMap;
    size_t capacity = 10;
    size_t reHashCap = 22;
    size_t numOfPairs = 33;
    int* keyArr;
    int* valArr;
    size_t index;
/*    int* removedKey;*/
/*    int* removedVal;*/
    MapStats mapStats;
    
    keyArr = CreateAscendingIntArray(numOfPairs);
    valArr = CreateRandomIntArray(numOfPairs, -1000, 1000);
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
    for (index = 0; index < numOfPairs; ++index)
    {	
		HashMapInsert(hashMap, (Key_t*)(keyArr + index), (Value_t*)(valArr + index));
    }
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(33 == mapStats.m_pairs);
    ASSERT_THAT(22 == mapStats.m_collisions);
    ASSERT_THAT(11 == mapStats.m_buckets);
    ASSERT_THAT(11 == mapStats.m_chains);
    ASSERT_THAT(3 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapRehash(&hashMap, reHashCap);
    #ifndef NDEBUG
    mapStats = HashMapGetStatistics(hashMap);
    ASSERT_THAT(33 == mapStats.m_pairs);
    ASSERT_THAT(8 == mapStats.m_collisions);
    ASSERT_THAT(25 == mapStats.m_buckets);
    ASSERT_THAT(25 == mapStats.m_chains);
    ASSERT_THAT(2 == mapStats.m_maxChainLength);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
    DestroyIntArray(keyArr);
    DestroyIntArray(valArr);
END_UNIT


TEST_SUITE(HashMap Tests)

	TEST(HashMap_Create_InvalidArguments)	
	TEST(HashMap_Create_1Capacity)
	TEST(HashMap_Create_32Capacity)
	TEST(HashMap_Insert_1Pair_StrKey)
	TEST(HashMap_Insert_1Pair_SizetKey)
	TEST(HashMap_Insert_2Pair_SizetKey)
	TEST(HashMap_Insert_3Pair_1Collision_SizetKey)
	TEST(HashMap_Insert_22Pair_11buckets_11Collisions_IntKey)
	TEST(HashMap_Remove_21Pair_11buckets_10Collisions_IntKey)
	TEST(HashMap_Remove_21Pair_11buckets_10Collisions_IntKey_NotFound)
	TEST(HashMap_Rehash_33Pair33_11buckets22_22Collisions11_IntKey)
	
END_SUITE

