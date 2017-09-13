#include "Container.h"
#include "./HashMap/HashMap.h"
#include <string.h>		/* strcmp */


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
	
	while(c = *_key++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	
	return hash;
}






int SubscriberEqualityFunc(const Subscriber* _sub1, const Subscriber* _sub2)
{
	int result = 1;
	
	result = strcmp(_sub1->m_msisdn, _sub2->m_msisdn);
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


/*
void CDRDataDestroyFunc(void* _data)
{
	free(_data);
}
*/





Container* ContainerCreate(size_t _subscribersCapacity, size_t _operatorsCapacity)
{
	Container* cont;

	cont = malloc(sizeof(Container));
	if (!cont)
	{
		return NULL;
	}

	cont->m_subscribersHash = HashMapCreate(_subscribersCapacity, (HashFunction)CDRHashFunc, (EqualityFunction)SubscriberEqualityFunc);
	if (!cont->m_subscribersHash)	
	{
		free(cont);
		return NULL;
	}
	
	cont->m_operatorsHash = HashMapCreate(_operatorsCapacity, (HashFunction)CDRHashFunc, (EqualityFunction)OperatorEqualityFunc);
	if (!cont->m_subscribersHash)	
	{
		free(cont->m_subscribersHash);
		free(cont);
		return NULL;
	}
	
	return cont;
}






void ContainerDestroy(Container* _cont)
{
	HashMapDestroy(&_cont->m_subscribersHash, NULL, NULL);
	HashMapDestroy(&_cont->m_operatorsHash, NULL, NULL);
	free(_cont);
	
	return;
}







int	ContainerFindSubscriber(Container* _cont, Subscriber* _sub, Subscriber* _subFound)
{
	HashMapFind(_cont->m_subscribersHash, _sub->m_msisdn, (void**)&_subFound);
	if (NULL == _subFound)
	{
		return 0;
	}
	
	return 1;
}






int	ContainerFindOperator(Container* _cont, Operator* _oper, Operator* _operFound)
{
	MapResult mapErr;
	
	mapErr = HashMapFind(_cont->m_operatorsHash, (const void*)_oper->m_operatorMCCMNC, (void**)&_operFound);
	if (MAP_KEY_NOT_FOUND_ERROR == mapErr)
	{
		return 0;
	}
	
	return 1;
}







int ContainerUpdateSubscriber(Container* _cont, Subscriber* _sub)
{
	MapResult mapErr;
	Subscriber* foundSub;
	
	if (!_cont || !_sub)
	{
		return 0;
	}
	
	mapErr = HashMapFind(_cont->m_subscribersHash, _sub->m_msisdn, (void**)&foundSub);
	if (MAP_KEY_NOT_FOUND_ERROR == mapErr)
	{
		HashMapInsert(_cont->m_subscribersHash, _sub->m_msisdn, _sub);
		return 1;
	}
	
	foundSub->m_outVoiceWithinOp += _sub->m_outVoiceWithinOp;
	foundSub->m_inVoiceWithinOp += _sub->m_inVoiceWithinOp;
	foundSub->m_outVoiceOutsideOp += _sub->m_outVoiceOutsideOp;
	foundSub->m_inVoiceOutsideOp += _sub->m_inVoiceOutsideOp;
	foundSub->m_outSmsWithinOp += _sub->m_outSmsWithinOp;
	foundSub->m_inSmsWithinOp += _sub->m_inSmsWithinOp;
	foundSub->m_outSmsOutsideOp += _sub->m_outSmsOutsideOp;
	foundSub->m_inSmsOutsideOp += _sub->m_inSmsOutsideOp;
	foundSub->m_downloadMB += _sub->m_downloadMB;
	foundSub->m_uploadMB += _sub->m_uploadMB;
	
	return 1;
}






int ContainerUpdateOperator(Container* _cont, Operator* _oper)
{
	MapResult mapErr;
	Operator* foundOper;
	
	if (!_cont || !_oper)
	{
		return 0;
	}
	
	mapErr = HashMapFind(_cont->m_operatorsHash, (const void*)_oper->m_operatorMCCMNC, (void**)&foundOper);
	if (MAP_KEY_NOT_FOUND_ERROR == mapErr)
	{
		HashMapInsert(_cont->m_operatorsHash, _oper->m_operatorMCCMNC, _oper);
		return 1;
	}
	
	foundOper->m_outVoice += _oper->m_outVoice;
	foundOper->m_inVoice += _oper->m_inVoice;
	foundOper->m_outSms += _oper->m_outSms;
	foundOper->m_inSms += _oper->m_inSms;
	foundOper->m_downloadMB += _oper->m_downloadMB;
	foundOper->m_uploadMB += _oper->m_uploadMB;
	
	return 1;
}


















