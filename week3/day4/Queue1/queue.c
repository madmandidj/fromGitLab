#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue
{
    int* m_vec;         /*vec to work on*/
    size_t m_size;        /*size of vector*/
    size_t m_head;        /* index of head in m_vec*/
    size_t m_tail;        /* index of tail in m_vec*/
    size_t m_nItems;        /* number of items in vector*/
};


Queue* QueueCreate(size_t _size)
{
	size_t initHead = 0;
	size_t initTail = 0;
	size_t initItems = 0;
	Queue* queue;
	if(0 == _size)
	{
		return NULL;
	}
	queue = malloc(sizeof(Queue));
	if(NULL == queue)
	{
		return NULL;
	}
	else
	{
		queue->m_vec = malloc(_size * sizeof(int));
		if(NULL == queue->m_vec)
		{
			free(queue);
			return NULL;
		}
		queue->m_size = _size;
		queue->m_head = initHead;
		queue->m_tail = initTail;
		queue->m_nItems = initItems;
		
	}
	return queue;
}

void QueueDestroy(Queue* _queue)
{
	if(NULL != _queue->m_vec)
	{
		free(_queue->m_vec);
	}
	if(NULL != _queue)
	{
		free(_queue);
	}
	return;
}


ADTErr  QueueInsert(Queue* _queue, int _item)
{
	ADTErr err;
	if(NULL == _queue)
	{
		err = ERR_NOT_INITIALIZED;
	}
	else if (_queue->m_nItems == _queue->m_size)
	{
		err = ERR_FULL;
	}
	else
	{
		_queue->m_vec[_queue->m_head] = _item;
		++(_queue->m_nItems);
		++(_queue->m_head);
		_queue->m_head %= _queue->m_size;
		err = ERR_OK;
	}
	return err;
}

ADTErr  QueueRemove(Queue* _queue, int* _item)
{
	ADTErr err;
	if(NULL == _queue)
	{
		err = ERR_NOT_INITIALIZED;
		return err;
	}
	else if(_queue->m_nItems == 0)
	{
		err = ERR_EMPTY;
	}
	else
	{
		if(NULL != _item)
		{
			*_item = _queue->m_vec[_queue->m_tail];
		}
		++(_queue->m_tail);
		_queue->m_tail %= _queue->m_size;
		--(_queue->m_nItems);
		err = ERR_OK;
	}
	return err;
}

int QueueIsEmpty(Queue* _queue)
{
	int result;
	if(NULL == _queue)
	{
		result = 1;
	}
	else if(0 == _queue->m_nItems)
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return result;
}

void    QueuePrint(Queue* _queue)
{
    size_t printIndex;
    int i;
    printIndex = _queue->m_tail;
    for(i = 0; i < _queue->m_nItems; ++i)
    {
        printf("Index: %ld Value: %d", printIndex, _queue->m_vec[printIndex]);
        ++printIndex;
        printIndex %= _queue->m_size;
    }
    return;
}




