#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringHomework.h"

int main(){
    char* str = malloc(MY_STRING_CAPACITY*sizeof(char));
    int result;
    int base = 10;
    printf("\nEnter a string (<100 characters)\n");
    scanf("%s",str);
    result = ReverseString(str);
    printf("Reverse result is: %d\n", result);
    result = IsPalindrome(str);
    printf("Palindrome result is: %d\n",result);
    result = my_atoi(str);
    printf("my_atoi result is: %d\n", result);
    printf("atoi result: %d\n", atoi(str));
    str = my_itoa(result, str, base);
    printf("my_itoa result: %s\n", str);
    free(str);
    return 0;
}