#include "Bank.h"
#include "../Account/Account.h"

using namespace std;


Bank* Bank::m_bank = 0;


Bank* Bank::CreateBank()
{
	if (0 == m_bank)
	{
		m_bank = new Bank;
	}
	
	return m_bank;
}


Bank::~Bank()
{
	delete m_bank;
	
	m_bank = 0;
} 


bool CreateAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount, Subject* _subject)
{
	//check if account already exists
	//check subject not null
	Account* account = new Account(_impl, _ID, _name, _amount, _subject);
	
	m_accounts->insert(pair<string, Account*>(_impl, account));
	
	return true;
}


bool RemoveAccount(const string& _type, unsigned int _ID)
{
	pair<multimap<string, Account*>::iterator, multimap<string, Account*>::iterator> ret;
	
	ret = m_accounts.equals_range(_type);
	
	for (multimap<string, Account*>::iterator it=ret.first; it != ret.second; ++it)
	{
		if(_ID == it->second)
		{
			m_accounts->erase(it);
			break;
		}
	}
	
	return true;
}













