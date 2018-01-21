#include <stdio.h>
#include <string.h>
#include <limits.h>
/******************
*******************
*******************
*******************
*******************
1.  Write a function, count, which counts the occurences in the first argument, s1, of the characters in the second argument, s2:
        int count(char* s1, char* s2);
    For example,
        i = count("abracadabra", "bax");
    would return 7 (5 times for 'a', and twice for 'b')
******************/
/******************
Solution 1
******************/
/*
int Count(char* s1, char* s2)
{
    size_t index;
    size_t s1Length;
    size_t s2Length;
    unsigned int charsMap[CHAR_MAX] = {0};
    size_t count = 0;
    
    if (!s1 || !s2)
    {
        return -1;
    }
    
    s1Length = strlen(s1);
    s2Length = strlen(s2);
    if (!s1Length || !s2Length)
    {
        return 0;
    }

    for (index = 0; index < s1Length; ++index)
    {
        ++charsMap[(unsigned int)s1[index]];
    }

    for (index = 0; index < s2Length; ++index)
    {
        if (charsMap[(unsigned int)s2[index]])
        {
            count += charsMap[(unsigned int)s2[index]];
        }
    }

    return count;
}
/******************
Solution 2
******************/

int Count(char* s1, char* s2)
{
    size_t index;
    size_t s1Length;
    size_t s2Length;
    unsigned int charsMap[CHAR_MAX] = {0};
    size_t count = 0;
    
    if (!s1 || !s2)
    {
        return -1;
    }
    
    s1Length = strlen(s1);
    s2Length = strlen(s2);
    if (!s1Length || !s2Length)
    {
        return 0;
    }

    for (index = 0; index < s1Length; ++index)
    {
        ++charsMap[(unsigned int)s1[index]];
    }

    for (index = 0; index < s2Length; ++index)
    {
        if (charsMap[(unsigned int)s2[index]])
        {
            count += charsMap[(unsigned int)s2[index]];
        }
    }

    return count;
}


int main()
{
    char str1[] = "abracadabra";
    char str2[] = "bac";
    int count;

    count = Count(str1, str2);
    printf("count = %d\n", count);


    return 0;
}


/******************
*******************
*******************
*******************
*******************
2.  Write a function to find a palindromic substring in a string.
    Example: "ABC1771CDT"
        palindromic substring is: "C1771C"
******************/
/*
#define STRLENGTH 64
char* FindPalindromeSubString(char* s1)
{
    char* headPtr;
    char* curHeadPtr;
    char* workingHeadPtr;
    size_t curHead = 0;
    char* tailPtr;
    char* curTailPtr;
    char* workingTailPtr;
    size_t curTail;
    char* resultPtr = NULL;

    if (!s1 || 1 <= strlen(s1))
    {
        return NULL;
    }

    return NULL;
}
*/
/*
    Pseudo code:
        init head and tail pointers
        while (!IsPalindrome)
        {
            set headptr, curheadptr, tailptr, curtailptr;
            if (*curheadptr == *curtailptr)
            {
                workingHead = curheadptr;
                workingTail = curtailptr;
                while (*workingHead == *workingTail && ((workingHead + 1) != workingTail))
                {
                    
                }
            }
        }
*/














