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

typedef struct Node Node;
typedef Node* Iterator;

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
    Iterator iterator;
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
    *_removedElement = _list->m_head.m_next->m_data;
    _list->m_head.m_next->m_next->m_prev = &_list->m_head;
    _list->m_head.m_next = _list->m_head.m_next->m_next;
    return ERR_OK;
}

void ListPrint(List* _list, ElementFunc _elemPrintFunc)
{
    Iterator iterator;
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

