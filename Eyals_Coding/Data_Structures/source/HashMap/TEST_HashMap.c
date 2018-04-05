#include "../../inc/HashMap.h"
#include "../../inc/mu_test.h"
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
END_UNIT

UNIT(HashMap_Create_1Capacity)
    HashMap* hashMap;
    size_t capacity = 1;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MyStringHashFunc, (EqualityFunc)MyStringKeyEqualFunc);
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
/*    GetAndPrintMapStats(hashMap);*/
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Create_32Capacity)
    HashMap* hashMap;
    size_t capacity = 32;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MyStringHashFunc, (EqualityFunc)MyStringKeyEqualFunc);
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
/*    GetAndPrintMapStats(hashMap);*/
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_1Pair_StrKey)
    HashMap* hashMap;
    size_t capacity = 32;
    char* key1 = "Eyal";
    int val1 = 10;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MyStringHashFunc, (EqualityFunc)MyStringKeyEqualFunc);
	HashMapInsert(hashMap, (Key_t)key1, (Value_t)&val1);
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    GetAndPrintMapStats(hashMap);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT

UNIT(HashMap_Insert_1Pair_SizetKey)
    HashMap* hashMap;
    size_t capacity = 32;
    size_t key1 = 0;
    int val1 = 10;
    
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
	HashMapInsert(hashMap, (Key_t)&key1, (Value_t)&val1);
	    
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    GetAndPrintMapStats(hashMap);
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
    
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
	HashMapInsert(hashMap, (Key_t)&key1, (Value_t)&val1);
	HashMapInsert(hashMap, (Key_t)&key2, (Value_t)&val2);
	
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    GetAndPrintMapStats(hashMap);
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
    
    hashMap = HashMapCreate(capacity, (HashFunc)MySizetHashFunc, (EqualityFunc)MySizetEqualFunc);
	HashMapInsert(hashMap, (Key_t)&key1, (Value_t)&val1);
	HashMapInsert(hashMap, (Key_t)&key2, (Value_t)&val2);
	HashMapInsert(hashMap, (Key_t)&key3, (Value_t)&val3);
	
    ASSERT_THAT(hashMap);
    #ifndef NDEBUG
    GetAndPrintMapStats(hashMap);
    #endif /* NDEBUG */
    HashMapDestroy(hashMap, NULL, NULL);
END_UNIT







TEST_SUITE(HashMap Tests)

	TEST(HashMap_Create_InvalidArguments)	
	TEST(HashMap_Create_1Capacity)
	TEST(HashMap_Create_32Capacity)
	TEST(HashMap_Insert_1Pair_StrKey)
	TEST(HashMap_Insert_1Pair_SizetKey)
	TEST(HashMap_Insert_2Pair_SizetKey)
	TEST(HashMap_Insert_3Pair_1Collision_SizetKey)
	
END_SUITE

