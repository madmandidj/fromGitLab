#include <stdio.h>


void PrintMultLine(int _col)
{
	if (1 == _col)
	{
		printf("%d ", _col);
		return;
	}
	else
	{
		PrintMultLine(_col-1);
	}
	printf("%d ", _col);
	return;
} 



int main()
{
	PrintMultLine(5);
	return 0;
}
