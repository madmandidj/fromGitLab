#ifndef __VEC_FUNCTIONS_H__
#define __VEC_FUNCTIONS_H__
#include "Vector.h"

Vector* CreateRandomIntVector(size_t _numOfInts, int _maxVal, size_t _blockSize, int** _intArrResult);

void DestroyRandomIntVector(Vector* _vector, int* _intArr);

Vector* CopyCreateVector(Vector* _vector);

void FlipVector(Vector* _vector);

int AreVectorsEqual(Vector* _isSortedVector, Vector* _sortedVector);





#endif /*#ifndef __VEC_FUNCTIONS_H__*/

