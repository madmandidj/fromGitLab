#include "AccountImpl.h"
#include <string>

using namespace std;


AccountImpl::AccountImpl(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount)
{
	m_type = _impl;
	m_owner = _name;
	m_balance = _amount;
	m_ID = _ID;
}


AccountImpl::~AccountImpl(){}

































