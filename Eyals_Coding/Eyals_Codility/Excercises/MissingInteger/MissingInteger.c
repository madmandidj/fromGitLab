// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <stddef.h>
#define MY_MAX_N 100000
#define MY_MAX_INT 100000001
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    char myIntSet[MY_MAX_INT] = {0};
    size_t index;
    for (index = 0; index < N; ++index)
    {
        if (A[index] > 0)
        {
            myIntSet[A[index]] = 1;
        }        
    }
    for (index = 1; index < MY_MAX_INT; ++index)
    {
        if (!myIntSet[index])
        {
            return index;
        }
    }
    return 0;
}
