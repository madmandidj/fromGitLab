#ifndef __PROQUEUE_H__
#define __PROQUEUE_H__

#define _GNU_SOURCE

#include "ADTDefs.h"
#include <stdlib.h>

/*
Filename: 		queue.h 
Description:	queue API 
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	29/07/17
Modified by:	Eyal Alon
*/
typedef struct Queue Queue;

/*
	Function name: QueueCreate
	Input:	"size_t" size of integer array
	Output: "Queue*" Queue-type pointer
	Error:	NULL if allocation failed, or size is zero
*/
Queue*  ProQueueCreate(size_t _size);


/*
	Function name: QueueDestroy
	Input:	"Queue*" Queue-type pointer
	Output: void
	Error:	NA
*/
void    ProQueueDestroy(Queue* _queue);


/*
	Function name: QueueInsert
	Input:	"Queue*" Queue-type pointer, "void*" pointer to insert
	Output: "ADTErr" error-type, ERR_OK
	Error:	ERR_NOT_INITIALIZED, ERR_FULL 
*/
ADTErr  ProQueueInsert(Queue* _queue, void* _item);


/*
	Function name: QueueRemove
	Input:	"Queue*" Queue-type pointer, "int*" integer pointer to removed value
	Output: "ADTErr" error-type, ERR_OK
	Error:	ERR_NOT_INITIALIZED, ERR_EMPTY
*/
ADTErr  ProQueueRemove(Queue* _queue, void** _item);


/*
	Function name: QueueIsEmpty
	Input:	"Queue*" Queue-type pointer
	Output: "int" 1 if empty, 0 if not empty
	Error:	NA
*/
int     ProQueueIsEmpty(Queue* _queue);


/*
	Function name: QueuePrint (This is not part of the API)
	Input:	"Queue*" Queue-type pointer
	Output: void
	Error:	NA
*/
void    ProQueuePrint(Queue* _queue);


#endif/*#ifndef __PROQUEUE_H__*/

