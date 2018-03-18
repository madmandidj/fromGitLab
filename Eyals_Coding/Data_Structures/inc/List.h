#ifndef __LIST_H__
#define __LIST_H__
#include "ADTErr.h"

typedef struct List List;
typedef struct Node Node;
typedef Node* ListItr;
typedef void(*ElementFunc)(void*);

List* ListCreate();
void ListDestroy(List* _list, ElementFunc _elemDestroyFunc);
ADTErr ListPushHead(List* _list, void* _element);
ADTErr ListPopHead(List* _list, void** _removedElement);
ADTErr ListPushTail(List* _list, void* _element);
ADTErr ListPopTail(List* _list, void** _removedElement);
void ListPrint(List* _list, ElementFunc _elemPrintFunc);

ListItr ListItrBegin(List* _list);
ListItr ListItrEnd(List* _list);
void* ListItrGet(ListItr _itr);
ListItr ListItrSet(ListItr _itr, void* _element);
ListItr ListItrNext(ListItr _itr);
ListItr ListItrPrev(ListItr _itr);
ListItr ListInsertAfter(ListItr _itr, void* _element);


#endif/*#ifndef __LIST_H__*/

