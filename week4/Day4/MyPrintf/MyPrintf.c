#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "MyPrintf.h"


int MyPrintf(const char* format, ...)
{
	char str[1024]; 
	int strLen;
	int index = 0;
	int nextParmIndex = 0;
	int newStrIndex = 0;
	int output = 0;
	char* newStr;
	char* percPoint;
	int nextParmInt;
	double nextParmDbl;
	char nextParmStr[1024];
	va_list args;
	va_start(args, format);
	strLen = strlen(format);
	newStr = malloc((strLen+1) * sizeof(char));
	percPoint = strchr(format, '%');
	if (NULL == percPoint)
	{
		output = strLen;
		fputs(format, stdout);
	}
	else
	{
		while(format[index] != '\0')
		{
			if (format[index] != '%')
			{
				newStr[newStrIndex] = format[index];
				++newStrIndex;
			}
			else
			{
				switch(format[index+1])
				{
					case 's':
					nextParmStr = va_arg(args, char*);
					for (nextParmIndex = 0; nextParmIndex < strlen(nextParmStr); ++nextParmIndex)
					{
						newStr[index+nextParmIndex] = nextParmStr[nextParmIndex];
						++newStrIndex;
					}
					for(
						break;
					case 'd':
					nextParmInt = va_arg(args, int);
						break;
					case 'f':
					nextParmDbl = va_arg(args, double);
						break;
					case '%':
					newStr[index] = '%';
					++index;
						break;
					default:
						return 0;
						break;
				}
			}
			++index;
		}
	}
	free(newStr);
	return index;
}








