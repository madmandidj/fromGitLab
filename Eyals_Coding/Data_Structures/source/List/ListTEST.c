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
    printf("%lu\n", *(size_t*)_intPtr);
}

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


TEST_SUITE(List tests)
    TEST(List_Create)
END_SUITE
