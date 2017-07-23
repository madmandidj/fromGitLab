#include <stdio.h>
#include <stdlib.h>
#include "dynarr_inremfind.h"

int main(){
    struct dynarr* da1;
	int cap=2;
    int noe=0;
    int nomem_flag = 0;// value to detect no memory available
    int i;
	int* num;
	int numtofind;
	int index;
	int remove_flag;
	int* foundnum_p;
	int cont = 1;			// trigger to stop loop	
	unsigned int option;

	da1 = createDA(cap);
	if (da1 == NULL){
		printf("not enough memory");
		return 0;
	}
	
	while (cont) {
		printf("\nChoose option: \n");
		printf("1: Insert  \n");
		printf("2: Insert by index \n");
		printf("3: Remove    \n");
		printf("4: Find  \n");
		printf("5: Print  \n");
		printf("Any another number - stop \n\n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				/*	
				Insert
				*/
				num = malloc(sizeof(int*));
				if(num==NULL){
					printf("No available memory\n");
	    			return 0;
				}
				printf("Please enter number to insert: ");
        		scanf("%d",num);
				nomem_flag = insert(da1, num);
				if(nomem_flag == 1){
					printf("No available memory\n");
	    			return 0;
				}
				//free(num);
				break;
			case 2:
				/*	
				Insert by index
				*/
				num = malloc(sizeof(int*));
				if(num==NULL){
					printf("No available memory\n");
	    			return 0;
				}
				printf("Please enter number to insert (by index): ");
				scanf("%d", num);
				printf("\nPlease enter index: ");
				scanf("%d", &index);
				while (index<0 || index>da1->cap-1){ 
					printf("\nPlease enter valid index: "); //not working on zero size array
					scanf("%d", &index);
				}
				nomem_flag = insert_byindex(da1, num, index);
				if(nomem_flag == 1){
					printf("No available memory\n");
	    			return 0;
				}
// 				free(num);
				break;
			case 3:
				/*	
				Remove
				*/
				printf("Please enter number to remove: ");
				scanf("%d", &numtofind);
				remove_flag = remove_num(da1, numtofind);
				if (remove_flag == 1){
					printf("Remove succeeded\n");
				}
				else{
					printf("Remove failed\n");
				}
				break;
			case 4:
				/*	
				Find
				*/
				printf("Please enter number to find\n");
				scanf("%d", &numtofind);
				foundnum_p = find(da1,numtofind);
				if (foundnum_p == NULL){
					printf("Number not found in array\n");
				}
				else{
					printf("Address of number is %p\n",foundnum_p);
				}
				break;
			case 5:
				/*  
				Print
				*/
				printf("\n");
				printf("Array contents:\n");
				for(i=0; i<da1->noe;++i){
        			printf("%d\n",*(da1->arr[i]));
    			}
				break;
			default:
				cont=0;
				break;
		}
	}
	destroy(da1); 
    return 0;
}

