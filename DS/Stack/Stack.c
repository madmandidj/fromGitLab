/*
Filename: 		stack.c 
Description:	stack API Implementation (with LinkedList))
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	29/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "Stack.h"
#include "list.h"

#define TRUE 1
#define FALSE 0
#define IS_NULL(A)			(NULL == (S))
#define STACK_MAGIC_NUM 	0x05070A0C
#define IS_A_STACK(S)		((S) && STACK_MAGIC_NUM == (S)->m_magicNum)

/*struct Stack*/
/*{*/
/*	int m_magicNum;*/
/*    List* m_list;*/
/*};*/



/*typedef List Stack;*/


Stack* StackCreate()
{
	return ListCreate();
}






/*Stack* StackCreate()*/
/*{*/
/*	Stack* stack;*/
/*	*/
/*	if (!(stack = malloc(sizeof(Stack)))*/
/*	{*/
/*		return NULL;*/
/*	}*/
/*	*/
/*	if (!(stack->m_list = ListCreate()))*/
/*	{*/
/*		free(stack);*/
/*		return NULL;*/
/*	}*/
/*	*/
/*	stack->m_magicNum = STACK_MAGIC_NUM;*/
/*	return stack;*/
/*}*/

void StackDestroy(Stack** _stack, UserActionFunc _destroyFunc)
{
	/*
	list destroy should check if list is list
	do we need magic num for stack?
	*/
	if (IS_NULL(_stack) || !IS_A_STACK(*_stack))
	{
		return;
	}
	ListDestroy(&(stack->m_list), _destroyFunc);
	stack->m_magicNum = 0;
	free(*_stack);
	*_stack = NULL;
	return;
}

StackError StackPush(Stack* _stack, void* _element)
{
	ListErrors listErr;
	
	if (!IS_A_STACK(_stack))
	{
		return STACK_UNINITIALIZED;
	}
	
	listErr = ListPushTail(_stack->m_list, _element);
	if (LIST_UNINITIALIZED == listErr)
	{
		return STACK_UNINITIALIZED;
	}
	
	else if (LIST_ALLOCATION_FAILED == listErr)
	{
		return STACK_ALLOCATION_FAILED;
	}
	
	return STACK_OK;
}

StackError StackPop(Stack* _stack, void** _element)
{
	ListErrors listErr;
	
	if (!IS_A_STACK(_stack))
	{
		return STACK_UNINITIALIZED;
	}
	
	if (IS_NULL(_element))
	{
		return STACK_INV_ARG;
	}
	
	listErr = ListPopTail(_stack->m_list, *_element);
	if (LIST_UNINITIALIZED == listErr)
	{
		return STACK_UNINITIALIZED;
	}
	
	else if (LIST_IS_EMPTY == listErr)
	{
		return STACK_IS_EMPTY;
	}
	
	return STACK_OK;
}





