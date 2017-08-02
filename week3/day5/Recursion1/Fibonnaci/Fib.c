#include <stdio.h>


unsigned int Fib(unsigned int _i)
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
	int result;
	result = Fib(0);
	printf("%d\n",result);
	result = Fib(1);
	printf("%d\n",result);
	result = Fib(2);
	printf("%d\n",result);
	result = Fib(3);
	printf("%d\n",result);
	result = Fib(4);
	printf("%d\n",result);
	return 0;
}
