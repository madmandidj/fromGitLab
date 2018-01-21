#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* accum(const char* source)
{
	size_t index;
	size_t curCharIndex = 0;
	size_t length;
	size_t newLength;
	char curChar = 'a';
	if (NULL = source)
	{
		return NULL;
	}
	length = strlen(source);
	newLength = 
	while (curChar != '\0')
	{
		curChar = source[curCharIndex];
		if (isalpha(curChar))
		{
			printf("%c", toupper(curChar));
			for(index = 0; index < curCharIndex; ++index)
			{
				printf("%c", tolower(source[curChar]));
			}
			printf("-");
		}
	}
	
}



int main()
{
	return 0;
}
