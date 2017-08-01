#include <stdio.h>
int check_sorted(int* array, int size){
	//Return 0 if not sorted, 1 if sorted
	int counter;
	int result=0;
	for(counter=0;counter<size-1;++counter){
		if(array[counter]<=array[counter+1]){
			result=1;
		}
		else if(array[counter]>array[counter+1]){
			result=0; 
			return result;
		}
	}
	return result;	
}

void swap(int* array, int index){
	int temp;
	temp=array[index];
	array[index]=array[index+1];
	array[index+1]=temp;
	return;
}

void sort_array(int* array, int size){
	int sorted=0;
	int counter=0;
	while (sorted==0){
		for(counter=0;counter<(size-1);++counter){
			if(array[counter]>array[counter+1]){
				swap(array,counter);
			}
		}
		sorted=check_sorted(array,size);
	}
	return;
}

int main(){
	int arraysize;
	int counter=0;
	int issorted;
	printf("Enter array size\n");
	scanf("%d", &arraysize);
	int array[arraysize];
	for(counter=0;counter<arraysize;++counter){
		printf("enter number for array\n");
		scanf("%d", &array[counter]);
	}

	for(counter=0;counter<arraysize;++counter){
		printf("%d, ",array[counter]);
	}
	printf("\n");
	sort_array(array,arraysize);
	for(counter=0;counter<arraysize;++counter){
		printf("%d, ",array[counter]);
	}
	return 0;
}

