/*
Filename: 		GenBubSort.c 
Description:	Generic bubble sort implementation
Created: 		02/08/17
Created by:		Eyal Alon
Last modified: 	02/08/17
Modified by:	Eyal Alon
*/

/*
TODO: How to detect and handle nItems that is not the actual nItems of data?
TODO: How detect and handle itemSize that is not actual itemSize
*/

#include <string.h> /* Used for memcpy */
#include "GenBubSort.h"
static ADTErr CheckParams(void* _data, size_t _nItems, size_t _itemSize)
{
	if (NULL == _data)
	{
		return ERR_NOT_INITIALIZED;
	}
	if (0 == _nItems)
	{
		return ERR_ZERO_ITEMS;
	}
	if (1 == _nItems)
	{
		return ERR_OK;
	}
	if (0 == _itemSize)
	{
		return ERR_INVALID_ITEMSIZE;
	}
	return ERR_OK;
}

static void GenericSwap(void* _leftItem, void* _rightItem, void* _tempItem, size_t _itemSize)
{
	memcpy(_tempItem, _leftItem, _itemSize);
	memcpy(_leftItem, _rightItem, _itemSize);
	memcpy(_rightItem, _tempItem, _itemSize);
	return;
}


ADTErr GenericBubbleSort(void* _data, size_t _nItems, size_t _itemSize, SortMethod _func)
{
	/*TODO: init pointers = NULL */
	void* tempItem;
	size_t index;
	int isSorted = 0;
	int isSwapNeeded = 0;
	ADTErr errResult;
	errResult = CheckParams(_data, _nItems, _itemSize);
	if (errResult != ERR_OK)
	{
		return errResult;
	}
	tempItem = malloc(_itemSize * sizeof(char));
	if (NULL == tempItem)
	{
		return ERR_ALLOCATION_FAILED;
	}
	while (!isSorted)
	{
		isSorted = 1;
		for(index = 0; index < _nItems-1; ++index)
		{
			/* TODO: following lines are too long. can make them smaller */
			/* TODO: define TRUE = 1 and FALSE = 0 */
			isSwapNeeded = _func(((char*)_data + _itemSize * index), ((char*)_data + _itemSize * index + _itemSize));
			if (isSwapNeeded == 1)
			{
				GenericSwap(((char*)_data + _itemSize * index), ((char*)_data + _itemSize * index + _itemSize), tempItem, _itemSize);
				isSorted = 0;
			}
		}
		--_nItems;
	}
	_data = (void*) _data;
	free(tempItem);
	return ERR_OK;
}















