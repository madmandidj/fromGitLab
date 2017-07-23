#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Files.h"

int PrintCharFreq(FILE* _fp)
{
    /*
    Number of letters is 26 (x2 for upper & lower)
    Left column stores letter, right column stores frequency
    */
    int table[52][2];
    int tabElements = 0;
    int tableIndex = 0;
     /* Variable to read new line from text file */
    char line[512];
    int lineIndex = 0;
    /* Flagged if valid char is detected from line */
    int isNewChar;
    /* Counter */
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
    /* Initial capacity of StringFreq array*/
    int strFreqCap = 2; 
    /* Initial capacity of StringFreq-member string*/
    int strCap = 64;
    /* Variable to read new line from text file */
    char line[512];
    int lineIndex = 0;
    /* Variable to store detected string, then compare to StringFreq array */
    char string[64];
    int stringIndex = 0;
    /* Flagged if valid string is detected from line */
    int isStr = 0;
    /* Flagged if string is not in StringFreq array */
    int isNewStr = 0;
    /* Counters */
    int i = 0;
    int j = 0;
    if (NULL == _fp)
    {
        return 0;
    }
    sFA = (StringFreqArr*) malloc(sizeof(StringFreqArr));
    if (NULL == sFA)
    {
        return 0;
    }
    sFA->m_cap = strFreqCap;
    sFA->m_noe = 0;
    sFA->m_stringFreq = (StringFreq*) malloc(sFA->m_cap * sizeof(StringFreq));
    if (NULL == sFA->m_stringFreq)
    {
        free(sFA);
        return 0;
    }
    for (i = 0; i < sFA->m_cap; ++i)
    {
        sFA->m_stringFreq[i].m_string = (char*) malloc(strCap * sizeof(char));
        if(NULL == sFA->m_stringFreq[i].m_string)
        {
            for(j = i; j < 0; --j)
            {
                free(sFA->m_stringFreq[j].m_string);
            }
            free(sFA->m_stringFreq);
            free(sFA);
        }
        sFA->m_stringFreq[i].m_freq = 0;
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
                                for (i = 0; i < sFA->m_cap; ++i)
                                {
                                    free(sFA->m_stringFreq[i].m_string);
                                }
                                free(sFA->m_stringFreq);
                                free(sFA);
                                return 0;
                            }
                            sFA->m_cap *= 2;
                            sFA->m_stringFreq = sFTemp;
                            for (i = sFA->m_noe; i < sFA->m_cap; ++i)
                            {
                                sFA->m_stringFreq[i].m_string = (char*) malloc(strCap * sizeof(char));
                                sFA->m_stringFreq[i].m_freq = 0;
                            }
                        }
                        ++sFA->m_noe;

                        for (i = 0; i < strlen(string); ++i)
                        {
                            sFA->m_stringFreq[sFA->m_noe-1].m_string[i] = string[i];                        
                        }
                        sFA->m_stringFreq[sFA->m_noe-1].m_string[i] = '\0';
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
    for (i = 0; i < sFA->m_cap; ++i)
    {
        free(sFA->m_stringFreq[i].m_string);
    }
    free(sFA->m_stringFreq);
    free(sFA);
    return 1;  
}


/*
This function is not complete as of 6 July 2017
*/
int PrintLastNLines(FILE *_fp, int N)
{
    char line[512];
    int lineIndex = 0;
    int textIndex = 0;
    int* newLineIndArr;
    int foundNewLineNum = 0;
    newLineIndArr = (int*) malloc(N * sizeof(int));
    if (NULL == newLineIndArr)
    {
        return 0;
    }
    if (NULL == _fp)
    {
        return 0;
    }
    newLineIndArr[0] = 0;
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
            lineIndex = 0;
            fgets(line, 512, _fp);
            while (line[lineIndex] != '\0' && line[lineIndex] != '\n')
            {
                ++lineIndex;
            }
            if (line[lineIndex] == '\n')
            {
                ++foundNewLineNum;
                newLineIndArr[foundNewLineNum-1 % N] = textIndex + lineIndex;
                textIndex += lineIndex;
            }
        }
    }
    printf("%d\n",newLineIndArr[foundNewLineNum-3 % N]);
    printf("%d\n",newLineIndArr[foundNewLineNum-2 % N]);
    printf("%d\n",newLineIndArr[foundNewLineNum-1 % N]);
    free(newLineIndArr);
    return 1;
}
