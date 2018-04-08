





/*
This got 45%
*/
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stddef.h>
#define MY_MAXINT 1000000001
#define MY_MAXN 100000
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    char intSet[MY_MAXINT] = {0};
    size_t index;
    for (index = 0; index < N; ++index)
    {
        ++intSet[A[index]];
        if (intSet[A[index]] > 1)
        {
            return 0;
        }
    }
    for (index = 1; index <= N; ++index)
    {
        if (intSet[index] != 1)
        {
            return 0;
        }
    }
    return 1;
}


