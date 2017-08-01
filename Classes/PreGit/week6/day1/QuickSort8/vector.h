#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <stdlib.h> /* size_t */
#include "ADTDefs.h"

typedef struct Vector Vector;
/* size      - The initial allocation size.
   blockSize - The extention block size.    */
Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize);
void 	VectorDestroy(Vector* _vector);
ADTErr  VectorAdd(Vector *_vector,  int  _item);
/*
ADTErr  VectorDelete(Vector *_vector,  int* _item);
*/
ADTErr  VectorDelete(Vector *_vector,  size_t* _item);
ADTErr 	VectorGet(Vector *_vector, size_t _index, int *_item);
ADTErr 	VectorSet(Vector *_vector, size_t _index, int  _item);
ADTErr 	VectorItemsNum(Vector *_vector, int*  _numOfItems);
void 	VectorPrint(Vector *_vector);

#endif /*#ifndef __VECTOR_H__*/





