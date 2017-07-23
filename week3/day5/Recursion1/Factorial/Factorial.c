#include <stdio.h>

int Fact(int num)
{
	if (1 == num)
	{
		return 1;
	}
	return Fact(num-1) * num;
}


int Fib(int n)
{
	if (n < 2)
	{
		return n;
	}
	return Fib(n-2) + Fib(n-1);
}

unsigned int FibIt(unsigned int _i)
{
	unsigned int prevVal = 0;
	unsigned int curVal = 1;
	unsigned int temp = 0;
	unsigned int result = 0;
	unsigned int index;
	for(index = 0; index < _i; ++index)
	{	
		result = prevVal + curVal;
		prevVal = curVal;
		curVal = result;
	}
	return result;
}

int main()
{
	/*printf("%d\n",Fact(2));*/
	printf("%d\n",Fib(50));
	/*printf("%d",FibIt(7));*/
	return 0;
}
