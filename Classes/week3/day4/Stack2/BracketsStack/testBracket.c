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
		case '(':
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

int isComplementBracket(char stackChar, char strChar)
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
	Stack* stack
	char string[64];
	int index = 0;
	int numOfItems;
	int result;
	Printf("Enter a string (upto 64 characters");
	scanf("%s",string);
	stack = malloc(sizeof(Stack));
	if (NULL == stack)
	{
		return NULL;
	}
	while('\0' != string[index])
	{
		if(isBrackets(string[index]))
		{
			if(StackIsEmpty(stack))
			{
				StackPush(stack, string[index]);
				++index;
			}
			else 
			{
				isComplementBracket(StackTop(stack, result));
				if(result == 1)
				{
					StackPop(stack);
					++index;
				}
				else
				{
					StackPush(stack, string[index]);
					++index;
				}
			}
		} 
	}
	return 0;
}
