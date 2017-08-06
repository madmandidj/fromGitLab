/*
Filename: 		GenericDLL.c 
Description:	Implementation of generic DLL API
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	06/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "GenericDoubleLinkedList.h"
#define MAGIC_NUM 0x00002000; /* DLL Magic Num is 0x00002000*/

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

/* 
Static functions to add:
Create Node
Insert Node
Remove Node
Delete Node
Check NULL
Check Data (use void pointer to make generic)
Check Empty
*/



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
void ListDestroy(List** _list, UserActionFunc _destoryFunc)
{
	Node* curN;
	
	if (NULL != *_list  && MAGIC_NUM == *_list->m_magicNum)
	{
		if (*_list->m_head.m_next != &(*_list->m_tail))
		{
			curN = *_list->m_head.m_next;
			while(curN->m_next != &(*_list->m_tail))
			{
				_destoryFunc(curN->m_data);
				curN = curN->m_next;
				free(curN->m_prev);
				
			}
			_destoryFunc(curN->m_data);
			free(curN);
		}
		*_list->m_magicNum = 0;
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
			_list->m_head.m_next =  _list->m_head.m_next->m_next;
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
	int result = 1;
	if (NULL == _list)
	{
		result = -1;
	}
	else if (_list->m_head.m_next != &(_list->m_tail))
	{
		result = 0;
	}
	return result;
}









/******
LIST PRINT
******/
void	ListPrint(List* _list)
{
	Node* curN;
	if (NULL != _list)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			curN = _list->m_head.m_next;
			while(curN->m_next != &(_list->m_tail))
			{
				printf("%d\n", curN->m_data);
				curN = curN->m_next;
			}
			printf("%d\n", curN->m_data);
		}
	}
	return;
}




