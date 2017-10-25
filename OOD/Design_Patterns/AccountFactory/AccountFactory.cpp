
#include "AccountFactory.h"
#include "../AccountImpl/AccountImpl.h"
#include "../PersonalAccount/PersonalAccount.h"
#include "../FamilyAccount/FamilyAccount.h"
#include "../StockAccount/StockAccount.h"
#include <string>

using namespace std;

AccountImpl* AccountFactory::Create(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount)
{
	AccountImpl* ptrAccnt = 0;
	
	if ("Personal" == _impl)
	{
		ptrAccnt = new PersonalAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount);
	}
	else if ("Family" == _impl)
	{
		ptrAccnt = new FamilyAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount);
	}
	else if ("Stock" == _impl)
	{
		ptrAccnt = new StockAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount);
	}
	
	return ptrAccnt;
}


AccountFactory::AccountFactory(){}

AccountFactory::~AccountFactory(){}
















