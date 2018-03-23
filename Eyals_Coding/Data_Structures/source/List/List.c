#include <stdlib.h>
#include "../../inc/List.h"

#define IS_A_LIST(L) ((L))
#define IS_LIST_EMPTY(L) (LIST_FIRST(L) == LIST_END(L))
#define LIST_FIRST(L) ((L)->m_head.m_next)
#define LIST_LAST(L) ((L)->m_tail.m_prev)
#define LIST_BEGIN(L) (&(L)->m_head)
#define LIST_END(L) (&(L)->m_tail)

#define NODE_DATA(N) ((N)->m_data)
#define NODE_NEXT(N) ((N)->m_next)
#define NODE_PREV(N) ((N)->m_prev)

#define ITR_DATA(I) ((Node*)(I)->m_data)
#define ITR_NEXT(I) ((Node*)(I)->m_next)
#define ITR_PREV(I) ((Node*)(I)->m_prev)

/*typedef struct Node Node;*/
/*typedef Node* ListItr;*/

struct Node
{
    void* m_data;
    Node* m_next;
    Node* m_prev;
};

struct List
{
    Node m_head;
    Node m_tail;
};

List* ListCreate()
{
    List* list;
    if (!(list = malloc(sizeof(List))))
    {
        return NULL;
    }
    LIST_FIRST(list) = LIST_END(list);
    LIST_LAST(list) = LIST_BEGIN(list);
    list->m_head.m_prev = NULL;
    list->m_tail.m_next= NULL;
    return list;
}

void ListDestroy(List* _list, ElementFunc _elemDestroyFunc)
{
    ListItr iterator;
    if (!_list)
    {
        return;
    }
    if (_elemDestroyFunc)
    {
        iterator = LIST_FIRST(_list);
        while(LIST_END(_list) != iterator)
        {
            _elemDestroyFunc(ITR_DATA(iterator));
            iterator = ITR_NEXT(iterator);
        }
    }
    free(_list);
}

ADTErr ListPushHead(List* _list, void* _element)
{
    Node* newNode;
    if (!_list || !_element)
    {
        return ERR_INVARG;
    }
    if (!(newNode = malloc(sizeof(Node))))
    {
        return ERR_NOMEM;
    }
    NODE_DATA(newNode) = _element;
    NODE_NEXT(newNode) = LIST_FIRST(_list);
    NODE_PREV(newNode) = LIST_BEGIN(_list);
    NODE_PREV(LIST_FIRST(_list)) = newNode;
    LIST_FIRST(_list) = newNode;
    return ERR_OK;
}

ADTErr ListPopHead(List* _list, void** _removedElement)
{
    if (!_list || !_removedElement)
    {
        return ERR_INVARG;
    }
    if (LIST_FIRST(_list) == LIST_END(_list))
    {
    	*_removedElement = NULL;
    }
    else
    {
		*_removedElement = NODE_DATA((LIST_FIRST(_list)));
		NODE_PREV(NODE_NEXT(LIST_FIRST(_list))) = LIST_BEGIN(_list);
		LIST_FIRST(_list) = NODE_NEXT(LIST_FIRST(_list));
    }
    return ERR_OK;
}

ADTErr ListPushTail(List* _list, void* _element)
{
	Node* newNode;
	if (!_list || !_element)
    {
        return ERR_INVARG;
    }
    if (!(newNode = malloc(sizeof(Node))))
    {
        return ERR_NOMEM;
    }
    NODE_DATA(newNode) = _element;
    NODE_NEXT(newNode) = LIST_END(_list);
    NODE_PREV(newNode) = LIST_LAST(_list);
    NODE_NEXT(LIST_LAST(_list)) = newNode;
    LIST_LAST(_list) = newNode;
    return ERR_OK;
}

ADTErr ListPopTail(List* _list, void** _removedElement)
{
	if (!_list || !_removedElement)
    {
        return ERR_INVARG;
    }
    if (LIST_LAST(_list) == LIST_BEGIN(_list))
    {
    	*_removedElement = NULL;
    }
    else
    {
		*_removedElement = NODE_DATA((LIST_LAST(_list)));
		NODE_NEXT(NODE_PREV(LIST_LAST(_list))) = LIST_END(_list);
		LIST_LAST(_list) = NODE_PREV(LIST_LAST(_list));
	}
    return ERR_OK;
}

