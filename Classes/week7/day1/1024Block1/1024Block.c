#include <stdio.h>


/* NOT COMPLETE */



static void* Init()
{
	void* ptr;
	ptr = malloc(1024 * 1000 * sizeof(char));
	if (NULL == ptr)
	{
		return NULL;
	}
	
}

void* alloc()
{

}

void free(void* _ptr)
{

}

int main()
{
	
	return 1;
}
