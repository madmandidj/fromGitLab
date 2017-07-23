#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include "stringHomework.h"

int ReverseString(char *str)
{
    if (str == NULL)
    {
        return ERROR_VAL;
    }
    int str_length = strlen(str);
    int index;
    char temp_char;
    for (index = 0; index < str_length / 2; ++index)
    {
        temp_char = str[index];
        str[index] = str[str_length - 1 - index];
        str[str_length - 1 - index] = temp_char;
    }
    return SUCCES_VAL;
}

int IsPalindrome(char *str)
{
    if (str == NULL)
    {
        return ERROR_VAL;
    }
    int str_length = strlen(str);
    int index;
    for (index = 0; index < str_length / 2; ++index)
    {
        if (str[index] != str[str_length - 1 - index])
        {
            return FAIL_VAL;
        }
    }
    return SUCCES_VAL;
}

int CheckFirstCharactersAreValid(char *str, int *parsed_chars_num)
{
    /*
        Check series of first characters are either digits, +, -, or end of string
    */
    while (!isdigit(str[*parsed_chars_num]) &&
           str[*parsed_chars_num] != '-' &&
           str[*parsed_chars_num] != '+' &&
           str[*parsed_chars_num] != END_OF_STRING)
    {
        /*
            Allow first characters to be white spaces 
        */
        if (!isspace(str[*parsed_chars_num]))
        {
            return FAIL_VAL;
        }
        (*parsed_chars_num)++;
    }
    return SUCCES_VAL;
}

int ParseSign(char *str, int *parsed_chars_num, int *num_sign)
{
    /*
        If char is '\0' return fail
    */
    if (str[*parsed_chars_num] == END_OF_STRING)
    {
        return FAIL_VAL;
    }
    /*
        If char is '-'/'+' set num_sign -1/+1 and increment char
    */
    if (str[*parsed_chars_num] == '-')
    {
        *num_sign = -1;
        (*parsed_chars_num)++;
    }
    else if (str[*parsed_chars_num] == '+')
    {
        *num_sign = 1;
        (*parsed_chars_num)++;
    }
    return SUCCES_VAL;
}

int ParseStringNum(char *str, int *parsed_chars_num, int *num_sign, char *parsed_str)
{
    int valid_chars_num = 0;
    /*
        If not a digit return fail
    */
    if (!isdigit(str[*parsed_chars_num]))
    {
        return FAIL_VAL;
    }
    /*
        Parse consecutive digits
    */
    while (isdigit(str[*parsed_chars_num]))
    {
        parsed_str[valid_chars_num] = str[*parsed_chars_num];
        ++valid_chars_num;
        ++(*parsed_chars_num);
    }
    /*
        Set end of string for parsed string
    */
    parsed_str[valid_chars_num + 1] = '\0';
    return SUCCES_VAL;
}

int ConvertStringToNum(char *parsed_str, int *num_sign, int *int_num)
{
    /*
        Convert parsed_str to integer
    */
    int parsed_str_length = strlen(parsed_str);
    for (int index = 0; index < parsed_str_length; ++index)
    {
        int digit = parsed_str[index] - '0';
        *int_num += digit * (pow(10, parsed_str_length - index - 1));
    }
    *int_num *= *num_sign;
    return SUCCES_VAL;
}

int DestroyMyAtoI(int *parsed_chars_num, int *num_sign, int *int_num)
{
    free(parsed_chars_num);
    free(num_sign);
    free(int_num);
    return SUCCES_VAL;
}

int my_atoi(char *str)
{
    if (str == NULL)
    {
        return FAIL_VAL;
    }
    char parsed_str[MY_STRING_CAPACITY];
    int result;
    int output_num;
    /*
        assign and initialize memory
    */
    int *parsed_chars_num = malloc(sizeof(int));
    if (parsed_chars_num == NULL)
    {
        return FAIL_VAL;
    }
    int *num_sign = malloc(sizeof(int));
    if (num_sign == NULL)
    {
        return FAIL_VAL;
    }
    int *int_num = malloc(sizeof(int));
    if (int_num == NULL)
    {
        return FAIL_VAL;
    }
    *parsed_chars_num = 0;
    *num_sign = 1;
    *int_num = 0;
    /*
        Start string to int program
    */
    result = ReverseString(str);
    if (result == FAIL_VAL)
    {
        return result;
    }
    result = CheckFirstCharactersAreValid(str, parsed_chars_num);
    if (result == FAIL_VAL)
    {
        return result;
    }
    result = ParseSign(str, parsed_chars_num, num_sign);
    if (result == FAIL_VAL)
    {
        return result;
    }
    result = ParseStringNum(str, parsed_chars_num, num_sign, parsed_str);
    if (result == FAIL_VAL)
    {
        return result;
    }
    result = ConvertStringToNum(parsed_str, num_sign, int_num);
    if (result == FAIL_VAL)
    {
        return result;
    }
    else
    {
        output_num = *int_num;
    }
    DestroyMyAtoI(parsed_chars_num, num_sign, int_num);
    return output_num;
}

char *my_itoa(int value, char *str, int base)
{
    int temp_value;
    char char_digit;
    int str_size = 0;
    int ascinums[11] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    char minus_sign[3] = "-"; 
    if (str == NULL)
    {
        return FAIL_VAL;
    }
    /*
    Extract individual digits and populate string with corresponding asci value
    */
    temp_value = abs(value);
    while (temp_value != 0)
    {
        ++str_size;
        char_digit = temp_value % 10;
        switch (char_digit)
        {
        case (0):
            str[str_size - 1] = ascinums[0];
            break;
        case (1):
            str[str_size - 1] = ascinums[1];
            break;
        case (2):
            str[str_size - 1] = ascinums[2];
            break;
        case (3):
            str[str_size - 1] = ascinums[3];
            break;
        case (4):
            str[str_size - 1] = ascinums[4];
            break;
        case (5):
            str[str_size - 1] = ascinums[5];
            break;
        case (6):
            str[str_size - 1] = ascinums[6];
            break;
        case (7):
            str[str_size - 1] = ascinums[7];
            break;
        case (8):
            str[str_size - 1] = ascinums[8];
            break;
        case (9):
            str[str_size - 1] = ascinums[9];
            break;
        }
        /*
        If reached the last digit
        */
        if (temp_value / 10 == 0)
        {
            char_digit = temp_value % 10;
            switch (char_digit)
            {
            case (0):
                str[str_size] = ascinums[0];
                break;
            case (1):
                str[str_size] = ascinums[1];
                break;
            case (2):
                str[str_size] = ascinums[2];
                break;
            case (3):
                str[str_size] = ascinums[3];
                break;
            case (4):
                str[str_size] = ascinums[4];
                break;
            case (5):
                str[str_size] = ascinums[5];
                break;
            case (6):
                str[str_size] = ascinums[6];
                break;
            case (7):
                str[str_size] = ascinums[7];
                break;
            case (8):
                str[str_size] = ascinums[8];
                break;
            case (9):
                str[str_size] = ascinums[9];
                break;
            }
        }
        temp_value /= 10;
    }
    /*
    Populate last string cell with '\0'
    */
    str[str_size] = '\0';
    /*
    If negative integer and base is 10 then concatenate '-' to str
    */
    if (value < 0 && base == 10)
    {
        strcat(str, minus_sign);
    }
    ReverseString(str);
    return str;
}