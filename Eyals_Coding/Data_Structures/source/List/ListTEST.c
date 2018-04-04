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
    ASSERT_THAT(list);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_PushHead_EmptyList)
    List* list;
    int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
    
    intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushHead(list, intArr + 0);
    ASSERT_THAT(1 == ListItemsNum(list));
    ListPopHead(list, (void**)&poppedData);
    ASSERT_THAT(0 == *poppedData);
    ASSERT_THAT(0 == ListItemsNum(list));
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_PushHead_NonEmptyList)
    List* list;
    int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
    
    intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushHead(list, intArr + 0);
    ListPushHead(list, intArr + 1);
    ListPushHead(list, intArr + 2);
    ASSERT_THAT(3 == ListItemsNum(list));
    ListPopHead(list, (void**)&poppedData);
    ASSERT_THAT(2 == *poppedData);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_PushTail_EmptyList)
    List* list;
    int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
    
    intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 0);
    ASSERT_THAT(1 == ListItemsNum(list));
    ListPopTail(list, (void**)&poppedData);
    ASSERT_THAT(0 == *poppedData);
    ASSERT_THAT(0 == ListItemsNum(list));
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_PushTail_NonEmptyList)
    List* list;
    int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
    
    intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 0);
    ListPushTail(list, intArr + 1);
    ListPushTail(list, intArr + 2);
    ASSERT_THAT(3 == ListItemsNum(list));
    ListPopTail(list, (void**)&poppedData);
    ASSERT_THAT(2 == *poppedData);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_First_EmptyList)
    List* list;
	ListItr endItr;
	ListItr itr;
	
    list = ListCreate();
    endItr = ListItrEnd(list);
	itr = ListItrFirst(list);
    ASSERT_THAT(endItr == itr);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Itr_First_1Element)
    List* list;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
    
    intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 4);
	itr = ListItrFirst(list);
    poppedData = (int*)ListItrGet(itr);
    ASSERT_THAT(4 == *poppedData);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_First_2Element)
    List* list;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
    
    intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 4);
    ListPushTail(list, intArr + 5);
	itr = ListItrFirst(list);
    poppedData = (int*)ListItrGet(itr);
    ASSERT_THAT(4 == *poppedData);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_Last_EmptyList)
    List* list;
	ListItr beginItr;
	ListItr itr;
	
    list = ListCreate();
    beginItr = ListItrBegin(list);
	itr = ListItrLast(list);
    ASSERT_THAT(beginItr == itr);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Itr_Last_1Element)
    List* list;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
	
	intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 4);
	itr = ListItrLast(list);
    poppedData = (int*)ListItrGet(itr);
    ASSERT_THAT(4 == *poppedData);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_Last_2Element)
    List* list;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
	
	intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 4);
    ListPushTail(list, intArr + 5);
	itr = ListItrLast(list);
    poppedData = (int*)ListItrGet(itr);
    ASSERT_THAT(5 == *poppedData);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_Next_EmptyList_beginItr)
	List* list;
	ListItr endItr;
	ListItr itr;
	
    list = ListCreate();
    itr = ListItrBegin(list);
    endItr = ListItrEnd(list);
	itr = ListItrNext(itr);
    ASSERT_THAT(endItr == itr);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Itr_Next_EmptyList_endItr)
	List* list;
	ListItr endItr;
	ListItr itr;
	
    list = ListCreate();
    itr = ListItrEnd(list);
    endItr = ListItrEnd(list);
	itr = ListItrNext(itr);
    ASSERT_THAT(endItr == itr);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Itr_Next_1Element)
	List* list;
	ListItr endItr;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
	
	intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 4);
    endItr = ListItrEnd(list);
    itr = ListItrBegin(list);
	itr = ListItrNext(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(4 == *poppedData);
	itr = ListItrNext(itr);
    ASSERT_THAT(endItr == itr);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_Next_5Element)
	List* list;
	ListItr endItr;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
	
	intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 0);
    ListPushTail(list, intArr + 1);
    ListPushTail(list, intArr + 2);
    ListPushTail(list, intArr + 3);
    ListPushTail(list, intArr + 4);
    endItr = ListItrEnd(list);
    itr = ListItrFirst(list);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(0 == *poppedData);
	itr = ListItrNext(itr);
	itr = ListItrNext(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(2 == *poppedData);
	itr = ListItrRemove(list, itr, (void**)&poppedData);
	ASSERT_THAT(2 == *poppedData);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(1 == *poppedData);
	ASSERT_THAT(4 == ListItemsNum(list));
	itr = ListItrNext(itr);
	itr = ListItrNext(itr);
	itr = ListItrNext(itr);
    ASSERT_THAT(endItr == itr);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_Prev_EmptyList_beginItr)
	List* list;
	ListItr beginItr;
	ListItr itr;
	
    list = ListCreate();
    itr = ListItrBegin(list);
    beginItr = ListItrBegin(list);
	itr = ListItrPrev(itr);
    ASSERT_THAT(beginItr == itr);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Itr_Prev_EmptyList_endItr)
	List* list;
	ListItr beginItr;
	ListItr itr;
	
    list = ListCreate();
    itr = ListItrEnd(list);
    beginItr = ListItrBegin(list);
	itr = ListItrPrev(itr);
    ASSERT_THAT(beginItr == itr);
    ListDestroy(list, NULL);
