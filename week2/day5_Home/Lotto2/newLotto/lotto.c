#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lotto.h"


int GenerateNums(int* lotto_nums, int lotto_num_amount){
    int num_of_elements=0;
    int is_unique_num=0;
    int index;
    int rand_num;
    srand(time(NULL));
    if(lotto_nums == NULL){
        return 0;
    }
    while(num_of_elements < lotto_num_amount){
        is_unique_num=1;
        rand_num = rand() % 49 + 1; 
        if (num_of_elements == 0){
            lotto_nums[0]=rand_num;
            ++num_of_elements;
        } 
        else{
            for(index = 0; index < num_of_elements; ++index){
                if(lotto_nums[index] == rand_num){
                    is_unique_num = 0;
                }
            }
            if(is_unique_num == 1){
                lotto_nums[num_of_elements] = rand_num;
                ++num_of_elements;
            }
        } 
    }
    return 1;
}

void PrintLottoNums(int* lotto_nums, int lotto_num_amount){
    int index;
    for(index = 0; index < lotto_num_amount; ++index){
        printf("%d\n",lotto_nums[index]);
    }
}

int PrepareNums(int* lotto_nums, int* lotto_nums_digits){
    if (lotto_nums==NULL || lotto_nums_digits==NULL){
        return FAILED;
    }
    int index;
    for(index=0; index<AMOUNT_OF_RAN_NUMS; ++index){
        if(lotto_nums[index]/10 < 1){
            lotto_nums_digits[index][0] = 0;
            lotto_nums_digits[index][1] = lotto_nums[index];
        }
        else if(lotto_nums[index]%10==0){
            lotto_nums_digits[index][0] = lotto_nums[index]/10;
            lotto_nums_digits[index][1] = lotto_nums[index];
        }
        else{
            lotto_nums_digits[index][0] = lotto_nums[index]/10;
            lotto_nums_digits[index][1] = lotto_nums[index]%10;
        }
    }
    return SUCCEEDED;
}