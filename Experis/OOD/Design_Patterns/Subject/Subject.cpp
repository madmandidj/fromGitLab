#include "Subject.h"
#include "../Observer/Observer.h"
#include <map>

using namespace std;


Subject::Subject(){}


Subject::~Subject(){}


void Subject::Attach(const string& _accountType, Observer* _observer)
{
	if (0 == _observer)
	{
		//handle null pointer
	}	
	
	m_observers.insert(pair<string, Observer*>(_accountType, _observer));
}


void Subject::Detach(const string& _accountType, Observer* _observer)
{
	if (0 == _observer)
	{
		//handle null pointer
	}
	
	pair<multimap<string, Observer*>::iterator, multimap<string, Observer*>::iterator> ret;
	
	ret = m_observers.equal_range(_accountType);
	
	for (multimap<string, Observer*>::iterator it=ret.first; it != ret.second; ++it)
	{
		if(_observer == it->second)
		{
			m_observers.erase(it);
			break;
		}
	}
	
	return;
}


void Subject::Notify(const string& _accountType)
{
	pair<multimap<string, Observer*>::iterator, multimap<string, Observer*>::iterator> ret;
	
	ret = m_observers.equal_range(_accountType);
	
	for (multimap<string, Observer*>::iterator it=ret.first; it != ret.second; ++it)
	{
		it->second->Update(this);
	}
}









