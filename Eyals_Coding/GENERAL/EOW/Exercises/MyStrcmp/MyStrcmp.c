#include <stdio.h>
// #include <string.h>
#define STRLENGTH 64
int MyStrCmp(const char* str1, const char* str2);

int MyStrCmp(const char* str1, const char* str2)
{
    size_t index = 0;
    while(0 != str1[index] && 0 != str2[index])
    {
        if (str1[index] == str2[index])
        {
            ++index;
            continue;
        }
        else
        {
            break;
        }
    }
    return str1[index] - str2[index];
}

int main()
{
    char str1[STRLENGTH];
    char str2[STRLENGTH];
    printf("Enter first string (upto %d characters)\n", STRLENGTH);
    scanf("%s", str1);
    printf("Enter second string (upto %d characters)\n", STRLENGTH);
    scanf("%s", str2);
    printf("MyStrCmp result = %d\n", MyStrCmp("Eyaly", "Eyal"));
    return 0;
}