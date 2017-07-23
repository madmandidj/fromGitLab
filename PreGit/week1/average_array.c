#include <stdio.h>

float calcaverage(int*, int);

int main(){
	int arraysize =4;
	int array[arraysize];
	int counter;
	double average;
	for(counter=0;counter<arraysize;++counter){
		printf("enter number for array\n");
		scanf("%d", &array[counter]);
	}

	average = calcaverage(array,arraysize);
	printf("%f\n", average);
	return 0;
}

float calcaverage(int* array, int arraysize){
	double average;
	int counter;
	float sum=0;
	for(counter=0;counter<arraysize;++counter){
		sum += *(array+counter);
	}
	average=sum/arraysize;
	return average;
}
