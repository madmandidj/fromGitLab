/*
Filename: 		GenericDLL.h 
Description:	Contains generic DLL (Double Linked List) API.
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	06/08/17
Modified by:	Eyal Alon
*/

#ifndef __GENERICDLL_H__
#define __GENERICDLL_H__

#include <stdlib.h>
#include "ADTDefs.h"

typedef struct List List;
typedef int	(*ListElementAction)(void* _element, size_t _index, void* _context);
typedef void (*ElementDestroy)(void* _item);


List* 	ListCreate(void);


void	ListDestroy(List** _list, ElementDestroy _elementDestroy);


ADTErr	ListPushHead(List* _list, void* _data);


ADTErr	ListPushTail(List* _list, void* _data);


ADTErr	ListPopHead(List* _list, void** _data);


ADTErr	ListPopTail(List* _list, void** _data);


size_t	ListCountItems(List* _list);


int		ListIsEmpty(List* _list);


void	ListPrint(List* _list);


size_t 	ListForEach(const List* _list, ListElementAction _action, void* _context);

#endif /* #ifndef __GENERICDLL_H__ */
