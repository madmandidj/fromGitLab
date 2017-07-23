/*
Filename: 		TESTBubbleAndShakeSortVec.c 
Description:	TEST Implementation of Bubble And Shake Sort using Vector API given by Ronny
Created: 		20/07/17
Created by:		Eyal Alon
Last modified: 	21/07/17
Modified by:	Eyal Alon
*/
#include "BubbleAndShakeSortVec.h"
#include <stdio.h>
/* rand, srand */
/* #include <stdlib.h> 	*/
/* time used to init srand */
#include <time.h>
#include <string.h>		

/*
static void PrintErrResult(char* _testName, ADTErr _err, ADTErr _passErr)
{
    char errString[32];
    if (_err == _passErr)
    {
        printf("PASSED: %s\n", _testName);
    }
    else
    {
        if (_err == ERR_OK)
        {
            strcpy(errString, "ERR_OK");
        }
        else if (_err == ERR_GENERAL)
        {
           strcpy(errString, "ERR_GENERAL");
        }
        else if (_err == ERR_NOT_INITIALIZED)
        {
           strcpy(errString, "ERR_NOT_INITIALIZED");
        }
        else if (_err == ERR_ALLOCATION_FAILED)
        {
           strcpy(errString, "ERR_ALLOCATION_FAILED");
        }
        else if (_err == ERR_REALLOCATION_FAILED)
        {
           strcpy(errString, "ERR_REALLOCATION_FAILED"); 
        }
        else if (_err == ERR_UNDERFLOW)
        {
           strcpy(errString, "ERR_UNDERFLOW"); 
        }
        else if (_err == ERR_OVERFLOW)
        {
           strcpy(errString, "ERR_OVERFLOW");
        }
        else if (_err == ERR_WRONG_INDEX)
        {
           strcpy(errString, "ERR_WRONG_INDEX"); 
        }
        else if (_err == ERR_EMPTY)
        {
           strcpy(errString, "ERR_EMPTY"); 
        }
        else if (_err == ERR_FULL)
        {
           strcpy(errString, "ERR_FULL"); 
        }
        else if (_err == ERR_EMPTY_LIST)
        {
           strcpy(errString, "ERR_EMPTY_LIST"); 
        }
        else if (_err == ERR_EMPTY_HEAP)
        {
           strcpy(errString, "ERR_EMPTY_HEAP"); 
        }
		else
		{
			strcpy(errString, "ERR_UNDEFINED");
		}
        printf("FAILED: %s %s\n", _testName, errString);
    }
    return;
}

void TestBubbleSortNULLVec()
{


}
*/

int main()
{
	/*
	TestBubbleSortNULLVec();
	TestBubbleSortEmptyVec();
	TestBubbleSort1Item();
	TestBubbleSort10Items();
	TestBubbleSort100Items();
	return 0;
	*/
	
	
	ADTErr errResult;
	Vector* vec;
	int index;
	int randNum;
	size_t initSize = 10;
	size_t initBlockSize = 2;
	srand (time(NULL));
	vec = VectorCreate(initSize, initBlockSize);
	
	
	for (index = 0; index < initSize; ++index)
	{
		randNum = rand() % 100 + 1;
		VectorAdd(vec, randNum);
	}
	



	
	
	// VectorAdd(vec, 83);
	// VectorAdd(vec, 56);
	// VectorAdd(vec, 66);
	// VectorAdd(vec, 86);
	// VectorAdd(vec, 44);
	// VectorAdd(vec, 35);
	// VectorAdd(vec, 55);
	// VectorAdd(vec, 91);
	// VectorAdd(vec, 24);
	// VectorAdd(vec, 18); 
    

	

	printf("Unsorted: \n");
	VectorPrint(vec);

	// errResult = BubbleSort(vec); 

	 errResult = ShakeSort(vec);

	printf("Sorted: \n");
	VectorPrint(vec);
	return 0;
	
	
}
