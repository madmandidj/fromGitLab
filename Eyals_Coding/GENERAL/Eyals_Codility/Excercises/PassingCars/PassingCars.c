// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int eastCarsNum = 0;
    unsigned int passingCarsNum = 0;
    int index;
    
    for (index = 0; index < N; ++index)
    {
        if (0 == A[index])
        {
            ++eastCarsNum;
        }
        else
        {
            passingCarsNum += eastCarsNum;
        }
    }
    return passingCarsNum > 1000000000 ? -1 : passingCarsNum;
}

