#include <stdio.h>
#include <stdlib.h>
#include "lotto.h"

int main (){
    int lotto_nums[AMOUNT_OF_RAN_NUMS];
    int lotto_nums_digits[AMOUNT_OF_RAN_NUMS][2];
    int lotto_num_amount=AMOUNT_OF_RAN_NUMS;
    int index;
    int generated;
    
    generated = GenerateNums(lotto_nums, lotto_num_amount);
    PrintLottoNums(lotto_nums, lotto_num_amount);
    for(int i=0; i < AMOUNT_OF_RAN_NUMS; i++){
        for(int j=0; j < 2; )
    }
    return 0;
}