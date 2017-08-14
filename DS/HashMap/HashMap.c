
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
	const void* m_key;
	const void* m_val;
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






/**************
HASH MAP CREATE
**************/
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

static HashMap* AllocateHashMap(size_t _hashSize)
{
	HashMap* hashMap = NULL;
	size_t index;

	if (!(hashMap = malloc(sizeof(HashMap))))
	{
		return NULL;
	}
	
	if (!(hashMap->m_buckets = malloc(_hashSize * sizeof(List*))))
	{
		free(hashMap);
		return NULL;
	}
	
	for (index = 0; index < _hashSize; ++index)
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
	return hashMap;
}

static void InitHashMap(HashMap* _hashMap, HashFunction _hashFunc, EqualityFunction _keysEqualFunc, size_t _hashSize)
{
	_hashMap->m_magicNum = HASHMAP_MAGIC_NUM;
	_hashMap->m_hashSize = _hashSize;
	_hashMap->m_hashFunc = _hashFunc;
	_hashMap->m_keysEqualFunc = _keysEqualFunc;
	#ifndef NDEBUG
	_hashMap->m_mapStats.m_pairs = 0;
	_hashMap->m_mapStats.m_collisions = 0;
	_hashMap->m_mapStats.m_buckets = _hashSize;
	_hashMap->m_mapStats.m_chains = 0;
	_hashMap->m_mapStats.m_maxChainLength = 0;
	_hashMap->m_mapStats.m_averageChainLength = 0;
	#endif /* NDEBUG */
	return;
}


HashMap* HashMapCreate(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	HashMap* hashMap;
	size_t hashSize;
	
	if (0 == _capacity || IS_NULL(_hashFunc) || IS_NULL(_keysEqualFunc))
	{
		return NULL;
	}
	
	hashSize = CalcHashSize(_capacity);
	if (!(hashMap = AllocateHashMap(hashSize)))
	{
		return NULL;
	}
	
	InitHashMap(hashMap, _hashFunc, _keysEqualFunc, hashSize);
	return hashMap;
}












/**************
HASH MAP DESTROY
**************/
static void DestroyBuckets(HashMap** _map, KeyDestroy _keyDestroyFunc, ValDestroy _valDestroyFunc)
{
	size_t index;
	ListItr nodeSentinel;
	ListItr nodeItr;
	Data* data;
	
	for (index = 0; index < (*_map)->m_hashSize; ++index)
	{
		nodeSentinel = ListItrEnd((*_map)->m_buckets[index]);
		nodeItr = ListItrBegin((*_map)->m_buckets[index]);
		while(nodeItr != nodeSentinel)
		{
			data = (Data*) ListItrGet(nodeItr);
			if (!IS_NULL(_keyDestroyFunc))
			{
				_keyDestroyFunc((void*)data->m_key);
			}
			if (!IS_NULL(_valDestroyFunc))
			{
				_valDestroyFunc((void*)data->m_val);
			}
			nodeItr = ListItrNext(nodeItr);
		}
		ListDestroy(&((*_map)->m_buckets[index]), NULL);
	}
	return;
}

void HashMapDestroy(HashMap** _map, KeyDestroy _keyDestroyFunc, ValDestroy _valDestroyFunc)
{

	if (IS_NULL(_map) || !IS_A_HASHMAP(*_map))
	{
		return;
	}
	
	DestroyBuckets(_map, _keyDestroyFunc, _valDestroyFunc);
	free((*_map)->m_buckets);
	free(*_map);
	*_map = NULL;
}










/**************
HASH MAP INSERT
**************/
static size_t CalculateBucketIndex(HashMap* _map, const void* _key)
{
	size_t hashFuncResult;
	
	hashFuncResult = _map->m_hashFunc(_key);
	return hashFuncResult % _map->m_hashSize;
}

static ListItr FindKeyDuplicateInBucket(HashMap* _map, const void* _key, size_t _bucketIndex)
{
	ListItr nodeItr;
	ListItr nodeSentinel;
	Data* itrData;
	
	nodeSentinel = ListItrEnd(_map->m_buckets[_bucketIndex]);
	nodeItr = ListItrBegin(_map->m_buckets[_bucketIndex]);
	while(nodeItr != nodeSentinel)
	{
		itrData = (Data*) ListItrGet(nodeItr);
		if (_map->m_keysEqualFunc((void*)itrData->m_key, _key))
		{
			return nodeItr;
		}
		nodeItr = ListItrNext(nodeItr);
	}
	return NULL;
}

