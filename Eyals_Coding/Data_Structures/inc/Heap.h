#ifndef __HEAP_H__
#define __HEAP_H__

#include "ADTErr.h"
#include "Vector.h"

typedef struct Heap Heap;
typedef int (*IsLeftBigger)(void*, void*);

Heap* HeapBuild(Vector* _vec, IsLeftBigger _isLeftBiggerFunc);

void HeapDestroy(Heap* _heap);

ADTErr HeapInsert(Heap* _heap, void* _element);

ADTErr HeapMax(Heap* _heap, void** _maxElement);

ADTErr HeapExtractMax(Heap* _heap, void** _maxElement);

size_t HeapItemsNum(Heap* _heap);

void HeapPrint(Heap* _heap, ElementFunc _printFunc);


#endif /*#ifndef __HEAP_H__*/

