#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "stack.h"


int isBrackets(char mychar)
{
	int result;
	switch (mychar)
	{
		case '(':
			result = 1;
			break;
		case ')':
			result = 1;
			break;
		case '[':
			result = 1;
			break;
		case ']':
			result = 1;
			break;
		case '{':
			result = 1;
			break;
		case '}':
			result = 1;
			break;
		default:
			result = 0;
	}
	return result;
}

int isComplementBracket(int stackChar, char strChar)
{
	int result;
	switch (stackChar)
	{
		case '(':
			if(')' == strChar)
			{
				result = 1;
			}
			break;
		case '[':
			if(']' == strChar)
			{
				result = 1;
			}
			break;
		case '{':
			if('}' == strChar)
			{
				result = 1;
			}
			break;
		default:
			result = 0;
			break;
	}
	return result;
}

int main()
{
	Stack* stack;
	size_t size = 10;
	size_t blockSize = 2;
	char string[64];
	char temp;
	int index = 0;
	int result;
	printf("Enter a string (upto 64 characters)\n");
	fgets(string, 64, stdin);
	stack = StackCreate(size, blockSize);
	if (NULL == stack)
	{
		return 0;
	}
	while('\0' != string[index])
	{
		if(isBrackets(string[index]))
		{
			if(StackIsEmpty(stack))
			{
				StackPush(stack, string[index]);
				++index;
				continue;
			}
			else 
			{
				isComplementBracket(StackTop(stack, &result), string[index]);
				if(result == 1)
				{
					StackPop(stack, NULL);
					++index;
					continue;
				}
				else
				{
					StackPush(stack, string[index]);
					++index;
					continue;
				}
			}
		}
		++index; 
	}
	if(StackIsEmpty(stack))
	{
		printf("All GOOD in this string\n");
	}
	else
	{
		printf("This string is NOT GOOD\n");
	}
	StackDestroy(stack);
	return 0;
}
