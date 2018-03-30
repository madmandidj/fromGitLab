#include "../../inc/Stack.h"
#include "../../inc/Vector.h"
#include "../../inc/ADTErr.h"
#include <stdlib.h>

struct Stack
{
	Vector* m_vector;
};

Stack* StackCreate(size_t _initCap, size_t _blockSize)
{
	Stack* stack;
	if (!_initCap)
	{
		return NULL;
	}
	stack = malloc(sizeof(Stack));
	if (!stack)
	{
		return NULL;
	}
	stack->m_vector = VectorCreate(_initCap, _blockSize);
	if (!stack->m_vector)
	{
		free(stack);
		return NULL;
	}
	return stack;
}

void StackDestroy(Stack* _stack, ElementFunc _elementDestroyFunc)
{
	if (!_stack)
	{
		return;
	}
	VectorDestroy(_stack->m_vector, _elementDestroyFunc);
	free(_stack);
}

ADTErr StackPush(Stack* _stack, void* _item)
{
	if (!_stack || !_item)
	{
		return ERR_INVARG;
	}
	return VectorAppend(_stack->m_vector, _item);
}

ADTErr StackPop(Stack* _stack, void** _poppedElement)
{
	if (!_stack || !_poppedElement)
	{
		return ERR_INVARG;
	}
	return VectorRemove(_stack->m_vector, _poppedElement);
}

ADTErr StackTop(Stack* _stack, void** _topElement)
{
	size_t numOfItems;
	
	if (!_stack || !_topElement)
	{
		return ERR_INVARG;
	}
	numOfItems = VectorItemsNum(_stack->m_vector);
	return VectorGet(_stack->m_vector, numOfItems - 1, _topElement);
}

int StackIsEmpty(Stack* _stack)
{
	size_t numOfItems;
	
	if (!_stack)
	{
		return 1;
	}
	numOfItems = VectorItemsNum(_stack->m_vector);
	return numOfItems == 0 ? 1 : 0;
}

void StackPrint(Stack* _stack, ElementFunc _elementPrintFunc)
{
	if (!_stack || !_elementPrintFunc)
	{
		return;
	}
	VectorPrint(_stack->m_vector, _elementPrintFunc);
}


