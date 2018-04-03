#ifndef __GENERAL_FUNCTIONS_H__
#define __GENERAL_FUNCTIONS_H__

#include <stdlib.h>

/******
Integer Array Functions
******/
int* CreateAscendingIntArray(size_t _numOfInts);
int* CreateRandomIntArray(size_t _numOfInts, int _minIntVal, int _maxIntVal);
void DestroyIntArray(int* _intArr);


/******
Print Functions
******/
void PrintSingleInt(int _int);










#endif /*#ifndef __GENERAL_FUNCTIONS_H__*/

