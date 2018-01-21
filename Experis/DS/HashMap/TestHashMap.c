#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../../inc/HashMap.h"

#define TRUE 1
#define FALSE 0

typedef struct Person Person;

struct Person
{
	char 	m_firstName[32];
	char 	m_lastName[32];
	int 	m_age;
};

/*****
PRINT HASHMAP ERROR FUNCTION
*****/
static void PrintErrResult(char* _testName, MapResult _err, MapResult _passErr)
{
    char errString[64];
    if (_err == _passErr)
    {
        printf("PASS: %s\n", _testName);
    }
    else
    {
        if (_err == MAP_SUCCESS)
        {
            strcpy(errString, "MAP_SUCCESS");
        }
        else if (_err == MAP_UNINITIALIZED_ERROR)
        {
           strcpy(errString, "MAP_UNINITIALIZED_ERROR");
        }
        else if (_err == MAP_KEY_NULL_ERROR)
        {
           strcpy(errString, "MAP_KEY_NULL_ERROR");
        }
        else if (_err == MAP_KEY_DUPLICATE_ERROR)
        {
           strcpy(errString, "MAP_KEY_DUPLICATE_ERROR");
		}
		else if (_err == MAP_KEY_NOT_FOUND_ERROR)
        {
           strcpy(errString, "MAP_KEY_NOT_FOUND_ERROR");
		}
		else if (_err == MAP_ALLOCATION_ERROR)
        {
           strcpy(errString, "MAP_ALLOCATION_ERROR");
        }
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAIL: %s %s\n", _testName, errString);
    }
    return;
}

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
static size_t* InitSizeTArr(size_t _numOfInts)
{
    size_t* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(size_t));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (size_t)index;
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

/*******************************/
static int* InitPersArr(size_t _numOfPers)
{
    Person* arr;
    size_t index;
    assert(0 != _numOfPers);

    arr = malloc(_numOfPers * sizeof(Person));
    if (NULL == arr)
    {
        return NULL;
    }
    
    for (index = 0; index < _numOfPers; ++index)
    {
        arr[index] = (int)index;
    }
    
    return arr;
}

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


/*
AUX FUNCTIONS
*/ 
static MapResult InsertTenKeyValPairsInt(HashMap* _map, size_t _hashSize, size_t* _keyArr, int* _valArr)
{
	size_t index;
	MapResult err = MAP_SUCCESS;
	for(index = 0; index < _hashSize; ++index)
	{
		if (MAP_SUCCESS != (err = HashMapInsert(_map, _keyArr + index, _valArr + index)))
		{
			return err;
		}
	}
	return err;
}




