#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"

struct Stack
{
    Vector *m_vector;
};

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
    stack->m_vector = VectorCreate(_size, _blocksize);
    if (NULL == stack->m_vector)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

void  StackDestroy(Stack* _stack)
{
    if (NULL == _stack)
    {
        return;
    }
    if (NULL != _stack->m_vector)
    {
        VectorDestroy(_stack->m_vector)
        free(_stack);
    }
    return;
}


ADTErr  StackPush(Stack* _stack, int  _item)
{
    /*
    Stack* tempStack;
    */
    if (NULL == _stack)
    {
        return ERR_NOT_INITIALIZED;
    }
    return ERR_OK;
}

ADTErr  StackPop(Stack* _stack, int* _item)
{
    return ERR_OK;
}

ADTErr  StackTop(Stack* _stack, int* _item)
{
    return ERR_OK;
}

int     StackIsEmpty(Stack* _stack)
{
    return ERR_OK;
}





void    StackPrint(  Stack *_stack)
{

}

