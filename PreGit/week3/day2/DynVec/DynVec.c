#include <stdio.h>
#include <stdlib.h>
#include "DynVec.h"

struct Vector{
    int*    m_items;
    size_t  m_originalSize;   /* original allocated space for items) */
    size_t  m_size;                 /* actual allocated space for items)*/
    size_t  m_nItems;           /* actual number of items */
    size_t  m_blockSize;     /* the chunk size to be allocated when no space*/

};

Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize)
{
	if (_initialSize == 0 && _extensionBblockSize == 0)
	{
		return NULL;
	}
	Vector* vector;
	vector = malloc(sizeof(Vector));
    if (NULL == vector){
		return NULL;
	}
	else{
		vector->m_items = malloc(_initialSize * sizeof(int));
		if(NULL == vector->m_items){
			return NULL;
		}
		else{
			vector->m_originalSize = _initialSize;
			vector->m_size = _initialSize;
			vector->m_nItems = 0;
			vector->m_blockSize = _extensionBblockSize;
			return vector;
		}
	}
}

void VectorDestroy(Vector* _vector)
{
	if (NULL == _vector)
	{
		return;
	}
	free(_vector->m_items);
	free(_vector);
	return;
}

ADTErr VectorAdd(Vector *_vector,  int  _item)
{
	if (NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}
	int* tempIntArr;
    if (_vector->m_nItems < _vector->m_size)
	{
		_vector->m_items[_vector->m_nItems] = _item;
		++(_vector->m_nItems);
		return ERR_OK;
    }
	else if (_vector->m_nItems == _vector->m_size)
	{
		tempIntArr = _vector->m_items;
		tempIntArr = realloc(_vector->m_items, (_vector->m_size + _vector->m_blockSize) * sizeof(int));	
		if (NULL == tempIntArr)
		{
			ERR_REALLOCATION_FAILED;
		}
		else 
		{
			tempIntArr[_vector->m_nItems] = _item;
			_vector->m_items = tempIntArr;
			_vector->m_size = _vector->m_size + _vector->m_blockSize;
			++(_vector->m_nItems);
			return ERR_OK;
		}	
	}
}

ADTErr VectorDelete(Vector *_vector,  int* _item)
{
	int* tempIntArr;
	if (NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_vector->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}
	*_item = _vector->m_items[_vector->m_nItems];
	--(_vector->m_nItems);
	if (_vector->m_size - _vector->m_blockSize <= _vector->m_originalSize)
	{
		return ERR_GENERAL;
	}
	if (_vector->m_size - _vector->m_nItems > 2 * _vector->m_blockSize) 
	{
		tempIntArr = _vector->m_items;
		tempIntArr = realloc(_vector->m_items, (_vector->m_size - _vector->m_blockSize) * sizeof(int));
		if (NULL == tempIntArr)
		{
			return ERR_REALLOCATION_FAILED;
		}
		_vector->m_items = tempIntArr;
		_vector->m_size = _vector->m_size - _vector->m_blockSize;	
		return ERR_OK;	
	}
}


ADTErr VectorGet(Vector *_vector, size_t _index, int *_item)
{
	if (NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index < 0 || _index > _vector->m_size-1)
	{
		return ERR_WRONG_INDEX;
	}
	else
	{
		*_item = _vector->m_items[_index];
		return ERR_OK;
	}
	
}

ADTErr VectorSet(Vector *_vector, size_t _index, int  _item)
{
	if (NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index < 0 || _index > _vector->m_size-1)
	{
		return ERR_WRONG_INDEX;
	}
	else
	{
		_vector->m_items[_index] = _item;
		return ERR_OK;
	}
}

ADTErr VectorItemsNum(Vector *_vector, int*  _numOfItems)
{
	if (NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (NULL == _numOfItems)
	{
		return ERR_NOT_INITIALIZED;
	}
	*_numOfItems = _vector->m_nItems;
	return ERR_OK;
}

void VectorPrint(Vector *_vector)
{
	if (NULL == _vector)
	{
		return;
	}
	int i;
	for (i = 0; i < _vector->m_nItems; i++)
	{
		printf("%d\n", _vector->m_items[i]);
	}
	return;
}





