#ifndef __PROQUEUE_H__
#define __PROQUEUE_H__

#define _GNU_SOURCE
#define EOW_SEM "eowSem"


#include <stdlib.h>


typedef struct ProQueue ProQueue;


ProQueue*  ProQueueCreate(size_t _size);


void    ProQueueDestroy(ProQueue* _queue);


int  ProQueueInsert(ProQueue* _queue, void* _item);


int  ProQueueRemove(ProQueue* _queue, void** _item);


int     ProQueueIsEmpty(ProQueue* _queue);


#endif/*#ifndef __PROQUEUE_H__*/

