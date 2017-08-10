#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Heap.h"




/*****
INIT FUNCTIONS
*****/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    return arr;
}


/*****
LESS THAN FUNCTIONS
*****/
int LessThanInt(int* _left, int* _right)
{
	if (*_left <= *_right)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



int	VectorElementIntPrint(void* _element, size_t _index, void* _context)
{
	printf("Index = %u, Value = %d\n", _index, *(int*)_element);
	return 1;
}




void TestCreateHeap()
{
	int* arr;
	Vector* vec;
	Heap* heap;
	const size_t numOfInts = 10;
	size_t _initialCapacity = 10;
	size_t _blockSize = 2;
    int* data;
    size_t index;

    arr = InitIntArr(numOfInts);
    vec = VecCreate(_initialCapacity, _blockSize);
    for (index = 0; index < numOfInts; ++index)
    {
    	VecAppend(vec, arr + index);
    }
    heap = HeapBuild(vec, (LessThanComparator)LessThanInt);
    VecForEach(vec, (VectorElementAction) VectorElementIntPrint, NULL);
    HeapDestroy(&heap);
    free(arr);
}




int main()
{
	TestCreateHeap();
	return 1;
}




















