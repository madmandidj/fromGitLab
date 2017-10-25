#include "PersonalAccount.h"
#include "../AccountImpl/AccountImpl.h"
using namespace std;

PersonalAccount::PersonalAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount)
	: AccountImpl(_impl, _name, _ID, _amount) {}
	
PersonalAccount::~PersonalAccount(){}	

