#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "ADTDefs.h"
/*
	"Queue.h": Queue implemented with an integer array 
*/
typedef struct Queue Queue;

/*
	Function name: QueueCreate
	Input:	"size_t" size of integer array
	Output: "Queue*" Queue-type pointer
	Error:	NULL if allocation failed, or size is zero
*/
Queue*  QueueCreate(size_t _size);
/*
	Function name: QueueDestroy
	Input:	"Queue*" Queue-type pointer
	Output: void
	Error:	NA
*/
void    QueueDestroy(Queue* _queue);
/*
	Function name: QueueInsert
	Input:	"Queue*" Queue-type pointer, "int" integer value to insert
	Output: "ADTErr" error-type, ERR_OK
	Error:	ERR_NOT_INITIALIZED, ERR_FULL 
*/
ADTErr  QueueInsert(Queue* _queue, int _item);
/*
	Function name: QueueRemove
	Input:	"Queue*" Queue-type pointer, "int*" integer pointer to removed value
	Output: "ADTErr" error-type, ERR_OK
	Error:	ERR_NOT_INITIALIZED, ERR_EMPTY
*/
ADTErr  QueueRemove(Queue* _queue, int* _item);
/*
	Function name: QueueIsEmpty
	Input:	"Queue*" Queue-type pointer
	Output: "int" 1 if empty, 0 if not empty
	Error:	NA
*/
int     QueueIsEmpty(Queue* _queue);
/*
	Function name: QueuePrint (This is not part of the API)
	Input:	"Queue*" Queue-type pointer
	Output: void
	Error:	NA
*/
void    QueuePrint(Queue* _queue);

#endif/*#ifndef __QUEUE_H__*/

