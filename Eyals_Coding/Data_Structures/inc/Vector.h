#ifndef __VECTOR_H__
#define __VECTOR_H__
/*
--------------------
Eyals Generic Vector
--------------------
*/
#include <stddef.h>
#include "ADTErr.h"

typedef struct Vector Vector;
typedef void(*ElementFunc)(void*);

Vector* VectorCreate(size_t _initCapacity, size_t _blockSize);
void VectorDestroy(Vector* _vector, ElementFunc _elemDestroyFunc);
ADTErr VectorAppend(Vector* _vector, void* _element);
ADTErr VectorRemove(Vector* _vector, void** _removedElement);
ADTErr VectorSet(Vector* _vector, size_t _index, void* _element);
ADTErr VectorGet(Vector* _vector, size_t _index, void** _gotElement);
size_t VectorItemsNum(Vector* _vector);
void VectorPrint(Vector* _vector, ElementFunc _elemPrintfunc);
/*void** VectorGetContainer(Vector* _vector);*/

#endif/*#ifndef __VECTOR_H__*/