/****
HASHMAP INSERT TESTS
****/
static void TestHashMapInsert_TenIntsOneBucket()
{
	HashMap* map;
	size_t capacity = 1;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;
	MapStats stats;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	err = InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	stats = HashMapGetStatistics(map);
	if (10 == stats.m_maxChainLength)
	{
		printf("PASS: TestHashMapInsert_TenIntsOneBucket\n");
	}
	else
	{
		printf("FAIL: TestHashMapInsert_TenIntsOneBucket\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

static void TestHashMapInsert_TenIntsTwoBucket()
{
	HashMap* map;
	size_t capacity = 2;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;
	MapStats stats;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	err = InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	stats = HashMapGetStatistics(map);
	if (5 == stats.m_maxChainLength)
	{
		printf("PASS: TestHashMapInsert_TenIntsTwoBucket\n");
	}
	else
	{
		printf("FAIL: TestHashMapInsert_TenIntsTwoBucket\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

static void TestHashMapInsert_TenIntsTenBucket()
{
	HashMap* map;
	size_t capacity = 10;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;
	MapStats stats;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	err = InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	stats = HashMapGetStatistics(map);
	if (1 == stats.m_maxChainLength)
	{
		printf("PASS: TestHashMapInsert_TenIntsTenBucket\n");
	}
	else
	{
		printf("FAIL: TestHashMapInsert_TenIntsTenBucket\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

static void TestHashMapInsert_DuplicateKey()
{
	HashMap* map;
	size_t capacity = 10;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	err = HashMapInsert(map, keyArr + 5, valArr + 5);
	PrintErrResult("TestHashMapInsert_DuplicateKey", err, MAP_KEY_DUPLICATE_ERROR);
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}







/****
HASHMAP REHASH TESTS
****/
static void TestHashMapRehash_OneToFiveBucket()
{
	HashMap* map;
	size_t capacity = 1;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;
	MapStats stats;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	err = HashMapRehash(map, 5);
	stats = HashMapGetStatistics(map);
	if (2 == stats.m_maxChainLength)
	{
		printf("PASS: TestHashMapRehash_OneToFiveBucket\n");
	}
	else
	{
		printf("FAIL: TestHashMapRehash_OneToFiveBucket\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

static void TestHashMapRehash_FiveToOneBucket()
{
	HashMap* map;
	size_t capacity = 5;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;
	MapStats stats;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	err = HashMapRehash(map, 1);
	stats = HashMapGetStatistics(map);
	if (10 == stats.m_maxChainLength)
	{
		printf("PASS: TestHashMapRehash_FiveToOneBucket\n");
	}
	else
	{
		printf("FAIL: TestHashMapRehash_FiveToOneBucket\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}







/****
HASHMAP REMOVE TESTS
****/
static void TestHashMapRemove_KeyFound()
{
	HashMap* map;
	size_t capacity = 1;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	int* pKey;
	int* pValue;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	HashMapRemove(map, keyArr + 7, (void**)&pKey, (void**)&pValue);

	if (7 == *pValue)
	{
		printf("PASS: TestHashMapRemove_KeyFound\n");
	}
	else
	{
		printf("FAIL: TestHashMapRemove_KeyFound\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

static void TestHashMapRemove_KeyNotFound()
{
	HashMap* map;
	size_t capacity = 1;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	int* pKey;
	int* pValue;
	MapResult err;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts - 1, keyArr, valArr);
	err = HashMapRemove(map, keyArr + 9, (void**)&pKey, (void**)&pValue);
	PrintErrResult("TestHashMapRemove_KeyNotFound", err, MAP_KEY_NOT_FOUND_ERROR);
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}






/****
HASHMAP FIND TESTS
****/
static void TestHashMapFind_KeyFound()
{
	HashMap* map;
	size_t capacity = 1;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	int* pValue;
	MapResult err;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	err = HashMapFind(map, keyArr + 9, (void**)&pValue);
	PrintErrResult("TestHashMapFind_KeyFound", err, MAP_SUCCESS);
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}

static void TestHashMapFind_KeyNotFound()
{
	HashMap* map;
	size_t capacity = 1;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	int* pValue;
	MapResult err;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts - 1, keyArr, valArr);
	err = HashMapFind(map, keyArr + 9, (void**)&pValue);
	PrintErrResult("TestHashMapFind_KeyNotFound", err, MAP_KEY_NOT_FOUND_ERROR);
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}















/*
PERSON TESTS
*/
static void TestHashMapInsert_DuplicateKey()
{
	HashMap* map;
	size_t capacity = 10;
	size_t* keyArr;
	int* valArr;
	size_t numOfInts = 10;
	MapResult err;

	keyArr = InitSizeTArr(numOfInts);
	valArr = InitIntArr(numOfInts);
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	InsertTenKeyValPairsInt(map, numOfInts, keyArr, valArr);
	err = HashMapInsert(map, keyArr + 5, valArr + 5);
	PrintErrResult("TestHashMapInsert_DuplicateKey", err, MAP_KEY_DUPLICATE_ERROR);
	HashMapDestroy(&map, NULL, NULL);
	free(keyArr);
	free(valArr);
	return;
}





















int main()
{
	printf("\n");
	TestHashMapInsert_TenIntsOneBucket();
	TestHashMapInsert_TenIntsTwoBucket();
	TestHashMapInsert_TenIntsTenBucket();
	TestHashMapInsert_DuplicateKey();
	
	TestHashMapRehash_OneToFiveBucket();
	TestHashMapRehash_FiveToOneBucket();

	TestHashMapRemove_KeyFound();
	TestHashMapRemove_KeyNotFound();
	
	TestHashMapFind_KeyNotFound();
	TestHashMapFind_KeyFound();
	
	
	
	printf("\n");
	/*
	TODO:
	TestHashMapCreate_ZeroCap();
	TestHashMapCreate_NULLHashFunc();
	TestHashMapCreate_NULLEqualityFunc();
	
	TestHashMapDestroy_NULLMap();
	TestHashMapDestroy_Ints();
	TestHashMapDestroy_Persons();
	TestHashMapDestroy_DoubleDestroy();

	TestHashMapRehash_NULLMap();

	TestHashMapInsert_NULLMap();
	TestHashMapInsert_NULLKey();

	TestHashMapRemove_NULLMap();
	TestHashMapRemove_NULLSearchKey();
	TestHashMapRemove_NULLPKey();
	TestHashMapRemove_NULLPVal();



	*/
	return 0;
}






