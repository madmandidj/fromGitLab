#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  const int size=6;
  const int rowlength=22;
  int randnum;
  int lottonums[size];
  int noe=0;
  int index;
  int uniquenumflag=0;
  char r1[22]="  1 2 3 4 5 6 7 8 9 10";
  char rowsC0[5]= "01234";
  const int col_num_pos[]={2,4,6,8,10,12,14,16,18,20,22};  // 0 1 2 3 4 5 6 7 8 9 10
  const int row_num_pos[]={0,1,2,3,4}; // 0 1 2 3 4
  int numplaces[size][2]; // 6 numbers, row and column place

    printf("\nStarting to draw numbers. Please wait...\n");
    while(noe < 6){
        srand (time(NULL));
        randnum = rand() % 48 + 1;
        uniquenumflag=1;
        if (noe == 0){
            lottonums[0]=randnum;
            ++noe;
            printf("1 numbers drawn\n\n");
        } 
        else{
            for(index=0; index<noe; ++index){
                if(lottonums[index] == randnum){
                    uniquenumflag = 0;
                }
            }
            if(uniquenumflag == 1){
                lottonums[noe] = randnum;
                ++noe;
                printf("%d numbers drawn\n\n", noe);
            }
        } 
    }
    printf("The numbers are:\n");
    for(int i=0; i<noe; ++i){
        printf("%d\n\n",lottonums[i]);
    }
    for(index=0; index<size; ++index){
        if(lottonums[index]/10 < 1){
            numplaces[index][0] = 0;
            numplaces[index][1] = lottonums[index];
        }
        else{
            numplaces[index][0] = lottonums[index]/10;
            numplaces[index][1] = lottonums[index]%10;
        }
    }
    printf("\n\n");
    for(index=0; index<size; ++index){
        printf("%d, %d\n", numplaces[index][0], numplaces[index][1]);        
    }
    
    for(index=0;index<22;++index){
      printf("%c",r1[index]);
    }
    printf("\n");
    // for(int rows=0; rows<5;rows++){
    //     for(index=0;index<22;++index){
    //         if(index==0){
    //             printf("%c",rowsC0[rows]);
    //         }
    //         else if(index%2!=0){
    //             printf(" ");
    //         }
    //         // else {
    //         else if(index%2==0){
                
    //             for (int i=0;i<size;++i){
    //                 // if(numplaces[i][0]==rows && numplaces[i][1]==col_num_pos[index]){
    //                 // if(numplaces[i][0]==rows && numplaces[i][1]==col_num_pos[index]){
    //                 if(numplaces[i][0]==rows && numplaces[i][1]==col_num_pos[index]){
    //                     printf("+");
    //                 }
    //                 // else if(index%2==0){
    //                 //     printf("-");
    //                 // }
                    
    //             }
    //         }
    //     }
    //     printf("\n");
    // }

    for(int rows=0; rows<5;rows++){
        for(int cols=1; cols<11; ++cols){
            if(lottonums[rows][0]==rows && lottonums[rows][1]==cols){
                printf(" +");
            }
            else{
                printf(" -");
            }
        }
    }

  return 0;
}
