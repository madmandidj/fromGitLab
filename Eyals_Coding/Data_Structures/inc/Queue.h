#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stddef.h>
#include "ADTErr.h"

typedef struct Queue Queue;
#ifndef __ELEMENT_FUNC__
#define __ELEMENT_FUNC__
	typedef void(*ElementFunc)(void*);
#endif /*__ELEMENT_FUNC__*/

Queue* QueueCreate(size_t _size);

void QueueDestroy(Queue* _queue, ElementFunc _elementDestroyFunc);

ADTErr QueueInsert(Queue* _queue, void* _element);

ADTErr QueueRemove(Queue* _queue, void** _removedElement);

int QueueIsEmpty(Queue* _queue);

void QueuePrint(Queue* _queue, ElementFunc _elementPrintFunc);


#endif/*#ifndef __QUEUE_H__*/





