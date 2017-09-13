
#include "../../inc/HashMap.h"
#include "../../inc/list_itr.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define HASHMAP_MAGIC_NUM 0x05566770
#define IS_NULL(A) 	(NULL == (A))
#define IS_A_HASHMAP(H) ((H) && HASHMAP_MAGIC_NUM == (H)->m_magicNum)
#define NUM_OF_MUTEXS 100

typedef struct Data
{
	const void* m_key;
	const void* m_val;
}Data;

typedef struct List* Bucket;

struct HashMap
{
	int 				m_magicNum;
	Bucket* 			m_buckets;
	size_t 				m_hashSize;
	HashFunction 		m_hashFunc;
	EqualityFunction 	m_keysEqualFunc;
	pthread_mutex_t 	m_mutexArr[NUM_OF_MUTEXS];
	#ifndef NDEBUG
	MapStats 			m_mapStats;
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
		if (isPrime == 0)
		{
			++_num;
		}
		else
		{
			break;
		}
    }
    return _num;
}

static Bucket AllocateBucket(Bucket _bucket)
{
	_bucket = ListCreate();
	return _bucket;
}

static void DestroyBucket(Bucket _bucket)
{
	ListDestroy(&_bucket, NULL);
	return;
}

static HashMap* AllocateHashMap(size_t _hashSize)
{
	HashMap* hashMap = NULL;
	size_t index;

	if (!(hashMap = malloc(sizeof(HashMap))))
	{
		return NULL;
	}
	
	if (!(hashMap->m_buckets = malloc(_hashSize * sizeof(Bucket))))
	{
		free(hashMap);
		return NULL;
	}

	for (index = 0; index < _hashSize; ++index)
	{
		if (!(hashMap->m_buckets[index] = AllocateBucket(hashMap->m_buckets[index])))
		{
			--index;
			while (index != 0)
			{
				DestroyBucket(hashMap->m_buckets[index]);
				--index;
			}
			DestroyBucket(hashMap->m_buckets[index]);
			free(hashMap->m_buckets);
			free(hashMap);
			return FALSE;
		}
	}
	
	if (_hashSize < )

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
static void DestroyKeyValPairs(Bucket _bucket, KeyDestroy _keyDestroyFunc, ValDestroy _valDestroyFunc)
{
	ListItr nodeSentinel;
	ListItr nodeItr;
	Data* data;

	nodeSentinel = ListItrEnd(_bucket);
	nodeItr = ListItrBegin(_bucket);
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
	return;
}

static void DestroyBuckets(HashMap** _map, KeyDestroy _keyDestroyFunc, ValDestroy _valDestroyFunc)
{
	size_t index;

	for (index = 0; index < (*_map)->m_hashSize; ++index)
	{
		DestroyKeyValPairs((*_map)->m_buckets[index], _keyDestroyFunc, _valDestroyFunc);
		DestroyBucket((*_map)->m_buckets[index]);
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
HASH MAP REHASH
**************/
static size_t CalculateBucketIndex(HashFunction _hashFunc, const void* _key, size_t _hashSize)
{
	size_t hashFuncResult;
	
	hashFuncResult = _hashFunc(_key);
	return hashFuncResult % _hashSize;
}

MapResult HashMapRehash(HashMap *_map, size_t newCapacity)
{
	Bucket* newBuckets;
	size_t newHashSize;
	size_t index;
	size_t insertIndex;
	Data* data;
	void* itrData;

	if(!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}

	newHashSize = CalcHashSize(newCapacity);

	if (!(newBuckets = malloc(newHashSize * sizeof(Bucket))))
	{
		return MAP_ALLOCATION_ERROR;
	}
	
	for (index = 0; index < newHashSize; ++index)
	{
		if (!(newBuckets[index] = ListCreate()))
		{
			--index;
			while (index != 0)
			{
				ListDestroy(&(newBuckets[index]), NULL);
				--index;
			}
			free(newBuckets);
			return MAP_ALLOCATION_ERROR;
		}
	}

	for (index = 0; index < _map->m_hashSize; ++index)
	{
		while(!ListIsEmpty(_map->m_buckets[index]))
		{
			ListPopHead(_map->m_buckets[index], &itrData);
			data = (Data*)itrData;
			insertIndex = CalculateBucketIndex(_map->m_hashFunc, data->m_key, newHashSize);
			ListPushHead(newBuckets[insertIndex], (void*) data);
		}
	}
	_map->m_hashSize = newHashSize;
	free(_map->m_buckets);
	_map->m_buckets = newBuckets;
	return MAP_SUCCESS;
}









/**************
HASH MAP INSERT
**************/
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

	if (!IS_A_HASHMAP(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	if (IS_NULL(_key))
	{
		return MAP_KEY_NULL_ERROR;
	}

	bucketIndex = CalculateBucketIndex(_map->m_hashFunc, _key, _map->m_hashSize);

	if (FindKeyDuplicateInBucket(_map, _key, bucketIndex))
	{
		return MAP_KEY_DUPLICATE_ERROR;
	}
	
	if (MAP_ALLOCATION_ERROR == CreateAndInsertElement(_map, _key, _value, bucketIndex))
	{
		return MAP_ALLOCATION_ERROR;
	}
	return MAP_SUCCESS;
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
	
	bucketIndex = CalculateBucketIndex(_map->m_hashFunc, _searchKey, _map->m_hashSize);
	
	if ((itrFound = FindKeyDuplicateInBucket((HashMap*)_map, _searchKey, bucketIndex)))
	{
		removedData = (Data*)ListItrRemove(itrFound);
		*_pKey = (void*)removedData->m_key;
		*_pValue = (void*)removedData->m_val;
		return MAP_SUCCESS; 
	}
	return MAP_KEY_NOT_FOUND_ERROR;
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
	
	bucketIndex = CalculateBucketIndex(_map->m_hashFunc, _searchKey, _map->m_hashSize);
	
	if ((itrFound = FindKeyDuplicateInBucket((HashMap*)_map, _searchKey, bucketIndex)))
	{
		*_pValue = (void*)((Data*)itrFound)->m_val;
		return MAP_SUCCESS; 
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}







/**************
HASH MAP SIZE
**************/
size_t HashMapSize(const HashMap* _map)
{
	if (!IS_A_HASHMAP(_map))
	{
		return 0;
	}
	
	return _map->m_hashSize;
}










/**************
HASH MAP FOR EACH
**************/
size_t HashMapForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	size_t index;
	size_t count = 0;
	ListItr nodeSentinel;
	ListItr nodeItr;
	Data* data;
	
	if (IS_NULL(_map) || IS_NULL(_action))
	{
		return 0;
	}

	for (index = 0; index < _map->m_hashSize; ++index)
	{
		printf("bucket %lu:\n ", index);
		nodeSentinel = ListItrEnd(_map->m_buckets[index]);
		nodeItr = ListItrBegin(_map->m_buckets[index]);
		while(nodeItr != nodeSentinel)
		{
			data = (Data*) ListItrGet(nodeItr);
			if (!(_action(data->m_key, (void*)data->m_val, _context)))
			{
				return count;
			}
			++count;
			nodeItr = ListItrNext(nodeItr);
		}
	}
	return count;
}









/**************
HASH MAP GET STATISTICS
**************/
#ifndef NDEBUG

static void GetMaxChainLength(HashMap* _map)
{
	size_t index;
	size_t maxChainLength = 0;
	size_t chainLength = 0;
	size_t pairsNum = 0;
	size_t chainsNum = 0;
	size_t collisions = 0;

	for (index = 0; index < _map->m_hashSize; ++index)
	{
		chainLength = ListCountItems(_map->m_buckets[index]);
		pairsNum += chainLength;
		if (chainLength > 0)
		{
			++chainsNum;
		}
		if (chainLength > 1)
		{
			collisions += chainLength - 1;
		}
		if (chainLength > maxChainLength)
		{
			maxChainLength = chainLength;
		}
	}
	_map->m_mapStats.m_pairs = pairsNum;
	_map->m_mapStats.m_collisions = collisions;
	_map->m_mapStats.m_chains = chainsNum;
	_map->m_mapStats.m_maxChainLength = maxChainLength;
	_map->m_mapStats.m_buckets = _map->m_hashSize;
	_map->m_mapStats.m_averageChainLength = _map->m_mapStats.m_pairs / _map->m_mapStats.m_buckets;
	return;
}

MapStats HashMapGetStatistics(const HashMap* _map)
{
	assert(IS_A_HASHMAP(_map));

	GetMaxChainLength((HashMap*)_map);
	return _map->m_mapStats;
}

#endif /* NDEBUG */





