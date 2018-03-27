#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void CountingSort(Vector* _vector)
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
	
}
