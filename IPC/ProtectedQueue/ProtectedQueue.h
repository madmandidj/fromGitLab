#ifndef __PROQUEUE_H__
#define __PROQUEUE_H__

#define _GNU_SOURCE
#define P_ATND_SEM "pSem"


#include "ADTDefs.h"
#include <stdlib.h>




typedef struct Queue Queue;


Queue*  ProQueueCreate(size_t _size);



void    ProQueueDestroy(Queue* _queue);



ADTErr  ProQueueInsert(Queue* _queue, void* _item);



ADTErr  ProQueueRemove(Queue* _queue, void** _item);



int     ProQueueIsEmpty(Queue* _queue);



void    ProQueuePrint(Queue* _queue);


#endif/*#ifndef __PROQUEUE_H__*/

