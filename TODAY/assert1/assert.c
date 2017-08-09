/*

get 4 numbers from user
assert (!1) if != 1
*/

#include <stdio.h>
//#define NDEBUG 0 /* If set to 1 -> Disables assertions */
#include <assert.h>

int main()
{
	int arr[4];
	size_t numOfItems = 4;
	size_t index;
	for (index = 0; index < numOfItems; ++index)
	{
		printf("Enter number #%u\n", index);
		scanf("%d", arr + index);
		assert(arr[index] == (int)index + 1);
		printf("After assert\n");
	}
	printf("Function done\n");
	return 0;
}
