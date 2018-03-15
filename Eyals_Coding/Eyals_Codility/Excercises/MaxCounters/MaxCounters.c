// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stddef.h>
struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    size_t index;
    size_t findMaxIndex;
    int maxVal = 0;
    int* counters;
    counters = calloc(N, sizeof(int));
    for (index = 0; index < M; ++index)
    {
        if (A[index] >= 1 && A[index] <= N)
        {
            if (++counters[A[index] - 1] > maxVal)
            {
                maxVal = counters[A[index] - 1];
            }
        }
        else if(N + 1 == A[index])
        {
            for (findMaxIndex = 0; findMaxIndex < N; ++findMaxIndex)
            {
                counters[findMaxIndex] = maxVal;
            }
        }
    }
    result.C = counters;
    result.L = N;
    return result;
}
