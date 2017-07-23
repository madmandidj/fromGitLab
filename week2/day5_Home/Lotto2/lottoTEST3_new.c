#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateNums(){
    printf("\nStarting to draw numbers. Please wait...\n");
    while(noe < 6){
        randnum = rand() % 48 + 1;
        uniqueNumFlag=1;
        if (noe == 0){
            lottonums[0]=randnum;
            ++noe;
            printf("1 numbers drawn\n\n");
        } 
        else{
            for(index=0; index<noe; ++index){
                if(lottonums[index] == randnum){
                    uniqueNumFlag = 0;
                }
            }
            if(uniqueNumFlag == 1){
                lottonums[noe] = randnum;
                ++noe;
                printf("%d numbers drawn\n\n", noe);
            }
        } 
    }
}

int main (){
    int noe=0;
    int randnum;
    int uniqueNumFlag;
    int lottonums[6];
    int index;
    srand (time(NULL));
    // printf("\nStarting to draw numbers. Please wait...\n");
    // while(noe < 6){
    //     randnum = rand() % 48 + 1;
    //     uniqueNumFlag=1;
    //     if (noe == 0){
    //         lottonums[0]=randnum;
    //         ++noe;
    //         printf("1 numbers drawn\n\n");
    //     } 
    //     else{
    //         for(index=0; index<noe; ++index){
    //             if(lottonums[index] == randnum){
    //                 uniqueNumFlag = 0;
    //             }
    //         }
    //         if(uniqueNumFlag == 1){
    //             lottonums[noe] = randnum;
    //             ++noe;
    //             printf("%d numbers drawn\n\n", noe);
    //         }
    //     } 
    // }
    return 0;
}