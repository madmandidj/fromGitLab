#include <stdio.h>
#include <pthread.h>
#define NUM_OF_THREADS 400

/*
	-pthread needed when using gcc to compile
*/
int g_globalVar = -1;

void* PrintFunc(void* tid)
{
	int local;
/*	while(1)*/
/*	{*/
		printf("%p\n", &local);
/*	}*/
}

int main()
{
	
	pthread_t threads[NUM_OF_THREADS];
	int index = 0;
	int* tid;
	int status;
	while (1)
	{
		status = pthread_create(&threads[index], NULL, &PrintFunc, (void*) index);
		++index;
		if (status != 0)
		{
			printf("error\n");
			printf("index %d= ", index);
			break;
		}
	}
	return 1;
}

