/*
Binary_search.c
----
Performs binary search on user generated, pre-sorted array. 
----
Eyal Alon
24/06/17
*/
#include<stdio.h>
/*
Global variables
*/
int size; 		// size of the sorted array (user generated)
int search_num;	// value to search for in array (user generated)

void Prompt_size(){
	/*
	Prompt user to enter size of sorted array
	*/
    printf("\n");
    printf("*********************************\n");
    printf("Welcome to Eyal's magical-binary-searcher-9001\n");
    printf("*********************************\n");
	printf("\nPlease enter the size of sorted array\n"); 
	scanf("%d",&size);	
	printf("\n");
	return;
}

void Prompt_arrayvars(int* array){
	/*
	Prompt user to enter array variables
	*/
	int i; //counter
	for(i=0;i<size;++i){
		printf("Enter value for array index '%d' \n",i); 
		scanf("%d",&array[i]);
	}	
	printf("\n");
	return;
}

void Prompt_searchnum(){
	/*
	Prompt user to enter number for search
	*/
	printf("Enter search number\n"); 
	scanf("%d",&search_num);
	printf("\n");
	return;
}

int Binary_search(int* array){
	int i; //counter
	int cur_index = 0; 
	int new_size = size; // initialize with size of array. new_size will be divided by 2, each iteration.
	int num_found = 0; // array index of search_num if found in array. If -1, num not found in array.
	while (new_size >2){
		// check search num is equal to value in current index
		if (array[cur_index] ==	search_num){
			return cur_index;
		}
		// calculate new block size (different for even/odd new_size)
		if(new_size%2==0){
			new_size=new_size/2;
		}
		else{
			new_size=(new_size/2)+1;
		}
		// check value in current index is smaller than search num
		if (array[cur_index] < search_num){ 
				cur_index+=new_size;
				continue;
		}
		// else check value in current index is larger than search num
		else if (array[cur_index] > search_num){
				cur_index-=new_size;
				continue;
		}
	}
	// After reaching size of 2 or less perform the following
	if (array[cur_index] ==	search_num){
			return cur_index;
	}
		if(array[cur_index+1] == search_num){
			return cur_index+1;
		}
		if(array[cur_index-1] == search_num){
			return cur_index-1;
		}
	return -1; //search_num not found in array
}

int main(){
	int i; //counter
	Prompt_size();	
	int array[size];
	Prompt_arrayvars(array);
	Prompt_searchnum();
    // If Binary search function returns -1 then search number not found in array
    if (Binary_search(array)==-1){
        printf("*********************************\n");
        printf("%d not found in array\n",search_num);
        printf("*********************************\n");
        printf("\n");
    }
    // Else return the index of the number found
    else{
        printf("*********************************\n");
        printf("Index of the value %d is: %d \n",search_num, Binary_search(array));
        printf("*********************************\n");
        printf("\n");
    }
	return 0;
}