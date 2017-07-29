/*
Filename: 		HashSet.c 
Description:	Implementation of HashSet API given by Ronny
Created: 		19/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include "HashSet.h"

struct Hash
{
	int* 	m_data;
	size_t 	m_originalSize;
	size_t	m_hashSize;
	size_t	m_maxCollisions;
	size_t	m_numberOfInsertions;
	size_t	m_totalCollisions;
	int		m_magicNum;
};

/*************** 
STATIC FUNCTIONS 
***************/
size_t HashFunc(int _key)
{
	return _key;
}

/************ 
API FUNCTIONS 
************/
Hash* 	HashCreate(const size_t _size)
{
	Hash* hash;
	size_t newSize;
	if (0 == _size)
	{
		return NULL;
	}
	/* Hash capacity is 30% larger than input size */
	/* TODO: change newSize to be closest prime number */
	newSize = (_size * 130) / 100;
	hash = malloc(sizeof(Hash));
	if (NULL == hash)
	{
		return NULL;
	}
	hash->m_data = (int*) calloc(newSize, sizeof(int));
	if (NULL == hash->m_data)
	{
		return NULL;
	}
	hash->m_originalSize = _size;
	hash->m_hashSize = newSize;
	hash->m_maxCollisions = 0;
	hash->m_numberOfInsertions = 0;
	hash->m_totalCollisions = 0;
	hash->m_magicNum = MAGIC_NUM;
	return hash;
}

void 	HashDestroy(Hash* _hash)
{
	if (NULL != _hash && _hash->m_magicNum == MAGIC_NUM)
	{
		if (NULL != _hash->m_data)
		{
			free(_hash->m_data);
		}
		_hash->m_magicNum = NOT_MAGIC_NUM;
		free(_hash);
	}
	return;
}

ADTErr	HashInsert(Hash* _hash, int _data)
{
	ADTErr errResult = ERR_OK;
	int insIndex;
	size_t tempCollisions = 0;
	if (NULL == _hash)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else if (_hash->m_numberOfInsertions == _hash->m_originalSize)
	{
		errResult = ERR_HASH_FULL;
	}
	else
	{
		/*insIndex = _data % _hash->m_hashSize;*/
		/*insIndex = HashFunc(_data) % _hash->m_hashSize;*/
		insIndex = HashFunc(_data) % _hash->m_originalSize;
		while(1)
		{
			if (_hash->m_data[insIndex] == _data)
			{
				errResult = ERR_VAL_EXISTS;
				break;
			}
			else if (_hash->m_data[insIndex] == 0 || _hash->m_data[insIndex] == -1)
			{
				_hash->m_data[insIndex] = _data;
				++_hash->m_numberOfInsertions;
				break;
			}
			else
			{
				++_hash->m_totalCollisions;
				++tempCollisions;
				if (tempCollisions > _hash->m_maxCollisions)
				{
					_hash->m_maxCollisions = tempCollisions;
				}
				++insIndex;
				/* insIndex %= _hash->m_hashSize; */
				/* HashFunc(insIndex) %= _hash->m_hashSize; */
				insIndex = HashFunc(insIndex) % _hash->m_hashSize;
			}
		}
	}
	return errResult;
}

int HashIsFound(const Hash* _hash, int _data)
{
	int foundIndex;
	int index;
	int isFound = 0;
	if (NULL == _hash)
	{
		isFound = 0;
	}
	else
	{
		/* index = _data % _hash->m_hashSize; */
		index = HashFunc(_data) % _hash->m_hashSize;
		for (foundIndex = index; foundIndex <= index + _hash->m_maxCollisions; ++foundIndex)
		{
			/* foundIndex %= _hash->m_hashSize; */
			foundIndex = HashFunc(foundIndex)  % _hash->m_hashSize;
			if (_hash->m_data[foundIndex] == _data)
			{
				isFound = 1;
				break;
			}
		}
	}
	return isFound;
}

ADTErr HashRemove(Hash* _hash, int _data)
{
	ADTErr errResult = ERR_VAL_NOT_EXISTS;
	int foundIndex;
	int index;
	if (NULL == _hash)
	{
		errResult = ERR_NOT_INITIALIZED;
	}
	else
	{
		/*index = _data % _hash->m_hashSize;*/
		index = HashFunc(_data) % _hash->m_hashSize;
		for (foundIndex = index; foundIndex <= index + _hash->m_maxCollisions; ++foundIndex)
		{
			/*foundIndex %= _hash->m_hashSize;*/
			foundIndex = HashFunc(foundIndex) % _hash->m_hashSize;
			if (_hash->m_data[foundIndex] == _data)
			{
				_hash->m_data[foundIndex] = -1;
				--_hash->m_numberOfInsertions;
				errResult = ERR_OK;
				break;
			}
		}
	}
	return errResult;
}

size_t 	HashCapacity(const Hash* _hash)
{
	if (NULL == _hash)
	{
		return 0;
	}
	return _hash->m_hashSize; /* TODO: change to origSize*/
}

double	HashAverageCollisions(const Hash* _hash)
{
	if (NULL == _hash)
	{
		return 0;
	}
	return _hash->m_totalCollisions / _hash->m_numberOfInsertions;
}


void HashPrint(Hash* _hash)
{
	int index;
	if (NULL == _hash)
	{
		return;
	}
	for (index = 0; index < _hash->m_hashSize; ++index)
	{
		printf("%d\n", _hash->m_data[index]);
	}
	return;
}
