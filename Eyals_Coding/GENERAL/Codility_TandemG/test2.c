#include <stdio.h>

int solution(int *A, int A_length) {
    int n = A_length;
    int result = 0;
    int i;
    for (i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1])
            result = result + 1;
    }
    int r = 0;
    for (i = 0; i < n; i++) {
        int count = 0;
        if (i > 0) {
            if (A[i - 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (i < n - 1) {
            if (A[i + 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (count > r)
            r = count;
    }
    return result + r;
}


int main()
{
	int A[6] = {1,1,0,1,0,0};
	int N = 6;
	
	printf("%d\n", solution(A, N));
	return 0;
}
