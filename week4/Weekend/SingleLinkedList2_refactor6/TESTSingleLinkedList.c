#include <stdio.h>
#include <string.h>
#include "SingleLinkedList.h"


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

static int testNum = 0;

static void InsertHeadGenericTest(Person* _head, Person* _p)
{
	++testNum;
	printf("\nTest number: %d\n", testNum);
	/* InsertHead NULL person to empty list */
	_head = ListInsertHead(_head, _p);
	PrintList(_head);


	// head[0] = ListInsertHead(NULL, NULL);
	// PrintList(head[0]);
}



int main()
{
	
	Person pArr[10];
	int pNum = 10;
	Person* head[64] = {NULL};
	Person* item;
	/* Initialize Person array */
	InitPersonArr(pArr, pNum);

	/* ITERATIVE TESTS */
	InsertHeadGenericTest(NULL, NULL);
	InsertHeadGenericTest(NULL, pArr+2);
	InsertHeadGenericTest(head[0], NULL);
	InsertHeadGenericTest(head[0], pArr+9);
	InsertHeadGenericTest(head[0], pArr+5);



	// /* InsertHead person to empy list */
	// head[1] = ListInsertHead(NULL, pArr+2);
	// PrintList(head[1]);
	// /* 2x InsertHead new person  */
	// head[2] = ListInsertHead(NULL, pArr+3);
	// head[2] = ListInsertHead(head[2], pArr+1);
	// PrintList(head[2]);
	// /* Remove Head NULL head */
	// head[3] = ListRemoveHead(NULL, &item);
	// PrintList(head[3]);
	// /* Remove Head NULL head NULL person */
	// head[4] = ListRemoveHead(NULL, NULL);
	// PrintList(head[4]);
	// /* Remove Head x1 */
	// head[5] = ListInsertHead(NULL, pArr+9);
	// head[5] = ListRemoveHead(head[5], &item);
	// printf("Item = %d\n", (*item).m_id);
	// PrintList(head[5]);



	/* Remove Head x2 */

	/* InsertByKey NULL head */

	/* InsertByKey NULL head NULL p*/

	/* InsertByKey NULL p*/

	/* InsertHead, InsertByKey to head */

	/* InsertHead, InsertByKey, to mid-list */

	/* InsertHead, InsertByKey, to end-of-list */

	/* RemoveByKey NULL head */

	/* InsertHead, RemoveByKey head */

	/* InsertByKey, RemoveByKey mid-list */

	/* InsertByKey, RemoveByKey end-of-list */


	/* RECURSIVE TESTS*/
	/* InsertByKey, RemoveByKey end-of-list */
	

	/*  */

	/*  */

	/*  */

	/*  */

	/*  */

	/*  */

	/*  */

	/*  */


	// head[0] = ListInsertHead(head[0], pArr+2);

	// head[0] = ListInsertByKey(head[0], pArr[1].m_id, pArr+1);

	// head[0] = ListInsertByKey(head[0], pArr[4].m_id, pArr+4);
	// head[0] = ListInsertHead(head[0], pArr+0);
	// PrintList(head[0]);
	// head = ListRemoveHead(head, item);
	// PrintList(head);
	// head = ListInsertByKey(head, pArr[0].m_id, pArr+0);
	// PrintList(head);
	// head = ListRemoveByKey(head, pArr[2].m_id, item);
	// PrintList(head);
	// head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	// PrintList(head);
	// head = ListRemoveByKeyRec(head, pArr[4].m_id, item);
	// PrintList(head);
	// head = ListInsertByKeyRec(head, pArr[2].m_id, pArr+2);
	// head = ListInsertHead(head, pArr+3);
	
	// PrintList(head);
	// head = ListRemoveHead(head, item);
	// PrintList(head);

	// head = ListInsertByKeyRec(head, pArr[1].m_id, pArr+1);
	// PrintList(head);
	return 0;
}
