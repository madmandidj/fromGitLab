#include <stdio.h>



void GetUserData()
{
	char str[10];
	size_t index;
	
/*	while(1)*/
/*	{*/
/*		printf("Enter string up to 10 characters\n");*/
/*		scanf("%s", str);*/
/*		printf("Result: %s\n", str);*/
/*	}*/

	for(index = 0; index < 5; ++index)
	{
		printf("Enter string up to 10 characters\n");
		scanf("%s", str);
		printf("Result: %s\n", str);
	}

	return;
}


int main()
{
	GetUserData();
	printf("Returned to main\n");
	return 0;
}
