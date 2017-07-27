#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_OF_THREADS 2
typedef struct Semaphore
{
	sem_t mutex;
	sem_t empty;
	sem_t full;
}Semaphore;
/*
	-pthread needed when using gcc to compile
*/
int g_globalVar = 0;

void* Producer(void* _semaphore)
{
	size_t index;
	Semaphore* semaphore;
	semaphore = (Semaphore*) _semaphore;
	while (1)
	{
		sem_wait(&(semaphore->empty));
		sem_wait(&(semaphore->mutex));
		for (index = 0; index < 1000; ++index)
		{
			/* produce item */
			/* insert item */
			++g_globalVar;
			printf("Global var from producer: %d\n", g_globalVar);
		}
		sem_post(&(semaphore->mutex));
		sem_post(&(semaphore->full));
	}
	pthread_exit(NULL);
}

void* Consumer(void* _semaphore)
{
	size_t index;
	Semaphore* semaphore;
	semaphore = (Semaphore*) _semaphore;
	while (1)
	{
		sem_wait(&(semaphore->full));
		sem_wait(&(semaphore->mutex));
		for (index = 0; index < 1000; ++index)
		{
			/* produce item */
			/* insert item */
			--g_globalVar;
			printf("Global var from consumer: %d\n", g_globalVar);
		}
		sem_post(&(semaphore->mutex));
		sem_post(&(semaphore->empty));
	}
	pthread_exit(NULL);
}


int main()
{
	pthread_t threads[NUM_OF_THREADS];
	int index;
	int statusProd;
	int statusCons;
	Semaphore semaphore;
	sem_init(&semaphore.mutex, 0, 1);
	sem_init(&semaphore.empty, 0, 1);
	sem_init(&semaphore.full, 0, 0);
	statusProd = pthread_create(&threads[0], NULL, &Producer, (void*) &semaphore);
	statusCons = pthread_create(&threads[1], NULL, &Consumer, (void*) &semaphore);
	for (index = 0; index < NUM_OF_THREADS; ++index)
	{
		pthread_join(threads[index], NULL);
	}
	return 1;
}

