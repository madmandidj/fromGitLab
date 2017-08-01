#ifndef __STACK_H__
#define __STACK_H__
/*
Filename: 		stack.h 
Description:	stack API 
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/

#include <stdlib.h> /* size_t */
#include "ADTDefs.h"
typedef struct Stack Stack;
/*
TODO:
* Double check what the API says for parameter types
* Add file description
* Add API function details
*/

/*
Desc:	Create stack	
In:		size_t initial stack size, size_t block extension size		
Out:	Stack* 
Err: 	If no memery available, NULL returned
*/
Stack*  StackCreate     (size_t _size, size_t _blockSize);

/*
Desc:	Destroy stack	
In:		Stack*
Out:	void
Err: 	If no memery available, NULL returned
*/
void    StackDestroy    (Stack* _stack);

/*
Desc:	Push new item to stack	
In:		Stack*, int data to push
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_UNDERFLOW
*/
ADTErr  StackPush       (Stack* _stack, int  _item);

/*
Desc:	Pop last item from stack	
In:		Stack*, int* to receive popped data
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_UNDERFLOW
*/
ADTErr  StackPop        (Stack* _stack, int* _item);

/*
Desc:	Retrieve value of last item in stack
In:		Stack*, int* to receive top item data
Out:	ERR_OK
Err: 	ERR_NOT_INITIALIZED, ERR_UNDERFLOW
*/
ADTErr  StackTop        (Stack* _stack, int* _item);

/*
Desc:	Check if stack is empty
In:		Stack*
Out:	int, 1 if empty, 0 if not empty
Err: 	ERR_NOT_INITIALIZED, ERR_UNDERFLOW
*/
int     StackIsEmpty    (Stack* _stack);

/*
Desc:	Print stack
In:		Stack*
Out:	void
Err: 	if NULL Stack*, return
*/
void    StackPrint      (Stack *_stack);

#endif /*#ifndef __STACK_H__*/
