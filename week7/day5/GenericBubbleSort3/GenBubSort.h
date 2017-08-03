#ifndef __GENBUBSORT_H__
#define __GENBUBSORT_H__
/*
Filename: 		GenBubSort.h 
Description:	Generic bubble sort API
Created: 		02/08/17
Created by:		Eyal Alon
Last modified: 	02/08/17
Modified by:	Eyal Alon
*/
#include <stdlib.h>
#include "ADTDefs.h"

/* 
Determines if item1 and item2 should be swapped.
This function is written by the user and provided as parameter to GenericBubbleSort
returns 1 if swap needed. 0 if no swap needed.
*/
typedef int(*SortMethod)(const void* _item1, const void* _item2);

/*
DESC:	Generic Bubble Sort
IN:		void*: data to sort, size_t: number of items, size_t: size of single item, SortMethod: sorting method function provided by user
OUT:	ERR_OK
ERROR:	ERR_NOT_INITIALIZED, ERR_INVALID_ITEMSIZE, ERR_ZERO_ITEMS, ERR_ALLOCATION_FAILED
*/
ADTErr GenericBubbleSort(void* _data, size_t _nItems, size_t _itemSize, SortMethod _func);


#endif /* #ifndef __GENBUBSORT_H__ */

