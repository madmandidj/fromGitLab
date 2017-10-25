#include "../AccountImpl/AccountImpl.h"
#include "StockAccount.h"

StockAccount::StockAccount(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount)
	: AccountImpl(_impl, _ID, _name, _amount) {}
	

StockAccount::~StockAccount(){}


bool StockAccount::AddStock(unsigned int _numOfStock)
{
	m_numOfStock += _numOfStock;
	
	return true;
}


bool StockAccount::RemoveStock(unsigned int _numOfStock)
{
	if (_numOfStock > m_numOfStock)
	{
		return false;
	}
	
	m_numOfStock += _numOfStock;
	
	return true;
}





