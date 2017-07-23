#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Files.h"

int PrintCharFreq(FILE* _fp)
{
    /*
    Number of upper and lower case letters is 52
    */
    int table[52][2];
    char line[512];
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
            fgets(line, 512, _fp);
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

int PrintStringFreq(FILE* _fp)
{
    StringFreqArr* sFA;
    StringFreq* sFTemp;
    int sFNum = 0;
    char strTemp[64];
    int sFACap = 1;
    int sCap = 64;
    char line[512];
    int lineIndex = 0;
    char string[64];
    int stringIndex = 0;
    int isStr = 0;
    int isNewStr = 0;
    int i = 0;
    int index;
    if (NULL == _fp)
    {
        return 0;
    }
    sFA = (StringFreqArr*) malloc(sizeof(StringFreqArr));
    if (NULL == sFA)
    {
        return 0;
    }
    sFA->m_cap = sFACap;
    sFA->m_noe = 0;
    sFA->m_stringFreq = (StringFreq*) malloc(sFA->m_cap * sizeof(StringFreq));
    if (NULL == sFA->m_stringFreq)
    {
        return 0;
    }
    for (index = 0; index < sFA->m_cap; ++index)
    {
        sFA->m_stringFreq[index].m_string = (char*) malloc(sCap * sizeof(char));
        sFA->m_stringFreq[index].m_freq = 0;
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
            fgets(line, 512, _fp);
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
                    for (i = 0; i < sFA->m_noe; ++i)
                    {
                        if (0 == strcmp(string, sFA->m_stringFreq[i].m_string))
                        {
                            isNewStr = 0;
                            ++sFA->m_stringFreq[i].m_freq;
                            break;
                        }
                    }
                    if (1 == isNewStr)
                    {
                        if(sFA->m_noe == sFA->m_cap)
                        {
                            sFTemp = realloc(sFA->m_stringFreq, sFA->m_cap * sizeof(StringFreq) * 2);
                            if (NULL == sFTemp)
                            {
                                for (index = 0; index < sFA->m_cap; ++index)
                                {
                                    free(sFA->m_stringFreq[index].m_string);
                                }
                                free(sFA->m_stringFreq);
                                free(sFA);
                                return 0;
                            }
                            sFA->m_cap *= 2;
                            sFA->m_stringFreq = sFTemp;
                            for (index = sFA->m_noe; index < sFA->m_cap; ++index)
                            {
                                sFA->m_stringFreq[index].m_string = (char*) malloc(sCap * sizeof(char));
                                sFA->m_stringFreq[index].m_freq = 0;
                            }
                        }
                        ++sFA->m_noe;

                        for (index = 0; index < strlen(string); ++index)
                        {
                            sFA->m_stringFreq[sFA->m_noe-1].m_string[index] = string[index];                        
                        }
                        sFA->m_stringFreq[sFA->m_noe-1].m_string[index] = '\0';
                        sFA->m_stringFreq[sFA->m_noe-1].m_freq = 1;
                    }
                }
                else
                {
                    ++lineIndex;
                }
            }
        }
    }
    for (i = 0; i < sFA->m_noe; ++i)
    {
        printf("%s\t\t%d\n", sFA->m_stringFreq[i].m_string, sFA->m_stringFreq[i].m_freq);
    }
    for (index = 0; index < sFA->m_cap; ++index)
    {
        free(sFA->m_stringFreq[index].m_string);
    }
    free(sFA->m_stringFreq);
    free(sFA);
    return 1;  
}

int PrintLastNLines(FILE *_fp, int N)
{
    char line[512];
    int lineIndex = 0;
    int textIndex = 0;
    int* newLineIndArr;
    int foundNewLineNum = 0;
    int i = 0;
    newLineIndArr = (int*) malloc(N * sizeof(int));
    if (NULL == newLineIndArr)
    {
        return 0;
    }
    if (NULL == _fp)
    {
        return 0;
    }
    fseek(_fp, 0, 0);
    while (1)
    {
        if (feof(_fp))
        {
            printf("Reached end of file\n");
            break;
        }
        else
        {
            if(fgets(line, 512, _fp) != NULL)
            {
                lineIndex = 0;
                while (line[lineIndex] != '\n' && line[lineIndex] != '\0')
                {
                    ++lineIndex;    
                }
                textIndex += lineIndex;
                newLineIndArr[foundNewLineNum % N] = textIndex;
                ++foundNewLineNum;
                printf("%d\n", textIndex);
            }
            
        }
    }
    printf("%d\n", newLineIndArr[0]);
    printf("%d\n", newLineIndArr[1]);
    printf("%d\n", newLineIndArr[2]);
    free(newLineIndArr);
    return 1;
}
