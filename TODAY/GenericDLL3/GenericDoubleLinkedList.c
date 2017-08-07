/*
Filename: 		GenericDoubleLinkedList.c 
Description:	Implementation of generic DLL API
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	06/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "GenericDoubleLinkedList.h"
#define MAGIC_NUM 0x00002000 /* Generic DLL Magic Num is 0x00002000*/
#define TRUE 1
#define FALSE 0

/*
TODO: factorize all functions
*/

typedef struct Node Node;

struct Node
{
	void* 	m_data;
	Node*	m_next;
	Node*	m_prev;
};

struct List
{
	size_t m_magicNum;
	Node m_head;
	Node m_tail;
};









/******
LIST CREATE
******/
List* 	ListCreate(void)
{
	List* list;
	
	list = malloc(sizeof(List));
	if (NULL == list)
	{
		return NULL;
	}
	list->m_head.m_next = &(list->m_tail);
	list->m_head.m_prev = NULL;
	list->m_tail.m_prev = &(list->m_head);
	list->m_tail.m_next = NULL;
	list->m_magicNum = MAGIC_NUM;
	return list;
}









/******
LIST DESTROY
******/
void ListDestroy(List** _list, UserActionFunc _destroyFunc)
{
	Node* curN;
	
	if (NULL != _list && NULL != *_list && MAGIC_NUM == (*_list)->m_magicNum)
	{
		if ((*_list)->m_head.m_next != &((*_list)->m_tail))
		{
			curN = (*_list)->m_head.m_next;
			while(curN->m_next != &((*_list)->m_tail))
			{
				curN = curN->m_next;
				if (_destroyFunc != NULL)
				{
					_destroyFunc(curN->m_prev->m_data, NULL);
				}
				free(curN->m_prev);
				
			}
			if (_destroyFunc != NULL)
			{
				_destroyFunc(curN->m_data, NULL);
			}
			free(curN);
		}
		(*_list)->m_magicNum = 0;
		free(*_list);
		*_list = NULL;
	}
	return;
}









/******
LIST PUSH HEAD
******/
ListErrors	ListPushHead(List* _list, void* _data)
{
	Node* node;
	
	if (NULL != _list && MAGIC_NUM == _list->m_magicNum)
	{
		node = malloc(sizeof(Node));
		if (NULL == node)
		{
			return LIST_ALLOCATION_FAILED;
		}
		node->m_data = _data;
		node->m_next = _list->m_head.m_next;
		node->m_prev = &(_list->m_head);
		node->m_prev->m_next = node;
		node->m_next->m_prev = node;
	}
	else
	{
		return LIST_UNINITIALIZED;	
	}
	return LIST_OK;
}









/******
LIST PUSH TAIL
******/
ListErrors	ListPushTail(List* _list, void* _data)
{
	Node* node;
	
	if (NULL != _list && MAGIC_NUM == _list->m_magicNum)
	{
		node = malloc(sizeof(Node));
		if (NULL == node)
		{
			return LIST_ALLOCATION_FAILED;
		}
		node->m_data = _data;
		node->m_prev = _list->m_tail.m_prev;
		node->m_next = &(_list->m_tail);
		node->m_next->m_prev = node;
		node->m_prev->m_next = node;
	}
	else
	{
		return LIST_UNINITIALIZED;	
	}
	return LIST_OK;
}









/******
LIST POP HEAD
******/
ListErrors ListPopHead(List* _list, void* *_data)
{
	Node* freeNode;
	
	if (NULL != _list && NULL != _data && MAGIC_NUM == _list->m_magicNum)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			*_data = _list->m_head.m_next->m_data;
			freeNode = _list->m_head.m_next;
			_list->m_head.m_next->m_next->m_prev = &(_list->m_head);
			_list->m_head.m_next = _list->m_head.m_next->m_next;
			free(freeNode);
		}
		else
		{
			return LIST_IS_EMPTY;
		}
	}
	else
	{
		return LIST_UNINITIALIZED;	
	}
	return LIST_OK;
}









