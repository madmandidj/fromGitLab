#include "../../inc/Queue.h"
#include "../../inc/ADTErr.h"
#include "../../inc/mu_test.h"
#include <stdlib.h>
#include <stdio.h>

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}


/**********************************/

UNIT(QueueCreate_0_Size)
	Queue* queue;
	size_t size = 0;
	queue = QueueCreate(size);
    ASSERT_THAT(!queue);
END_UNIT

UNIT(QueueCreate_5_Size)
	Queue* queue;
	size_t size = 5;
	queue = QueueCreate(size);
    ASSERT_THAT(queue);
    QueueDestroy(queue, NULL);
END_UNIT

UNIT(QueueInsert_EmptyQueue)
	Queue* queue;
	size_t size = 5;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* element;
	queue = QueueCreate(size);
    ASSERT_THAT(QueueIsEmpty(queue));
	QueueInsert(queue, (void*) (intArr + 9));
    ASSERT_THAT(!QueueIsEmpty(queue));
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 9);
    QueueDestroy(queue, NULL);
END_UNIT

UNIT(QueueInsert_NonEmptyQueue)
	Queue* queue;
	size_t size = 5;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* element;
	queue = QueueCreate(size);
	QueueInsert(queue, (void*) (intArr + 9));
	QueueInsert(queue, (void*) (intArr + 8));
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 9);
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 8);
    QueueDestroy(queue, NULL);
END_UNIT

UNIT(QueueInsert_FullQueue)
	Queue* queue;
	size_t size = 5;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* element;
	queue = QueueCreate(size);
	QueueInsert(queue, (void*) (intArr + 9));
	QueueInsert(queue, (void*) (intArr + 8));
	QueueInsert(queue, (void*) (intArr + 7));
	QueueInsert(queue, (void*) (intArr + 6));
	QueueInsert(queue, (void*) (intArr + 5));
	QueueInsert(queue, (void*) (intArr + 4));
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 9);
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 8);
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 7);
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 6);    
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 5);
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(element == NULL);
    QueueDestroy(queue, NULL);
END_UNIT

UNIT(QueueInsert_AbusedQueue)
	Queue* queue;
	size_t size = 5;
	int intArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* element;
	queue = QueueCreate(size);
	QueueInsert(queue, (void*) (intArr + 9));
	QueueInsert(queue, (void*) (intArr + 8));
	QueueInsert(queue, (void*) (intArr + 7));
	QueueInsert(queue, (void*) (intArr + 6));
	QueueInsert(queue, (void*) (intArr + 5));
/*	QueuePrint(queue, (ElementFunc)PrintInt);*/
    QueueRemove(queue, (void**)&element);
    ASSERT_THAT(*element == 9);
	QueueInsert(queue, (void*) (intArr + 4));
    QueueRemove(queue, (void**)&element);
	ASSERT_THAT(*element == 8);
/*	QueuePrint(queue, (ElementFunc)PrintInt);*/
    QueueDestroy(queue, NULL);
END_UNIT


TEST_SUITE(QUEUE TESTS)
	
	TEST(QueueCreate_0_Size)
	
	TEST(QueueCreate_5_Size)
	
	TEST(QueueInsert_EmptyQueue)
	
	TEST(QueueInsert_NonEmptyQueue)
	
	TEST(QueueInsert_FullQueue)
	
	TEST(QueueInsert_AbusedQueue)
	
END_SUITE


