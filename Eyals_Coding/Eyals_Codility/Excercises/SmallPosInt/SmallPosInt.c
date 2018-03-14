#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int solution(int A[], int N)
{
	char* bitSet;
	unsigned int index;
	bitSet = malloc(INT_MAX * sizeof(char));
	for (index = 0; index < N; ++index)
	{
		if (A[index] <= 0)
		{
			continue;
		}
		bitSet[A[index]] = 1;
	}
	for (index = 1; index < INT_MAX; ++index)
	{
		if(!bitSet[index])
		{
			return index;
		}
	}
	free(bitSet);
	return 0;
}

int main()
{
/*	int A[4] = {1, 2, 3, 4};*/
	int A[8] = {5, 1, -2, 3, 4, 5, 7, 9};
	int N = 8;
	printf ("%d\n", solution(A, N));
	return 0;
}
