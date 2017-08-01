#ifndef LOTTO_H
#define LOTTO_H
#define AMOUNT_OF_LOTTO_NUMS 6
#define FAIL_VAL 0
#define SUCCESS_VAL 1
#define ERROR_VAL -1
#define LOTTO_TABLE_ROWS 5
#define LOTTO_TABLE_COLS 10

/*
Generates 6 psuedo-random numbers and populates the given integer array
Input:      integer array (size >= 6) 
Output:     '1' if succeeded, '-1' if error 
Error:      lotto_ints = NULL will return '-1'. lotto_ints is not a valid integer array 
*/
int GenerateLottoNums(int* lotto_ints);
/*
Calculates and populates the lotto num char table. '+' number is present, '-' number is not present.
Input:      integer array (size >= 6) 
Output:     '1' if succeeded, '-1' if error 
Error:      lotto_ints = NULL will return '-1'. lotto_ints is not a valid integer array 
*/
int PrintLottoNumsTable(int* lotto_ints);

#endif