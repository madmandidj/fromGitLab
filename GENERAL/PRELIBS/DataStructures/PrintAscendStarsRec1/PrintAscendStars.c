#include <stdio.h>




int PrintAscStars(int _numOfRows)
{
	int output;
	int index;
	if (0 == _numOfRows)
	{
		return 1;
	}
	PrintAscStars(_numOfRows - 1);
	for (index = 0; index < _numOfRows; ++index)
	{
		printf("* ");
	}
	printf("\n");
	return 0;
}


int main()
{
	PrintAscStars(8);
	return 0;
}
