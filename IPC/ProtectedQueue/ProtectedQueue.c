#include "ProtectedQueue.h"
#include <fcntl.h>			/* O_CREAT */
#include <semaphore.h>		/* sem_t, sem_open */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>





struct Queue
{
    void** 				m_vec;         	/*vec to work on*/
    size_t 				m_size;        	/*size of vector*/
    size_t 				m_head;        	/* index of head in m_vec*/
    size_t 				m_tail;        	/* index of tail in m_vec*/
    size_t 				m_nItems;       /* number of items in vector*/
    sem_t 				m_emptySem;
    sem_t				m_fullSem;
    pthread_mutex_t 	m_qMutex;
};






Queue* ProQueueCreate(size_t _size)
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
		queue->m_vec = malloc(_size * sizeof(void*));
		if(NULL == queue->m_vec)
		{
			free(queue);
			return NULL;
		}
		
		queue->m_size = _size;
		queue->m_head = initHead;
		queue->m_tail = initTail;
		queue->m_nItems = initItems;
		
		if (sem_init(&queue->m_emptySem, 0, _size))
		{
			free(queue->m_vec);
			free(queue);
			return NULL;
		}
		
		if (sem_init(&queue->m_fullSem, 0, 0))
		{
			sem_destroy(&queue->m_emptySem);
			free(queue->m_vec);
			free(queue);
			return NULL;
		}
		
		if (pthread_mutex_init(&queue->m_qMutex, NULL))
		{
			sem_destroy(&queue->m_fullSem);
			sem_destroy(&queue->m_emptySem);
			free(queue->m_vec);
			free(queue);
			return NULL;
		}
	}
	
	return queue;
}







void ProQueueDestroy(Queue* _queue)
{	
	if(NULL != _queue)
	{
		if(NULL != _queue->m_vec)
		{
			sem_destroy(&_queue->m_fullSem);
			sem_destroy(&_queue->m_emptySem);
			pthread_mutex_destroy(&_queue->m_qMutex);
			free(_queue->m_vec);
		}
		free(_queue);
	}
	
	return;
}









ADTErr  ProQueueInsert(Queue* _queue, void* _item)
{
	ADTErr err;
	if(NULL == _queue || NULL == _queue->m_vec)
	{
		err = ERR_NOT_INITIALIZED;
	}
	/*
	else if (_queue->m_nItems == _queue->m_size)
	{
		err = ERR_FULL;
	}
	*/
	
	else
	{
		pthread_mutex_lock(&_queue->m_qMutex);
		sem_wait(&_queue->m_emptySem);
		
		_queue->m_vec[_queue->m_head] = _item;
		++(_queue->m_nItems);
		++(_queue->m_head);
		_queue->m_head %= _queue->m_size;
		err = ERR_OK;
		
		sem_post(&_queue->m_fullSem);
		pthread_mutex_unlock(&_queue->m_qMutex);
	}
	
	return err;
}










ADTErr  ProQueueRemove(Queue* _queue, void** _item)
{
	ADTErr err;
	if(NULL == _queue || NULL == _queue->m_vec)
	{
		err = ERR_NOT_INITIALIZED;
		return err;
	}
	/*
	else if(_queue->m_nItems == 0)
	{
		err = ERR_EMPTY;
	}
	*/
	else
	{
		pthread_mutex_lock(&_queue->m_qMutex);
		sem_wait(&_queue->m_fullSem);
		
		if(NULL != _item)
		{
			*_item = _queue->m_vec[_queue->m_tail];
		}
		++(_queue->m_tail);
		_queue->m_tail %= _queue->m_size;
		--(_queue->m_nItems);
		err = ERR_OK;
		
		sem_post(&_queue->m_emptySem);
		pthread_mutex_unlock(&_queue->m_qMutex);
	}
	
	return err;
}









int ProQueueIsEmpty(Queue* _queue)
{
	int result;
	if(NULL == _queue || NULL == _queue->m_vec)
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









void    ProQueuePrint(Queue* _queue)
{
    size_t printIndex;
    int i;
    if(NULL == _queue || NULL == _queue->m_vec)
    {
    	return;
    }
    printIndex = _queue->m_tail;
    for(i = 0; i < _queue->m_nItems; ++i)
    {
        printf("Index: %u Value: %d\n", printIndex, *(int*)_queue->m_vec[printIndex]);
        ++printIndex;
        printIndex %= _queue->m_size;
    }
    return;
}




