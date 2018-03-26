#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void InsertionSort(Vector* _vector)
{
	size_t numOfItems;
	size_t curIndex = 1;
	size_t index_L;
	size_t index_R;
	int* item_R;
	int* item_L;
	
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
		while(curIndex < numOfItems)
		{
			index_R = curIndex;
			index_L = index_R - 1;
			VectorGet(_vector, index_R, (void**)&item_R);
			while(index_R > 0)
			{
				VectorGet(_vector, index_L, (void**)&item_L);
				if (*item_R < *item_L)
				{
					VectorSet(_vector, index_R, item_L);
					--index_L;
					--index_R;
					continue;
				}
				break;
			}
			++curIndex;
		}
	} 
}







