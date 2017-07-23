#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myFiles.h"

int PrintRepeatedLetters(FILE *fp)
/*
TODO:
DONE - check why output is double --> because had "\n" within the input string to the file
*/
{
    if (fp == NULL)
    {
        return 0;
    }
    char str[1024];
    int result_table[50][2];
    int num_of_elements = 0;
    int i = 0;
    int str_index = 0;
    int table_index = 0;
    int is_new_char;
    for (i = 0; i < 50; ++i)
    {
        result_table[i][0] = 0;
        result_table[i][1] = 0;
    }
    fseek(fp, 0, 0);
    while (1)
    {
        if (feof(fp))
        {
            break;
        }
        else
        {
            str_index = 0;
            fgets(str, 1024, fp);
            //str[strlen(str)] = '\0'; // remove trailing \n from str
            while (str[str_index] != '\0')
            {
                if (islower(str[str_index]) || isupper(str[str_index]))
                {
                    table_index = 0;
                    is_new_char = 1;
                    while (table_index < num_of_elements)
                    {
                        if (result_table[table_index][0] == str[str_index])
                        {
                            ++(result_table[table_index][1]);
                            is_new_char = 0;
                            break;
                        }
                        ++table_index;
                    }
                    if (is_new_char == 1)
                    {
                        result_table[num_of_elements][0] = str[str_index];
                        result_table[num_of_elements][1] = 1;
                        ++num_of_elements;
                    }
                }
                ++str_index;
            }
        }
    }
    for (i = 0; i < num_of_elements; ++i)
    {
        printf("%c  %d\n", result_table[i][0], result_table[i][1]);
    }
    return 1;
}

int PrintRepeatedStrings(FILE *fp)
{
    if (fp == NULL)
    {
        return 0;
    }
    char line[1024];
    int line_index = 0;
    char temp_str[32];
    int temp_str_index;
    int temp_str_cap;
    int str_freq_cap = 256;
    int is_valid_string;
    int strfreq_elements = 0;
    int strfreq_index;
    str_freq *str_freq;
    str_freq = malloc(256 * sizeof(str_freq));
    if (str_freq == NULL)
    {
        return -1;
    }
    else
    {
        str_freq->str = malloc(32 * sizeof(char));
        if (str_freq->str == NULL)
        {
            return -1;
        }
        else
        {
            str_freq->cap = 256;
        }
    }
    fseek(fp, 0, 0);
    fgets(line, 1024, fp);
    printf("%s", line);

    while (1)
    {
        // iterate until end of file
        // gets current string
        // if current string index is upper/lowercase continue, else go to next char
        // while current string index is upper/lowercase add current char to end of temp string
        // if current string already exists in string array, increment, else create new array object
        //str[strlen(str)] = '\0'; // remove trailing \n from str
        if (feof(fp))
        {
            break;
        }
        else
        {
            line_index = 0;
            fgets(line, 1024, fp);
            while (line[line_index] != '\0')
            {
                temp_str_index = 0;
                temp_str_cap = 0;
                is_valid_string = 0;
                while(islower(line[line_index]) || isupper(line[line_index])
                {
                    temp_str[temp_str_index] = line[line_index];
                    ++temp_str_cap;
                    ++line_index;
                    ++temp_str; 
                    is_valid_string = 1;                   
                }
                strfreq_index = 0;
                if (is_valid_string == 1)
                {
                    //check which string is larger, string to compare or array string
                    ++strfreq_elements;
                }
                    ++line_index;
            }
        }
    }
    free(str_freq->str);
    free(str_freq);
    return 1;
}

int PrintLast(FILE *fp, int N)
{
    if (fp == NULL)
    {
        return 0;
    }

    return 1;
}