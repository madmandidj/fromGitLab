#include <stdio.h>

void PMRRec(int _col, int _row, int _size)
{
	if (1 == _col && 1 == _row)
	{
		printf("%d\t", _col * _row);
		return;
	}
	else if (1 ==_col && 1 != _row)
	{
		PMRRec(_size, _row-1, _size);
		printf("\n");
	}
	else if (1 !=_col)
	{
		PMRRec(_col-1, _row, _size);
	}
	printf("%d\t", _col * _row);
	return;
}

void PrintMultiRow(int _size)
{
	int col = _size;
	int row = _size;
	printf("\n");
	if (0 >= _size || 32 <= _size)
	{
		printf("\n");
		return;
	}
	else if (1 == _size)
	{
		printf("%d ", _size);
		printf("\n");
		return;
	}
	else
	{
		PMRRec(col, row, _size);
		printf("\n\n");
	}
	return;
}

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
	//PrintMultLine(5);
	PrintMultiRow(13);
	return 0;
}
