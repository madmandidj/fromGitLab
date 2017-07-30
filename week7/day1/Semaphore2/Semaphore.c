#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_OF_THREADS 2
typedef struct Semaphore
{
	pthread_mutex_t mutex;
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
		pthread_mutex_lock(&semaphore->mutex);
		for (index = 0; index < 10; ++index)
		{
			/* produce item */
			/* insert item */
			++g_globalVar;
			printf("Global var from producer: %d\n", g_globalVar);
		}
		pthread_mutex_unlock(&semaphore->mutex);
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
		pthread_mutex_lock(&semaphore->mutex);
		for (index = 0; index < 10; ++index)
		{
			/* produce item */
			/* insert item */
			--g_globalVar;
			printf("Global var from consumer: %d\n", g_globalVar);
		}
		pthread_mutex_unlock(&semaphore->mutex);
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
	pthread_mutex_init(&semaphore.mutex, NULL);
	/*
	int sem_init(sem_t *sem, int pshared, unsigned int value);
	If pshared has the value 0, then the semaphore is shared between the
    threads of a process, and should be located at some address that is
    visible to all threads (e.g., a global variable, or a variable
    allocated dynamically on the heap).
    If pshared is nonzero, then the semaphore is shared between
    processes, and should be located in a region of shared memory.
    The value argument specifies the initial value for the
    semaphore.
	*/
	sem_init(&semaphore.empty, 0, 1);
	sem_init(&semaphore.full, 0, 0);
	statusProd = pthread_create(&threads[0], NULL, &Producer, (void*) &semaphore);
	statusCons = pthread_create(&threads[1], NULL, &Consumer, (void*) &semaphore);
	for (index = 0; index < NUM_OF_THREADS; ++index)
	{
		pthread_join(threads[index], NULL);
	}
	sem_destroy(&semaphore.empty);
	sem_destroy(&semaphore.full);
	pthread_mutex_destroy(&semaphore.mutex);
	return 1;
}

