#include "Container.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>		/* strcmp */



struct Container
{
	HashMap*		m_storage;
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
	
	if (!_func)
	{
		return NULL;
	}

	cont = malloc(sizeof(Container));
	if (!cont)
	{
		return NULL;
	}
	
	cont->m_storage = HashMapCreate(_capacity, (HashFunction)CDRHashFunc, _func);
	if (!cont->m_storage)	
	{
		free(cont);
		
		return NULL;
	}
	
	return cont;
}



void ContainerDestroy(Container* _cont)
{
	HashMapDestroy(&_cont->m_storage, NULL, NULL);

	free(_cont);
	
	return;
}



int	ContainerGetElement(Container* _cont, char* _key, void** _elementFound)
{
	MapResult mapErr;
	
	mapErr = HashMapFind(_cont->m_storage, _key, _elementFound);
	
	if (MAP_SUCCESS != mapErr)
	{
		return 0;
	}
	
	return 1;
}



int ContainerInsertElement(Container* _cont, char* _key, void* _element)
{
	MapResult mapErr;
	
	mapErr = HashMapInsert(_cont->m_storage, _key, _element);
	
	if (MAP_SUCCESS != mapErr)
	{
		return 0;
	}

	return 1;
}



int PrintAllSubscribers(const void* _key, Subscriber* _sub, void* _context)
{

	printf("%s,%s,%u,%u,%u,%u,%u,%u,%u,%u,%f,%f\n", _sub->m_imsi, _sub->m_msisdn, _sub->m_outVoiceWithinOp, _sub->m_inVoiceWithinOp, _sub->m_outVoiceOutsideOp, _sub->m_inVoiceOutsideOp, _sub->m_outSmsWithinOp, _sub->m_inSmsWithinOp, _sub->m_outSmsOutsideOp, _sub->m_inSmsOutsideOp, _sub->m_downloadMB, _sub->m_uploadMB);
	
	return 1;
}



/*
TODO: change this so can be used to print all operators as well. container shouldnt know about subscriber so maybe accumulator should send func
*/
size_t ContainerPrintAllElements(Container* _cont)
{
	return HashMapForEach(_cont->m_storage, (KeyValueActionFunction)PrintAllSubscribers, NULL);
}





