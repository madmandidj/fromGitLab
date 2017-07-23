#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myFiles.h"




int main()
{
    FILE* fp;
    fp = fopen("testfile", "w+");
    /*
    Print the number of times letters are repeated in the string
    */
    // fprintf(fp,"Dani studies in Medical school and Yael studies in college");
    // fprintf(fp,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxzy");
    fprintf(fp,"Hello World ha ha!.");
    // fprintf(fp,"yo ho ho!");
    PrintRepeatedLetters(fp);
    printf("\n");
    PrintRepeatedStrings(fp);
    fclose(fp);


    return 0;
}