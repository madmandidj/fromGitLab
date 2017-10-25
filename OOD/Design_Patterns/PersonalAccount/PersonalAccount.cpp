#include "PersonalAccount.h"
#include "../AccountImpl/AccountImpl.h"

PersonalAccount::PersonalAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount)
	: AccountImpl(_impl, _ID, _name, _amount) {}
	
PersonalAccount::~PersonalAccount(){}	

PersonalAccount::Tell()
{
	//What to tell here?
}
