#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "b.h"

int main(int argc, char *argv[])
{
	int a = (argc>1) ? atoi(argv[1]) : 5;
	int b = (argc>2) ? atoi(argv[2]) : 7;

	printf("Min (%d, %d) = %d\n", a, b, min(a, b));
	printf("Max (%d, %d) = %d\n", a, b, max(a, b));

	return 0;
}
