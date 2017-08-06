/*
Filename: 		GenBubSort.c 
Description:	Generic bubble sort implementation
Created: 		02/08/17
Created by:		Eyal Alon
Last modified: 	04/08/17
Modified by:	Eyal Alon
*/

/*
TODO: Add documentation for checkparams (e.g. why check 1 == _nItems)
TODO: Add macros for TRUE and FALSE
*/
#include <string.h> /* Used for memcpy */
#include "GenBubSort.h"

#define TRUE 1
#define FALSE 0

static ADTErr CheckParams(void* _data, size_t _nItems, size_t _itemSize, SortMethod _sortMethFunc)
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
	if (NULL == _sortMethFunc)
	{
		return ERR_INVALID_SORTMETHOD;
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

static int DoBubble(char* _dataChar, size_t* _nItems, size_t _itemSize, SortMethod _sortMethFunc, void* _tempItem)
{
	int isSwapNeeded = FALSE;
	int isSorted = TRUE;
	size_t counter;
	size_t dataOffset;
	
	for(counter = 0; counter < *_nItems-1; ++counter)
	{
		dataOffset = _itemSize * counter;
		isSwapNeeded = _sortMethFunc(_dataChar + dataOffset, _dataChar + dataOffset + _itemSize);
		if (isSwapNeeded == 1)
		{
			GenericSwap(_dataChar + dataOffset, _dataChar + dataOffset + _itemSize, _tempItem, _itemSize);
			isSorted = FALSE;
		}
	}
	--(*_nItems);
	return isSorted;
}


ADTErr GenericBubbleSort(void* _data, size_t _nItems, size_t _itemSize, SortMethod _sortMethFunc)
{
	void* tempItem = NULL;
	char* dataChar = NULL;
	int isSorted = FALSE;
	ADTErr errResult;

	errResult = CheckParams(_data, _nItems, _itemSize, _sortMethFunc);
	if (errResult != ERR_OK)
	{
		return errResult;
	}
	tempItem = malloc(_itemSize * sizeof(char));
	if (NULL == tempItem)
	{
		return ERR_ALLOCATION_FAILED;
	}
	dataChar = (char*)_data;
	while (!isSorted)
	{
		isSorted = DoBubble(dataChar, &_nItems, _itemSize, _sortMethFunc, tempItem);
	}
	free(tempItem);
	return ERR_OK;
}















