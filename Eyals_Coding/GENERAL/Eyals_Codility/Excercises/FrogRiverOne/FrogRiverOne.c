

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stddef.h>
#define MY_MAX_INT 100000
int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    char positionSet[MY_MAX_INT] = {0};
    unsigned int targetSum = 0;
    unsigned int tempSum = 0;
    size_t index;
    
    for (index = 1; index <= X; ++index)
    {
        targetSum += index;
    }
    
    for (index = 0; index < N; ++index)
    {
        if (!positionSet[A[index]])
        {
            positionSet[A[index]] = 1;
            tempSum += A[index];
        }
        if (tempSum == targetSum)
        {
            return index;
        }
    }
    return -1;
}


