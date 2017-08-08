#include <stdio.h>

int main()
{
	int a = 1;
	int const b = 1;
	int* aPtr;
	int const * aConstPtr = &a;
	int* const aPtrConst = &a;
	int const* const aConstPtrConst = &a;
	int* const* aPtrConstPtrConst = &aPtrConst;
	int* changeB = &b;
	
	a = 5;
	printf("a = %d", a);
	b = 5;
	printf("b = %d", b);
	aPtr = &a;
	printf("*aPtr = %d", *aPtr);
	*aConstPtr = 10;
	printf("*aPtr = %d", *aPtr);
	aPtrConst = &b;
	printf("*aPtr = %d", *aPtr);
	aConstPtrConst = &b;
	*aConstPtrConst = 100;
	*aPtrConstPtrConst = &aConstPtr;
	*changeB = 75;
	printf("a through aConstPtrConst: %d", *aConstPtrConst);
	printf("a through aPtrConstPtrConst: %d", **aPtrConstPtrConst);
	
	return 1;
}
