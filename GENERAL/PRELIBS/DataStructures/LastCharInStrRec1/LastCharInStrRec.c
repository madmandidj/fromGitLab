#include <stdio.h>

/*
char LastChar(char* _str, int index)
{
	if ('\0' == _str[index] && 0 == index)
	{
		return 0;
	} 
	else if ('\0' == _str[index])
	{
		return _str[index-1];
	} 
	else 
	{
		return (LastChar(_str, index+1));
	}
}
*/

char LastChar(char* _str)
{
	if ('\0' == _str[1])
	{
		return _str[0];
	} 
	else 
	{
		return (LastChar(_str+1));
	}
}

int main()
{
	char result;
	char str[] = "\nblahahH";
	int index = 0;
	/* result = LastChar(str, index); */
	result = LastChar(str);
	printf("%c\n", result);
	return 0;
}
