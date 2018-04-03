#include "GeneralFunctions.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <limits.h>

int* CreateAscendingIntArray(size_t _numOfInts)
{
	int* intArr;
	size_t index;
	if (0 == _numOfInts || _numOfInts > INT_MAX)
	{
		return NULL;
	}
	intArr = malloc(_numOfInts * sizeof(int));
	if (!intArr)
	{
		return NULL;
	}
	for (index = 0; index < _numOfInts; ++index)
	{
		intArr[index] = (int)index;
	}
	return intArr;
}

int* CreateRandomIntArray(size_t _numOfInts, int _minIntVal, int _maxIntVal)
{
	size_t index;
	int* intArr;
	int range;
	int normalisedRandNum;
	if (0 == _numOfInts || _minIntVal > _maxIntVal)
	{
		return NULL;
	}
	intArr = malloc(_numOfInts * sizeof(int));
	if (!intArr)
	{
		return NULL;
	}
	range = 1 + _maxIntVal - _minIntVal;
	srand((unsigned int)time(NULL));
	for (index = 0; index < _numOfInts; ++index)
	{
		normalisedRandNum = rand() % range;
		intArr[index] = _maxIntVal - normalisedRandNum;
	}
	return intArr;
}

void DestroyIntArray(int* _intArr)
{
	if (_intArr)
	{
		free(_intArr);
	}
	
	return;
}


void PrintSingleInt(int _int)
{
	printf("%d\n", _int);
}















