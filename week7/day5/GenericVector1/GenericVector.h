#ifndef __GENERICVECTOR_H__
#define __GENERICVECTOR_H__
/*
Filename: 		GenericVector.h 
Description:	Generic vector API 
Created: 		03/08/17
Created by:		Eyal Alon
Last modified: 	03/08/17
Modified by:	Eyal Alon
*/

#include <stdlib.h> /* size_t */
#include "ADTDefs.h"

typedef struct Vector Vector;
/*
Generic print function should be implemented by user for specific type of data 
*/
typedef void (*PrintTypeFunc)(void* _item);
/*
Desc:	Create generic vector	
In:		
Out:	Vector* 
Err: 	If no memery available, NULL returned
*/
Vector* VectorCreate    (size_t _initialSize, size_t _extensionBblockSize);

/*
Desc:	Destroy generic vector	
In:		Vector*		
Out:	void
Err: 	No double-free protection. TODO: add double free protection
*/
void 	VectorDestroy   (Vector* _vector, DestroyFunc _destroyFunc);

/*
Desc:	Add item to last position in vector
In:		Vector*, int value to enter
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_OVERFLOW, ERR_REALLOCATION_FAILED
*/
ADTErr  VectorAdd       (Vector* _vector,  void*  _item);

/*
Desc:	Delete last item in vector	
In:		Vector*, int* to receive deleted value	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_UNDERFLOW
*/
ADTErr  VectorDelete    (Vector* _vector,  void** _item);

/*
Desc:	Delete last item in vector	
In:		Vector*, int* to receive retreived value	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_WRONG_INDEX
*/
ADTErr 	VectorGet       (Vector* _vector, size_t _index, void** _item);

/*
Desc:	Delete last item in vector	
In:		Vector*, int* to receive retreived value	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_WRONG_INDEX
*/
ADTErr 	VectorSet       (Vector* _vector, size_t _index, void*  _item);

/*
Desc:	Get number of items in vector	
In:		Vector*, int* to receive number of items	
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED
*/
ADTErr 	VectorItemsNum  (Vector* _vector, size_t*  _numOfItems);

/*
Desc:	Print conent of vector	
In:		Vector*	
Out:	void
Err: 	NA
*/
void 	VectorPrint     (Vector* _vector, PrintTypeFunc _printFunc);

#endif /*#ifndef __GENERICVECTOR_H__*/


