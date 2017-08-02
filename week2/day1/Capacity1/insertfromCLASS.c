#include <stdio.h>
#include <stdlib.h>


int* insert (int* Arr, int N, int *index, int* capacity)
{
	int* ip;
	if (*index<*capacity)
		Arr[*index]=N;
		
	else
	{
		ip= realloc (Arr, (*capacity)*2);
		if (ip != NULL)
		{
		*capacity*=2;
		Arr[*index]=N;
		*index += 1;
		}
	}

return ip;

}



int main()
{
	int* pArr,a;	
	int i=0, capacity=0, N, index=0;
	
	printf("Please insert initial capacity of the array: ");
	scanf("%d", &capacity);
	
	pArr = malloc(capacity*sizeof(int));
	do
	{	
		printf ("Please enter a positive number to inser to the array. To stop, enter a negative number: ");
		scanf ("%d", &N);
		a = insert (pArr, N, &index, &capacity);
		if (a==NULL)
			printf("Not enough space for the array\n");
		pArr = a;
		
	}
	while (N>0);
	


	


return 0;
}
