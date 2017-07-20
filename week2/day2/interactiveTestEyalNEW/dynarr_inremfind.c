#include <stdlib.h>
#include "dynarr_inremfind.h"

struct dynarr* createDA(int capacity){
	struct dynarr* da1;
	da1 = malloc(sizeof(struct dynarr));
    if (da1 == NULL){
		return NULL;
	}
	else{
		da1->arr = malloc(capacity * sizeof(intPTR));
		if(da1->arr == NULL){
			free(da1); // ADDED THIS
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
	if (da1==NULL || da1->arr==NULL){
		return;
	}
	int i;
	for(i=0;i<da1->noe;++i){
		free(da1->arr[i]);
	}
	free(da1->arr);
	free(da1);
}

int insert(struct dynarr* da1, int* num){ //returns 1 if realloc fails
	if (da1==NULL){
		return 2;
	}
	if (num==NULL){
		return 3;
	}
    intPTR* temp_da1_arr;
    temp_da1_arr = da1->arr;
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

int* find(struct dynarr* da1, int numtofind){
	int i;
	for(i=0;i<da1->noe;++i){
		if(*(da1->arr[i])==numtofind){
			return da1->arr[i];
		}
	}
	return NULL;
}

int remove_num(struct dynarr* da1, int numtoremove){
	int i=0;
	int j;
	int* numtoremove_p;
	numtoremove_p = find(da1, numtoremove);
	if (numtoremove_p==NULL){
		return 0;
	}
	else {
		while(*(da1->arr[i])!= numtoremove){
			++i;
		}
		free(da1->arr[i]);
		for(j=i; j<da1->noe; ++j){
			da1->arr[j] = da1->arr[j+1];
		}
		free(da1->arr[da1->noe]);
		da1->noe = da1->noe-1;
		return 1;
	}
}

int insert_byindex(struct dynarr* da1, int* num, int index){
	int i;
	intPTR* temp_da1_arr;
    temp_da1_arr = da1->arr;
    if (da1->noe < da1->cap){
		for (i=0;i<da1->noe-index+1;++i){
			da1->arr[(da1->noe)-i+1] = da1->arr[(da1->noe)-i];
		}
		da1->arr[index] = num;
        ++(da1->noe);
	return 0;
    }
    else if (da1->noe == da1->cap){
       temp_da1_arr = realloc(da1->arr, da1->cap*2*sizeof(intPTR));
       if(temp_da1_arr==NULL){
           return 1;
       }
       else{
       		for (i=0;i<da1->noe-index+1;++i){
				temp_da1_arr[(da1->noe)-i+1] = temp_da1_arr[(da1->noe)-i];
			}
			temp_da1_arr[index] = num;
            da1->arr = temp_da1_arr;
            da1->cap = 2 * da1->cap;
            ++(da1->noe);
	   return 0;
       }
    }
	return 0;
}
