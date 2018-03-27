#include "Sort_Algorithms.h"


#define FALSE 0
#define TRUE 1

void BubbleSort(Vector* _vector)
{
	unsigned int isSorted = FALSE;
	size_t index = 0;
	size_t itemsNum;
	size_t endIndex = 0;
	int* item_L;
	int* item_R;
	if (!_vector || VectorItemsNum(_vector) <= 1)
	{
		return;
	}
	itemsNum = VectorItemsNum(_vector);
	endIndex = itemsNum;
	while(!isSorted)
	{
		isSorted = 1;		
		VectorGet(_vector, 0, (void**)&item_R);
		for (index = 1; index < endIndex; ++index)
		{
			item_L = item_R;
			VectorGet(_vector, index, (void**)&item_R);
			if (*item_L > *item_R)
			{
				VectorSet(_vector, index - 1, (void*)item_R);
				VectorSet(_vector, index, (void*)item_L);
				item_R = item_L;
				isSorted = 0;
			}
		}
		--endIndex;
	}
}







