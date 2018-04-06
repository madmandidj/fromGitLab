#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include "ADTErr.h"
#include <stddef.h>

typedef void dummy;
typedef void Key_t;
typedef void Value_t;
typedef struct HashMap HashMap;
typedef size_t (*HashFunc)(const void* _key);
typedef void (*KeyDestroyFunc)(Key_t* _key);
typedef void (*ValueDestroyFunc)(Value_t* _value);
typedef int (*EqualityFunc)(const Key_t* _keyL, const Key_t* _keyR);
typedef int	(*MapElementActionFunc)(const Key_t* _key, Value_t* _value, void* _context);

HashMap* HashMapCreate(size_t _capacity, HashFunc _hashFunc, EqualityFunc _equalFunc);

void HashMapDestroy(HashMap* _hashMap, KeyDestroyFunc _keyDestroyFunc, ValueDestroyFunc _valDestroyFunc);

ADTErr HashMapInsert(HashMap* _hashMap, const Key_t* _key, const Value_t* _value);

ADTErr HashMapRemove(HashMap* _hashMap, const Key_t* _searchKey, Key_t** _removedKey, Value_t** _removedValue);

ADTErr HashMapRehash(HashMap** _hashMap, size_t _newCapacity);

ADTErr HashMapFind(HashMap* _hashMap, const Key_t* _searchKey, Value_t** _foundValue);

size_t HashMapSize(HashMap* _hashMap);

/*Iteration will stop if called functions returns a zero for a given pair */
size_t HashMapForEach(HashMap* _hashMap, MapElementActionFunc _actionFunc, void* _context);

#ifndef NDEBUG
typedef struct MapStats
{
    size_t m_pairs;               /* number of pairs stored */
	size_t m_collisions;          /* total number of collisions encountered */
	size_t m_buckets;             /* total number of buckets */
	size_t m_chains;              /* none empty buckets (having non zero length list) */
	size_t m_maxChainLength;      /* length of longest chain */
	float m_averageChainLength;  /* average length of none empty chains */
}MapStats;
MapStats HashMapGetStatistics(const HashMap* _hashMap);
#endif /* NDEBUG */






#endif/*#ifndef __HASHMAP_H__*/