/******
LIST POP TAIL
******/
ListErrors ListPopTail(List* _list, void* *_data)
{
	Node* freeNode;
	
	if (NULL != _list && NULL != _data && MAGIC_NUM == _list->m_magicNum)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			*_data = _list->m_tail.m_prev->m_data;
			freeNode = _list->m_tail.m_prev;
			_list->m_tail.m_prev->m_prev->m_next = &(_list->m_tail);
			_list->m_tail.m_prev =  _list->m_tail.m_prev->m_prev;
			free(freeNode);
		}
		else
		{
			return LIST_IS_EMPTY;
		}
	}
	else
	{
		return LIST_UNINITIALIZED;	
	}
	return LIST_OK;
}









/******
LIST COUNT ITEMS
******/
size_t	ListCountItems(const List* _list)
{
	Node* curN;
	
	size_t nItems = 0;
	if (NULL != _list && MAGIC_NUM == _list->m_magicNum)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			curN = _list->m_head.m_next;
			while(curN->m_next != &(_list->m_tail))
			{
				++nItems;
				curN = curN->m_next;
			}
			++nItems;
		}
	}
	return nItems;
}









/******
LIST IS EMPTY
******/
int		ListIsEmpty(const List* _list)
{
	int result = TRUE;
	if (NULL == _list || MAGIC_NUM != _list->m_magicNum)
	{
		result = -1;
	}
	else if (_list->m_head.m_next != &(_list->m_tail))
	{
		result = FALSE;
	}
	return result;
}









/******
LIST FIND FIRST FORWARD
******/
ListErrors FindFirstForward(const List* _list, PredicateFunc _predicateFunc, void* _context, void* *_item)
{
	Node* curN;
	int isFound = FALSE;
	if (NULL == _list || NULL == _predicateFunc || NULL == _item || MAGIC_NUM != _list->m_magicNum)
	{
		return LIST_UNINITIALIZED;
	}
	if (_list->m_head.m_next == &(_list->m_tail))
	{
		return LIST_IS_EMPTY;
	}
	curN = _list->m_head.m_next;
	while(curN->m_next != &(_list->m_tail))
	{
		isFound = _predicateFunc(curN->m_data, _context);
		if (isFound)
		{
			*_item = curN->m_data;
			return LIST_OK;
		}
		curN = curN->m_next;
	}
	*_item = NULL;
	return LIST_ITEM_NOT_FOUND;
}









/******
LIST FIND FIRST BACKWARD
******/
ListErrors FindFirstBackward(const List* _list, PredicateFunc _predicateFunc, void* _context, void* *_item)
{
	Node* curN;
	int isFound = FALSE;
	if (NULL == _list || NULL == _predicateFunc || NULL == _item || MAGIC_NUM != _list->m_magicNum)
	{
		return LIST_UNINITIALIZED;
	}
	if (_list->m_head.m_next == &(_list->m_tail))
	{
		return LIST_IS_EMPTY;
	}
	curN = _list->m_tail.m_prev;
	while(curN->m_prev != &(_list->m_head))
	{
		isFound = _predicateFunc(curN->m_data, _context);
		if (isFound)
		{
			*_item = curN->m_data;
			return LIST_OK;
		}
		curN = curN->m_prev;
	}
	*_item = NULL;
	return LIST_ITEM_NOT_FOUND;
}









/******
LIST FOR EACH 
******/
static size_t CheckListForEachParams(const List* _list, UserActionFunc _action)
{
	if (NULL == _list || NULL == _action || MAGIC_NUM != _list->m_magicNum)
	{
		return 0;
	}
	return 1;
}

static size_t DoListForEach(const List* _list, UserActionFunc _action, void* _context)
{
	size_t actionCount = 0;
	int result = 0;
	Node* curN;
	if (_list->m_head.m_next != &_list->m_tail)
	{
		curN = _list->m_head.m_next;
		while(curN->m_next != &_list->m_tail)
		{
			result = _action(curN->m_data, _context);
			if (result == 0)
			{
				return actionCount;
			}
			++actionCount;
			curN = curN->m_next;
		}
		result = _action(curN->m_data, _context);
		if (result == 0)
		{
			return actionCount;
		}
		++actionCount;
	}
	return actionCount;
}

size_t ListForEach(const List* _list, UserActionFunc _action, void* _context)
{
	if (CheckListForEachParams(_list, _action) == 0)
	{
		return 0;
	}
	return DoListForEach(_list, _action, _context);
}







