#include "../../inc/Queue.h"
#include "../../inc/Vector.h"
#include "../../inc/ADTErr.h"
#include <stdlib.h>

struct Queue
{
	Vector* m_vector;
	size_t m_size;
	size_t m_headIndex;
	size_t m_tailIndex;
	size_t m_numOfItems;
};

Queue* QueueCreate(size_t _size)
{
	Queue* queue;
	if (0 == _size)
	{
		return NULL;
	}
	if (!(queue = malloc(sizeof(Queue))))
	{
		return NULL;
	}
	if (!(queue->m_vector = VectorCreate(_size, 0)))
	{
		free(queue);
		return NULL;
	}
	queue->m_size = _size;
	queue->m_headIndex = queue->m_tailIndex = queue->m_numOfItems = 0;
	return queue;
}

void QueueDestroy(Queue* _queue, ElementFunc _elementDestroyFunc)
{
	void* element;
	int isQueueEmpty;
	if (!_queue)
	{
		return;
	}
	if (_elementDestroyFunc)
	{	
		isQueueEmpty = QueueIsEmpty(_queue);
		while(!isQueueEmpty)
		{
			QueueRemove(_queue, (void**)&element);
			_elementDestroyFunc(element);
			isQueueEmpty = QueueIsEmpty(_queue);
		}
	}
	VectorDestroy(_queue->m_vector, NULL);
	free(_queue);
}

ADTErr QueueInsert(Queue* _queue, void* _element)
{
	if (!_queue || !_element)
	{
		return ERR_INVARG;
	}
	if (_queue->m_numOfItems == _queue->m_size)
	{
		return ERR_QUEUE_FULL;
	}
	else if (_queue->m_headIndex < _queue->m_size)
	{
		VectorAppend(_queue->m_vector, _element);
		++_queue->m_headIndex;
	}
	else
	{
		VectorSet(_queue->m_vector, (_queue->m_headIndex++) % _queue->m_size, _element);
	}
	++_queue->m_numOfItems;
	return ERR_OK;
}

ADTErr QueueRemove(Queue* _queue, void** _removedElement)
{
	if (!_queue || !_removedElement)
	{
		return ERR_INVARG;
	}
	else if (_queue->m_numOfItems == 0)
	{
		*_removedElement = NULL;
		return ERR_QUEUE_EMPTY;
	}
	else
	{
		VectorGet(_queue->m_vector, _queue->m_tailIndex % _queue->m_size, _removedElement);
		++_queue->m_tailIndex;
		--_queue->m_numOfItems;
	}
	return ERR_OK;
}

int QueueIsEmpty(Queue* _queue)
{
	if (!_queue)
	{
		return ERR_INVARG;
	}
	return _queue->m_numOfItems == 0 ? 1 : 0;
}

void QueuePrint(Queue* _queue, ElementFunc _elementPrintFunc)
{
	size_t reps = 0;
	size_t index;
	void* element;
/*	size_t numOfItems;*/
	
	if (!_queue || ! _elementPrintFunc)
	{
		return;
	}
	index = _queue->m_tailIndex % _queue->m_size;
	while(reps < _queue->m_numOfItems)
	{	
		VectorGet(_queue->m_vector, index, (void**)&element);
		_elementPrintFunc(element);
		++index;
		index = index % _queue->m_size;
		++reps;
	}
}
























