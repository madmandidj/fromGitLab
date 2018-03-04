#include <stdio.h>
#include <stdlib.h>
#include "../../inc/Vector.h"
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

UNIT(VectorCreate_InvalidCapacity)
    Vector* vector;
    vector = VectorCreate(0, 0);
    ASSERT_THAT(NULL == vector);
END_UNIT

UNIT(VectorCreate_Capacity10_Blocksize2)
    Vector* vector;
    vector = VectorCreate(10, 2);
    ASSERT_THAT(NULL != vector);
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(VectorAppend_NULL_element)
    Vector* vector;
    ADTErr err;
    vector = VectorCreate(10, 2);
    ASSERT_THAT(NULL != vector);
    ASSERT_THAT(VectorItemsNum(vector) == 0);
    err = VectorAppend(vector, NULL);
    ASSERT_THAT(ERR_INVARG == err);
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(VectorAppend_Capacity10_Blocksize2)
    Vector* vector;
    ADTErr err;
    int intElem1 = 4;
    vector = VectorCreate(10, 2);
    ASSERT_THAT(NULL != vector);
    ASSERT_THAT(VectorItemsNum(vector) == 0);
    err = VectorAppend(vector, &intElem1);
    ASSERT_THAT(VectorItemsNum(vector) == 1);
    /*VectorPrint(vector, PrintInt);*/
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(VectorRemove_NULL_element)
    Vector* vector;
    ADTErr err;
    int intElem1 = 4;
    vector = VectorCreate(10, 2);
    ASSERT_THAT(NULL != vector);
    ASSERT_THAT(VectorItemsNum(vector) == 0);
    err = VectorAppend(vector, &intElem1);
    ASSERT_THAT(VectorItemsNum(vector) == 1);
    err = VectorRemove(vector, NULL);
    ASSERT_THAT(ERR_INVARG == err);
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(VectorRemove_numOfItems_AND_elemVal)
    Vector* vector;
    ADTErr err;
    int* removedElement;
    int intElem1 = 4;
    vector = VectorCreate(10, 2);
    ASSERT_THAT(NULL != vector);
    ASSERT_THAT(VectorItemsNum(vector) == 0);
    err = VectorAppend(vector, &intElem1);
    ASSERT_THAT(VectorItemsNum(vector) == 1);
    err = VectorRemove(vector, (void**)&removedElement);
    ASSERT_THAT(ERR_OK == err);
    ASSERT_THAT(*removedElement == 4);
    ASSERT_THAT(VectorItemsNum(vector) == 0);
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(VectorAppendRemove_Grow_Shrink)
    Vector* vector;
    ADTErr err;
    int* removedElement;
    size_t index;
    int intArr[10] = {0,1,2,3,4,5,6,7,8,9};
    vector = VectorCreate(3, 2);
    for (index = 0; index < 10; ++index)
    {
        err = VectorAppend(vector, intArr + index);
    }
    ASSERT_THAT(VectorItemsNum(vector) == 10);
    for (index = 9; index > 5; --index)
    {
        err = VectorRemove(vector, (void**)&removedElement);
        ASSERT_THAT(*removedElement == intArr[index]);
    }
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(Vector_SetGet)
    Vector* vector;
    ADTErr err;
    int intElem1 = 4;
    int intElem2 = 6;
    int intElem3 = 8;
    int* gotElem;
    vector = VectorCreate(10, 2);
    ASSERT_THAT(NULL != vector);
    ASSERT_THAT(VectorItemsNum(vector) == 0);
    err = VectorAppend(vector, &intElem1);
    ASSERT_THAT(VectorItemsNum(vector) == 1);
    err = VectorAppend(vector, &intElem2);
    ASSERT_THAT(VectorItemsNum(vector) == 2);
    err = VectorSet(vector, 1, &intElem3);
    err = VectorGet(vector, 1, (void**)&gotElem);
    ASSERT_THAT(*gotElem == 8);
    VectorDestroy(vector, NULL);
END_UNIT

UNIT(Vector_With_Person)
    Vector* vector;
    ADTErr err;
    Person Smitty ={50, 1, NULL};
    Smitty.m_mother = malloc(sizeof(Person) * 1);
    vector = VectorCreate(3, 2);
    VectorAppend(vector, &Smitty);
    VectorDestroy(vector, DeletePerson);
END_UNIT

TEST_SUITE(Vector tests)
    TEST(VectorCreate_InvalidCapacity)
    TEST(VectorCreate_Capacity10_Blocksize2)
    TEST(VectorAppend_NULL_element)
    TEST(VectorAppend_Capacity10_Blocksize2)
    TEST(VectorRemove_NULL_element)
    TEST(VectorRemove_numOfItems_AND_elemVal)
    TEST(VectorAppendRemove_Grow_Shrink)
    TEST(Vector_SetGet)
    TEST(Vector_With_Person)
END_SUITE
