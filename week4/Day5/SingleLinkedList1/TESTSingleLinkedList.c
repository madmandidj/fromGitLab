#include <stdio.h>
#include <string.h>
#include "SingleLinkedList.h"

int main()
{
	int index;
	Person pArr[5];
	Person* head;
	Person* curP;
	head = NULL;
	for (index = 0; index < 5; ++index)
	{
		pArr[index].m_id = index;
		sprintf(pArr[index].m_name, "Eyal %d", index);
		pArr[index].m_age = index;
		pArr[index].m_next = NULL;
	}
	head = ListInsertHead(head, pArr+3);
	head = ListInsertHead(head, pArr+2);
	
	
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[2].m_id, pArr+2);
	curP = head;
	while (curP->m_next != NULL)
	{
		printf("%d %s %d\n", curP->m_id, curP->m_name, curP->m_age);
		curP = curP->m_next;
	}
	printf("%d %s %d\n", curP->m_id, curP->m_name, curP->m_age);
	return 0;
}
