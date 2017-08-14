#include <stdio.h>
#include <stdlib.h>
#include "../../inc/HashMap.h"

#define TRUE 1
#define FALSE 0

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

void TestHashMapCreate()
{
	HashMap* map;
	size_t capacity = 3;
	int* key;
	int* value;
	int* elementValue;
	MapResult mapResult;
	int key2 = 11;
	
	key = malloc(sizeof(int));
	value = malloc(sizeof(int));
	*key = 11;
	*value = 11;
	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	mapResult = HashMapInsert(map, key, value);
	if (mapResult == MAP_SUCCESS)
	{
		printf("success\n");
	}
	mapResult = HashMapInsert(map, key, value);
	if (mapResult == MAP_KEY_DUPLICATE_ERROR)
	{
		printf("key duplicate error\n");
	}
	if (MAP_SUCCESS == HashMapFind(map, &key2, (void**)&elementValue))
	{
		printf("value found\n");
	}
	HashMapDestroy(&map, NULL, NULL);
	free(key);
	free(value);
	return;
}

int main()
{
	TestHashMapCreate();
	return 0;
}
