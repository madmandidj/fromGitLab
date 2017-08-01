#ifndef __SORTFUNCTIONS_H__
#define __SORTFUNCTIONS_H__
/*
Filename: 		SortFunctions.h 
Description:	Sort Functions API
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	24/07/17
Modified by:	Eyal Alon
*/
#include "vector.h"
#include "ADTDefs.h"

/* Sort type function prototype, used in Insertion Sort */
typedef int (*ShouldSwap)(int _leftVal, int _rightVal);
/*
Desc:	Bubble Sort the contents of a vector	
In:		Vector pointer		
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_v
*/
ADTErr 	BubbleSort(Vector* _v);
/*
Desc:	Shake Sort the contents of a vector	
In:		Vector pointer		
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_v
*/
ADTErr  ShakeSort(Vector* _v);
/*
Desc:   Insert Sort the contents of a vector	
In:		Vector pointer, Pointer to sort type function (int, int)		
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec
*/
ADTErr InsertionSort(Vector* _vec, ShouldSwap _shouldSwapFunc);
#endif /* #ifndef __BUBBLESHAKEINSERT_H__ */
