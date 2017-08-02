/*
Filename: 		TESTSLLFlip.c 
Description:	Test file for SLL flip function
Created: 		13/07/17
Created by:		Eyal Alon
Last modified: 	18/07/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include <string.h>
#include "SLLFlip.h"

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

void TesFlipSLL()
{
	Person pArr[10];
	int pNum = 10;
	Person* head = NULL;
	InitPersonArr(pArr, pNum);
	head = ListInsertByKey(head, pArr[3].m_id, pArr+3); 
	head = ListInsertByKey(head, pArr[7].m_id, pArr+7);
	head = ListInsertByKey(head, pArr[4].m_id, pArr+4);
	head = ListInsertByKey(head, pArr[9].m_id, pArr+9);
	PrintList(head);
	head = FlipSLL(head);
	PrintList(head);
}


int main()
{
	/* Test FLIPSLL */
	TesFlipSLL();
	return 0;
}
