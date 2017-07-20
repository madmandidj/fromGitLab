/*
Filename: 		TESTSingleLinkedList.c 
Description:	Test file for SLL implementation. Test functions:
				InsertHeadNULLHeadNULLP, InsertHeadNULLHead, InsertHeadNULLP, InsertHeadX1
				InsertHeadX2, RemoveHeadNULLHead, RemoveHeadX1, RemoveHeadX2, 
				RemoveHeadItemValX1, RemoveHeadItemValX2, InsertByKeyNULLHead, InsertByKeyNULLP,
				InsertByKeyListHead, InsertByKeyListEnd, InsertByKeyListMid, 
				InsertByKeyAfterInsertHead, InsertByKeyAfterRemoveHead, RemoveByKeyNULLHead,
				RemoveByKeyNULLHeadNULLItem, RemoveByKeyListHead, RemoveByKeyListMid,
				RemoveByKeyListEnd, RemoveByKeyValX1, RemoveByKeyValX2, 
				RemoveByKeyNoMatchingKey, InsertByKeyRecNULLHead, InsertByKeyRecNULLP,
				InsertByKeyRecListHead, InsertByKeyRecListEnd, InsertByKeyRecListMid,
				RemoveByKeyRecNULLHead, RemoveByKeyRecNULLHeadNULLItem,
				RemoveByKeyRecListHead, RemoveByKeyRecListEnd, RemoveByKeyRecListMid,
				RemoveByKeyRecValX1, RemoveByKeyRecValX2, RemoveByKeyRecNoMatchingKey
Created: 		13/07/17
Created by:		Eyal Alon
Last modified: 	15/07/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include <string.h>
#include "SingleLinkedList.h"

static int testNum = 0;

static void InitPersonArr(Person* _pArr, int _pNum)
{
	int index;

	for (index = 0; index < _pNum; ++index)
	{
		_pArr[index].m_id = index;
		sprintf(_pArr[index].m_name, "Eyal%d", index);
		_pArr[index].m_age = index;
		_pArr[index].m_next = NULL;
	}
}

static void InsertHeadNULLHeadNULLP()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(NULL, NULL);
	PrintList(head);
}

static void InsertHeadNULLHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(NULL, pArr+4);
	PrintList(head);
}

static void InsertHeadNULLP()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, NULL);
	PrintList(head);
}

static void InsertHeadX1()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+1);
	PrintList(head);
}

static void InsertHeadX2()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+3);
	head = ListInsertHead(head, pArr+0);
	PrintList(head);
}

static void RemoveHeadNULLHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL; 
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListRemoveHead(NULL, &item);
	PrintList(head);
}

static void RemoveHeadX1()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	/* Person** item = NULL; */ /* Ask on sunday why does this cause a segmentation fault */
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+3);
	head = ListRemoveHead(head, &item);
	/* head = ListRemoveHead(head, item); */ /* Ask on sunday why does this cause a segmentation fault */
	PrintList(head);
}

static void RemoveHeadX2()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+3);
	head = ListInsertHead(head, pArr+2);
	head = ListRemoveHead(head, &item);
	head = ListRemoveHead(head, &item);
	PrintList(head);
}

static void RemoveHeadItemValX1()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+9);
	head = ListRemoveHead(head, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	PrintList(head);
}

static void RemoveHeadItemValX2()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+9);
	head = ListInsertHead(head, pArr+8);
	head = ListRemoveHead(head, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	head = ListRemoveHead(head, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	PrintList(head);
}

static void InsertByKeyNULLHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(NULL, pArr[0].m_id, pArr+0);
	PrintList(head);
}

static void InsertByKeyNULLP()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[0].m_id, NULL);
	PrintList(head);
}

static void InsertByKeyListHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	PrintList(head);
}

static void InsertByKeyListEnd()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[8].m_id, pArr+8);
	PrintList(head);
}

static void InsertByKeyListMid()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[8].m_id, pArr+8);
	head = ListInsertByKey(head, pArr[6].m_id, pArr+6);
	PrintList(head);
}

static void InsertByKeyAfterInsertHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+4);
	head = ListInsertByKey(head, pArr[8].m_id, pArr+8);
	PrintList(head);
}

static void InsertByKeyAfterRemoveHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveHead(head, NULL);
	head = ListInsertByKey(head, pArr[8].m_id, pArr+8);
	PrintList(head);
}

static void RemoveByKeyNULLHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListRemoveByKey(NULL, pArr[4].m_id, &item);
	PrintList(head);
}

static void RemoveByKeyNULLHeadNULLItem()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListRemoveByKey(NULL, pArr[2].m_id, NULL);
	PrintList(head);
}

static void RemoveByKeyListHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[4].m_id, NULL);
	PrintList(head);
}

static void RemoveByKeyListMid()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[6].m_id, NULL);
	PrintList(head);
}

static void RemoveByKeyListEnd()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[8].m_id, NULL);
	PrintList(head);
}

