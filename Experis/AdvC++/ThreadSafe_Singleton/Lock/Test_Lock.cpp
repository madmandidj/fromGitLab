#include "Lock.h"
#include<pthread.h>

int main()
{
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, 0);
	Lock lock(&mutex);
	pthread_mutex_destroy(&mutex);
	return 0;
}
