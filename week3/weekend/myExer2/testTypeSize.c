#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(char));
    return 0;
}
