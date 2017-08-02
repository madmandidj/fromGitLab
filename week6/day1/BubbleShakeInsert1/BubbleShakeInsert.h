#ifndef __BUBBLEANDSHAKESORTVEC_H__
#define __BUBBLEANDSHAKESORTVEC_H__
/*
Filename: 		BubbleShakeInsert.h 
Description:	Bubble shake and insert sort using Vector - API
Created: 		20/07/17
Created by:		Eyal Alon
Last modified: 	23/07/17
Modified by:	Eyal Alon
*/
#include "vector.h"
#include "ADTDefs.h"

/* Sort type function prototype, used in Insertion Sort */
typedef int (*SortFunc)(int, int);
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
ADTErr InsertionSort(Vector* _vec, SortFunc _func);
#endif /* #ifndef __BUBBLESORTVEC_H__ */
