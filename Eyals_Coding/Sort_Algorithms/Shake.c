#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void ShakeSort(Vector* _vector)
{
	unsigned int isSorted = FALSE;
	size_t index = 0;
/*	size_t itemsNum;*/
	size_t startIndex = 0;
	size_t endIndex = 0;
	void* item_L;
	void* item_R;
	if (!_vector || VectorItemsNum(_vector) <= 1)
	{
		return;
	}
	endIndex = VectorItemsNum(_vector) - 1;
	while(!isSorted)
	{
		isSorted = 1;
		index = startIndex;		
		VectorGet(_vector, index, &item_R);
		while(index < endIndex)
		{
			item_L = item_R;
			VectorGet(_vector, index + 1, &item_R);
			if (*(int*)item_L > *(int*)item_R)
			{
				VectorSet(_vector, index, item_R);
				VectorSet(_vector, index + 1, item_L);
				item_R = item_L;
				isSorted = 0;
			}
			++index;
		}
		if (isSorted)
		{
			break;
		}
		index = --endIndex;
		VectorGet(_vector, index, &item_L);
		while(index > startIndex)
		{
			item_R = item_L;
			VectorGet(_vector, index -1, &item_L);
			if (*(int*)item_L > *(int*)item_R)
			{
				VectorSet(_vector, index - 1, item_R);
				VectorSet(_vector, index, item_L);
				item_L = item_R;
				isSorted = 0;
			}
			--index;
		}
		if (isSorted)
		{
			break;
		}
		++startIndex;
	}
}







