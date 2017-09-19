#include "Container.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>		/* strcmp */

struct Container
{
/*	size_t 		m_capacity;*/
	HashMap*		m_storage;
/*	pthread_mutex_t m_mutex;*/
};




/*
Hash function adapted from:
https://stackoverflow.com/questions/7666509/hash-function-for-string
*/

size_t CDRHashFunc(char* _key)
{
	unsigned long hash = 5381;
	int c;
	
	while((c = *_key++))
	{
		hash = ((hash << 5) + hash) + (unsigned long)c;
	}
	
	return hash;
}



Container* ContainerCreate(size_t _capacity, EqualityFunction _func)
{
	Container* cont;

	cont = malloc(sizeof(Container));
	if (!cont)
	{
		return NULL;
	}

/*	cont->m_capacity = _capacity;*/

/*	if (pthread_mutex_init(&cont->m_mutex, NULL))*/
/*	{*/
/*		free(cont);*/
/*		return NULL;*/
/*	}*/
	
	cont->m_storage = HashMapCreate(_capacity, (HashFunction)CDRHashFunc, _func);
	if (!cont->m_storage)	
	{
/*		pthread_mutex_destroy(&cont->m_mutex);*/
		free(cont);
		return NULL;
	}
	
	return cont;
}




void ContainerDestroy(Container* _cont)
{
	HashMapDestroy(&_cont->m_storage, NULL, NULL);
/*	pthread_mutex_destroy(&_cont->m_mutex);*/
	free(_cont);
	
	return;
}



int	ContainerGetElement(Container* _cont, char* _key, void** _elementFound)
{
	MapResult mapErr;
	
/*	pthread_mutex_lock(&_cont->m_mutex);*/
/*	printf("Before hashmapFind\n");*/
	mapErr = HashMapFind(_cont->m_storage, _key, _elementFound);
/*	printf("After hashmapFind\n");*/
/*	pthread_mutex_unlock(&_cont->m_mutex);*/
	
	if (MAP_SUCCESS != mapErr)
	{
		return 0;
	}
	
	return 1;
}



int ContainerInsertElement(Container* _cont, char* _key, void* _element)
{
	MapResult mapErr;
	
/*	pthread_mutex_lock(&_cont->m_mutex);*/
	
	mapErr = HashMapInsert(_cont->m_storage, _key, _element);
	
/*	pthread_mutex_unlock(&_cont->m_mutex);*/
	
	if (MAP_SUCCESS != mapErr)
	{
		return 0;
	}

	return 1;
}



int PrintAllSubscribers(const void* _key, Subscriber* _sub, void* _context)
{
/*	printf("%s\n",_sub->m_msisdn);*/

	printf("%s,%s,%u,%u,%u,%u,%u,%u,%u,%u,%f,%f\n", _sub->m_imsi, _sub->m_msisdn, _sub->m_outVoiceWithinOp, _sub->m_inVoiceWithinOp, _sub->m_outVoiceOutsideOp, _sub->m_inVoiceOutsideOp, _sub->m_outSmsWithinOp, _sub->m_inSmsWithinOp, _sub->m_outSmsOutsideOp, _sub->m_inSmsOutsideOp, _sub->m_downloadMB, _sub->m_uploadMB);
	
	return 1;
}


size_t ContainerPrintAllElements(Container* _cont)
{
	return HashMapForEach(_cont->m_storage, (KeyValueActionFunction)PrintAllSubscribers, NULL);
}







