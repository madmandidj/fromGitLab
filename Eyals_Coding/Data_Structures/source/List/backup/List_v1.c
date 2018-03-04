#include <stdlib.h>
#include "../../inc/List.h"

typedef struct Node Node;
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
    list->m_head.m_next = &list->m_tail;
    list->m_tail.m_prev = &list->m_head;
    list->m_head.m_prev = NULL;
    list->m_tail.m_next= NULL;
    return list;
}

void ListDestroy(List* _list, ElementFunc _elemDestroyFunc)
{
    Node** iterator = NULL;
    if (!_list)
    {
        return;
    }
    if (_elemDestroyFunc)
    {
        /*TODO: this needs debugging */
        *iterator = (_list->m_head).m_next;
        while(&(_list->m_tail) != *iterator)
        {
            _elemDestroyFunc((*iterator)->m_data);
            *iterator = (*iterator)->m_next;
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
    newNode->m_data = _element;
    newNode->m_next = _list->m_head.m_next;
    newNode->m_prev = &_list->m_head;
    _list->m_head.m_next->m_prev = newNode;
    _list->m_head.m_next = newNode;
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
    Node** iterator = NULL;
    if (!_list || !_elemPrintFunc)
    {
        return;
    }
    iterator = &_list->m_head.m_next;
    while(&(_list->m_tail) != *iterator)
    {
        _elemPrintFunc((*iterator)->m_data);
        iterator = &(*iterator)->m_next;
    }
}

/*TODO: ForEach() */