static void RemoveByKeyValX1()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[8].m_id, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	PrintList(head);
}

static void RemoveByKeyValX2()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[8].m_id, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	head = ListRemoveByKey(head, pArr[4].m_id, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	PrintList(head);
}

static void RemoveByKeyNoMatchingKey()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[7].m_id, &item);
	PrintList(head);
}

static void InsertByKeyRecNULLHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKeyRec(NULL, pArr[0].m_id, pArr+0);
	PrintList(head);
}

static void InsertByKeyRecNULLP()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKeyRec(head, pArr[0].m_id, NULL);
	PrintList(head);
}

static void InsertByKeyRecListHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKeyRec(head, pArr[7].m_id, pArr+7);
	PrintList(head);
}

static void InsertByKeyRecListEnd()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKeyRec(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKeyRec(head, pArr[9].m_id, pArr+9);
	PrintList(head);
}

static void InsertByKeyRecListMid()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKeyRec(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKeyRec(head, pArr[9].m_id, pArr+9);
	head = ListInsertByKeyRec(head, pArr[8].m_id, pArr+8);
	PrintList(head);
}

static void RemoveByKeyRecNULLHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListRemoveByKeyRec(NULL, pArr[4].m_id, &item);
	PrintList(head);
}

static void RemoveByKeyRecNULLHeadNULLItem()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListRemoveByKeyRec(NULL, pArr[4].m_id, NULL);
	PrintList(head);
}

static void RemoveByKeyRecListHead()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	PrintList(head);
}

static void RemoveByKeyRecListEnd()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	PrintList(head);
}

static void RemoveByKeyRecListMid()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	PrintList(head);
}

static void RemoveByKeyRecValX1()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why is this '.' and not '->' ? */
	PrintList(head);
}

static void RemoveByKeyRecValX2()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why '.' and not '->' ? */
	head = ListRemoveByKeyRec(head, pArr[4].m_id, &item);
	printf("Item id = %d\n", (*item).m_id); /* Why '.' and not '->' ? */
	PrintList(head);
}

static void RemoveByKeyRecNoMatchingKey()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);
	++testNum;
	printf("\nTest number: %d\n", testNum);
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListRemoveByKeyRec(head, pArr[6].m_id, &item);
	/* TODO: Need to handle what is returned to item when item != NULL and no key found in list */
	PrintList(head);
}


int main()
{
	/* ITERATIVE TESTS */
	/* Test 1 */
	InsertHeadNULLHeadNULLP();
	/* Test 2 */
	InsertHeadNULLHead();
	/* Test 3 */
	InsertHeadNULLP();
	/* Test 4 */
	InsertHeadX1();
	/* Test 5 */
	InsertHeadX2();

	/* Test 6 */
	RemoveHeadNULLHead();
	/* Test 7 */
	RemoveHeadX1();
	/* Test 8 */
	RemoveHeadX2();
	/* Test 9 */
	RemoveHeadItemValX1();
	/* Test 10 */
	RemoveHeadItemValX2();

	/* Test 11 */
	InsertByKeyNULLHead();
	/* Test 12 */
	InsertByKeyNULLP();
	/* Test 13 */
	InsertByKeyListHead();
	/* Test 14 */
	InsertByKeyListEnd();
	/* Test 15 */
	InsertByKeyListMid();
	/* Test 16 */
	InsertByKeyAfterInsertHead();
	/* Test 17 */
	InsertByKeyAfterRemoveHead();

	/* Test 18 */
	RemoveByKeyNULLHead();
	/* Test 19 */
	RemoveByKeyNULLHeadNULLItem();
	/* Test 20 */
	RemoveByKeyListHead();
	/* Test 21 */
	RemoveByKeyListMid();
	/* Test 22 */
	RemoveByKeyListEnd();
	/* Test 23 */
	RemoveByKeyValX1();
	/* Test 24 */
	RemoveByKeyValX2();
	/* Test 25 */
	RemoveByKeyNoMatchingKey();

	/* RECURSIVE TESTS*/
	/* Test 26 */
	InsertByKeyRecNULLHead();
	/* Test 27 */
	InsertByKeyRecNULLP();
	/* Test 28 */
	InsertByKeyRecListHead();
	/* Test 29 */
	InsertByKeyRecListEnd();
	/* Test 30 */
	InsertByKeyRecListMid();

	/* Test 31 */
	RemoveByKeyRecNULLHead();
	/* Test 32 */
	RemoveByKeyRecNULLHeadNULLItem();
	/* Test 33 */
	RemoveByKeyRecListHead();
	/* Test 34 */
	RemoveByKeyRecListEnd();
	/* Test 35 */
	RemoveByKeyRecListMid();
	/* Test 36 */
	RemoveByKeyRecValX1();
	/* Test 37 */
	RemoveByKeyRecValX2();
	/* Test 38 */
	RemoveByKeyRecNoMatchingKey();
	return 0;
}
