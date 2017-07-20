#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  int randnum;
  int lottonums[6];
  int noe=0;
  int index;
  int uniquenumflag=0;

    while(noe < 6){
        /* initialize random seed: */
        srand (time(NULL));
        /* generate secret number between 1 and 10: */
        randnum = rand() % 48 + 1;
        uniquenumflag=1;
        if (noe == 0){
            lottonums[0]=randnum;
            ++noe;
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
            }
        } 
    }
    for(int i=0; i<noe; ++i){
        printf("%d\n",lottonums[i]);
    }

  return 0;
}
