#ifndef __BUBBLEANDSHAKESORTVEC_H__
#define __BUBBLEANDSHAKESORTVEC_H__
/*
Filename: 		BubbleAndShakeSortVec.h 
Description:	Bubble And Shake Sort using Vector API given by Ronny
Created: 		20/07/17
Created by:		Eyal Alon
Last modified: 	23/07/17
Modified by:	Eyal Alon
*/
#include "vector.h"
#include "ADTDefs.h"


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
#endif /* #ifndef __BUBBLESORTVEC_H__ */
