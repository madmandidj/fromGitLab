#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector{
    int*    m_items;
    size_t  m_originalSize;   /* original allocated space for items) */
    size_t  m_size;                 /* actual allocated space for items)*/
    size_t  m_nItems;           /* actual number of items */
    size_t  m_blockSize;     /* the chunk size to be allocated when no space*/

};

Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize)
{
	Vector* vector;
	if (_initialSize == 0 && _extensionBblockSize == 0)
	{
		return NULL;
	}
	vector = malloc(sizeof(Vector));
    if (NULL == vector){
		return NULL;
	}
	else{
		vector->m_items = malloc(_initialSize * sizeof(int));
		if(NULL == vector->m_items){
			free(vector);
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
	if (NULL != _vector->m_items)
	{
		free(_vector->m_items);
		_vector->m_items = NULL;
		_vector->m_nItems = 0;
	}
	free(_vector);
	return;
}

ADTErr VectorAdd(Vector *_vector,  int  _item)
{
	int* tempIntArr;
	if (NULL == _vector || NULL == _vector->m_items)
	{
		return ERR_NOT_INITIALIZED;
	}
	/* change so realoc is done before if needed*/
	/*Put in another function: If there is enough capacity add new item*/
    if (_vector->m_nItems < _vector->m_size)
	{
		_vector->m_items[_vector->m_nItems] = _item;
		++(_vector->m_nItems);
		return ERR_OK;
    }
    /*Put in another function: Check if need new capacity*/
	else if (_vector->m_nItems == _vector->m_size)
	{
		if (0 == _vector->m_blockSize)
		{
			return ERR_OVERFLOW;
		}
		tempIntArr = _vector->m_items;
		tempIntArr = realloc(_vector->m_items, (_vector->m_size + _vector->m_blockSize) * sizeof(int));	
		if (NULL == tempIntArr)
		{
			return ERR_REALLOCATION_FAILED;
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
    return ERR_OK;
}

ADTErr VectorDelete(Vector *_vector,  size_t* _item)
{
	int* tempIntArr;
	if (NULL == _vector || NULL == _vector->m_items || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_vector->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}
	*_item = _vector->m_items[_vector->m_nItems-1];
	--(_vector->m_nItems);
	
	/* 
	if (_vector->m_nItems == vector->m_size-2*(_vector->m_blockSize) &&  
	vector->m_size > vector->m_originalSize)
	*/
	
	
	if (_vector->m_size - _vector->m_blockSize < _vector->m_originalSize)
	{
		return ERR_OK;
	}
	if (_vector->m_size - _vector->m_nItems >= 2 * _vector->m_blockSize)
	{
		tempIntArr = _vector->m_items;
		tempIntArr = realloc(_vector->m_items, (_vector->m_size - _vector->m_blockSize) * sizeof(int));
		if (NULL == tempIntArr)
		{
			/*return ERR_REALLOCATION_FAILED;*/
			return ERR_OK; /* OK here because user doesnt care if managed to downsize or not */
		}
		_vector->m_items = tempIntArr;
		_vector->m_size = _vector->m_size - _vector->m_blockSize;	
		return ERR_OK;	
	}
    return ERR_OK;
}



/*
ADTErr VectorDelete(Vector *_vector,  int* _item)
{
	int* tempIntArr;
	if (NULL == _vector || NULL == _vector->m_items || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_vector->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}
	*_item = _vector->m_items[_vector->m_nItems-1];
	--(_vector->m_nItems);
	
	
	
	if (_vector->m_size - _vector->m_blockSize < _vector->m_originalSize)
	{
		return ERR_OK;
	}
	if (_vector->m_size - _vector->m_nItems >= 2 * _vector->m_blockSize)
	{
		tempIntArr = _vector->m_items;
		tempIntArr = realloc(_vector->m_items, (_vector->m_size - _vector->m_blockSize) * sizeof(int));
		if (NULL == tempIntArr)
		{
			
			return ERR_OK;
		}
		_vector->m_items = tempIntArr;
		_vector->m_size = _vector->m_size - _vector->m_blockSize;	
		return ERR_OK;	
	}
    return ERR_OK;
}
*/

ADTErr VectorGet(Vector *_vector, size_t _index, int *_item)
{
	if (NULL == _vector || NULL == _vector->m_items)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index > _vector->m_size)  /* change from _size-1 to _size */
	{
		return ERR_WRONG_INDEX;
	}
	if (_index == 0)
	{
		return ERR_WRONG_INDEX;
	}
	else
	{
		*_item = _vector->m_items[_index-1]; /* change from _index to _index-1 */
		return ERR_OK;
	}
	
}

ADTErr VectorSet(Vector *_vector, size_t _index, int  _item)
{
	if (NULL == _vector || NULL == _vector->m_items)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index > _vector->m_size)
	{
		return ERR_WRONG_INDEX;
	}
	if (_index == 0)
	{
		return ERR_WRONG_INDEX;
	}
	else
	{
		_vector->m_items[_index-1] = _item;
		return ERR_OK;
	}
}

ADTErr VectorItemsNum(Vector *_vector, int*  _numOfItems)
{
	if (NULL == _vector || NULL == _numOfItems)
	{
		return ERR_NOT_INITIALIZED;
	}
	*_numOfItems = _vector->m_nItems;
	return ERR_OK;
}

void VectorPrint(Vector *_vector)
{
	int i;
	if (NULL == _vector)
	{
		return;
	}
	for (i = 0; i < _vector->m_nItems; i++)
	{
		printf("%d\n", _vector->m_items[i]);
	}
	return;
}





