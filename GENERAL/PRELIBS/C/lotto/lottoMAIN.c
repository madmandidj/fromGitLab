#include <stdio.h>
#include "lotto.h"

// srand(time(NULL));

int main()
{
    int lotto_ints[AMOUNT_OF_LOTTO_NUMS];
    int index;
    int result;
    result = GenerateLottoNums(lotto_ints);
    result = PrintLottoNumsTable(lotto_ints);
    if(result == -1){
        printf("Please provide a valid integer pointer (size > = 6)");
    }
    return 0;
}