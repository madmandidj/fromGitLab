#include <stdio.h>


int CreateSortedArr(int* _sortedArr, int _numOfElem)
{
	int index;
	int output = 1;
	if (NULL == _sortedArr)
	{
		output = 0;
	}
	else
	{
		for (index = 0; index < _numOfElem; ++index)
		{
			*_sortedArr = index;
		}
	}
	return output;
}

int main()
{
	int sortedArr[50];
	int numofElem = 50;
	int result;
	result = CreateSortedArr(sortedArr, numOfElem);
	return 0;
}
