#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct String
{
    char m_string[64];
    unsigned int length;
}String;

typedef struct StringArr
{
    String m_strArr[256];
    int m_strFreqArr[256];
}StringArr;
*/


typedef struct String
{
    char m_string[64];
    unsigned int length;
}String;

typedef struct StringFreqTable
{
    String m_strArr[256];
    int m_strFreqArr[256];
}StringFreqTable;

int main() 
{

    StringFreqTable sFT;
    /*
    sFT = malloc(sizeof(StringFreqTable));
    if (NULL == sFT)
    {
        return 0;
    }
    */
     
    printf("Enter the first string\n");
    scanf("%s", sFT.m_strArr[0].m_string);
    sFT.m_strArr[0].length = strlen(sFT.m_strArr[0].m_string);
    printf("%s, %d\n", sFT.m_strArr[0].m_string, sFT.m_strArr[0].length);
    
    printf("Enter the second string\n");
    scanf("%s", sFT.m_strArr[1].m_string);
    printf("%s\n", sFT.m_strArr[1].m_string);
    
    /*
    StrFreq* strFreq;
    String* stringArr;
    char myString[64];
    strFreq = malloc(StrFreq);
    strFreq->m_strArr = malloc(64 * sizeof(String));
    strFreq->m_strArr[0]

    free(strFreq);
    */

/*
    String stringArr[256];
    printf("Enter first string");
    scanf("%s", stringArr[0].m_string);
    printf("Enter second string");
    scanf("%s", stringArr[1].m_string);
    printf("%s\n", stringArr[0].m_string);
    printf("%s\n", stringArr[1].m_string);
    */

    /*
    StringArr stringArr;
    printf("Enter the first string\n");
    scanf("%s", stringArr.m_strArr[0].m_string);
    printf("%s\n", stringArr.m_strArr[0].m_string);
    scanf("%s", stringArr.m_strArr[1].m_string);
    printf("%s\n", stringArr.m_strArr[1].m_string);
    */

    return 0;
}
