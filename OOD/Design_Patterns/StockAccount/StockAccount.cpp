#include "StockAccount.h"

StockAccount::StockAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount) : AccountImpl(_impl, _name, _ID, _amount) {}
	

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


void StockAccount::Tell()
{
	//What to tell here?
}