END_UNIT

UNIT(List_Itr_Prev_1Element)
	List* list;
	ListItr beginItr;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
	
	intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 4);
    beginItr = ListItrBegin(list);
    itr = ListItrEnd(list);
	itr = ListItrPrev(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(4 == *poppedData);
	itr = ListItrPrev(itr);
    ASSERT_THAT(beginItr == itr);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT

UNIT(List_Itr_Prev_5Element)
	List* list;
	ListItr beginItr;
	ListItr itr;
	int* intArr;
    size_t numOfInts = 10;
    int* poppedData;
	
	intArr = CreateAscendingIntArray(numOfInts);
    list = ListCreate();
    ListPushTail(list, intArr + 0);
    ListPushTail(list, intArr + 1);
    ListPushTail(list, intArr + 2);
    ListPushTail(list, intArr + 3);
    ListPushTail(list, intArr + 4);
    beginItr = ListItrBegin(list);
    itr = ListItrEnd(list);
	itr = ListItrPrev(itr);
	itr = ListItrPrev(itr);
	itr = ListItrInsertAfter(list, itr, intArr + 7);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(7 == *poppedData);
	itr = ListItrNext(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(4 == *poppedData);
	itr = ListItrPrev(itr);
	itr = ListItrPrev(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(3 == *poppedData);
	itr = ListItrInsertBefore(list, itr, intArr + 9);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(9 == *poppedData);
	itr = ListItrNext(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(3 == *poppedData);
	itr = ListItrPrev(itr);
	itr = ListItrPrev(itr);
	poppedData = (int*)ListItrGet(itr);
	ASSERT_THAT(2 == *poppedData);
	itr = ListItrPrev(itr);
	itr = ListItrPrev(itr);
	itr = ListItrPrev(itr);
    ASSERT_THAT(beginItr == itr);
    ListDestroy(list, NULL);
    DestroyIntArray(intArr);
END_UNIT


TEST_SUITE(List tests)

	TEST(List_Create)	
	TEST(List_PushHead_EmptyList)
	TEST(List_PushHead_NonEmptyList)
	TEST(List_PushTail_EmptyList)
	TEST(List_PushTail_NonEmptyList)
	TEST(List_Itr_First_EmptyList)
	TEST(List_Itr_First_1Element)
	TEST(List_Itr_First_2Element)
	TEST(List_Itr_Last_EmptyList)
	TEST(List_Itr_Last_1Element)
	TEST(List_Itr_Last_2Element)
	TEST(List_Itr_Next_EmptyList_beginItr)
	TEST(List_Itr_Next_EmptyList_endItr)
	TEST(List_Itr_Next_1Element)
	TEST(List_Itr_Next_5Element)
	TEST(List_Itr_Prev_EmptyList_beginItr)
	TEST(List_Itr_Prev_EmptyList_endItr)
	TEST(List_Itr_Prev_1Element)
	TEST(List_Itr_Prev_5Element)
	
	
	
	
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
	*/
END_SUITE

































