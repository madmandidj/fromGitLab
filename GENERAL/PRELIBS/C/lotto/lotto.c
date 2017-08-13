#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lotto.h"

int GenerateLottoNums(int *lotto_ints)
{
    if (lotto_ints == NULL)
    {
        return ERROR_VAL;
    }
    srand(time(NULL));
    int generated_ran_nums = 0;
    int random_num;
    int is_unique_num;
    int index_lotto_ints;
    int index;
    while (generated_ran_nums < AMOUNT_OF_LOTTO_NUMS)
    {
        random_num = rand() % 49 + 1;
        is_unique_num = 1;
        for (index_lotto_ints = 0; index_lotto_ints < generated_ran_nums; ++index_lotto_ints)
        {
            if (lotto_ints[index_lotto_ints] == random_num)
            {
                is_unique_num = 0;
            }
        }
        if (is_unique_num == 1)
        {
            lotto_ints[generated_ran_nums] = random_num;
            ++generated_ran_nums;
        }
    }
    return SUCCESS_VAL;
}

int PrintLottoNumsTable(int *lotto_ints)
{
    if (lotto_ints == NULL)
    {
        return ERROR_VAL;
    }
    char lottonums_char_table[5][10];
    int lottonum_tens;
    int lottonum_ones;
    int cur_row;
    int cur_col;
    int index;
    /*
        Init char table with '-'
    */
    for (cur_row = 0; cur_row < LOTTO_TABLE_ROWS; ++cur_row)
    {
        for (cur_col = 0; cur_col < LOTTO_TABLE_COLS; ++cur_col)
        {
            lottonums_char_table[cur_row][cur_col] = '-';
        }
    }
    /*
        Set last cell to whitespace
    */
    lottonums_char_table[LOTTO_TABLE_ROWS-1][LOTTO_TABLE_COLS-1] = ' ';
    for (index = 0; index < AMOUNT_OF_LOTTO_NUMS; ++index)
    {
        /*
            Populate table with a multiple of 10
        */
        if (lotto_ints[index] % 10 == 0)
        {
            lottonums_char_table[(lotto_ints[index] / 10) - 1][LOTTO_TABLE_COLS - 1] = '+';
        }
        /*
            Populate table with all numbers from 1 - 49, which are not a multiple of 10
        */
        else
        {
            lottonums_char_table[lotto_ints[index] / 10][(lotto_ints[index] % 10) - 1] = '+';
        }
    }
    printf("\nThe numbers are:\n");
    for (index = 0; index < AMOUNT_OF_LOTTO_NUMS; ++index)
    {
        printf("%d\n", lotto_ints[index]);
    }
    /*
        Print lotto table
    */
    for (cur_row = -1; cur_row < LOTTO_TABLE_ROWS; ++cur_row)
    {
        if (cur_row == -1)
        {
            printf("  1 2 3 4 5 6 7 8 9 10\n");
        }
        else
        {
            printf("%d", cur_row);
            for (cur_col = 0; cur_col < LOTTO_TABLE_COLS; ++cur_col)
            {
                printf(" %c", lottonums_char_table[cur_row][cur_col]);
            }
            printf("\n");
        }
    }
    printf("\n");
    return SUCCESS_VAL;
}