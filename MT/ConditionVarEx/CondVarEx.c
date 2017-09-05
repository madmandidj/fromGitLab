#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define NUM_OF_TEMPERS 3

/*
if (pthread_create(_prods->m_threadIDs + index, NULL, ProducersRoutine, _prods))





*/

typedef struct Temper Temper;

struct Temper
{
	pthread_t 		m_threadIDs[32];
	int 			m_temp;
	pthread_cond_t 	m_cond;
	pthread_mutex_t m_mutex;
};





int GenerateTempInc()
{
	return rand() %3 - 1;
}





Temper* CreateTemper()
{
	Temper* temper;
	
	temper = malloc(sizeof(Temper));
	if (NULL == temper)
	{
		return NULL;
	}
	
	temper->m_temp = 23;
	pthread_mutex_init(&temper->m_mutex, NULL);
	pthread_cond_init(&temper->m_cond, NULL);
	
	return temper;
}






void DestroyTemper(Temper* _temper)
{
	pthread_mutex_destroy(&_temper->m_mutex);
	pthread_cond_destroy(&_temper->m_cond);
	free(_temper);
	
	return;
}






void* TempMonitorRoutine(void* _temper)
{
	size_t index;
	
	/*
	for (index = 0; index < 5; ++index)
	*/
	for (;;)
	{
		pthread_mutex_lock(&((Temper*)_temper)->m_mutex);
		
		((Temper*)_temper)->m_temp += GenerateTempInc();
		
		/*if(((Temper*)_temper)->m_temp > 25 || ((Temper*)_temper)->m_temp < 21 )
		{*/
			
			printf("Temp out of bounds = %d\n", ((Temper*)_temper)->m_temp);
			pthread_cond_signal(&((Temper*)_temper)->m_cond);
			/*usleep(10000);
		/*}*/
	
		pthread_mutex_unlock(&((Temper*)_temper)->m_mutex);
	}
	
	pthread_exit(NULL);
	
	return NULL;
}




void* TempMasterRoutine(void* _temper)
{
	size_t index;
	
	/*
	for (index = 0; index < 5; ++index)
	*/
	for (;;)
	{
		pthread_mutex_lock(&((Temper*)_temper)->m_mutex);
	
		while(((Temper*)_temper)->m_temp <= 25 && ((Temper*)_temper)->m_temp >= 21)
		{
			pthread_cond_wait(&((Temper*)_temper)->m_cond, &((Temper*)_temper)->m_mutex);
			/*usleep(10000);*/
			printf("Temp in bounds = %d\n", ((Temper*)_temper)->m_temp);
		}
		printf("value reset to 23\n");
		((Temper*)_temper)->m_temp = 23;
		pthread_mutex_unlock(&((Temper*)_temper)->m_mutex);
	}
	
	pthread_exit(NULL);
	
	return NULL; 
}







void CreateThreads(Temper* _temper)
{
	size_t index;
	
	for (index = 0; index < NUM_OF_TEMPERS; index = index +2)
	{
		pthread_create(_temper->m_threadIDs + index, NULL, TempMonitorRoutine, _temper);
		pthread_create(_temper->m_threadIDs + index + 1, NULL, TempMasterRoutine, _temper);
	}
	
	return;
}





void JoinThreads(Temper* _temper)
{
	size_t index;
	
	for (index = 0; index < NUM_OF_TEMPERS * 2; ++index)
	{
		pthread_join(_temper->m_threadIDs[index], NULL);
	}
	
	return;
}




int main()
{
	Temper* temper;
	
	
	srand(time(NULL));
	
	temper = CreateTemper();
	CreateThreads(temper);
	JoinThreads(temper);
	DestroyTemper(temper);
	
	
	return 0;
}


