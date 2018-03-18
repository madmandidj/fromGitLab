#include <stdio.h>
#include <stdlib.h>
#include "../../inc/List.h"
#include "../../inc/mu_test.h"
#include "../../inc/ADTErr.h"

typedef struct Person Person;
struct Person
{
    size_t m_age;
    size_t m_gender;
    Person* m_mother;   
};

void DeletePerson(void* _personPtr)
{
    free(((Person*)_personPtr)->m_mother);
}

void PrintInt(void* _intPtr)
{
    printf("%u\n", *(size_t*)_intPtr);
}

/*
UNIT(List_Create)
    List* list;
    void* poppedHead;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
    list = ListCreate();
    ASSERT_THAT(NULL != list);
    ListPushHead(list, &intArr[7]);
    ListPushHead(list, &intArr[4]);
    ListPushHead(list, &intArr[9]);
    ListPushHead(list, &intArr[2]);
    ListPrint(list, PrintInt);
    ListPopHead(list, &poppedHead);
    ASSERT_THAT(2 == *(int*)poppedHead);
    ListDestroy(list, NULL);
END_UNIT
*/

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

UNIT(List_InsertAfter)
    List* list;
    ListItr itr;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
	void* poppedTail;
    list = ListCreate();
/*    itr = (ListItr)LIST_FIRST(list);*/
    ListPushTail(list, &intArr[1]);
    ListPushTail(list, &intArr[8]);
    ListPushTail(list, &intArr[3]);
    itr = ListItrBegin(list);
	ListInsertAfter(itr, &intArr[2]);
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

TEST_SUITE(List tests)
    TEST(List_Create)
	TEST(List_PushHead)
	TEST(List_PopHead)
	TEST(List_PopHead_multiple)
	TEST(List_PushTail)
	TEST(List_PopTail)
	TEST(List_InsertAfter)
END_SUITE
