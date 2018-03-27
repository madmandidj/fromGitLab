#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"
/*#include <unistd.h> */
#include <limits.h>

#define FALSE 0
#define TRUE 1

static void SwapElements(Vector* _vector, size_t _index1, size_t _index2, void* _elem1, void* _elem2)
{
	VectorSet(_vector, _index2, _elem1);
	VectorSet(_vector, _index1, _elem2);
}

static size_t Partition(Vector* _vector, size_t _low, size_t _high)
{
	int* pivot;
	int* element_i;
	int* element_j;
	int* element_i_plus1;
	size_t i, j;
	
	VectorGet(_vector, _high, (void**)&pivot);
	i = _low - 1;
	for (j = _low; j <= _high -1; ++j)
	{
		VectorGet(_vector, j, (void**)&element_j);
		if(*element_j <= *pivot)
		{
			if (++i != j)
			{
				VectorGet(_vector, i, (void**)&element_i);
				SwapElements(_vector, i, j, (void*)element_i, (void*)element_j);
			}
		}
	}
	VectorGet(_vector, i + 1, (void**)&element_i_plus1);
	SwapElements(_vector, i + 1, _high, (void*)element_i_plus1, (void*)pivot);
	return i+1;
}

static void QuickSortRec(Vector* _vector, size_t _low, size_t _high)
{
	size_t partitionIndex;
	size_t maxSizet = UINT_MAX;
	
	if (_low < _high && _high != maxSizet)
    {
        partitionIndex = Partition(_vector, _low, _high);
        QuickSortRec(_vector, _low, partitionIndex - 1);
        QuickSortRec(_vector, partitionIndex + 1, _high);
    }
}

void QuickSort(Vector* _vector)
{
	size_t numOfItems;
	
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
	}
	
	QuickSortRec(_vector, 0, numOfItems - 1);	
}

