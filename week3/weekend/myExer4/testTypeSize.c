#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{
    int* numArr;
    int i;
    numArr = (int*) malloc(10 * sizeof(int));
    if (NULL == numArr)
    {
        return 0;
    }
    for (i = 0; i < 100; ++i)
    {
        numArr[i] = i;
        printf("%d\n", numArr[i]);
    }
    printf("%lu", sizeof(int));
    free(numArr);
    return 0;
}
