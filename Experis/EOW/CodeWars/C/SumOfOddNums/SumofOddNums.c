#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>

/*
1
3 5
7 9 11           == 27
13 15 17 19 == 28 + 36 == 64
21 23 25 27 29


		(0) + 1,
	(2*1) + 1, (2*2) + 1
	(2*3) + 1, (2*4) + 1, (2*5) + 1, 
	
1st row, 1st element index: 1
2nd row, 1st element index: 2
3rd row, 1st element index: 4
4th row, 1st element index: 7
5th row, 1st element index: 11
6th row, 1st element index: 16
7th 22
8th 29
9th 37
10th 46
11th 56


calculateFirstElementIndex
{
	uint64_t elemIndex = 1;
	uint64_t curRow = 1;
	uint64_t addOffset = 1;
	sum
	for (curRow = 1; cuRow < n; ++curRow)
	{
		for(numOfElemInRow = 0; numOfElemInRow < curRow, ++numOfElemInRow)
		{
			
		}
	}
}

*/


/*Version 1 *//*
uint64_t rowSumOddNumbers(uint32_t n)
{
	uint64_t sum = 0;
	uint64_t firstVal;
	size_t index;
	if (1 > n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	firstVal = 1 + ((n - 1) * 2);
	for (index = 0; index < n; ++index)
	{
		sum += firstVal + (index * 2);
	}
	return sum;
}
*/

/*Version 2 *//*
uint64_t rowSumOddNumbers(uint32_t n)
{
	uint64_t sum = 0;
	uint64_t firstVal;
	size_t index;
	if (1 > n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	if (2 == n)
	{
		return 8;
	}
	firstVal = 1 + ((n) * 2);
	for (index = 0; index < n; ++index)
	{
		sum += firstVal + (index * 2);
	}
	return sum;
}
*/

/*Version 3 *//*
uint64_t rowSumOddNumbers(uint32_t n)
{
	uint64_t sum = 0;
	uint64_t prevFirstVal = 1;
	uint64_t curFirstVal;
	uint64_t index;
	if (1 > n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	
	for (index = 2; index <= n; ++index)
	{
		curFirstVal = ((index-1)*2) + prevFirstVal;
		prevFirstVal = curFirstVal;
	}
	for (index = 0; index < n; ++index)
	{
		sum += curFirstVal + (2 * index);
	}
	return sum;
}
*/


/*Version 4 */
uint64_t rowSumOddNumbers(uint32_t n)
{
	return n*n*n;
}


int main()
{
	printf("%llu\n", rowSumOddNumbers(0));
	printf("%llu\n", rowSumOddNumbers(1));
	printf("%llu\n", rowSumOddNumbers(2));
	printf("%llu\n", rowSumOddNumbers(3));
	printf("%llu\n", rowSumOddNumbers(4));
/*	printf("%llu\n", rowSumOddNumbers(5));*/
/*	printf("%llu\n", rowSumOddNumbers(6));*/
/*	printf("%llu\n", rowSumOddNumbers(7));*/
/*	printf("%llu\n", rowSumOddNumbers(8));*/
/*	printf("%llu\n", rowSumOddNumbers(9));*/
/*	printf("%llu\n", rowSumOddNumbers(10));*/
	return 0;
}





















