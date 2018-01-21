#include <stdio.h>

int* g_intPtr;

void Hack(int _y)
{
	int l;
	
	printf("In Hack\n");
	*(&_y - 1) = g_intPtr;
	return;
}


void Foo(int _x)
{
	int k;
	
	printf("In Foo\n");
	g_intPtr = *(&_x - 1);
	*(&_x - 1) = Hack;
	
	printf("&_x = %p, _x = %d\n", &_x, _x);
	printf("&_x-1 = %p, *(_x-1) = %d, *(_x-1) = %p\n", &_x-1, *(&_x-1), *(&_x-1));
	printf("&_x-2 = %p, *(_x-2) = %d\n", &_x-2, *(&_x-2));
	printf("&_x-3 = %p, *(_x-3) = %d\n", &_x-3, *(&_x-3));
	printf("&_x-4 = %p, *(_x-4) = %d\n", &_x-4, *(&_x-4));
	printf("&_x-5 = %p, *(_x-5) = %d\n", &_x-5, *(&_x-5));
	printf("&_x-6 = %p, *(_x-6) = %d\n", &_x-6, *(&_x-6));
	printf("&k = %p, k = %d\n", &k, k);
	
	
	return;
}


int main()
{
	printf("Begin main\n");
	Foo(5);
	printf("End main\n");
	return 0;
}

/*Use this to print elf to file*/
/* readelf -a ./a.out >file.txt */


