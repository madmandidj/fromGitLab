#include "DataGenerator.h"
#include <stdio.h>
#include <stdlib.h>







int main()
{
	size_t index;
/*	Subscriber subArr[64];*/
	Subscriber* subArr;
	
	subArr = malloc(64 * sizeof(Subscriber));
	
	for (index = 0; index < 64; ++index)
	{
		GenerateSubscriber(subArr + index);
		printf("%s\n", subArr[index].m_imsi);
	}
	
	free(subArr);
	return 0;
}


