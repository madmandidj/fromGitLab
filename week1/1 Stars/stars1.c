/*
	Eyal Alon
	21/06/17
*/

#include <stdio.h>

void func1(int);
void func2(int);
void func3(int);

int main(){
	int numoflines=0;
	printf("Please enter the number of lines (integer)\n");
	scanf("%d",&numoflines);  
  	printf("Number of lines entered is: %d \n", numoflines);
	func1(numoflines);
	printf("\n");
	func2(numoflines);
	printf("\n");
	func3(numoflines);
	return 0;
}

void func1(int nolines){
	//Initialise the row counter
	int curline=0;
	//Iterate for number of rows equal to nolines
	while(curline<nolines){
		int j;		
		//Iterate for current row number
		for(j=0;j<curline+1;++j){
			printf("*");		
		}
		++curline;
		printf("\n");
	}
	return;
}

void func2(int nolines){
	//Call func1() to complete first half of triangle
	func1(nolines);
	//Initialise the row counter
	int curline=nolines;
	//Iterate for number of rows equal to nolines
	while(curline>0){
		int j;		
		//Iterate for current row number
		for(j=0;j<curline-1;++j){
			printf("*");		
		}
		--curline;
		printf("\n");
	}	
	return;
}

void func3(int nolines){
	int blanksum=nolines-1; //number of blanks per row
	int starnum = 1;		//number of stars per row
	int curline;			//current row num
	for(curline=0;curline<nolines;++curline){
		int curpos;
		for(curpos=0;curpos<blanksum;curpos++){
			printf(" ");
		}
		for(curpos=0;curpos<starnum;curpos++){
			printf("*");
		}
		for(curpos=0;curpos<blanksum;curpos++){
			printf(" ");
		}
		starnum+=2;
		blanksum-=1;
		printf("\n");
	}
	return;
}

