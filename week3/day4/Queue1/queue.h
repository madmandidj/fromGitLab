#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "ADTDefs.h"

typedef struct Queue Queue;

Queue*  QueueCreate(size_t _size);
void    QueueDestroy(Queue* _queue);
ADTErr  QueueInsert(Queue* _queue, int _item);
ADTErr  QueueRemove(Queue* _queue, int* _item);
int     QueueIsEmpty(Queue* _queue);
void    QueuePrint(Queue* _queue);


#endif/*#ifndef __QUEUE_H__*/
