
#include "../../inc/HashMap.h"
#include "../../inc/list_itr.h"
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define HASHMAP_MAGIC_NUM 0x05566770
#define IS_NULL(A) 	(NULL == (A))
#define IS_A_HASHMAP(H) ((H) && HASHMAP_MAGIC_NUM == (H)->m_magicNum)


typedef struct Data
{
	void* m_key;
	void* m_val;
}Data;

struct HashMap
{
	int m_magicNum;
	List** 	m_buckets;
	size_t m_hashSize;
	HashFunction m_hashFunc;
	EqualityFunction m_keysEqualFunc;
	#ifndef NDEBUG
	MapStats m_mapStats;
	#endif /* NDEBUG */
};



static size_t CalcHashSize(size_t _num)
{
    int isPrime = 0;
    size_t i;
    _num *= 1.3;

    while (!isPrime)
    {
        isPrime = 1;   
        for (i = 2; i < sqrt(_num) ; ++i)
        {
            if (_num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        ++_num;
    }
    return _num;
}



HashMap* HashMapCreate(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	HashMap* hashMap;
	size_t hashSize;
	size_t index;
	
	if (0 == _capacity || IS_NULL(_hashFunc) || IS_NULL(_keysEqualFunc))
	{
		return NULL;
	}
	
	if (!(hashMap = malloc(sizeof(HashMap*))))
	{
		return NULL;
	}
	
	hashSize = CalcHashSize(_capacity);
	if (!(hashMap->m_buckets = malloc(hashSize * sizeof(List*))))
	{
		free(hashMap);
		return NULL;
	}
	
	for (index = 0; index < hashSize; ++index)
	{
		if (!(hashMap->m_buckets[index] = ListCreate()))
		{
			--index;
			while (index != 0)
			{
				ListDestroy(&(hashMap->m_buckets[index]), NULL);
				--index;
			}
			ListDestroy(&(hashMap->m_buckets[index]), NULL);
			free(hashMap->m_buckets);
			free(hashMap);
			return NULL;
		}
	}
	
	hashMap->m_magicNum = HASHMAP_MAGIC_NUM;
	hashMap->m_hashSize = hashSize;
	hashMap->m_hashFunc = _hashFunc;
	hashMap->m_keysEqualFunc = _keysEqualFunc;
	#ifndef NDEBUG
	hashMap->m_mapStats.m_pairs = 0;
	hashMap->m_mapStats.m_collisions = 0;
	hashMap->m_mapStats.m_buckets = hashSize;
	hashMap->m_mapStats.m_chains = 0;
	hashMap->m_mapStats.m_maxChainLength = 0;
	hashMap->m_mapStats.m_averageChainLength = 0;
	#endif /* NDEBUG */
	return hashMap;
}



void HashMapDestroy(HashMap** _map, KeyDestroy _keyDestroyFunc, ValDestroy _valDestroyFunc)
{
	size_t index;
	ListItr nodeSentinel;
	ListItr nodeItr;
	Data* data;
	
	if (IS_NULL(_map) || !IS_A_HASHMAP(*_map))
	{
		return;
	}
	
	for (index = 0; index < (*_map)->m_hashSize; ++index)
	{
		nodeSentinel = ListItrEnd((*_map)->m_buckets[index]);
		nodeItr = ListItrBegin((*_map)->m_buckets[index]);
		while(nodeItr != nodeSentinel)
		{
			data = (Data*) ListItrGet(nodeItr);
			if (!IS_NULL(_keyDestroyFunc))
			{
				_keyDestroyFunc(data->m_key);
			}
			if (!IS_NULL(_valDestroyFunc))
			{
				_valDestroyFunc(data->m_val);
			}
			nodeItr = ListItrNext(nodeItr);
		}
		ListDestroy(&((*_map)->m_buckets[index]), NULL);
	}
	free((*_map)->m_buckets);
	free(*_map);
	*_map = NULL;
}

MapResult HashMapInsert(HashMap* _map, const void* _key, const void* _value)
{
	size_t hashFuncResult;
	size_t bucketIndex;
	ListItr nodeItr;
	ListItr nodeSentinel;
	Data* data;

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (IS_NULL(_key))
	{
		return MAP_KEY_NULL_ERROR;
	}

	hashFuncResult = _map->m_hashFunc(_key);
	bucketIndex = hashFuncResult % _map->m_hashSize;
	nodeSentinel = ListItrEnd(_map->m_buckets[bucketIndex]);
	nodeItr = ListItrBegin(_map->m_buckets[bucketIndex]);
	while(nodeItr != nodeSentinel)
	{
		data = (Data*) ListItrGet(nodeItr);
		if (_map->m_keysEqualFunc((void*)data->m_key, _key))
		{
			return MAP_KEY_DUPLICATE_ERROR;
		}
		nodeItr = ListItrNext(nodeItr);
	}
	if (!(data = malloc(sizeof(Data))))
	{
		return MAP_ALLOCATION_ERROR;
	}
	ListPushHead(_map->m_buckets[bucketIndex], (void*) data);
	return MAP_SUCCESS;
}

MapResult HashMapRemove(HashMap* _map, const void* _searchKey, void** _pKey, void** _pValue)
{
	size_t hashFuncResult;
	size_t bucketIndex;
	ListItr nodeItr;
	ListItr nodeSentinel;
	Data* data;

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (IS_NULL(_pKey))
	{
		return MAP_KEY_NULL_ERROR;
	}

	hashFuncResult = _map->m_hashFunc(_key);
	bucketIndex = hashFuncResult % _map->m_hashSize;
	for (index = 0; index < (*_map)->m_hashSize; ++index)
	{
		nodeSentinel = ListItrEnd(_map->m_buckets[bucketIndex]);
		nodeItr = ListItrBegin(_map->m_buckets[bucketIndex]);
		while(nodeItr != nodeSentinel)
		{
			data = (Data*)ListItrGet(nodeItr);
			if (_map->m_keysEqualFunc((void*)data->m_key, _key))
			{
				*_pKey = data->m_key;
				*_pVal = data->m_val;
				/*
				Need to free key-val pair?
				*/
				ListItrRemove(nodeItr);
				return MAP_SUCCESS;
			}
			nodeItr = ListItrNext(nodeItr);
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}

MapResult HashMapFind(const HashMap* _map, const void* _searchKey, void** _pValue)
{
	size_t hashFuncResult;
	size_t bucketIndex;
	ListItr nodeItr;
	ListItr nodeSentinel;
	Data* data;

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (IS_NULL(_pKey))
	{
		return MAP_KEY_NULL_ERROR;
	}

	hashFuncResult = _map->m_hashFunc(_key);
	bucketIndex = hashFuncResult % _map->m_hashSize;
	for (index = 0; index < (*_map)->m_hashSize; ++index)
	{
		nodeSentinel = ListItrEnd(_map->m_buckets[bucketIndex]);
		nodeItr = ListItrBegin(_map->m_buckets[bucketIndex]);
		while(nodeItr != nodeSentinel)
		{
			data = (Data*)ListItrGet(nodeItr);
			if (_map->m_keysEqualFunc((void*)data->m_key, _key))
			{
				*_pKey = data->m_key;
				*_pVal = data->m_val;
				return MAP_SUCCESS;
			}
			nodeItr = ListItrNext(nodeItr);
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}

/*


MapResult HashMapRehash(HashMap *_map, size_t newCapacity)
{
	
	ReHashCheckParams();
	CreateNewHashMap();
	InsertAllElements();
	
}
*/
size_t HashMapSize(const HashMap* _map)
{
	if (!IS_A_HASHMAP(_map))
	{
		return 0;
	}
	
	return _map->m_hashSize;
}







