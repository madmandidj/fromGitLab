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
Last modified: 	16/07/17
Modified by:	Eyal Alon
TODO: 
- update description functions
- ask about Person** in RemoveHeadX1(), line 143
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
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(NULL, NULL);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
	return;
}

static void InsertHeadNULLHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(NULL, pArr+4);
	if (NULL == head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertHeadNULLP()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+4);
	head = ListInsertHead(head, NULL);
	if (head != pArr+4)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertHeadX1()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+4);
	if (head != pArr+4)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertHeadX2()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+5);
	head = ListInsertHead(head, pArr+4);
	if (head != pArr+4 || head->m_next != pArr+5)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveHeadNULLHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL; 
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListRemoveHead(NULL, &item);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveHeadX1()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	/* Person** item = NULL; */ /* Ask on sunday why does this cause a segmentation fault */
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveHead(head, &item);
	/* head = ListRemoveHead(head, item); */ /* Ask on sunday why does this cause a segmentation fault */
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveHeadX2()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+5);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveHead(head, &item);
	head = ListRemoveHead(head, &item);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveHeadItemValX1()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveHead(head, &item);
	if (pArr[4].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveHeadItemValX2()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL; 
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+5);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveHead(head, &item);
	head = ListRemoveHead(head, &item);
	if (pArr[5].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyNULLHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(NULL, pArr[4].m_id, pArr+4);
	if (head != pArr+4)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyNULLP()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[4].m_id, NULL);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyListHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	if (head != pArr+4)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyListEnd()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[3].m_id, pArr+3);
	head = ListInsertByKey(head, pArr[6].m_id, pArr+6);
	if (head != pArr+3 || head->m_next != pArr+6 || head->m_next->m_next != NULL)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyListMid()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[3].m_id, pArr+3);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListInsertByKey(head, pArr[6].m_id, pArr+6);
	if (head != pArr+3 || head->m_next != pArr+6 || head->m_next->m_next != pArr+9)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyAfterInsertHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+4);
	head = ListInsertByKey(head, pArr[8].m_id, pArr+8);
	if (head != pArr+4 || head->m_next != pArr+8)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyAfterRemoveHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveHead(head, NULL);
	head = ListInsertByKey(head, pArr[8].m_id, pArr+8);
	if (head != pArr+8)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyNULLHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListRemoveByKey(NULL, pArr[4].m_id, &item);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyNULLHeadNULLItem()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListRemoveByKey(NULL, pArr[2].m_id, NULL);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyListHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* item = NULL;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[4].m_id, &item);
	if (head != pArr+6 || pArr[4].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyListMid()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* item = NULL;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[6].m_id, &item);
	if (head != pArr+4 || pArr[6].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyListEnd()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* item = NULL;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[8].m_id, &item);
	if (head != pArr+4 || pArr[8].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyValX1()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[8].m_id, &item);
	if (head != pArr+4 || pArr[8].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyValX2()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[8].m_id, &item);
	head = ListRemoveByKey(head, pArr[4].m_id, &item);
	if (head != pArr+6 || pArr[4].m_id != (*item).m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyNoMatchingKey()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertHead(head, pArr+8);
	head = ListInsertHead(head, pArr+6);
	head = ListInsertHead(head, pArr+4);
	head = ListRemoveByKey(head, pArr[7].m_id, &item);
	if (head != pArr+4 || head->m_next != pArr+6 || head->m_next->m_next != pArr+8 || NULL != head->m_next->m_next->m_next)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyRecNULLHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKeyRec(NULL, pArr[0].m_id, pArr+0);
	if (head != pArr+0)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyRecNULLP()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKeyRec(head, pArr[0].m_id, NULL);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyRecListHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKeyRec(head, pArr[7].m_id, pArr+7);
	if (head != pArr+7)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyRecListEnd()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKeyRec(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKeyRec(head, pArr[9].m_id, pArr+9);
	if (head != pArr+7 || head->m_next != pArr+9 || NULL != head->m_next->m_next)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void InsertByKeyRecListMid()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKeyRec(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKeyRec(head, pArr[9].m_id, pArr+9);
	head = ListInsertByKeyRec(head, pArr[8].m_id, pArr+8);
	if (head != pArr+7 || head->m_next != pArr+8)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecNULLHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListRemoveByKeyRec(NULL, pArr[4].m_id, &item);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecNULLHeadNULLItem()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListRemoveByKeyRec(NULL, pArr[4].m_id, NULL);
	if (NULL != head)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecListHead()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	if (NULL != head || (*item).m_id != pArr[7].m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecListEnd()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	if (head !=  pArr+4 || (*item).m_id != pArr[7].m_id)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecListMid()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	if (head !=  pArr+4 || (*item).m_id != pArr[7].m_id || head->m_next !=  pArr+9)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecValX2()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	head = ListRemoveByKeyRec(head, pArr[7].m_id, &item);
	head = ListRemoveByKeyRec(head, pArr[4].m_id, &item);
	if (head !=  pArr+9 || (*item).m_id != pArr[4].m_id || NULL != head->m_next)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void RemoveByKeyRecNoMatchingKey()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListRemoveByKeyRec(head, pArr[6].m_id, &item);
	if (head !=  pArr+4 || head->m_next != pArr+7 || NULL != head->m_next->m_next)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
}

static void TestListGetTailRec()
{
	int result = 1;
	Person pArr[10];
	int pNum = 10;
	Person* tail = NULL;
	Person* head = NULL;
	Person* item = NULL;
	InitPersonArr(pArr, pNum);
	++testNum;
	/*head = ListInsertByKey(head, pArr[8].m_id, pArr+8); */
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	tail = ListGetTailRec(head);
	if (tail !=  pArr+7)
	{
		result = 0;
	}
	printf("Test number %d result = %d\n", testNum, result);
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
	RemoveByKeyRecValX2();
	/* Test 37 */
	RemoveByKeyRecNoMatchingKey();
	/* Test 38 */
	TestListGetTailRec();
	
	
	/* Test FLIPSLL */
	TesFlipSLL();
	return 0;
}
