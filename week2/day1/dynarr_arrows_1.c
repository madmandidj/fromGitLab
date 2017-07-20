#include <stdio.h>
#include <stdlib.h>

struct dynarr{
    int* arr;
    int cap;
    int noe;
};

void insert(struct dynarr* da1, int num){
    int* temp_da1_arr;
    temp_da1_arr = da1->arr;// da1 ->arr
    if (da1->noe < da1->cap){
        da1->arr[da1->noe] = num;
        ++(da1->noe);
    }
    else if (da1->noe == da1->cap){
       temp_da1_arr = realloc(da1->arr, da1->cap*2*sizeof(int));
       if(temp_da1_arr==NULL){
           printf("Not enough memory\n");
           return;
       }
       else{
           temp_da1_arr[da1->noe] = num;
           da1->arr = temp_da1_arr;
           da1->cap = 2 * da1->cap;
           ++(da1->noe);
       }
    }

}

int main(){
    struct dynarr da1;
    da1.cap=3;
    da1.noe=0;
    int num = 0;        // user generated value for array
    int exit_num = -99; // number to enter when user wants to stop entering array variables
    int i;
    da1.arr = malloc(da1.cap*sizeof(int));
    if (da1.arr == NULL){
        printf("Not enough memory\n");
        return 0;
    }
    printf("Enter number for array in index %d \n",da1.noe);
    scanf("%d",&num);
    while(num != exit_num){
        insert(&da1, num);
        printf("Enter number for array in index %d \n",da1.noe);
        scanf("%d",&num);
    }
    for(i=0; i<da1.cap;++i){
        printf("%d\n",da1.arr[i]);
    }
    free(da1.arr); 
    return 0;
}

