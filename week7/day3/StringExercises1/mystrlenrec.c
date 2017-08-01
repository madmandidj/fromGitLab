#include <stdio.h>


int StrLenRec(const char* _str, int index)
{
	if (_str[index] == '\0')
	{
		return index - 1;
	}
	else
	{
		index += 1;
		index = StrLenRec(_str, index);
	}	
	return index;
}

int MyStrLenRec(const char* _str)
{
	int index = 0;
	if (NULL == _str)
	{
		return 0;
	}
	index = StrLenRec(_str, index);
	return index;
}

int MyStrLenIter(const char* _str)
{
	int index = 0;
	if (NULL == _str)
	{
		return 0;
	}
	while (_str[index] != '\0')
	{
		++index;
	}
	return index - 1;
}

int main()
{
	char str[128];
	int strlength = 0;
	printf("Enter a string\n");
	fgets(str, 128, stdin);
	printf("%s\n", str);
	strlength = MyStrLenRec(str);
	printf("strlength Rec = %d\n", strlength);
	strlength = MyStrLenIter(str);
	printf("strlength Iter = %d\n", strlength);
	return 1;
}
