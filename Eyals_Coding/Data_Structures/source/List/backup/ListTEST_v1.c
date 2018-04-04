#include <stdio.h>
#include <stdlib.h>
#include "../../inc/List.h"
#include "../../inc/mu_test.h"
#include "../../inc/ADTErr.h"
#include "../../../GeneralFunctions/GeneralFunctions.h"

typedef struct Person Person;
struct Person
{
    size_t m_age;
    size_t m_gender;
    Person* m_mother;  
};

void DeletePerson(Person* _personPtr)
{
    free(((Person*)_personPtr)->m_mother);
}

void PrintInt(int* _intPtr)
{
    printf("%u\n", *(size_t*)_intPtr);
}




UNIT(List_Create)
    List* list;
    list = ListCreate();
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_PushHead)
    List* list;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	ADTErr err;
    list = ListCreate();
    err = ListPushHead(list, &intArr[7]);
    ASSERT_THAT(ERR_OK == err);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_PopHead)
    List* list;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedHead;
    list = ListCreate();
    ListPushHead(list, &intArr[7]);
	ListPopHead(list, &poppedHead);
    ASSERT_THAT(7 == *(int*)poppedHead);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_PopHead_multiple)
    List* list;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedHead;
    list = ListCreate();
    ListPushHead(list, &intArr[7]);
    ListPushHead(list, &intArr[2]);
    ListPushHead(list, &intArr[4]);
    ListPushHead(list, &intArr[1]);
	ListPopHead(list, &poppedHead);
    ASSERT_THAT(1 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(4 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(2 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(7 == *(int*)poppedHead);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_PushTail)
    List* list;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedHead;
    list = ListCreate();
    ListPushHead(list, &intArr[7]);
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushHead(list, &intArr[2]);
    ListPushTail(list, &intArr[3]);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(2 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(7 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(1 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(8 == *(int*)poppedHead);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(3 == *(int*)poppedHead);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_PopTail)
    List* list;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedTail;
    list = ListCreate();
    ListPushHead(list, &intArr[7]);
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushHead(list, &intArr[2]);
    ListPushTail(list, &intArr[3]);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(3 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(8 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(1 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(7 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(2 == *(int*)poppedTail);
    ListDestroy(list, NULL);
END_UNIT


UNIT(List_Set)
    List* list;
    ListItr itr;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedTail;
	void* elementData;
    list = ListCreate();
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushTail(list, &intArr[3]);
    itr = ListItrBegin(list);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
	ListItrSet(itr, &intArr[2]);
	itr = ListItrFirst(list);
	itr = ListItrNext(itr);
	elementData = ListItrGet(itr);
	ASSERT_THAT(2 == *(int*)elementData);
	ListPopTail(list, &poppedTail);
    ASSERT_THAT(3 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(2 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(1 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(0 == poppedTail);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_InsertAfter)
    List* list;
    ListItr itr;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedTail;
    list = ListCreate();
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushTail(list, &intArr[3]);
    itr = ListItrBegin(list);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
	ListItrInsertAfter(list, itr, &intArr[2]);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(3 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(2 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(8 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(1 == *(int*)poppedTail);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_InsertBefore)
    List* list;
    ListItr itr;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedTail;
    list = ListCreate();
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushTail(list, &intArr[3]);
    itr = ListItrBegin(list);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
	ListItrInsertBefore(list, itr, &intArr[2]);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(3 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(8 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(2 == *(int*)poppedTail);
    ListPopTail(list, &poppedTail);
    ASSERT_THAT(1 == *(int*)poppedTail);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Remove)
    List* list;
    ListItr itr;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* removedElem;
    list = ListCreate();
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushTail(list, &intArr[3]);
    itr = ListItrBegin(list);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
	itr = ListItrRemove(list, itr, &removedElem);
	ASSERT_THAT(8 == *(int*)removedElem);
    itr = ListItrRemove(list, itr, &removedElem);
	ASSERT_THAT(1 == *(int*)removedElem);
	itr = ListItrNext(itr);
	itr = ListItrRemove(list, itr, &removedElem);
	ASSERT_THAT(3 == *(int*)removedElem);
	itr = ListItrRemove(list, itr, &removedElem);
	ASSERT_THAT(0 == removedElem);
    ListDestroy(list, NULL);
END_UNIT


UNIT(List_PushHead_Person)
    List* list;
    Person* person;
	ADTErr err;
    person  = malloc(sizeof(Person));
    person->m_mother = malloc(sizeof(Person));
    list = ListCreate();
    err = ListPushHead(list, person);
    ASSERT_THAT(ERR_OK == err);
    ListDestroy(list, (ElementFunc)DeletePerson);
END_UNIT



TEST_SUITE(List tests)
	/*
	TODO:
	List_PushHead_NULL_list
	List_PushHead_NULL_element
	List_PopHead_NULL_list
	List_PopHead_NULL_element
	List_PopHead_Empty_list
	List_PushTail_NULL_list
	List_PushTail_NULL_element
	List_PopTail_NULL_list
	List_PopTail_NULL_element
	List_PopTail_Empty_list
	*/
    TEST(List_Create)
	TEST(List_PushHead)
	TEST(List_PopHead)
	TEST(List_PopHead_multiple)
	TEST(List_PushTail)
	TEST(List_PopTail)
	TEST(List_Set)
	TEST(List_InsertAfter)
	TEST(List_InsertBefore)
	TEST(List_Remove)
	
	TEST(List_PushHead_Person)
	
	
END_SUITE

































