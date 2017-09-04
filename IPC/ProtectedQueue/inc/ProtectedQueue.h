#ifndef __PROQUEUE_H__
#define __PROQUEUE_H__

#define _GNU_SOURCE
#define EOW_SEM "eowSem"

#include "ADTDefs.h"
#include <stdlib.h>

typedef struct ProQueue ProQueue;


void (*PrintMsg)(void* _msg);


ProQueue*  ProQueueCreate(size_t _size);


void    ProQueueDestroy(ProQueue* _queue);


ADTErr  ProQueueInsert(ProQueue* _queue, void* _item);


ADTErr  ProQueueRemove(ProQueue* _queue, void** _item);


int     ProQueueIsEmpty(ProQueue* _queue);


void    ProQueuePrint(ProQueue* _queue);


#endif/*#ifndef __PROQUEUE_H__*/

