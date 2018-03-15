// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    unsigned int  expectedSum = 0;
    unsigned int actualSum = 0;
    unsigned int index;
    
    for (index = 0; index < N; ++index)
    {
        expectedSum += (index + 1);
        actualSum += A[index];
    }
    expectedSum += N + 1;
    
    return expectedSum - actualSum;
}
