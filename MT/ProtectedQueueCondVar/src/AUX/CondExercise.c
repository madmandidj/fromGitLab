#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void* (*StartRoutine) (void*);

typedef struct
{
	pthread_cond_t m_cond; 
	pthread_mutex_t m_mutex; 
	int m_temperature; 
	int m_shouldBreak;
}TempControl;

void* Mazgan(TempControl* _tempControl)
{
	pthread_mutex_lock(&_tempControl->m_mutex);
	while(1)
	{
		if (_tempControl->m_shouldBreak)
		{
			pthread_mutex_unlock(&_tempControl->m_mutex);
			break;
		}
		
		while((_tempControl->m_temperature < 25 && _tempControl->m_temperature > 21) || _tempControl->m_shouldBreak)
		{
			pthread_cond_wait(&_tempControl->m_cond, &_tempControl->m_mutex);
		}
		
		_tempControl->m_temperature = 23;
		printf("temperature balanced to %d\n", _tempControl->m_temperature);
	}
	
	return NULL;
}

void* Weather(TempControl* _tempControl)
{
	while(1)
	{
		pthread_mutex_lock(&_tempControl->m_mutex);
		if (_tempControl->m_shouldBreak)
		{
			pthread_mutex_unlock(&_tempControl->m_mutex);
			break;
		}
		
		_tempControl->m_temperature += rand()%3 - 1;
		printf("temperature was changed to %d\n", _tempControl->m_temperature);
		
		if (_tempControl->m_temperature > 25 || _tempControl->m_temperature < 21)
		{
			printf("wake mazgan\n");
			pthread_cond_signal(&_tempControl->m_cond);
		}
		pthread_mutex_unlock(&_tempControl->m_mutex);
		usleep((rand()% 1000000));
	}
	
	return NULL;
}

void RunThreads(pthread_t* _threads, int _total, StartRoutine _startRoutine, TempControl* _tempControl)
{
	int i;
	for (i = 0 ; i < _total ; ++i)
	{
		pthread_create(&_threads[i], NULL, _startRoutine, (void*)_tempControl);
	}
}

void JoinThreads(pthread_t* _threads, int _total)
{
	int i;
	for (i = 0 ; i < _total ; ++i)
	{
		pthread_join(_threads[i], NULL);
	}
}

int main()
{
	TempControl tempControl;
	pthread_t weatherThreads[5];
	pthread_t mazganThreads[5];
	
	pthread_mutex_init(&tempControl.m_mutex, NULL);
	pthread_cond_init(&tempControl.m_cond, NULL);
	
	tempControl.m_shouldBreak = 0;
	tempControl.m_temperature = 20;
	
	RunThreads(weatherThreads, 5, (StartRoutine)Weather, &tempControl);
	RunThreads(mazganThreads, 5, (StartRoutine)Mazgan, &tempControl);
	
	sleep(60);
	
	pthread_mutex_lock(&tempControl.m_mutex);
	tempControl.m_shouldBreak = 1;
	pthread_mutex_unlock(&tempControl.m_mutex);
	pthread_cond_broadcast(&tempControl.m_cond);
	
	JoinThreads(weatherThreads, 5);
	JoinThreads(mazganThreads, 5);
	
	pthread_cond_destroy(&tempControl.m_cond);
	pthread_mutex_destroy(&tempControl.m_mutex);
	
	return 0;
}
