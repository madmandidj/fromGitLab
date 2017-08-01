#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct String
// {
//     char m_string[64];
//     unsigned int length;
// }String;

// typedef struct StringFreqTable
// {
//     String m_strArr[256];
//     int m_strFreqArr[256];
// }StringFreqTable;



typedef struct Char
{
    char m_char;
}Char;

typedef struct String
{
    Char* m_string;
}String;

typedef struct StrArr
{
    String* m_strArr;
}StrArr;


int main() 
{
    StrArr* strArr;
    strArr = malloc(32 * sizeof(StrArr));
    strArr->m_strArr = malloc(32 * sizeof(String));
    strArr->m_strArr[0]->m_string[0] = 'c';
    /*
    StringFreqTable sFT;
    printf("Enter the first string\n");
    scanf("%s", sFT.m_strArr[0].m_string);
    sFT.m_strArr[0].length = strlen(sFT.m_strArr[0].m_string);
    printf("%s, %d\n", sFT.m_strArr[0].m_string, sFT.m_strArr[0].length);
    printf("Enter the second string\n");
    scanf("%s", sFT.m_strArr[1].m_string);
    printf("%s\n", sFT.m_strArr[1].m_string);
    */

    // int i;
    // StringArr* stringArr;
    // string = malloc(32 * sizeof(String));
    // // char* string;
    // // string = malloc(sizeof(char) * 21);
    // for (i = 0; i < 20; ++i)
    // {
    //     string[i] = 48+i;
    //     printf("%c\n", string[i]);
    // }
    // string[20] = '\0';
    // printf("%s\n", string);
    // printf("%c\n", string[19]);
    
    // free(string);
    // printf("%lu\n", sizeof(int));
    // printf("%lu\n", sizeof(char));

    return 0;
}
