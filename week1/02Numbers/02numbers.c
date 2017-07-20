/*
	Eyal Alon
	21/06/17

*/

#include <stdio.h>
#include <math.h>

int Checkifprime();
int Checkifpal();
int Checkifascend();
int reversenumber();


int main(){
	printf("%d\n",Checkifprime());
	printf("%d\n",Checkifpal());
	printf("%d\n",Checkifascend());
	printf("%d\n",reversenumber());
	return 0;
}


int Checkifprime(){
/*
	Check if number is prime or not.
	Return 1 if prime, Return 0 if not prime
*/
	int usernum;
	printf("Enter the number you would like to check if is prime\n");
	scanf("%d",&usernum);  
	if(usernum<=0){
		return 0;
	}
	else if(usernum>0 && usernum<=3){
		return 1;
	}
	else{
		int dividenum = 2;
		int sqrtresult;
		sqrtresult = sqrt(usernum);
		while(dividenum<=sqrtresult){
			if(usernum%dividenum==0){
				return 0;			
			}
			dividenum+=1;
		}	
	}
	return 1;
}


int Checkifpal(){
/*
	Check if number is palindrome.
	Return 1 if true, return 0 if false
*/
	int usernum;
	int tempnum;
	int numofdigits=1;
	int counter=0;
	int pow=1;
	printf("Enter the number you would like to check if is palindrome\n");
	scanf("%d",&usernum);
	//Assign usernum to tempnum to calculate number of digits without losing usernum
	tempnum = usernum;
	//Calculate number of digits
	while (tempnum/10 !=0){
		++numofdigits;
		tempnum/=10;
	}
	//If single digit, consider as palindrome
	if (numofdigits==1){
		return 1;
	}
	//Assign usernum to tempnum to calculate number of digits without losing usernum
	tempnum = usernum;
	for(counter=0;counter<numofdigits-1;counter++){
		pow*=10;
	}
	for(counter=0;counter<(numofdigits/2);++counter){
		if((tempnum/pow)!=tempnum%10){			
			return 0;
		}
		else{
			tempnum %= pow;
			tempnum /= 10;
			pow/=100;
		}
	}
	return 1;
}

int Checkifascend(){
/*
	Check if number is ascending. Repeated numbers is not ascending
	Return 1 if true, return 0 if false
*/
	int usernum;
	int tempnum;
	int numofdigits=1;
	int digit1;
	int digit2;
	int counter=0;
	printf("Enter the number you would like to check if is ascending\n");
	scanf("%d",&usernum);
	//Assign usernum to tempnum to calculate number of digits without losing usernum
	tempnum = usernum;
	//Calculate number of digits
	while (tempnum/10 !=0){
		++numofdigits;
		tempnum/=10;
	}
	//If single digit, consider as ascending
	if (numofdigits==1){
		return 1;
	}
	//Assign usernum to tempnum to calculate number of digits without losing usernum
	tempnum = usernum;
	//iterate for number of digits calculated
	while(counter<numofdigits){
		digit1=tempnum%10;
		digit2=(tempnum/10)%10;
		if (digit1<=digit2){
			return 0;
		}
		else {
			tempnum/=10;
			++counter;
		}
	}
	return 1;
}


int reversenumber(){
	int usernum;
	int tempnum;
	int numofdigits=1;
	int counter=0;
	int pow=1;
	int sum=0;
	int digit;
	int newdigit;
	printf("Enter the number you would like to reverse\n");
	scanf("%d",&usernum);
	//Assign usernum to tempnum to calculate number of digits without losing usernum
	tempnum = usernum;
	//Calculate number of digits
	while (tempnum/10 !=0){
		++numofdigits;
		tempnum/=10;
	}
	if (numofdigits==1){
		return 1;
	}
	//Calculate power of number in 10^x
	for(counter=0;counter<numofdigits-1;counter++){
		pow*=10;
	}
	tempnum=usernum;
	for (counter=0;counter<numofdigits;++counter){
		//Find ones digit
		digit=tempnum%10;
		//Multiply by current power
		newdigit=digit*pow;
		//Add to intermediate sum
		sum +=newdigit;
		//Remove ones digit from current number
		tempnum=tempnum/10;
		//Recalculate current power
		pow/=10;		
	}
	return sum;
}

