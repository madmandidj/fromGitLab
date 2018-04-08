#include <stdio.h>

int solution(int N)
{
	int isCounting = 0;
	int gap = 0;
	int tempGap = 0;
	while(N > 0)
	{
		if(1 == (N & 1))
		{
			if (tempGap > gap && isCounting)
			{
				gap = tempGap;
			}
			isCounting = 1;
			tempGap = 0;
		}
		else
		{
			if (isCounting)
			{
				++tempGap;
			}
		}
		N >>= 1;
	}
	return gap;
}

int main()
{
	int num = 16961;
	printf("%d\n", solution(num));
	return 0;
}


