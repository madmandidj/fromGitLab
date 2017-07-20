#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "ArgVArgC.h"

int IsAge(char* _str)
{
	int i;
	int strLen;
	if (NULL == _str)
	{
		return 0;
	}
	strLen = strlen(_str);
	if (isdigit(_str[0]))
	{
		for (i = 1; i < strLen; ++i)
		{
			if (!isdigit(_str[i]))
			{
				return 0;
			}
		}
		return atoi(_str);
	}
	else
	{
		return 0;
	}
}

int IsFirstName(char* _str)
{
	int i;
	int strLen;
	if (NULL == _str)
	{
		return 0;
	}
	strLen = strlen(_str);
 	if (isupper(_str[0]))
	{
		for (i = 1; i < strLen; ++i)
		{
			if (!islower(_str[i]))
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

