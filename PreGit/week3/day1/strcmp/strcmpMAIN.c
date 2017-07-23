#include <stdio.h>
#include <string.h>
#include "strcmp.h"

int main()
{
    char str1[MY_STRING_CAP];
    char str2[MY_STRING_CAP];
    printf("Enter string\n");
    fgets(str1,MY_STRING_CAP, stdin);
    int str1_len = strlen(str1);
    printf("%d\n", str1_len);
    str1[str1_len-1] = '\0';
    str1_len = strlen(str1);
    printf("%d\n", str1_len);
    printf("%s\n", str1);
    return 0;
}