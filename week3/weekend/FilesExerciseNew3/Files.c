#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Files.h"

int PrintRepeatedLetters(FILE* _fp)
{
    char line[1024];
    int table[50][2];
    int tabElements = 0;
    int lineIndex = 0;
    int tableIndex = 0;
    int isNewChar;
    int i = 0;
    if (NULL == _fp)
    {
        return 0;
    }
    fseek(_fp, 0, 0);
    while (1)
    {
        if (feof(_fp))
        {
            break;
        }
        else
        {
            lineIndex = 0;
            fgets(line, 1024, _fp);
            while (line[lineIndex] != '\0')
            {
                if (islower(line[lineIndex]) || isupper(line[lineIndex]))
                {
                    tableIndex = 0;
                    isNewChar = 1;
                    while (tableIndex < tabElements)
                    {
                        if (table[tableIndex][0] == line[lineIndex])
                        {
                            ++(table[tableIndex][1]);
                            isNewChar = 0;
                            break;
                        }
                        ++tableIndex;
                    }
                    if (isNewChar == 1)
                    {
                        table[tabElements][0] = line[lineIndex];
                        table[tabElements][1] = 1;
                        ++tabElements;
                    }
                }
                ++lineIndex;
            }
        }
    }
    for (i = 0; i < tabElements; ++i)
    {
        printf("%c  %d\n", table[i][0], table[i][1]);
    }
    return 1;
}

int PrintRepeatedStrings(FILE* _fp)
{
    StringFreq* sF;
    StringFreqArr* sFA;
    char line[1024];
    char string[64];
    int initSFACap = 256;
    int strElements = 0;
    int lineIndex = 0;
    int stringIndex = 0;
    int tableIndex = 0;
    int isStr = 0;
    int isNewStr = 0;
    int i = 0;

    sFA = malloc(sizeof(StringFreqArr));
    if (NULL == sF)
    {
        return 0;
    }
    sFA->m_sF = malloc(initSFACap * sizeof(StringFreq));
    if (NULL == sFA->m_sF)
    {
        free(sFA);
        return 0;
    }
    sFA->cap = initSFACap;

    if (NULL == _fp)
    {
        return 0;
    }
    fseek(_fp, 0, 0);
    while (1)
    {
        if (feof(_fp))
        {
            break;
        }
        else
        {
            lineIndex = 0;
            fgets(line, 1024, _fp);
            while (line[lineIndex] != '\0')
            {
                isStr = 0;
                stringIndex = 0;
                while (islower(line[lineIndex]) || isupper(line[lineIndex]))
                {
                    isStr = 1;
                    string[stringIndex] = line[lineIndex];
                    ++lineIndex;
                    ++stringIndex;
                }
                if (1 == isStr)
                {
                    string[stringIndex] = '\0';
                    isNewStr = 1;
                    for (i = 0; i < strElements; ++i)
                    {
                        if (0 == strcmp(string, sFA->m_sF[i].m_string))
                        
                        {
                            isNewStr = 0;
                            ++sFA->m_sF[i].m_freq;
                        }
                    }
                    if (1 == isNewStr)
                    {
                         ++strElements;
                        strcpy(sFA->m_sF[strElements-1].m_string, string);
                        ++(sFA->m_sF[strElements-1].m_freq);
                    }
                }
                else
                {
                    ++lineIndex;
                }
            }
        }
    }
    for (i = 0; i < strElements; ++i)
    {
        printf("%s  %d\n", sFA->m_sF[i].m_string, sFA->m_sF[strElements-1].m_freq);
    }
    free (sFA->m_sF);
    free(sFA);
    return 1;  
}

int PrintLast(FILE *_fp, int N)
{
    if (_fp == NULL)
    {
        return 0;
    }

    return 1;
}
