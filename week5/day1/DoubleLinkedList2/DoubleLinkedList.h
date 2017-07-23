/*
Filename: 		DoubleLinkedList.h 
Description:	Contains DLL (Double Linked List) API given by Izik.
Created: 		16/07/17
Created by:		Eyal Alon
Last modified: 	17/07/17
Modified by:	Eyal Alon
*/
#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__
#define MAGIC_NUM 17

#include "ADTDefs.h"

typedef struct List List;
/*
Desc: Create double linked list
In:	void
Out: Pointer to created list
Err: If no memory available, NULL returned
*/
List* 	ListCreate(void);
/*
Desc: Destroy double linked list
In:	Pointer to list to destroy
Out: void
Err: No errors. List double free protection.
*/
void	ListDestroy(List* _list);
/*
Desc: Insert new head to double linked list
In:	Pointer to existing list, integer value for new head data 
Out: ADTErr = ERR_OK if no errors
Err: ERR_ALLOCATION_FAILED, ERR_NOT_INITIALIZED
*/
ADTErr	ListPushHead(List* _list, int _data);
/*
Desc: Insert new tail to double linked list
In:	Pointer to existing list, integer value for new tail data 
Out: ADTErr = ERR_OK if no errors
Err: ERR_ALLOCATION_FAILED, ERR_NOT_INITIALIZED
*/
ADTErr	ListPushTail(List* _list, int _data);
/*
Desc: Remove head from double linked list
In:	Pointer to existing list, integer pointer to hold data value of removed head 
Out: ADTErr = ERR_OK if no errors
Err: ERR_EMPTY_LIST, ERR_NOT_INITIALIZED
*/
ADTErr	ListPopHead(List* _list, int* _data);
/*
Desc: Remove tail from double linked list
In:	Pointer to existing list, integer pointer to hold data value of removed tail 
Out: ADTErr = ERR_OK if no errors
Err: ERR_EMPTY_LIST, ERR_NOT_INITIALIZED
*/
ADTErr	ListPopTail(List* _list, int* _data);
/*
Desc: Count the current number of list items
In:	Pointer to existing list
Out: ADTErr = ERR_OK if no errors
Err: ERR_EMPTY_LIST, ERR_NOT_INITIALIZED
*/ 
size_t	ListCountItems(List* _list);
int		ListIsEmpty(List* _list);

void	ListPrint(List* _list);

#endif /* #ifndef __DOUBLELINKEDLIST_H__ */
