#include <stdio.h>
#include <pthread.h>
#define NUM_OF_THREADS 100

/*
	-pthread needed when using gcc to compile
*/
int g_globalVar = -1;

void* PrintFunc(void* tid)
{
	int localVar = -1;
	int index = 0;
	int reps = 10;
	/*int retVal; */
	for (index = 0; index < reps; ++index)
	{
		++localVar;
		++g_globalVar;
		printf("tid = %d, localVar = %d, g_globalVar = %d\n", (int) tid, localVar, g_globalVar);
	}
	pthread_exit(NULL);
}

int main()
{
	
	pthread_t threads[NUM_OF_THREADS];
	int index;
	int status;
	for (index = 0; index < NUM_OF_THREADS; ++index)
	{
		status = pthread_create(&threads[index], NULL, &PrintFunc, (void*) index);
		//if (0 == status)
		//{
		//	printf("Thread %d created\n",index);
		//}
	}
	for (index = 0; index < NUM_OF_THREADS; ++index)
	{
		pthread_join(threads[index], NULL);
	}
	return 1;
}

