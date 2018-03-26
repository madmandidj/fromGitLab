#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void ShellSort(Vector* _vector)
{
	size_t numOfItems;
	size_t curIndex;
	size_t index_L;
	size_t index_R;
	int* item_R;
	int* item_L;
	size_t gap;
	
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
		gap = numOfItems/2;
		while(gap >=1)
		{
			curIndex = gap;
			while(curIndex < numOfItems)
			{
				index_R = curIndex;
				index_L = index_R - gap;
				VectorGet(_vector, index_R, (void**)&item_R);
				while(index_R > 0)
				{
					VectorGet(_vector, index_L, (void**)&item_L);
					if (*item_R < *item_L)
					{
						VectorSet(_vector, index_R, item_L);
						index_L -= gap;
						index_R -= gap;
						continue;
					}
					break;
				}
				curIndex += gap;
			}
			gap /= 2;
		}
	} 
}







