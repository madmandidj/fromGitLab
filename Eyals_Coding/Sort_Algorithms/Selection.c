#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void SelectionSort(Vector* _vector)
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
		while (curIndex < numOfItems - 1)
		{
			swapIndex = curIndex + 1;
			VectorGet(_vector, curIndex, (void**)&item_cur);
			VectorGet(_vector, swapIndex, (void**)&item_swap);
			item_smallest = item_cur;
			smallestIndex = curIndex;
			while (swapIndex < numOfItems)
			{
				if (*item_swap < *item_smallest)
				{
					smallestIndex = swapIndex;
					item_smallest = item_swap;
				}
				++swapIndex;
				VectorGet(_vector, swapIndex, (void**)&item_swap);
			}
			if (smallestIndex != curIndex)
			{
				VectorSet(_vector, curIndex, (void*)item_smallest);
				VectorSet(_vector, smallestIndex, (void*)item_cur);				
			}
			++curIndex;
		}
	}
}
