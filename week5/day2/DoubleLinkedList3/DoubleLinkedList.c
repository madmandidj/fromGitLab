/*
Filename: 		DoubleLinkedList.c 
Description:	Implementation of DLL API
Created: 		16/07/17
Created by:		Eyal Alon
Last modified: 	17/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

typedef struct Node Node;

struct Node
{
	int 	m_data;
	Node*	m_next;
	Node*	m_prev;
};

struct List
{
	Node m_head;
	Node m_tail;
	size_t m_magicNum;
};

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

void	ListDestroy(List* _list)
{
	Node* curN;
	if (NULL != _list  && MAGIC_NUM == _list->m_magicNum)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			curN = _list->m_head.m_next;
			while(curN->m_next != &(_list->m_tail))
			{
				curN = curN->m_next;
				free(curN->m_prev);
			}
			free(curN);
		}
		/* Change magic number to protect against double free of list */
		_list->m_magicNum = 0;
		free (_list);
	}
	return;
}

ADTErr	ListPushHead(List* _list, int _data)
{
	Node* node;
	if (NULL != _list)
	{
		node = malloc(sizeof(node));
		if (NULL == _list)
		{
			return ERR_ALLOCATION_FAILED;
		}
		node->m_data = _data;
		/* Set new node next to point to item1/tail */
		node->m_next = _list->m_head.m_next;
		/* Set new node previous to point to head */
		node->m_prev = &(_list->m_head);
		/* Set head next to point to node*/
		node->m_prev->m_next = node;
		/* Set item1/tail previous to point to node*/
		node->m_next->m_prev = node;
	}
	else
	{
		return ERR_NOT_INITIALIZED;	
	}
	return ERR_OK;
}

ADTErr	ListPushTail(List* _list, int _data)
{
	Node* node;
	if (NULL != _list)
	{
		node = malloc(sizeof(node));
		if (NULL == _list)
		{
			return ERR_ALLOCATION_FAILED;
		}
		node->m_data = _data;
		/* Set new node prev to point to last item/head */
		node->m_prev = _list->m_tail.m_prev;
		/* Set new node next to point to tail */
		node->m_next = &(_list->m_tail);
		/* Set tail prev to point to node */
		node->m_next->m_prev = node;
		/* Set last item/head next to point to node */
		node->m_prev->m_next = node;
	}
	else
	{
		return ERR_NOT_INITIALIZED;	
	}
	return ERR_OK;
}

ADTErr	ListPopHead(List* _list, int* _data)
{
	Node* freeNode;
	if (NULL != _list && NULL != _data)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			freeNode = _list->m_head.m_next;
			*_data = _list->m_head.m_next->m_data;
			/* Set 2nd item/tail prev to point to head */
			_list->m_head.m_next->m_next->m_prev = &(_list->m_head);
			/* Set head next to point to 2nd item/tail */
			_list->m_head.m_next =  _list->m_head.m_next->m_next;
			free(freeNode);
		}
		else
		{
			return ERR_EMPTY_LIST;
		}
	}
	else
	{
		return ERR_NOT_INITIALIZED;	
	}
	return ERR_OK;
}

ADTErr	ListPopTail(List* _list, int* _data)
{
	Node* freeNode;
	if (NULL != _list && NULL != _data)
	{
		if (_list->m_head.m_next != &(_list->m_tail))
		{
			freeNode = _list->m_tail.m_prev;
			*_data = _list->m_tail.m_prev->m_data;
			/* Set 2nd last item/head next to point to tail */
			_list->m_tail.m_prev->m_prev->m_next = &(_list->m_tail);
			/* Set tail prev to point to 2nd last item/head */
			_list->m_tail.m_prev =  _list->m_tail.m_prev->m_prev;
			free(freeNode);
		}
		else
		{
			return ERR_EMPTY_LIST;
		}
	}
	else
	{
		return ERR_NOT_INITIALIZED;	
	}
	return ERR_OK;
}

size_t	ListCountItems(List* _list)
{
	Node* curN;
	size_t nItems = 0;
	if (NULL != _list)
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

int		ListIsEmpty(List* _list)
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
