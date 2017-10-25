#include "Bank.h"
#include "../Subject/Subject.h"
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


void Bank::DestroyBank()
{
	delete m_bank;
	
	m_bank = 0;
}


Bank::~Bank(){} 


bool Bank::CreateAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount, Subject* _subject)
{
	if (0 == _subject)
	{
		//handle NULL pointer
	}
	
	Account* account = new Account(_impl, _ID, _name, _amount, _subject);
	
	if (0 == account)
	{
		//handle new fail
	}
	
	m_accounts.insert(pair<string, Account*>(_impl, account));
	
	return true;
}


bool Bank::RemoveAccount(const string& _type, unsigned int _ID)
{
	pair<multimap<string, Account*>::iterator, multimap<string, Account*>::iterator> ret;
	
	ret = m_accounts.equal_range(_type);
	
	multimap<string, Account*>::iterator it;
	
	for (it = ret.first; it != ret.second; ++it)
	{
		if(_ID == it->second->GetID())
		{
			delete it->second;
			m_accounts.erase(it);
			break;
		}
	}
	
	return true;
}


void Bank::SummonPersonalAccountOwners()
{
	Notify("Personal");
}


void Bank::GiveBonusToFamilyAccounts()
{
	Notify("Family");
}


void Bank::InvestInStockAccounts()
{
	Notify("Stock");
}


