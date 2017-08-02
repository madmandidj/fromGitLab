#ifndef LOTTO_H
#define LOTTO_H
#define POINTER_NOT_INIT 0
#define AMOUNT_OF_RAN_NUMS 6
#define SUCCEEDED 1
#define FAILED 0
#define COLS 10
#define ROWS 5

int GenerateNums(int* lotto_nums, int lotto_num_amount);
void PrintLottoNums(int* lotto_nums, int lotto_num_amount);
int PrepareNums(int* lotto_nums, int* lotto_nums_digits);


#endif