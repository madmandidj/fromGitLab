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
    Strings Frequency - 1st string is fine, 2nd and 3rd strings struggle, 3rd string some results produce garbage
    */
    printf("Testing repeated string counter: \n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"Dani studies in Medical school and Yael studies in college and in eyal alon tenth");
    PrintStringFreq(fp);
    fclose(fp);
    printf("\n");
    fp = fopen("amchap2.txt", "r");
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
    /*
    printf("Testing print last N lines: \n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"Test1\nTest2");
    PrintLastNLines(fp, 3);
    fclose(fp);
    */

    return 0;
}
