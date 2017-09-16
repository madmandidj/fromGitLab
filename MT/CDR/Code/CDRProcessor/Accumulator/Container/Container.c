#include "Container.h"
#include <string.h>		/* strcmp */

struct Container
{
	size_t 		m_capacity;
	HashMap*	m_storage;
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

	cont->m_capacity = _capacity;
	
	cont->m_storage = HashMapCreate(cont->m_capacity, (HashFunction)CDRHashFunc, _func);
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










