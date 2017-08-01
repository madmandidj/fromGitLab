#ifndef __SORTFUNCTIONS_H__
#define __SORTFUNCTIONS_H__
/*
Filename: 		SortFunctions.h 
Description:	Sort Functions API
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	26/07/17
Modified by:	Eyal Alon
*/
#include "vector.h"
#include "ADTDefs.h"

/*
TODO:
*
* 
*
*
*/


/* 
Sort type function prototype, used in Insertion+Shell Sort to determine sort type:
A ShouldSwap function receives 2 int values of vector elements, and returns wether swap should occur
*/
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
/*
Desc:   Shell Sort the contents of a vector	
In:		Vector pointer, Pointer to sort type function (int, int)		
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec
*/
ADTErr ShellSort(Vector* _vec, ShouldSwap _shouldSwapFunc);
/*
Desc:   Selection Sort the contents of a vector	
In:		Vector pointer	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec
*/
ADTErr SelectionSort(Vector* _vec);
/*
Desc:   Merge Sort the contents of a vector	
In:		Vector pointer	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec TODO: add err for allocation failed
*/
ADTErr MergeSort(Vector* _vec);
/*
Desc:   Merge Sort Recursive the contents of a vector 	
In:		Vector pointer	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec TODO: add err for allocation failed
*/
ADTErr MergeSortRec(Vector* _vec);
/*
Desc:   Counting Sort the contents of a vector 	
In:		Vector pointer	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec TODO: add err for allocation failed
*/
ADTErr CountingSort(Vector* _vec, int _maxValue);
/*
Desc:   Radix Sort the contents of a vector 	
In:		Vector pointer	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED when NULL ==_vec 
*/
ADTErr RadixSort(Vector* _vec, int _nDigits);
#endif /* #ifndef __SORTFUNCTIONS_H__ */

