#include "MyMalloc.h"
#include <stdio.h>

int main()
{
	MyBuf* myBuf;
	
	myBuf = MyBufCreate(256, 32);
	MyBufDestroy(myBuf);
	return 0;
}
