#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int main()
{
	// char c;
	// c = 77;
	// printf("%c\n",c);
	// return 0;

	char temp[] = "  12rt";
	// char temp[]=" r 12rt";
	// char temp[100];
	char temp2[100];
	int str_length;
	int num1;
	int num2;
	int num = 0;
	char *str1;
	char *str;
	char *pch;
	char c;
	int i = 0;
	int j = 0;
	str_length = strlen(temp);
	while (!isdigit(temp[i]) && temp[i] != 0)
	{
		if (!isspace(temp[i]))
		{
			printf("Not a valid input");
			return 0;
		}
		i++;
	}
	if (temp[i] == 0)
	{
		printf("Not a valid input");
		return 0;
	}
	else
	{
		while (isdigit(temp[i]))
		{
			temp2[j] = temp[i];
			++j;
			++i;
		}
		temp2[j+1]='\0';
		puts("Great");
		printf("%s\n",temp2);
	}
	printf("%d\n", i);
	return 0;
}