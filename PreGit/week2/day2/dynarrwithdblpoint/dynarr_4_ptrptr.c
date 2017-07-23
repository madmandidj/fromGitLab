#include <stdlib.h>
#include "dynarr_4_ptrptr.h"

struct dynarr* createDA(int capacity){
	struct dynarr* da1;
	da1 = malloc(sizeof(struct dynarr));
    if (da1 == NULL){
		return NULL;
	}
	else{
		da1->arr = malloc(capacity * sizeof(intPTR));
		if(da1->arr == NULL){
			return NULL;
		}
		else{
			da1->cap=capacity;
			da1->noe=0;
			return da1;
		}
	}
}

void destroy(struct dynarr* da1){
	int i;
	for(i=0;i<da1->noe;++i){
		free(da1->arr[i]);
	}
	free(da1->arr);
	free(da1);
}

int insert(struct dynarr* da1, int* num){ //returns 1 if realloc fails
    intPTR* temp_da1_arr;
    temp_da1_arr = da1->arr;// da1 ->arr
    if (da1->noe < da1->cap){
        da1->arr[da1->noe] = num;
        ++(da1->noe);
	return 0;
    }
    else if (da1->noe == da1->cap){
       temp_da1_arr = realloc(da1->arr, da1->cap*2*sizeof(intPTR));
       if(temp_da1_arr==NULL){
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
