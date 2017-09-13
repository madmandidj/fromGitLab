#include "Container.h"
#include "./HashMap/Hashmap.h"


struct Container
{
	size_t 		m_subscribersCapacity;
	size_t 		m_operatorsCapacity;
	HashMap*	m_subscribersHash;
	HashMap*	m_operatorsHash;
};


/*
Hash function adapted from:
https://stackoverflow.com/questions/7666509/hash-function-for-string
*/
size_t CDRHashFunc(char* _key)
{
	unsigned long hash = 5381;
	int c;
	
	while(c = *str++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	
	return hash;
}




int SubscriberEqualityFunc(const Subscriber* _sub1, const Subscriber* _sub2)
{
	int result = 1;
	
	result = strcmp(_sub1->m_imsi, _sub2->m);
	if (0 != result)
	{
		return 0;
	}
	
	return 1;
}




int OperatorEqualityFunc(const Operator* _oper1, const Operator* _oper2)
{
	if (_oper1->m_operatorMCCMNC != _oper2->m_operatorMCCMNC)
	{
		return 0;
	}
	
	return 1;
}



void CDRDestroyFunc(void* _)






Container* ContainerCreate(size_t _subscribersCapacity, size_t _operatorsCapacity)
{
	Container* cont;

	cont = malloc(sizeof(Container));
	if (!cont)
	{
		return NULL;
	}

	cont->m_subscribersHash = HashMapCreate(_subscribersCapacity, CDRHashFunc, SubscriberEqualityFunc);
	if (!cont->m_subscribersHash)	
	{
		free(cont);
		return NULL;
	}
	
	cont->m_operatorsHash = HashMapCreate(_operatorsCapacity, CDRHashFunc, OperatorEqualityFunc);
	if (!cont->m_subscribersHash)	
	{
		free(cont->m_subscribersHash);
		free(cont);
		return NULL;
	}
	
	return cont;
}
























