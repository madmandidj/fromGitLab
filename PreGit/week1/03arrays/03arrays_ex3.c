#include <stdio.h>


int mostrepeated(int* array, int size){
	//Counter for current array num
	int counter;
	//Counter for numbers to compare
	int counter2;	
	int numofrepeats=0;
	int mostrepeatednum=array[0];
	for(counter=0;counter<size;++counter){
		int curnumcheck=array[counter];
		int temprepeatnum=0;
		//Check how many times curnumcheck appearrs in array
		for(counter2=0;counter2<size;++counter2){	
			if(array[counter2]==curnumcheck){
				//Increment amount repeated
				++temprepeatnum;
			}
		}
		//Check if temprepeatnum is the most repeated number
		if(temprepeatnum>numofrepeats){
			mostrepeatednum=array[counter];
			numofrepeats=temprepeatnum;
		}
	}	
	return mostrepeatednum;
}




int main(){
	int size;
	int counter;
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
	printf("%d\n", mostrepeated(array,size));
	return 0;
}
