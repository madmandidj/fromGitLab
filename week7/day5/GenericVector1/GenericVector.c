/*
Filename: 		GenericVector.c 
Description:	Generic vector implementation 
Created: 		03/08/17
Created by:		Eyal Alon
Last modified: 	03/08/17
Modified by:	Eyal Alon
*/

#include "GenericVector.h"

struct Vector{
    void**  m_items;
    size_t m_originalSize;   /* original allocated space for items) */
    size_t m_size;           /* actual allocated space for items)*/
    size_t m_nItems;         /* actual number of items */
    size_t m_blockSize;      /* the chunk size to be allocated when no space*/
    /*
    TODO: Add magic number
    */
};










/************	
VECTOR CREATE
*************/


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
		vector->m_items = malloc(_initialSize * sizeof(void*));
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









/************	
VECTOR DESTROY
*************/

/*
	parameter is Vector** so to place NULL in Vector* after destroy
*/
void VectorDestroy(Vector** _vector, DestroyFunc _destroyFunc)
{
	if (NULL == _vector)
	{
		return;
	}
	/*
	Use destroyFunc to free individual items before freeing items
	*/
	if (NULL != _vector->m_items)
	{
		free(_vector->m_items);
		_vector->m_items = NULL;
		_vector->m_nItems = 0;
	}
	free(_vector);
	return;
}











/************	
VECTOR ADD
*************/


ADTErr VectorAdd(Vector *_vector,  void*  _item)
{
	void** tempArr;
	if (NULL == _vector || NULL == _vector->m_items || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	/* TODO: change so realoc is done before if needed*/
	/*TODO: Put in another function: If there is enough capacity add new item*/
    if (_vector->m_nItems < _vector->m_size)
	{
		_vector->m_items[_vector->m_nItems] = _item;
		++(_vector->m_nItems);
		return ERR_OK;
    }
    /*TODO: Put in another function: Check if need new capacity*/
	else if (_vector->m_nItems == _vector->m_size)
	{
		if (0 == _vector->m_blockSize)
		{
			return ERR_OVERFLOW;
		}
		tempArr = _vector->m_items;
		tempArr = realloc(_vector->m_items, (_vector->m_size + _vector->m_blockSize) * sizeof(void*));	
		if (NULL == tempArr)
		{
			return ERR_REALLOCATION_FAILED;
		}
		else 
		{
			tempArr[_vector->m_nItems] = _item;
			_vector->m_items = tempArr;
			_vector->m_size = _vector->m_size + _vector->m_blockSize;
			++(_vector->m_nItems);
			return ERR_OK;
		}	
	}
    return ERR_OK;
}













/************	
VECTOR DELETE
*************/


ADTErr VectorDelete(Vector *_vector,  void** _item)
{
	void** tempArr;
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
		tempArr = _vector->m_items;
		tempArr = realloc(_vector->m_items, (_vector->m_size - _vector->m_blockSize) * sizeof(void*));
		if (NULL == tempArr)
		{
			/* 
			ERR_OK here because user doesnt care if managed to downsize or not 
			*/
			return ERR_OK; 
		}
		_vector->m_items = tempArr;
		_vector->m_size = _vector->m_size - _vector->m_blockSize;	
		return ERR_OK;	
	}
    return ERR_OK;
}











/************	
VECTOR GET
*************/


ADTErr VectorGet(Vector *_vector, size_t _index, void** _item)
{
	if (NULL == _vector || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	else if (_index > _vector->m_size || _index == 0)  
	{
		return ERR_WRONG_INDEX;
	}
	*_item = _vector->m_items[_index-1];
	return ERR_OK;
}









/************	
VECTOR SET
*************/


ADTErr VectorSet(Vector *_vector, size_t _index, void* _item)
{
	if (NULL == _vector || NULL == _vector->m_items || NULL == _item)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (_index > _vector->m_size || _index == 0)
	{
		return ERR_WRONG_INDEX;
	}
	else
	{
		_vector->m_items[_index-1] = _item;
		return ERR_OK;
	}
}













/***************	
VECTOR ITEMS NUM
****************/


ADTErr VectorItemsNum(Vector *_vector, size_t*  _numOfItems)
{
	if (NULL == _vector || NULL == _numOfItems)
	{
		return ERR_NOT_INITIALIZED;
	}
	*_numOfItems = _vector->m_nItems;
	return ERR_OK;
}












/***************	
VECTOR PRINT
****************/


void VectorPrint(Vector *_vector, PrintTypeFunc _printFunc)
{
	size_t i;
	if (NULL == _vector || NULL == _printFunc)
	{
		return;
	}
	for (i = 0; i < _vector->m_nItems; i++)
	{
/*		printf("%d\n", _vector->m_items[i]);*/
		_printFunc(_vector->m_items[i]);
	}
	return;
}





