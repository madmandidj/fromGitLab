#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Files.h"




int main()
{
    FILE* fp;
    /*
    Chars Frequency
    */
    printf("Testing repeated char counter: \n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"Hello World ha ha!.");
    PrintCharFreq(fp);
    fclose(fp);
    printf("\n");
    fp = fopen("testfile", "w+");
    PrintCharFreq(fp);
    fclose(fp);
    printf("\n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxzy");
    PrintCharFreq(fp);
    fclose(fp);
    printf("\n");
    /*
    Strings Frequency
    */
    printf("Testing repeated string counter: \n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"Dani studies in Medical school and Yael studies in college yooo    ");
    PrintStringFreq(fp);
    fclose(fp);
    printf("\n");
    fp = fopen("venusadonis.txt", "r");
    PrintStringFreq(fp);
    fclose(fp);
    printf("\n");
    /*
    Print Last N Lines
    */

    return 0;
}
