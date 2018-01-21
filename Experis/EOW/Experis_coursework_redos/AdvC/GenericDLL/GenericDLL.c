#include "GenericDLL.h"
#include <stdlib.h>
#define LIST_MAGIC_NUM 0xDEADBEEF
#define IS_NULL(T) (!(T))
#define IS_A_DLL(T) ((T) && (LIST_MAGIC_NUM == (T)->m_magicNum)) 
/**********************************/
/*******Struct definitions*********/
/**********************************/
struct DLL
{
	int 	m_magicNum;
	Node 	m_head;
	Node 	m_tail;
};

struct Node
{
	void*	m_data;
	Node*	m_next;
	Node*	m_prev;
};
/**********************************/
/********Iterator Functions********/
/**********************************/
Itr ListItrBegin(DLL* _dll)
{
	if (!IS_A_DLL(_dll))
	{
		return NULL;
	}
	return _dll.m_head->m_next;
}

Itr ListItrEnd(DLL* _dll)
{
	if (!IS_A_DLL(_dll))
	{
		return NULL;
	}
	return _dll.m_tail->m_prev;
}

Itr ListItrNext(Itr _itr)
{
	
}
/**********************************/
/********Static Functions**********/
/**********************************/
static void InitDLL(DLL* _dll)
{
	dll->m_magicNum = LIST_MAGIC_NUM;
	dll->m_data = NULL;
	dll.m_head->m_data = NULL;
	dll.m_tail->m_data = NULL;
	dll.m_head->m_next = &dll.m_tail;
	dll.m_head->m_prev = NULL;
	dll.m_tail->m_prev = &dll.m_head;
	dll.m_tail->m_next = NULL;
}
/**********************************/
/**********API Functions***********/
/**********************************/
DLL* DLLCreate()
{
	DLL* dll;
	if (NULL == (dll = malloc(sizeof(DLL))))
	{
		return NULL;
	}
	InitDLL(dll);
	return dll;
}

void DLLDestroy(DLL* _dll, UserActionFunc _destroyFunc)
{
	if (!IS_A_DLL(_dll))
	{
		return;
	}
	DLLForEach
}









