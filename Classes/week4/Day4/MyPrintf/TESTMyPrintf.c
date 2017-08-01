#include <stdio.h>
#include <string.h>
#include "MyPrintf.h"

int main()
{
	char str[1024]; 
	printf("Enter string\n");
	scanf("%s", str);
	MyPrintf("TestYo\n");
	return 0;
}
