#ifndef __STACK_H__
#define __STACK_H__
#include "ADTDefs.h"
typedef struct Stack Stack;
/*
TODO:
* Double check what the API says for parameter types
* Add file description
* Add API function details
*/
Stack*  StackCreate( size_t _size, size_t _blockSize);
void    StackDestroy(Stack* _stack);
ADTErr  StackPush(Stack* _stack, int  _item);
/*
ADTErr  StackPop(Stack* _stack, int* _item);
*/
ADTErr  StackPop(Stack* _stack, size_t* _item);
ADTErr  StackTop(Stack* _stack, int* _item);
int     StackIsEmpty(Stack* _stack);
/*  Unit-Test functions  */
void    StackPrint(  Stack *_stack);

#endif /*#ifndef __STACK_H__*/
