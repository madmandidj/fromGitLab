#include <stdio.h>
#include <stdlib.h>


int main()
{
	int* ptr;
	size_t index = 0;
	while(1)
	{
		ptr = malloc(1024 * 1024);
		if (ptr == NULL)
		{
			break;
		}
		++index;
	}
	printf("index = %zu", index);
	free (ptr);
	return 1;
}
