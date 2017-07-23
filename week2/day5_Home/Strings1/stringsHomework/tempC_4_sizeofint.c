#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main()
{
    int num;
    int i;
    int temp_num;
    char str[100];
    int ascinums[11] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    char c;
    int size = 0;
    char tempchar;
    printf("Enter an integer\n");
    scanf("%d", &num);
    temp_num = num;
    while (temp_num != 0)
    {
        ++size;
        tempchar = temp_num % 10;
        switch (tempchar)
        {
        case (0):
            str[size-1] = ascinums[0];
            break;

        case (1):
            str[size-1] = ascinums[1];
            break;

        case (2):
            str[size-1] = ascinums[2];
            break;

        case (3):
            str[size-1] = ascinums[3];
            break;

        case (4):
            str[size-1] = ascinums[4];
            break;

        case (5):
            str[size-1] = ascinums[5];
            break;

        case (6):
            str[size-1] = ascinums[6];
            break;

        case (7):
            str[size-1] = ascinums[7];
            break;

        case (8):
            str[size-1] = ascinums[8];
            break;

        case (9):
            str[size-1] = ascinums[9];
            break;
        }
        if (temp_num / 10 == 0)
        {
            // ++size;
            tempchar = temp_num % 10;
            switch (tempchar)
            {
            case (0):
                str[size] = ascinums[0];
                break;

            case (1):
                str[size] = ascinums[1];
                break;

            case (2):
                str[size] = ascinums[2];
                break;

            case (3):
                str[size] = ascinums[3];
                break;

            case (4):
                str[size] = ascinums[4];
                break;

            case (5):
                str[size] = ascinums[5];
                break;

            case (6):
                str[size] = ascinums[6];
                break;

            case (7):
                str[size] = ascinums[7];
                break;

            case (8):
                str[size] = ascinums[8];
                break;

            case (9):
                str[size] = ascinums[9];
                break;
            }
            // temp_num /= 10;
        }
        temp_num /= 10;
        printf("str[size] is:  %c\n", str[size-1]);
    }
    // ++size;
    str[size] = '\0';
    printf("str[size] is:  %d\n", str[size]);
    printf("Size is:  %d\n", size);
    printf("str is: %s\n", str);
    return 0;
}