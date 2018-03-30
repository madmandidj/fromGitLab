#ifndef __LIST_H__
#define __LIST_H__
#include "ADTErr.h"

typedef struct List List;
typedef struct Node Node;
typedef Node* ListItr;
#ifndef __ELEMENT_FUNC__
#define __ELEMENT_FUNC__
	typedef void(*ElementFunc)(void*);
#endif /*__ELEMENT_FUNC__*/

List* ListCreate();
void ListDestroy(List* _list, ElementFunc _elemDestroyFunc);
ADTErr ListPushHead(List* _list, void* _element);
ADTErr ListPopHead(List* _list, void** _removedElement);
ADTErr ListPushTail(List* _list, void* _element);
ADTErr ListPopTail(List* _list, void** _removedElement);
void ListPrint(List* _list, ElementFunc _elemPrintFunc);

ListItr ListItrBegin(List* _list);
ListItr ListItrEnd(List* _list);
ListItr ListItrFirst(List* _list);
ListItr ListItrLast(List* _list);
void* ListItrGet(ListItr _itr);
ListItr ListItrSet(ListItr _itr, void* _element);
ListItr ListItrNext(ListItr _itr);
ListItr ListItrPrev(ListItr _itr);
ListItr ListItrInsertAfter(ListItr _itr, void* _element);
ListItr ListItrInsertBefore(ListItr _itr, void* _element);
ListItr ListItrRemove(List* _list, ListItr _itr, void** _removedElement); /*should all itr functions have list as param?*/


#endif/*#ifndef __LIST_H__*/

