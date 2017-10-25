#include "Account.h"
#include "../Subject/Subject.h"
#include "../AccountFactory/AccountFactory.h"
#include "../AccountImpl/AccountImpl.h"
#include <iostream>

using namespace std;

Account::Account(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount, Subject* _subject)
{
	if (0 == _subject)
	{
		//handle null pointer
	}
	
	m_account = AccountFactory::Create(_impl, _name, _ID, _amount);
	m_subject = _subject;
	m_subject->Attach(_impl, this);
}


Account::~Account()
{
	m_subject->Detach(GetType(), this);
	delete m_account;
	m_account = 0;
}


const string& Account::GetType() const
{
	return m_account->GetType();
}


unsigned int Account::GetID() const
{
	return m_account->GetID();
}


void Account::Update(Subject* _subject)
{
	if (0 == _subject)
	{
		//handle NULL pointer
	}
	
	if (_subject == m_subject)
	{
		cout << GetType() << "account has received update" << endl;
	}
}









