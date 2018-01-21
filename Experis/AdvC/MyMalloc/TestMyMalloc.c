#include "MyMalloc.h"
#include <stdio.h>

int main()
{
	MyBuf* myBuf;
	int* myPtr;
	
	myBuf = MyBufCreate(1, 10);
	
	myPtr = MyMalloc(myBuf);
	
	MyMallocFree(myBuf, myPtr);
	
	MyBufDestroy(myBuf);
	return 0;
}








/*

int main()
{
	MyBuf* myBuf;
	int* myPtr;
	int* generalPtr;
	
	myBuf = MyBufCreate(32, 4);
	
	printf("myBuf 0x: %p\n", myBuf);
	printf("myBuf int: %d\n", myBuf);
	printf("myPtr 0x: %p\n", myPtr);
	
	myPtr = MyMalloc(myBuf);
	
	printf("myPtr 0x: %p\n", myPtr);
	printf("myPtr int: %d\n", myPtr);
	printf("myPtr + (32*4) 0x: %p\n", myPtr + (32*4));
	printf("myPtr + (32*4) int: %d\n", myPtr + (32*4));
	printf("generalPtr 0x: %p\n", generalPtr);
	
	generalPtr = malloc(sizeof(int));
	
	printf("generalPtr 0x: %p\n", generalPtr);
	printf("generalPtr int: %d\n", generalPtr);
	
	MyBufDestroy(myBuf);
	
	free(generalPtr);
	return 0;
}

*/
