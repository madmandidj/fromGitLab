#include <stdio.h>
#include <stdlib.h>

struct dynarr{
    int* arr;
    int cap;
    int noe;
};

int insert(struct dynarr* da1, int num){ //returns -99 if realloc fails
    int* temp_da1_arr;
    temp_da1_arr = da1->arr;// da1 ->arr
    if (da1->noe < da1->cap){
        da1->arr[da1->noe] = num;
        ++(da1->noe);
	return 0;
    }
    else if (da1->noe == da1->cap){
       temp_da1_arr = realloc(da1->arr, da1->cap*2*sizeof(int));
      // temp_da1_arr = realloc(da1->arr, da1->cap*10000000000*sizeof(int)); //Use this to fail realloc
       if(temp_da1_arr==NULL){
           printf("Not enough memory\n");
           return 1;
       }
       else{
           temp_da1_arr[da1->noe] = num;
           da1->arr = temp_da1_arr;
           da1->cap = 2 * da1->cap;
           ++(da1->noe);
	   return 0;
       }
    }
}

int main(){
    struct dynarr da1;
    da1.cap=2;
    da1.noe=0;
    int num = 0;        // user generated value for array
    int exit_num = -99; // enter this value to stop program 
    int nomem_flag = 0;// value to detect no memory available
    int i;

    da1.arr = malloc(da1.cap*sizeof(int));
    if (da1.arr == NULL){
        printf("Not enough memory\n");
        return 0;
    }

    do{
	printf("Enter number for array in index %d \n",da1.noe);
        scanf("%d",&num);
	if (num==-99){
	    break;
	}
	nomem_flag = insert(&da1, num);
	if(nomem_flag == 1){
	    return 0;
	}
    } while(num != exit_num);

    printf("\ncap = %d\n",da1.cap);
    printf("noe = %d\n\n",da1.noe);
    for(i=0; i<da1.cap;++i){
        printf("%d\n",da1.arr[i]);
    }
    printf("\n");
    free(da1.arr); 
    return 0;
}

