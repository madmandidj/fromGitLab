#include <stdio.h>
#include <stdlib.h> /* size_t, rand, srand */
#include <time.h>   /* time used to initialize srand */
#include <string.h>	
#define VALUE_FOUND 1
#define VALUE_NOT_FOUND 0
#define PARAMETER_NOT_INIT -1



/*********	
AUX FUNCTIONS
*********/


static void InitIntArrRand(int* _intArr, size_t _numOfItems)
{
	int index;
	int randNum;
	srand(time(NULL));
	for (index = 0; index < _numOfItems; ++index)
	{
		randNum = rand() % 10000 + 1;
		_intArr[index] = randNum;
	}
    return;
}


/*********	
WHILE NOT END OF ARRAY LINEAR SEARCH
*********/


static int WhileNotEndSearch(int* _intArr, size_t _numOfItems, int _searchVal, int* _foundIndex)
{
	size_t index =0;
	if (NULL == _intArr || NULL == _foundIndex)
	{
		return PARAMETER_NOT_INIT;
	}
	while (index < _numOfItems)
	{
		if (_intArr[index] == _searchVal)
		{
			*_foundIndex = index;
			return VALUE_FOUND;
		}
		++index;
	}
	return VALUE_NOT_FOUND;
}



/*********	
WHILE 1 PUT END LINEAR SEARCH
*********/


/*********	
MOVE BACK ELEMENTS LINEAR SEARCH
*********/


/*********	
BINARY SEARCH
*********/


/*********	
PROPORTIONAL SEARCH
*********/












/*********	
MAIN TESTS
*********/
static void TESTWhileNotEndSearch()
{
	size_t numOfItems = 10000;
	int intArr[10000];
	int searchResult;
	size_t foundIndex;
	int searchVal = 17;
	clock_t start_t;
    clock_t end_t;
    clock_t total_t;
	foundIndex = 0;
	InitIntArrRand(intArr, numOfItems);
	start_t = clock();
	searchResult = WhileNotEndSearch(intArr, numOfItems, searchVal, &foundIndex);
	end_t = clock();
	total_t = (end_t - start_t);
	printf("TESTWhileNotEndSearch- Found: %d, Index: %u, Runtime: %f\n", searchResult, foundIndex, ((float)total_t) / CLOCKS_PER_SEC);
}



int main()
{
	TESTWhileNotEndSearch();
	return 1;
}






