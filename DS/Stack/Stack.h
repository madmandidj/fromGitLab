#ifndef __STACK_H__
#define __STACK_H__
/*
Filename: 		Stack.h 
Description:	Generic stack API 
Created: 		13/08/17
Created by:		Eyal Alon
Last modified: 	13/08/17
Modified by:	Eyal Alon
*/

#include <stdlib.h> /* size_t */

typedef enum
{
    STACK_OK,
    STACK_UNINITIALIZED,
    STACK_ALLOCATION_FAILED,
    STACK_IS_EMPTY,
    STACK_INV_ARG
} StackError;

typedef List Stack

typedef int (*UserActionFunc)(void* _element, void* _context);


Stack* StackCreate();


void StackDestroy(Stack** _stack, DestroyFunc _destroyFunc);


StackError StackPush(Stack* _stack, void* _element);


StackError StackPop(Stack* _stack, void** _element);


StackError StackTop(Stack* _stack, void** _element);


int StackIsEmpty(Stack* _stack);


void StackPrint(Stack *_stack);

#endif /*#ifndef __STACK_H__*/
