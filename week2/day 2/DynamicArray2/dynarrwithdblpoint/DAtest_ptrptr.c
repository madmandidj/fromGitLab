#include <stdio.h>
#include <stdlib.h>
#include "dynarr_4_ptrptr.h"

int main(){
    struct dynarr* da1;
	int cap=2;
    int noe=0;
    int exit_num = -99; // enter this value to stop program 
    int nomem_flag = 0;// value to detect no memory available
    int i;
	int* num;

	da1 = createDA(cap);
	if (da1 == NULL){
		printf("not enough memory");
		return 0;
	}
	
    do{
		num = malloc(sizeof(int*));
		printf("Enter number for array in index %d \n",da1->noe);
        scanf("%d",num);
		if (*num==-99){
	    	break;
		}
		nomem_flag = insert(da1, num);
		if(nomem_flag == 1){
	    	return 0;
		}
    } while(*num != exit_num);
    printf("\ncap = %d\n",da1->cap);
    printf("noe = %d\n\n",da1->noe);
    //for(i=0; i<da1->cap;++i){
	for(i=0; i<da1->noe;++i){
        printf("%d\n",*(da1->arr[i]));
    }
    printf("\n");
	destroy(da1); 
    return 0;
}

