int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    if (0 == A)
    {
        return B/K + 1;
    }
    return B/K - (A-1)/K;
}





/*
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    if (A == 0 && B == 0)
    {
        return 1;
    }
    else if(B-A == 0)
    {
        return (K == B || ((B % K)==0)) ? 1 : 0;
    }
    return A % K == 0 || B % K == 0  ? ( ((B-A)/K) + 1 ) : (B-A)/K;
}

*/
