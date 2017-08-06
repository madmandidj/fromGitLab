/*
Filename: 		GenericVector.c 
Description:	Generic vector implementation 
Created: 		03/08/17
Created by:		Eyal Alon
Last modified: 	05/08/17
Modified by:	Eyal Alon
*/

#include "GenericVector.h"
#include <stdlib.h>
#define MAGIC_NUM 1717
#define NOT_MAGIC_NUM 2222 
#define TRUE 1
#define FALSE 0
struct Vector{
    void** 	m_items;			/* Void* array to hold generic item pointers */
    size_t 	m_initialCapacity;	/* original allocated space for items */
    size_t 	m_size;           	/* actual allocated space for items */
    size_t 	m_nItems;         	/* actual number of items */
    size_t 	m_blockSize;      	/* the chunk size for resizing */
	int 	m_magicNum;			/* Magic number for double free prevention */
};











/************	
VECTOR CREATE
*************/
static int CheckCreateParams(size_t _initialCapacity, size_t _blockSize)
{
	if (_initialCapacity == 0 && _blockSize == 0)
	{
		return FALSE;
	}
	return TRUE;
}

static Vector* AllocateVecAndVerify(Vector* _vector)
{
	_vector = malloc(sizeof(Vector));
    if (NULL == _vector)
	{
		return NULL;
	}
	return _vector;
}

static Vector* AllocateVecItemsAndVerify(Vector* _vector, size_t _initialCapacity)
{
	_vector->m_items = malloc(_initialCapacity * sizeof(void*));
	if(NULL == _vector->m_items){
		free(_vector);
		return NULL;
	}
	return _vector;
}

static void InitVecParams(Vector* _vector, size_t _initialCapacity, size_t _blockSize)
{
	_vector->m_initialCapacity = _initialCapacity;
	_vector->m_size = _initialCapacity;
	_vector->m_nItems = 0;
	_vector->m_blockSize = _blockSize;
	_vector->m_magicNum = MAGIC_NUM;
	return;
}

Vector* VecCreate(size_t _initialCapacity, size_t _blockSize)
{
	Vector* vector = NULL;
	int areParamsValid;
	if ((areParamsValid = CheckCreateParams(_initialCapacity, _blockSize)) != TRUE)
	{
		return NULL;
	}
	if ((vector = AllocateVecAndVerify(vector)) == NULL)
	{
		return NULL;
	}
	if ((vector = AllocateVecItemsAndVerify(vector, _initialCapacity)) == NULL)
	{
		return NULL;
	}
	InitVecParams(vector, _initialCapacity, _blockSize);
	return vector;
}











/************	
VECTOR DESTROY
*************/
static int CheckDestroyParams(Vector** _vector, ElementDestroy _elementDestroy)
{
	if (NULL == _vector || NULL == *_vector)
	{
		return FALSE;
	}
	else if (MAGIC_NUM != (*_vector)->m_magicNum)
	{
		return FALSE;
	}
	else if (NULL == (*_vector)->m_items)
	{
		return FALSE;
	}
	return TRUE;
}

static void CheckAndDoElementDestroy(Vector** _vector, ElementDestroy _elementDestroy)
{
	size_t index;
	if (NULL != _elementDestroy)
	{
		for (index = 0; index < (*_vector)->m_nItems; ++index)
		{
			_elementDestroy((*_vector)->m_items[index]);
		}
	}
	return;
}

static void DoVecDestroy(Vector** _vector)
{
	(*_vector)->m_nItems = 0;
	(*_vector)->m_magicNum = NOT_MAGIC_NUM;
	free((*_vector)->m_items);
	(*_vector)->m_items = NULL;
	free(*_vector);
	*_vector = NULL;
	return;
}

void VecDestroy(Vector** _vector, ElementDestroy _elementDestroy)
{
	if (!CheckDestroyParams(_vector, _elementDestroy))
	{
		return;
	}
	CheckAndDoElementDestroy(_vector, _elementDestroy);
	DoVecDestroy(_vector);
	return;
}











/************	
VECTOR APPEND
*************/
static ADTErr CheckAppendParams(Vector* _vector, void* _item)
{
	if (NULL == _vector || NULL == _vector->m_items)
	{
		return ERR_NOT_INITIALIZED;
	}
	return ERR_OK;
}

static int AppendWithNoResize(Vector* _vector, void* _item)
{ 
	if (_vector->m_nItems < _vector->m_size)
	{
		++(_vector->m_nItems);
		_vector->m_items[_vector->m_nItems-1] = _item;
		return TRUE;
    }
	return FALSE;
}

static ADTErr AppendWithResize(Vector* _vector, void* _item)
{
	void** tempArr;
	if (0 == _vector->m_blockSize)
	{
		return ERR_OVERFLOW;
	}
	tempArr = realloc(_vector->m_items, (_vector->m_size + _vector->m_blockSize) * sizeof(void*));	
	if (NULL == tempArr)
	{
		return ERR_REALLOCATION_FAILED;
	}
	tempArr[_vector->m_nItems] = _item;
	_vector->m_items = tempArr;
	++(_vector->m_nItems);
	_vector->m_size = _vector->m_size + _vector->m_blockSize;
	return ERR_OK;
}

