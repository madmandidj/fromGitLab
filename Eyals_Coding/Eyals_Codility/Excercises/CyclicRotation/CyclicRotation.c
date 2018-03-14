#include <stdio.h>
#include <stddef.h>

/* didnt take care of case where array is empty */

void solution(int A[], int N, int K) 
{
    int rotation;
    int index;
    int tempNum;
    K = K % N;
    for (rotation = 0; rotation < K; ++rotation)
    {
    	tempNum = A[N-1];
    	for (index = N-1; index > 0; --index)
    	{
    		A[index] = A[index - 1];
    	}
    	A[0] = tempNum;
    }
    return;
}




int main()
{
	int A[4] = {1, 2, 3, 4};
	int N = 4;
	int K = 2;
	size_t index;
	
	for (index = 0; index < N; ++index)
	{
		printf("%d ", A[index]);
	}
	printf("\n");
	
	solution(A, N, K);
	
	for (index = 0; index < N; ++index)
	{
		printf("%d ", A[index]);
	}
	printf("\n");
	
	return 0;
}

