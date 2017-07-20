#include <stdio.h>

int PrintDecStars(int _numOfRows)
{
	int output;
	int index;
	if (0 == _numOfRows)
	{
		return 1;
	}
	for (index = 0; index < _numOfRows; ++index)
	{
		printf("* ");
	}
	printf("\n");
	PrintDecStars(_numOfRows - 1);
	return 0;
}


int main()
{
	PrintDecStars(3);
	return 0;
}
