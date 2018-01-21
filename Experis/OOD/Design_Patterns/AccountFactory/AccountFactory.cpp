#include "AccountFactory.h"
#include "../PersonalAccount/PersonalAccount.h"
#include "../FamilyAccount/FamilyAccount.h"
#include "../StockAccount/StockAccount.h"
#include <string>

using namespace std;

AccountImpl* AccountFactory::Create(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount)
{
	AccountImpl* ptrAccnt = 0;
	
	if ("Personal" == _impl)
	{
		ptrAccnt = new PersonalAccount(_impl, _name, _ID, _amount);
	}
	else if ("Family" == _impl)
	{
		ptrAccnt = new FamilyAccount(_impl, _name, _ID, _amount);
	}
	else if ("Stock" == _impl)
	{
		ptrAccnt = new StockAccount(_impl, _name, _ID, _amount);
	}
	
	return ptrAccnt;
}


AccountFactory::AccountFactory(){}

AccountFactory::~AccountFactory(){}
















