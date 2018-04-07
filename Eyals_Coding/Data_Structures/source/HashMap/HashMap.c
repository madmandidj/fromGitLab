#include "../../inc/HashMap.h"
#include "../../inc/List.h"
#include "../../inc/ADTErr.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct KeyAndVal_t
{
	Key_t*	m_key;
	Value_t*	m_value;
}KeyAndVal_t;

struct HashMap
{
	List** 			m_buckets;
	HashFunc 		m_hashFunc;
	EqualityFunc	m_equalFunc;
	size_t			m_numOfElements;
	size_t			m_userCapacity;
	size_t			m_actualCapacity;
	#ifndef NDEBUG
	MapStats* 		m_mapStats;
	#endif
};

/*******
STATIC FUNCTIONS
*******/

static size_t CalcHashSize(size_t _num)
{
    int isPrime = 0;
    size_t i;
    _num = _num < 10 ? 10 : _num;
    _num *= 11;
    _num /= 10;

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

static void SetHashMapAttributes(HashMap* _hashMap, size_t _numOfElements, size_t _userCapacity, size_t _actualCapacity)
{
	_hashMap->m_numOfElements = _numOfElements;
	_hashMap->m_userCapacity = _userCapacity;
	_hashMap->m_actualCapacity = _actualCapacity;
}

#ifndef NDEBUG
static void SetMapStatsAttributes(MapStats* _mapStats, size_t _pairs, size_t _collisions, size_t _buckets,
									 size_t _chains, size_t _maxChainLength, float _avgChainLength)
{
	_mapStats->m_pairs = _pairs;
	_mapStats->m_collisions = _collisions;
	_mapStats->m_buckets = _buckets;
	_mapStats->m_chains = _chains;
	_mapStats->m_maxChainLength = _maxChainLength;
	_mapStats->m_averageChainLength = _avgChainLength;
}
#endif

/*******
API FUNCTIONS
*******/

HashMap* HashMapCreate(size_t _capacity, HashFunc _hashFunc, EqualityFunc _equalFunc)
{
	HashMap* hashMap;
	if (0 == _capacity || !_hashFunc || !_equalFunc)
	{
		return NULL;
	}
	
	if (!(hashMap = malloc(sizeof(HashMap))))
	{
		return NULL;
	}
	hashMap->m_hashFunc = _hashFunc;
	hashMap->m_equalFunc = _equalFunc;
	SetHashMapAttributes(hashMap, 0, _capacity, CalcHashSize(_capacity));
	if (!(hashMap->m_buckets = calloc(hashMap->m_actualCapacity, sizeof(List*))))
	{
		free(hashMap);
		return NULL;
	}
	#ifndef NDEBUG
		if (!(hashMap->m_mapStats = malloc(sizeof(MapStats))))
		{
			free(hashMap->m_buckets);
			free(hashMap);
			return NULL;
		}
		SetMapStatsAttributes(hashMap->m_mapStats, 0, 0, hashMap->m_actualCapacity, 0, 0, 0);
	#endif 
	return hashMap;
}

void HashMapDestroy(HashMap* _hashMap, KeyDestroyFunc _keyDestroyFunc, ValueDestroyFunc _valDestroyFunc)
{
	size_t index;
	ListItr itr;
	KeyAndVal_t* keyAndValPair;
	Key_t* curKey;
	Value_t* curVal;
	if (!_hashMap)
	{
		return;
	}
	
	for (index = 0; index < _hashMap->m_actualCapacity; ++index)
	{
		while (_hashMap->m_buckets[index])
		{
			itr = ListItrFirst(_hashMap->m_buckets[index]);
			keyAndValPair = (KeyAndVal_t*)ListItrGet(itr);
			HashMapRemove(_hashMap, keyAndValPair->m_key, &curKey, &curVal);
			if (_keyDestroyFunc)
			{
				_keyDestroyFunc(curKey);
			}
			if (_valDestroyFunc)
			{
				_valDestroyFunc(curVal);
			}
		}
	}
	#ifndef NDEBUG
		free(_hashMap->m_mapStats);
	#endif 
	free(_hashMap->m_buckets);
	free(_hashMap);
	return;
}


ADTErr HashMapInsert(HashMap* _hashMap, const Key_t* _key, const Value_t* _value)
{
	size_t insertionIndex;
	ListItr itr;
	ListItr listEnd;
	KeyAndVal_t* newKeyValPair = NULL;
	KeyAndVal_t* returnedKeyValPair = NULL;
	if (!_hashMap || !_key || !_value)
	{
		return ERR_INVARG;
	}
	
	insertionIndex = _hashMap->m_hashFunc(_key);
	insertionIndex %= _hashMap->m_actualCapacity;
	if (_hashMap->m_buckets[insertionIndex])
	{
		listEnd = ListItrEnd(_hashMap->m_buckets[insertionIndex]);
		itr = ListItrFirst(_hashMap->m_buckets[insertionIndex]);
		while (itr != listEnd)
		{		
			returnedKeyValPair = (KeyAndVal_t*) ListItrGet(itr);
			if (returnedKeyValPair && _hashMap->m_equalFunc(_key, returnedKeyValPair->m_key))
			{
				return ERR_MAP_KEY_FOUND;
			}
			itr = ListItrNext(itr);
		}
	}
	else
	{		
		_hashMap->m_buckets[insertionIndex] = ListCreate();
	}
	if (!(newKeyValPair = malloc(sizeof(KeyAndVal_t))))
	{
		return ERR_NOMEM;
	}
	newKeyValPair->m_key = (Key_t*)_key;
	newKeyValPair->m_value = (Value_t*)_value;
	ListPushTail(_hashMap->m_buckets[insertionIndex], (void*)newKeyValPair);
	++_hashMap->m_numOfElements;
	
	return ERR_OK;
}

ADTErr HashMapRemove(HashMap* _hashMap, const Key_t* _searchKey, Key_t** _removedKey, Value_t** _removedValue)
{
	size_t insertionIndex;
	ListItr itr;
	ListItr listEnd;
	KeyAndVal_t* foundKeyValPair = NULL;
	KeyAndVal_t* dummyPair = NULL;
	if (!_hashMap || !_searchKey || !_removedKey || !_removedValue)
	{
		return ERR_INVARG;
	}
	
	insertionIndex = _hashMap->m_hashFunc(_searchKey);
	insertionIndex %= _hashMap->m_actualCapacity;
	if (_hashMap->m_buckets[insertionIndex])
	{
		listEnd = ListItrEnd(_hashMap->m_buckets[insertionIndex]);
		itr = ListItrFirst(_hashMap->m_buckets[insertionIndex]);
		while (itr != listEnd)
		{		
			foundKeyValPair = (KeyAndVal_t*) ListItrGet(itr);
			if (_hashMap->m_equalFunc(_searchKey, foundKeyValPair->m_key))
			{
				*_removedKey = foundKeyValPair->m_key;
				*_removedValue = foundKeyValPair->m_value;				
				itr = ListItrRemove(_hashMap->m_buckets[insertionIndex], itr, (void**)&dummyPair);
				free(dummyPair);
				if (0 == ListItemsNum(_hashMap->m_buckets[insertionIndex]))
				{
					ListDestroy(_hashMap->m_buckets[insertionIndex], NULL);
					_hashMap->m_buckets[insertionIndex] = NULL;
				}
				--_hashMap->m_numOfElements;
				return ERR_OK;
			}
			itr = ListItrNext(itr);
		}
	}
	*_removedKey = NULL;
	*_removedValue = NULL;
	return ERR_MAP_KEY_NOT_FOUND;	
}

ADTErr HashMapRehash(HashMap* _hashMap, size_t _newCapacity)
{
	List** newBuckets;
	size_t newActualCapacity;
	size_t numOfItems;
	size_t curItemNum = 0;
	
	KeyAndVal_t* curKeyAndVal;
	Key_t** keyArr;
	Value_t** valArr;
	size_t index;
	
	if (!_hashMap || 0 == _newCapacity)
	{
		return ERR_INVARG;
	}
	
	newActualCapacity = CalcHashSize(_newCapacity);
	numOfItems = _hashMap->m_numOfElements;
	if (!(newBuckets = calloc(newActualCapacity, sizeof(List*))))
	{
		return ERR_NOMEM;
	}
	if (!(keyArr = malloc(numOfItems * sizeof(Key_t*))))
	{
		free(newBuckets);
		return ERR_NOMEM;
	}
	if (!(valArr = malloc(numOfItems * sizeof(Key_t*))))
	{
		free(keyArr);
		free(newBuckets);
		return ERR_NOMEM;
	}
	
	for (index = 0; index < _hashMap->m_actualCapacity; ++index)
	{
		if (_hashMap->m_buckets[index])
		{
			while(0 != ListItemsNum(_hashMap->m_buckets[index]))
			{
				ListPopHead(_hashMap->m_buckets[index], (void**)&curKeyAndVal);
				keyArr[curItemNum] = curKeyAndVal->m_key;
				valArr[curItemNum] = curKeyAndVal->m_value;
				free(curKeyAndVal);
				++curItemNum;
			}
			ListDestroy(_hashMap->m_buckets[index], NULL);
		}
	}
	free(_hashMap->m_buckets);
	_hashMap->m_buckets = newBuckets;
	SetHashMapAttributes(_hashMap, 0, _newCapacity, newActualCapacity);
	#ifndef NDEBUG
		SetMapStatsAttributes(_hashMap->m_mapStats, 0, 0, _hashMap->m_actualCapacity, 0, 0, 0);
	#endif 
	for (index = 0; index < numOfItems; ++index)
	{
		HashMapInsert(_hashMap, keyArr[index], valArr[index]);
	}
	free(keyArr);
	free(valArr);
	return ERR_OK;
}

ADTErr HashMapFind(HashMap* _hashMap, const Key_t* _searchKey, Value_t** _foundValue)
{
	size_t insertionIndex;
	ListItr itr;
	ListItr listEnd;
	KeyAndVal_t* foundKeyValPair = NULL;
	if (!_hashMap || !_searchKey || !_foundValue)
	{
		return ERR_INVARG;
	}
	
	insertionIndex = _hashMap->m_hashFunc(_searchKey);
	insertionIndex %= _hashMap->m_actualCapacity;
	if (_hashMap->m_buckets[insertionIndex])
	{
		listEnd = ListItrEnd(_hashMap->m_buckets[insertionIndex]);
		itr = ListItrFirst(_hashMap->m_buckets[insertionIndex]);
		while (itr != listEnd)
		{		
			foundKeyValPair = (KeyAndVal_t*) ListItrGet(itr);
			if (_hashMap->m_equalFunc(_searchKey, foundKeyValPair->m_key))
			{
				*_foundValue = foundKeyValPair->m_value;				
				return ERR_OK;
			}
			itr = ListItrNext(itr);
		}
	}
	*_foundValue = NULL;
	return ERR_MAP_KEY_NOT_FOUND;
}


size_t HashMapSize(HashMap* _hashMap)
{
	return _hashMap ? _hashMap->m_numOfElements : 0; 
}



size_t HashMapForEach(HashMap* _hashMap, MapElementActionFunc _actionFunc, void* _context)
{
	size_t index;
	ListItr itr;
	ListItr listEnd;
	size_t numOfActions = 0;
	KeyAndVal_t* keyAndValPair;
	if (!_hashMap || !_actionFunc || 0 == _hashMap->m_numOfElements)
	{
		return 0;
	}
	
	for (index = 0; index < _hashMap->m_actualCapacity; ++index)
	{
		if (_hashMap->m_buckets[index])
		{
			listEnd = ListItrEnd(_hashMap->m_buckets[index]);
			itr = ListItrFirst(_hashMap->m_buckets[index]);
			while (itr != listEnd)
			{
				keyAndValPair = (KeyAndVal_t*)ListItrGet(itr);
				if (!(_actionFunc(keyAndValPair->m_key, keyAndValPair->m_value, _context)))
				{
					return numOfActions;
				}
				++numOfActions;
				itr = ListItrNext(itr);
			}
		}
	}
	return numOfActions;
}


#ifndef NDEBUG
MapStats HashMapGetStatistics(const HashMap* _hashMap)
{
	MapStats tempMapStats = {0};
	size_t index;
	size_t numOfChains = 0;
	size_t numOfCollisions = 0;
	size_t curChainLength = 0;
	size_t maxChainLength = 0;
	size_t chainLengthSum = 0;
	float averageChainLengthFloat;
	float chainsFloat;
	if (!_hashMap)
	{
		return tempMapStats;
	}
	
	_hashMap->m_mapStats->m_buckets = _hashMap->m_actualCapacity;
	for (index = 0; index < _hashMap->m_actualCapacity; ++index)
	{
		if (_hashMap->m_buckets[index])
		{
			++numOfChains;
			numOfCollisions += (ListItemsNum(_hashMap->m_buckets[index]) - 1);
			curChainLength = ListItemsNum(_hashMap->m_buckets[index]);
			maxChainLength = curChainLength > maxChainLength ? curChainLength : maxChainLength;
			chainLengthSum += curChainLength;
		}
	}
	_hashMap->m_mapStats->m_chains = numOfChains;
	averageChainLengthFloat = (float)chainLengthSum;
	chainsFloat = (float)(_hashMap->m_mapStats->m_chains);
	
	_hashMap->m_mapStats->m_buckets = _hashMap->m_actualCapacity;
	_hashMap->m_mapStats->m_pairs = _hashMap->m_numOfElements;
	_hashMap->m_mapStats->m_collisions = numOfCollisions;
	_hashMap->m_mapStats->m_averageChainLength = _hashMap->m_mapStats->m_chains ? averageChainLengthFloat / chainsFloat : 0;
	_hashMap->m_mapStats->m_maxChainLength = maxChainLength;
	return *(_hashMap->m_mapStats);
}
#endif 


















