#include <stdio.h>


float ArrAvgRec(int* _numArr, int numOfElem)
{
	if (1 == numOfElem)
	{
		return _numArr[0];
	} 
	else
	{
		return (((numOfElem-1)*ArrAvgRec(_numArr, numOfElem-1) + _numArr[numOfElem-1])/numOfElem);
	}
}

int main()
{
	int numOfElem = 3;
	int numArr[]={4,4,4};
	float result;
	result = ArrAvgRec(numArr, numOfElem);
	printf("%4.4f", result);
	return 0;
}
