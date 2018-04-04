#include "../../inc/HashMap.h"
#include "../../inc/List.h"
#include "../../inc/ADTErr.h"

typedef struct KeyAndVal_t
{
	Key_t	m_key;
	Value_t	m_value;
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
	#endif /* NDEBUG */
}

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

HashMap* HashMapCreate(size_t _capacity, HashFunc _hashFunc, EqualityFunc _equalFunc)
{
	HashMap* hashMap;
	size_t index;
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
	hashMap->m_numOfElements = 0;
	hashMap->m_userCapacity = _capacity;
	hashMap->m_actualCapacity = CalcHashSize(hashMap->m_userCapacity);
	hashMap->m_buckets = calloc(hashMap->m_actualCapacity, sizeof(List*));
	#ifndef NDEBUG
	hashMap->m_mapStats->m_pairs = 0;
	hashMap->m_mapStats->m_collisions = 0;
	hashMap->m_mapStats->m_buckets = hashMap->m_actualCapacity;
	hashMap->m_mapStats->m_chains = 0;
	hashMap->m_mapStats->m_maxChainLength = 0;
	hashMap->m_mapStats->m_averageChainLength = 0;
	#endif /* NDEBUG */
	return hashMap;
}


ADTErr HashMapInsert(HashMap* _hashMap, const Key_t _key, const Value_t _value)
{
	size_t index;
	size_t insertionIndex;
	ListItr itr;
	KeyAndVal_t* newKeyValPair = NULL;
	KeyAndVal_t* returnedKeyValPair = NULL;
	if (!_hashMap || !_key || !_value)
	{
		return ERR_INVARG;
	}
	
	insertionIndex = _hashMap->m_hashFunc(_key);
	if (_hashMap->m_buckets[insertionIndex])
	{
		itr = ListItrFirst(_hashMap->m_buckets[insertionIndex]);
		while (itr)
		{		
			returnedKeyValPair = (KeyAndVal_t*) ListItrGet(itr);
			if (_hashMap->m_equalFunc(_key, returnedKeyValPair->m_key))
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
	newKeyValPair->m_key = _key;
	newKeyValPair->m_value = _value;
	ListPushTail(_hashMap->m_buckets[insertionIndex], (void*)newKeyValPair);
	++_hashMap->m_numOfElements;
	
/*	while(hashMap->m_buckets[insertionIndex] && !_hashMap->m_equalFunc(newKeyValPair->m_key, returnedKeyValPair->m_key)*/
/*	{*/
/*		++insertionIndex;*/
/*		insertionIndex %= _hashMap->m_actualCapacity;*/
/*		itr = ListItrFirst(_hashMap->m_buckets[insertionIndex]);*/
/*		returnedKeyValPair = (KeyAndVal_t*) ListItrGet(itr);*/
/*	}*/
/*	if (!_hashMap->m_buckets[insertionIndex])*/
/*	{*/
/*		_hashMap->m_buckets[insertionIndex] = ListCreate();*/
/*	}*/
/*	ListPushTail(_hashMap->m_buckets[insertionIndex], (void*)newKeyValPair);*/
	return ERR_OK;
}




size_t HashMapForEach(HashMap* _hashMap, MapElementActionFunc _actionFunc, void* _context)
{
	size_t index;
	ListItr itr;
	size_t numOfActions = 0;
	if (!_hashMap || !_actionFunc || 0 == _hashMap->m_numOfElements)
	{
		return 0;
	}
	for (index = 0; index < _hashMap->m_actualCapacity; ++index)
	{
		if (_hashMap->m_buckets[index])
		{
			itr = ListItrFirst(_hashMap->m_buckets[index]);
			while (itr)
			{
				if (!(_actionFunc((Key_t)&index, (Value_t)ListItrGet(itr), _context)))
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





















