#ifndef __GENERAL_FUNCTIONS_H__
#define __GENERAL_FUNCTIONS_H__
#include "../Data_Structures/inc/Vector.h"
#include <stdlib.h>

/******
Integer Array Functions
******/
int* CreateAscendingIntArray(size_t _numOfInts);
int* CreateRandomIntArray(size_t _numOfInts, int _minIntVal, int _maxIntVal);
void DestroyIntArray(int* _intArr);

/******
Vector Functions
******/
Vector* CreateAscendingIntVector(size_t _numOfInts, size_t _blockSize, int** _intArr);
Vector* CreateRandomIntVector(size_t _numOfInts, int _minVal, int _maxVal, size_t _blockSize, int** _intArr);
void DestroyIntVector(Vector* _vector, int* _intArr);
Vector* CopyCreateVector(Vector* _vector);
void FlipVector(Vector* _vector);
int AreVectorsEqual(Vector* _isSortedVector, Vector* _sortedVector);

/******
Print Functions
******/
void PrintSingleInt(int _int);










#endif /*#ifndef __GENERAL_FUNCTIONS_H__*/

