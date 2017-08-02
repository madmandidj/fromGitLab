/*
Filename: 		stack.c 
Description:	stack API Implementation 
Created: 		24/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "stack.h"
#include "vector.h"

struct Stack
{
    Vector *m_vector;
};











/************	
STACK CREATE
*************/


Stack*  StackCreate( size_t _size, size_t _blockSize)
{
    Stack* stack;
    if (0 == _size && 0 == _blockSize)
    {
        return NULL;
    }
    stack = malloc(sizeof(Stack));
    if (NULL == stack)
    {
        return NULL;
    }
    stack->m_vector = VectorCreate(_size, _blockSize);
    if (NULL == stack->m_vector)
    {
        free(stack);
        return NULL;
    }
    return stack;
}













/************	
STACK DESTROY
*************/


void  StackDestroy(Stack* _stack)
{
    if (NULL == _stack)
    {
        return;
    }
    if (NULL != _stack->m_vector)
    {
        VectorDestroy(_stack->m_vector);
        free(_stack);
    }
    return;
}












/************	
STACK PUSH
*************/


ADTErr  StackPush(Stack* _stack, int  _item)
{
	ADTErr err = ERR_OK;
    if (NULL == _stack)
    {
        return ERR_NOT_INITIALIZED;
    }
    err = VectorAdd(_stack->m_vector, _item);
    return err;
}










/************	
STACK POP
*************/


ADTErr  StackPop(Stack* _stack, int* _item)
{
	ADTErr err = ERR_OK;
    if (NULL == _stack || NULL == _item)
    {
        return ERR_NOT_INITIALIZED;
    }
	err = VectorDelete(_stack->m_vector, _item);
    return err;
}










/************	
STACK TOP
*************/


ADTErr  StackTop(Stack* _stack, int* _item)
{
	ADTErr err;
	size_t itemsNum;
    if (NULL == _stack || NULL == _item)
    {
        return ERR_NOT_INITIALIZED;
    }
    VectorItemsNum(_stack->m_vector, &itemsNum);
    if (itemsNum == 0)
    {
        return ERR_UNDERFLOW;
    }
    err = VectorGet(_stack->m_vector, itemsNum, _item);
    return err;
}












/************	
STACK IS EMPTY
*************/


int	StackIsEmpty(Stack* _stack)
{
	size_t itemsNum;
    if (NULL == _stack)
    {
        return 1;
    }
    VectorItemsNum(_stack->m_vector, &itemsNum);
    if (0 != itemsNum)
    {
    	return 0;
    }
    return 1;
}












/************	
STACK PRINT
*************/


void    StackPrint(Stack *_stack)
{
    if (NULL == _stack)
    {
        return;
    }
	VectorPrint(_stack->m_vector);
	return;
}

