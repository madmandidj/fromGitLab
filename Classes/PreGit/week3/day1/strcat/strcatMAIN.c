#include <stdio.h>
#include <string.h>
#include "strcat.h"

int main()
{
    char str1[1024];
    char str2[1024];
    printf("Enter first string\n");
    fgets(str1, 1024, stdin);
    printf("Enter second string\n");
    fgets(str2, 1024, stdin);
    printf("%s\n", str1);
    printf("%s\n", str2);
    My_strcat(str1, str2);
    printf("%s\n",str1);
    return 0;
}