static MapResult CreateAndInsertElement(HashMap* _map, const void* _key, const void* _value, size_t _bucketIndex)
{
	Data* data;
	
	if (!(data = malloc(sizeof(Data))))
	{
		return MAP_ALLOCATION_ERROR;
	}
	data->m_key = _key;
	data->m_val = _value;
	ListPushHead(_map->m_buckets[_bucketIndex], (void*) data);
	return MAP_SUCCESS;
}

MapResult HashMapInsert(HashMap* _map, const void* _key, const void* _value)
{
	size_t bucketIndex;
	size_t chainLength;

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (IS_NULL(_key))
	{
		return MAP_KEY_NULL_ERROR;
	}

	bucketIndex = CalculateBucketIndex(_map, _key);
	
	if (FindKeyDuplicateInBucket(_map, _key, bucketIndex))
	{
		return MAP_KEY_DUPLICATE_ERROR;
	}
	
	if (MAP_ALLOCATION_ERROR == CreateAndInsertElement(_map, _key, _value, bucketIndex))
	{
		return MAP_ALLOCATION_ERROR;
	}
	
	#ifndef NDEBUG
	++_map->m_mapStats.m_pairs;
	chainLength = ListCountItems(_map->m_buckets[_bucketIndex]);
	if (1 == chainLength)
	{
		++_map->m_mapStats.m_chains;
	}
	if (1 < chainLength)
	{
		++_map->m_mapCollisions;
	}
/*	if (_map->m_mapStats.m_maxChainLength < chainLength)*/
/*	{*/
/*		_map->m_mapStats.m_maxChainLength = chainLength;*/
/*	}*/
	_map->m_mapStats.m_averageChainLength = _map->m_mapStats.m_pairs / _map->m_mapStats.m_buckets;
	#endif */ /* NDEBUG */
	return MAP_SUCCESS;
}








/**************
HASH MAP FIND
**************/
MapResult HashMapFind(const HashMap* _map, const void* _searchKey, void** _pValue)
{
	size_t bucketIndex;
	ListItr itrFound = NULL;

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if (IS_NULL(_searchKey))
	{
		return MAP_KEY_NULL_ERROR;
	}
	
	bucketIndex = CalculateBucketIndex((HashMap*)_map, _searchKey);
	
	if ((itrFound = FindKeyDuplicateInBucket((HashMap*)_map, _searchKey, bucketIndex)))
	{
		*_pValue = (void*)((Data*)itrFound)->m_val;
		return MAP_SUCCESS; 
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}













/**************
HASH MAP REMOVE
**************/
MapResult HashMapRemove(HashMap* _map, const void* _searchKey, void** _pKey, void** _pValue)
{
	size_t bucketIndex;
	ListItr itrFound = NULL;
	Data* removedData;

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if (IS_NULL(_searchKey))
	{
		return MAP_KEY_NULL_ERROR;
	}
	
	bucketIndex = CalculateBucketIndex((HashMap*)_map, _searchKey);
	
	if ((itrFound = FindKeyDuplicateInBucket((HashMap*)_map, _searchKey, bucketIndex)))
	{
		removedData = (Data*)ListItrRemove(itrFound);
		*_pKey = removedData->m_key;
		*_pValue = removedData->m_val;
		#ifndef NDEBUG
		--_map->m_mapStats.m_pairs;
		chainLength = ListCountItems(_map->m_buckets[_bucketIndex]);
		if (0 == chainLength)
		{
			--_map->m_mapStats.m_chains;
		}
		if (1 < chainLength)
		{
			--_map->m_mapCollisions;
		}
/*		if (_map->m_mapStats.m_maxChainLength < chainLength)*/
/*		{*/
/*			_map->m_mapStats.m_maxChainLength = chainLength;*/
/*		}*/
		_map->m_mapStats.m_averageChainLength = _map->m_mapStats.m_pairs / _map->m_mapStats.m_buckets;
		#endif */ /* NDEBUG */
		return MAP_SUCCESS; 
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}





/**************
HASH MAP FOR EACH
**************/
size_t HashMapForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	size_t index;
	size_t count = 0;
	
	for (index = 0; _map->m_hashSize; ++index)
	{
/*		if(!ListForEach(_map->m_buckets[index], _action, _context))*/
/*		{*/
/*			return count;*/
/*		}*/
/*		++count;*/
	}
	return count;
}




/**************
HASH MAP GET STATISTICS
**************/
MapStats HashMapGetStatistics(const HashMap* _map)
{
	MapStats mapStats;
	
	if (!IS_A_MAP(_map))
	{
		return NULL;
	}
	
	if (_map->m_mapStats.m_maxChainLength < chainLength)
	{
		_map->m_mapStats.m_maxChainLength = chainLength;
	}
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







