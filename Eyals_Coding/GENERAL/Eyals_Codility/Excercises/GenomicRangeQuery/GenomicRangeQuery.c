// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#define A_VAL 1
#define C_VAL 2
#define G_VAL 3
#define T_VAL 4
struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int minImpact;
    int queryIndex;
    int stringIndex = 0;
    int* resultArr;
    char* S_impact;
    char* charPtr = S;
    
    resultArr = malloc(M * sizeof(int));
    S_impact = malloc(100000 * sizeof(char));
    
    while(0 != *charPtr)
    {
        switch(*charPtr)
        {
            case 'A':
                S_impact[stringIndex] = 1;
                break;
            case 'C':
                S_impact[stringIndex] = 2;
                break;
            case 'G':
                S_impact[stringIndex] = 3;
                break;
            case 'T':
                S_impact[stringIndex] = 4;
                break;
        }
        ++charPtr;
        ++stringIndex;
    }
    // dont need section above .. can check character values, store minimpact in character value, then at the end do a conversion to impact values
    for(queryIndex = 0; queryIndex < M; ++queryIndex)
    {
        minImpact = 5;
        for (stringIndex = P[queryIndex]; stringIndex <= Q[queryIndex]; ++stringIndex)
        {
            if (1 == minImpact)
            {
                break;
            }
            else if (S_impact[stringIndex] < minImpact)
            {
                minImpact = S_impact[stringIndex];
            }
        }
        resultArr[queryIndex] = minImpact;
    }
    
    result.A = resultArr;
    result.M = M;
    return result;
}



/*
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#define A_VAL 1
#define C_VAL 2
#define G_VAL 3
#define T_VAL 4
struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int minImpact;
    int queryIndex;
    int stringIndex;
    int* resultArr;
    
    resultArr = malloc(M * sizeof(int));
    
    for(queryIndex = 0; queryIndex < M; ++queryIndex)
    {
        minImpact = 5;
        for (stringIndex = P[queryIndex]; stringIndex <= Q[queryIndex]; ++stringIndex)
        {
            if (1 == minImpact)
            {
                break;
            }
            switch(S[stringIndex])
            {
                case 'A':
                    minImpact = 1;
                    break;
                case 'C':
                    minImpact = C_VAL < minImpact ? C_VAL : minImpact;
                    break;
                case 'G':
                    minImpact = G_VAL < minImpact ? G_VAL : minImpact;
                    break;
                case 'T':
                    minImpact = T_VAL < minImpact ? T_VAL : minImpact;
                    break;
            }
        }
        resultArr[queryIndex] = minImpact;
    }
    
    result.A = resultArr;
    result.M = M;
    return result;
}
*/

