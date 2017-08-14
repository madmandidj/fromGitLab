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
	if (_firstKey == _secondKey)
	{
		return TRUE;
	}
	return FALSE;
}

void TestHashMapCreate()
{
	HashMap* map;
	size_t capacity = 3;

	map = HashMapCreate(capacity, (HashFunction)IntHashFunction, (EqualityFunction)IntEqualityFunction);
	printf("yo\n");
	HashMapDestroy(&map, NULL, NULL);
	printf("yo2\n");
	return;
}

int main()
{
	TestHashMapCreate();
	return 0;
}
