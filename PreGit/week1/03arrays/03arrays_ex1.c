#include <stdio.h>

void swap(unsigned int*a,unsigned int*b){
	unsigned int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int findnumofzeros(unsigned int* array,int size){
	int counter=0;
	int result=0;
	//Iterate for size of array and count number of zeros
	for(counter=0;counter<size;++counter){
		if(array[counter]==0){
			++result;
		}
	}
	return result;	
}

int calc_consec_zeros(unsigned int*array,int size){
	int counter=0;
	int consec0num=0;
	//Iterate while current array index is zero, increment consec 0 num
	while(array[counter]==0){
		++consec0num;
		++counter;
	}
	return consec0num;
}

void sort_0Left_1Right(unsigned int*array, int size, int numofzeros){
	int counter;
	int conseczeros=0;
	unsigned int* a;
	unsigned int* b;
	//Calculate number of consecutive zeros
	conseczeros=calc_consec_zeros(array,size);
	//Iterate while consecutive number of zeros is lower than total zeros
	while(conseczeros<numofzeros){
		for(counter=0;counter<size-1;++counter){
			//If array index is larger than array index+1, swap
			if(array[counter]>array[counter+1]){
				a=&array[counter];
				b=&array[counter+1];
				swap(a,b);
			}
		}
		//Recalculate number of consecutive zeros
		conseczeros=calc_consec_zeros(array,size);
	}
	return;
}

int main(){
	int size;
	int counter;
	int numofzeros;
	//Prompt user for array size
	printf("Enter array size\n");
	scanf("%d", &size);
	unsigned int array[size];
	//Prompt user to enter individual numbers for array
	for(counter=0;counter<size;++counter){
		printf("enter number for array\n");
		scanf("%d", &array[counter]);
	}
	printf("\n");
	//Calculate total number of zeros in array
	numofzeros=findnumofzeros(array,size);
	//Sort array
	sort_0Left_1Right(array,size,numofzeros);
	for(counter=0;counter<size;++counter){
		printf("%d ",array[counter]);
	}
	return 0;
}
