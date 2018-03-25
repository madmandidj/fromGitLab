#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void BubbleSort(Vector* _vector)
{
	unsigned int isSorted = FALSE;
	size_t index;
	size_t endIndex = 0;
/*	size_t vecItemsNum;*/
	void* item_L;
	void* item_R;
	if (!_vector)
	{
		return;
	}
	endIndex = VectorItemsNum(_vector) - 1;
	while(!isSorted)
	{
		isSorted = 1;
		for (index = 0; index < endIndex; ++index)
		{
			VectorGet(_vector, index, &item_L);
			VectorGet(_vector, index + 1, &item_R);
			if (*(int*)item_L > *(int*)item_R)
			{
				VectorSet(_vector, index, item_R);
				VectorSet(_vector, index + 1, item_L);
				isSorted = 0;
			}
		}
		--endIndex;
	}
}







