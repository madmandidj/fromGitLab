#include "../Subject/Subject.h"
#include "../AccountFactory/AccountFactory.h"
#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount, Subject* _subject)
{
	m_account = AccountFactory::Create(_impl, _ID, _name, _amount);
	m_subject = _subject; //Check if null pointer
	m_subject->Attach(_impl, this);
}


Account::~Account()
{
	m_subject->Detach(GetType(), this);
	delete m_account;
	m_account = 0;
}

void Account::Tell()
{
	// What to print here?
}


const string& Account::GetType() const
{
	return (const string&) m_account->m_type;
}


void Account::Update(Subject* _subject)
{
	if (_subject == m_subject)
	{
		cout << GetType() << "account has received update" << endl;
	}
}









