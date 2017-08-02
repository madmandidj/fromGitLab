#include <stdio.h>
#include "stack.h"
#include "vector.h"
#define NUM_OF_TOWERS 3

void InitTowers(Stack** _towers, size_t _size, size_t _blockSize)
{
	int index;
	size_t ring;
	if (NULL == _towers || 0 == _size)
	{
		return;
	}
	for (index = 0; index < NUM_OF_TOWERS; ++index)
	{
		_towers[index] = StackCreate(_size, _blockSize);
	}
	for (ring = _size; ring > 0; --ring)
	{
		StackPush(_towers[0], ring);
	}
	return;
}

void DestroyTowers(Stack** _towers)
{
	int index;
	if (NULL == _towers)
	{
		return;
	}
	else
	{
		for (index = 0; index < NUM_OF_TOWERS; ++index)
		{
			StackDestroy(_towers[index]);
		}
	}
	return;
}

void moveRings(Stack** _towers, int _rNum, int _source, int _dest, int _using)
{
	int topSource;
	int topDest;
	int topUsing;
	if (NULL == _towers || NULL == *_towers)
	{
		return;
	}
	else
	{
		StackTop(_towers[_source], topSource);
		
		if (item )
	}
}

int main()
{
	// Create 3 integers arrays
	Stack* towers[NUM_OF_TOWERS];
	size_t size = 6;
	size_t blockSize = 2;
	int item;
	InitTowers(towers, size, blockSize);
	StackPop(towers[0], &item);
	StackPush(towers[1], item);
	printf("******\n");
	StackPrint(towers[0]);
	printf("**\n");
	StackPrint(towers[1]);
	printf("**\n");
	StackPrint(towers[2]);
	printf("**\n");
	DestroyTowers(towers);
	// int item = 17;

	// towers[0] = StackCreate(size, blockSize);
	// StackPrint(towers[0]);
	// StackPush(towers[0], item);


	// StackDestroy(towers[0]);
	return 0;
}
