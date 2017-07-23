#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Files.h"




int main()
{
    FILE* fp;
    /*
    Print the number of times letters are repeated in the string
    */
    printf("Testing repeated char counter: \n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"Hello World ha ha!.");
    PrintRepeatedLetters(fp);
    fclose(fp);
    printf("\n");
    fp = fopen("testfile", "w+");
    PrintRepeatedLetters(fp);
    fclose(fp);
    printf("\n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxzy");
    PrintRepeatedLetters(fp);
    fclose(fp);
    printf("\n");
    printf("Testing repeated string counter: \n");
    fp = fopen("testfile", "w+");
    fprintf(fp,"Dani studies in Medical school and Yael studies in college"); 
    PrintRepeatedStrings(fp);
    fclose(fp);
    printf("\n");

    /* PrintRepeatedStrings(fp); */


    return 0;
}
