#include <stdio.h>

void swap(int*a,int*b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int calcnumofevens(int*array, int size){
	int counter=0;
	int result=0;
	//Iterate for size of array and count number of evens
	for(counter=0;counter<size;++counter){
		if(array[counter]%2==0){
			++result;
		}
	}
	return result;
}

int calc_consec_evens(int*array,int size){
	int counter=0;
	int consecevennum=0;
	//Iterate while current array index is even, increment consecevennum
	while(array[counter]%2==0){
		++consecevennum;
		++counter;
	}
	return consecevennum;
}

void sort_Eleft_Oright(int*array, int size, int numofevens){
	int counter;
	int consecevens=0;
	int* a;
	int* b;
	//Calculate number of consecutive evens
	consecevens=calc_consec_evens(array,size);
	//Iterate while consecutive number of evens is lower than total evens
	while(consecevens<numofevens){
		for(counter=0;counter<size-1;++counter){
			//If array index is odd and index+1 is even, swap
			if(array[counter]%2!=0 && array[counter+1]%2==0){
				a=&array[counter];
				b=&array[counter+1];
				swap(a,b);
			}
		}
		//Recalculate number of consecutive evens
		consecevens=calc_consec_evens(array,size);
	}
	return;
}

int main(){
	int size;
	int counter;
	int numofevens;
	//Prompt user for array size
	printf("Enter array size\n");
	scanf("%d", &size);
	int array[size];
	//Prompt user to enter individual numbers for array
	for(counter=0;counter<size;++counter){
		printf("enter number for array\n");
		scanf("%d", &array[counter]);
	}
	printf("\n");
	
	//Calculate number of evens
	numofevens=calcnumofevens(array,size);
	printf("Number of evens = %d\n",numofevens);
	//Sort evens to left and odds to right
	sort_Eleft_Oright(array, size, numofevens);
	for(counter=0;counter<size;++counter){
		printf("%d ",array[counter]);
	}
	return 0;
}