ADTErr VecAppend(Vector* _vector, void* _item)
{
	ADTErr errResult;
	if ((errResult = CheckAppendParams(_vector, _item)) != ERR_OK)
	{
		return errResult;
	}
	if ((AppendWithNoResize(_vector, _item)) == TRUE)
	{
		return ERR_OK;
	}
	if ((errResult = AppendWithResize(_vector, _item)) != ERR_OK)
	{
		return errResult;
	}
    return ERR_OK;
}











/************	
VECTOR REMOVE
*************/
static ADTErr CheckRemoveParams(Vector* _vector, void** _pValue)
{
	if (NULL == _vector || NULL == _pValue)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_vector->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}
	return ERR_OK;
}

static void DoRemoveAndUpdateNItems(Vector* _vector, void** _pValue)
{
	*_pValue = _vector->m_items[_vector->m_nItems-1];
	--(_vector->m_nItems);
	return;
}

static int LimitSizeToInitialCapacity(Vector* _vector)
{
	if (_vector->m_size - _vector->m_blockSize < _vector->m_initialCapacity)
	{
		return 1;
	}
	return 0;
}

static void CheckAndDoResize(Vector* _vector)
{
	void** tempArr;
	if (_vector->m_size - _vector->m_nItems >= 2 * _vector->m_blockSize)
	{
		tempArr = _vector->m_items;
		tempArr = realloc(_vector->m_items, (_vector->m_size - _vector->m_blockSize) * sizeof(void*));
		if (NULL == tempArr)
		{
			return; 
		}
		_vector->m_items = tempArr;
		_vector->m_size = _vector->m_size - _vector->m_blockSize;	
		return;	
	}
	return;
}

ADTErr VecRemove(Vector* _vector, void** _pValue)
{
	ADTErr errResult;
	if ((errResult = CheckRemoveParams(_vector, _pValue)) != ERR_OK)
	{
		return errResult;
	}
	DoRemoveAndUpdateNItems(_vector, _pValue);
	if (LimitSizeToInitialCapacity(_vector) == 1)
	{
		return ERR_OK;
	}
	CheckAndDoResize(_vector);
	return ERR_OK;
}











/************	
VECTOR GET
*************/
static ADTErr CheckGetParams(const Vector* _vector, size_t _index, void** _pValue)
{
	if (NULL == _vector || NULL == _pValue)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index > _vector->m_nItems || _index == 0)
	{
		return ERR_WRONG_INDEX;
	}
	return ERR_OK;
}

static void DoGet(const Vector* _vector, size_t _index, void** _pValue)
{
	*_pValue = _vector->m_items[_index - 1];
	return;
}


ADTErr VecGet(const Vector* _vector, size_t _index, void** _pValue)
{
	ADTErr errResult;
	if ((errResult = CheckGetParams(_vector, _index, _pValue)) != ERR_OK)
	{
		return errResult;
	}
	DoGet(_vector, _index, _pValue);
	return ERR_OK;
}











/************	
VECTOR SET
*************/
static ADTErr CheckSetParams(const Vector* _vector, size_t _index)
{
	if (NULL == _vector)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index > _vector->m_nItems || _index == 0)
	{
		return ERR_WRONG_INDEX;
	}
	return ERR_OK;
}

static void DoSet(Vector* _vector, size_t _index, void*  _value)
{
	_vector->m_items[_index - 1] = _value;
	return;
}


ADTErr VecSet(Vector* _vector, size_t _index, void*  _value)
{
	ADTErr errResult;
	if ((errResult = CheckSetParams(_vector, _index)) != ERR_OK)
	{
		return errResult;
	}
	DoSet(_vector, _index, _value);
	return ERR_OK;
}











/***************	
VECTOR ITEMS NUM
****************/
size_t VecSize(const Vector* _vector)
{
	if (NULL == _vector)
	{
		return 0;
	}
	return _vector->m_nItems;
}











/***************	
VECTOR CAPACITY
****************/
size_t VecCapacity(const Vector* _vector)
{
	if (NULL == _vector)
	{
		return 0;
	}
	return _vector->m_size;
}











/************	
VECTOR FOR EACH
*************/
static size_t CheckVecForEachParams(const Vector* _vector, VectorElementAction _action)
{
	if (NULL == _vector || NULL == _action)
	{
		return 0;
	}
	return 1;
}

static size_t DoVecForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
	size_t index;
	int result = 0;
	for (index = 0; index < _vector->m_nItems; ++index)
	{
		result = _action(_vector->m_items[index], index, _context);
		if (result == 0)
		{
			break;
		}
	}
	return index;
}

size_t VecForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
	if (CheckVecForEachParams(_vector, _action) == 0)
	{
		return 0;
	}
	return DoVecForEach(_vector, _action, _context);
}










