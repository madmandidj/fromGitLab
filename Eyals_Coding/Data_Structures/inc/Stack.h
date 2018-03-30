#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h>
#include "ADTErr.h"

typedef struct Stack Stack;
#ifndef __ELEMENT_FUNC__
#define __ELEMENT_FUNC__
	typedef void(*ElementFunc)(void*);
#endif /*__ELEMENT_FUNC__*/

Stack* StackCreate(size_t _initCap, size_t _blockSize);

void StackDestroy(Stack* _stack, ElementFunc _elementDestroyFunc);

ADTErr StackPush(Stack* _stack, void* _item);

ADTErr StackPop(Stack* _stack, void** _poppedElement);

ADTErr StackTop(Stack* _stack, void** _topElement);

int StackIsEmpty(Stack* _stack);

void StackPrint(Stack* _stack, ElementFunc _elementPrintFunc);

#endif/*#ifndef __STACK_H__*/

