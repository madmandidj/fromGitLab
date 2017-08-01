#include <stdio.h>
#include <string.h>
#include "SingleLinkedList.h"

int main()
{
	int index;
	Person pArr[5];
	Person* head;
	Person** item = NULL;;
	head = NULL;
	for (index = 0; index < 5; ++index)
	{
		pArr[index].m_id = index;
		sprintf(pArr[index].m_name, "Eyal%d", index);
		pArr[index].m_age = index;
		pArr[index].m_next = NULL;
	}
	// head = ListInsertHead(head, pArr+3);
	head = ListInsertHead(head, pArr+2);

	head = ListInsertByKey(head, pArr[0].m_id, pArr+0);

	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertHead(head, pArr+2);
	PrintList(head);
	// head = ListRemoveHead(head, item);
	// PrintList(head);
	// head = ListInsertByKey(head, pArr[0].m_id, pArr+0);
	// PrintList(head);
	// head = ListRemoveByKey(head, pArr[4].m_id, item);
	// PrintList(head);
	// head = ListInsertByKey(head, pArr[2].m_id, pArr+2);
	// PrintList(head);
	// head = ListRemoveByKeyRec(head, pArr[0].m_id, item);
	// PrintList(head);
	// head = ListInsertByKeyRec(head, pArr[0].m_id, pArr+0);
	// PrintList(head);
	// head = ListInsertByKeyRec(head, pArr[1].m_id, pArr+1);
	// PrintList(head);
	return 0;
}
