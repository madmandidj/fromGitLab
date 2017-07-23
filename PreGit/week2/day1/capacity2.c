#include <stdio.h>
#include <stdlib.h>

int* insert(int* arr, int num, int* ind, int* cap){
    int* temp_arr;
    temp_arr = arr;
    // if(*ind<*cap-1){
    if(*ind < *cap){
        arr[*ind] = num;
        ++(*ind);
        return arr;
    }
    if(*ind == *cap){
        temp_arr = realloc(arr, *cap * 2 * sizeof(int));
        if(temp_arr==NULL){
            printf("Not enough memory\n");
            return arr;
        }
        else{
            temp_arr[*ind] = num;
            *cap= 2 * (*cap);
            ++(*ind);
            return temp_arr;
        }
    }
}

int main(){
    int cap = 3;        // capacity
    int NUE=0;            // number of elements
    int* arr;           // array
    // int* temp_arr;      // temporary array pointer
    int num = 0;        // user generated value for array
    int exit_num = -99; // number to enter when user wants to stop entering array variables
    int i;
    arr = malloc(cap*sizeof(int));
    // temp_arr=&arr;
    if (arr == NULL){
        printf("Not enough memory\n");
        return 0;
    }
    printf("Enter number for array in index %d \n",NUE);
    scanf("%d",&num);
    while(num != exit_num){
        arr = insert(arr, num, &NUE, &cap);
        printf("Enter number for array in index %d \n",NUE);
        scanf("%d",&num);
    }
    for(i=0; i<cap;++i){
        printf("%d\n",arr[i]);
    }
    
    return 0;
}


