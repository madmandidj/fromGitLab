/*
Filename: 		list_functions.c 
Description:	Implementation of list functions
Created: 		06/08/17
Created by:		Eyal Alon
Last modified: 	08/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>      /* printf */
#include <string.h>     /* strcpy */
#include "../../inc/list_functions.h"
/*#include "list_functions.h"*/
#define TRUE 1
#define FALSE 0






/******
USER ACTION FUNCTIONS
******/
int PrintElementInt(int* _intPtr, void* _context)
{
    if (NULL == _intPtr)
    {
        printf("\tNULL\n");
    }
    else
    {
        printf("\t%d\n", *_intPtr);
    }
    return 1;
}

int	ElementPersonPrint(Person* _prs, size_t _index, void* _context)
{
	printf("\tName = 	\t%s, \tAge = %u\n", _prs->m_name, _prs->m_age);
	printf("\tFamily1 = \t%s, \tAge = %u\n", _prs->m_family[0]->m_name, _prs->m_family[0]->m_age);
	printf("\tFamily2 = \t%s, \tAge = %u\n", _prs->m_family[1]->m_name, _prs->m_family[1]->m_age);
	return 1;
}

void ElementDestroyPerson(Person* _item, void* _context)
{
	if (NULL != _item && NULL != _item->m_family)
	{
		free(_item->m_family);
	}
	return;
}







/******
PREDICATE FUNCTIONS
******/
int IsIntFoundInElementData(int* _intPtr, int* _key)
{
    if (NULL == _intPtr || NULL == _key)
    {
        return FALSE;
    }
    if (*_intPtr == *_key)
    {
        return TRUE;
    }
    return FALSE;
}






/******
LESS FUNCTIONS
******/
int LessThanInt(int* _a, int* _b)
{
    if (NULL == _a || NULL == _b)
    {
        return FALSE;
    }
    if (*_a < *_b)
    {
        return TRUE;
    }
    return FALSE;
}



/******
EQUALS FUNCTIONS
******/
int IsEqualsInt(int* _a, int* _b)
{
    if (NULL == _a || NULL == _b)
    {
        return 0;
    }
    if (*_a == *_b)
    {
        return 1;
    }
    return 0;
}





/******
LIST ITER COUNT IF
******/
size_t ListItr_CountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
    size_t count = 0;
    int* itrIntData;
    if (NULL == _begin || NULL == _end || NULL == _predicate || NULL == _context)
    {
        return 0;
    }
    while(_begin != _end)
    {
        itrIntData = ListItrGet(_begin);
        if (_predicate(itrIntData, _context))
        {
            ++count;
        }
        _begin = ListItrNext(_begin);
    }
    return count;
}














/******
LIST ITERATE SORT FUNCTION
******/
/*
    TODO: add check to see that begin is placed before end
    TODO: write swap function
*/

static void ItrSwapData(ListItr _a, ListItr _b, void* _aData, void* _bData)
{
    ListItrSet(_a, _bData);
    ListItrSet(_b, _aData);
    return;
}

void ListItr_Sort(ListItr _begin, ListItr _end, LessFunction _less)
{
    ListItr a;
    ListItr b;
    int* aData;
    int* bData;
    int isSorted = FALSE;

    if(NULL == _begin || NULL == _end || NULL == _less)
    {
        return;
    }   
    while (!isSorted)
    {
        isSorted = TRUE;
        a = _begin;
        b = ListItrNext(a);
        while (b != _end)
        {
            aData = ListItrGet(a);
            bData = ListItrGet(b);
            if (_less(bData, aData))
            {
                ItrSwapData(a, b, aData, bData);
                isSorted = FALSE;
            }
            a = ListItrNext(a);
            b = ListItrNext(b);
        }
        _end = ListItrPrev(_end);
    }
    return;
}






