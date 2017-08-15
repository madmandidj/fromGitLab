#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../inc/HashMap.h"

#define TRUE 1
#define FALSE 0

/*****
INIT FUNCTIONS
*****/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    return arr;
}
/*******************************/

size_t IntHashFunction(const size_t* _key)
{
	return *_key;
}

int IntEqualityFunction(const int* _firstKey, const int* _secondKey)
{
	if (*_firstKey == *_secondKey)
	{
		return TRUE;
	}
	return FALSE;
}



/*
KEY VALUE FUNCTIONS
*/ 
int PrintKeysAndValuesInt(const int* _key, int* _value, void* _context)
{
	printf("key = %d, val = %d\n",*_key, *_value);
	return 1;
}

void TestHashMapCreate()
{
	HashMap* map;
	size_t capacity = 3;
	int* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	int* elementValue;
	int* pKey;
	int* pValue;
	MapResult mapResult;
	MapStats mapStats;
	
	keyArr = InitIntArr(numOfInts);
	valArr = InitIntArr(numOfInts);

	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	mapResult = HashMapInsert(map, keyArr, valArr);
	if (mapResult == MAP_SUCCESS)
	{
		printf("success\n");
	}
	
	mapResult = HashMapInsert(map, keyArr + 1, valArr + 1);
	mapResult = HashMapInsert(map, keyArr + 2, valArr + 2);
	mapResult = HashMapInsert(map, keyArr + 3, valArr + 3);
	mapResult = HashMapInsert(map, keyArr + 4 , valArr + 4);
	mapResult = HashMapInsert(map, keyArr + 5 , valArr + 5);
	mapResult = HashMapInsert(map, keyArr + 6 , valArr + 6);
	mapResult = HashMapInsert(map, keyArr + 7 , valArr + 7);
	mapResult = HashMapInsert(map, keyArr + 8 , valArr + 8);
	mapResult = HashMapInsert(map, keyArr + 9 , valArr + 9);
	mapResult = HashMapInsert(map, keyArr , valArr);
	if (mapResult == MAP_KEY_DUPLICATE_ERROR)
	{
		printf("key duplicate error\n");
	}
	if (MAP_SUCCESS == HashMapFind(map, keyArr + 7, (void**)&elementValue))
	{
		printf("value found\n");
	}
	
	mapResult = HashMapRemove(map, keyArr + 7, (void**)&pKey, (void**)&pValue);
	if (mapResult == MAP_KEY_NOT_FOUND_ERROR)
	{
	printf("key not found\n");
	}
	
	HashMapForEach(map, (KeyValueActionFunction) PrintKeysAndValuesInt, NULL);
	mapStats = HashMapGetStatistics(map);
	printf("pairs: %u\n", mapStats.m_pairs);
	printf("m_collisions: %u\n", mapStats.m_collisions);
	printf("m_buckets: %u\n", mapStats.m_buckets);
	printf("m_chains: %u\n", mapStats.m_chains);
	printf("m_maxChainLength: %u\n", mapStats.m_maxChainLength);
	printf("m_averageChainLength: %u\n", mapStats.m_averageChainLength);
	printf("\n");
	
	mapResult = HashMapRehash(map, 9);
	if (mapResult == MAP_SUCCESS)
	{
		printf("Rehash success\n");
	}
	HashMapForEach(map, (KeyValueActionFunction) PrintKeysAndValuesInt, NULL);

	mapStats = HashMapGetStatistics(map);
	printf("pairs: %u\n", mapStats.m_pairs);
	printf("m_collisions: %u\n", mapStats.m_collisions);
	printf("m_buckets: %u\n", mapStats.m_buckets);
	printf("m_chains: %u\n", mapStats.m_chains);
	printf("m_maxChainLength: %u\n", mapStats.m_maxChainLength);
	printf("m_averageChainLength: %u\n", mapStats.m_averageChainLength);
	printf("\n");

	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

int main()
{
	TestHashMapCreate();


	/*
	TestHashMapCreate_ZeroCap();
	TestHashMapCreate_NULLHashFunc();
	TestHashMapCreate_NULLEqualityFunc();
	TestHashMapCreate_CapacityOne();
	TestHashMapCreate_CapacityTwo();
	TestHashMapCreate_CapacityTen();

	TestHashMapDestroy_NULLMap();
	TestHashMapDestroy_Ints();
	TestHashMapDestroy_Persons();
	TestHashMapDestroy_DoubleDestroy();

	TestHashMapRehash_NULLMap();
	TestHashMapRehash_SmallerCap();
	TestHashMapRehash_LargerCap();

	TestHashMapInsert_NULLMap();
	TestHashMapInsert_NULLKey();
	TestHashMapInsert_TenDistinctKeys();
	TestHashMapInsert_DuplicateKey();

	TestHashMapRemove_NULLMap();
	TestHashMapRemove_NULLSearchKey();
	TestHashMapRemove_NULLPKey();
	TestHashMapRemove_NULLPVal();
	TestHashMapRemove_KeyNotFound();
	TestHashMapRemove_KeyFound();



	*/
	return 0;
}
