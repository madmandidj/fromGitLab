#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void QuickSort(Vector* _vector)
{
	size_t numOfItems;
	size_t curIndex = 0;
	size_t swapIndex;
	size_t smallestIndex = 0;
	int* item_cur;
	int* item_swap;
	int* item_smallest;
	
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
	}	
}
