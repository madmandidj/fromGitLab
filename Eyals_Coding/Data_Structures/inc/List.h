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
size_t ListItemsNum(List* _list);
void ListPrint(List* _list, ElementFunc _elemPrintFunc);

/* Returns iterator to beginning sentinel */
ListItr ListItrBegin(List* _list);
/* Returns iterator to end sentinel */
ListItr ListItrEnd(List* _list);
/* Returns iterator to first element or end sentinel (if empty) */
ListItr ListItrFirst(List* _list);
/* Returns iterator to last element or beginning sentinel (if empty) */
ListItr ListItrLast(List* _list);
void* ListItrGet(ListItr _itr);
ListItr ListItrSet(ListItr _itr, void* _element);
/* Returns iterator to next element or end sentinel (if empty) */
ListItr ListItrNext(ListItr _itr);
/* Returns iterator to previous element or beginning sentinel (if empty) */
ListItr ListItrPrev(ListItr _itr);
/* Returns iterator to new element in list */
ListItr ListItrInsertAfter(List* _list, ListItr _itr, void* _element);
/* Returns iterator to new element in list */
ListItr ListItrInsertBefore(List* _list, ListItr _itr, void* _element);
/* Returns iterator to the element before the one removed or beginning/end sentinel */
ListItr ListItrRemove(List* _list, ListItr _itr, void** _removedElement); /*should all itr functions have list as param?*/


#endif/*#ifndef __LIST_H__*/