void ListPrint(List* _list, ElementFunc _elemPrintFunc)
{
    ListItr iterator;
    if (!_list || !_elemPrintFunc)
    {
        return;
    }
    iterator = LIST_FIRST(_list);
    while(LIST_END(_list) != iterator)
    {
        _elemPrintFunc(ITR_DATA(iterator));
        iterator = ITR_NEXT(iterator);
    }
}


/*TODO: ForEach() */


/**********************
List iterator functions
**********************/



ListItr ListItrBegin(List* _list)
{
	if (!_list)
    {
        return NULL;
    }
    return (ListItr) LIST_BEGIN(_list);
}

ListItr ListItrEnd(List* _list)
{
	if (!_list)
    {
        return NULL;
    }
    return (ListItr) LIST_END(_list);
}

ListItr ListItrFirst(List* _list)
{
	if (!_list)
    {
        return NULL;
    }
    return (ListItr) LIST_FIRST(_list);
}

ListItr ListItrLast(List* _list)
{
	if (!_list)
    {
        return NULL;
    }
    return (ListItr) LIST_LAST(_list);
}

void* ListItrGet(ListItr _itr)
{
	if (!_itr)
    {
        return NULL;
    }
    return ITR_DATA(_itr);
}

ListItr ListItrSet(ListItr _itr, void* _element)
{
	if (!_itr || !_element)
    {
        return _itr;
    }
    NODE_DATA(_itr) = _element;
    return _itr;
}

ListItr ListItrNext(ListItr _itr)
{
	if (!_itr)
    {
        return NULL;
    }
    if (ITR_NEXT(_itr) == 0)
    {
    	return _itr;
    }
    return (ListItr) ITR_NEXT(_itr);
}

ListItr ListItrPrev(ListItr _itr)
{
	if (!_itr)
    {
        return NULL;
    }
    if (ITR_PREV(_itr) == 0)
    {
    	return _itr;
    }
    return (ListItr) ITR_PREV(_itr);
}

ListItr ListItrInsertAfter(ListItr _itr, void* _element)
{
	Node* newNode;
    if (!_itr || !_element || ListItrNext(_itr) == 0)
    {
        return _itr;
    }
    if (!(newNode = malloc(sizeof(Node))))
    {
        return _itr;
    }
    NODE_DATA(newNode) = _element;
    NODE_NEXT(newNode) = ITR_NEXT(_itr);
    NODE_PREV(newNode) = (Node*) _itr;
    NODE_PREV(ITR_NEXT(_itr)) = newNode;
    NODE_NEXT((Node*)_itr) = newNode;
	return (ListItr) newNode;
}

ListItr ListItrInsertBefore(ListItr _itr, void* _element)
{
	Node* newNode;
    if (!_itr || !_element || ListItrPrev(_itr) == 0)
    {
        return _itr;
    }
    if (!(newNode = malloc(sizeof(Node))))
    {
        return _itr;
    }
    NODE_DATA(newNode) = _element;
    NODE_NEXT(newNode) = (Node*) _itr;
    NODE_PREV(newNode) = ITR_PREV(_itr);
    NODE_NEXT(ITR_PREV(_itr)) = newNode;
    NODE_PREV((Node*)_itr) = newNode;
	return (ListItr) newNode;
}

ListItr ListItrRemove(List* _list, ListItr _itr, void** _removedElement)
{
	if (!_itr || !_removedElement || (Node*) _itr == LIST_BEGIN(_list) || (Node*) _itr == LIST_END(_list) )
    {
    	*_removedElement = NULL;
        return _itr;
    }
	*_removedElement = ITR_DATA(_itr);
	NODE_PREV(ITR_NEXT(_itr)) = ITR_PREV(_itr);
	NODE_NEXT(ITR_PREV(_itr)) = ITR_NEXT(_itr);
/*	_itr = ITR_PREV(_itr);*/
	return ITR_PREV(_itr);
    
}











