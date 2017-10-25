#ifndef __STOCK_ACCOUNT_H__
#define __STOCK_ACCOUNT_H__

#include "../AccountImpl/AccountImpl.h"
#include <string>
using namespace std;

class StockAccount : public AccountImpl
{
	public:
		~StockAccount();
		StockAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount);
		bool AddStock(unsigned int _numOfStock);
		bool RemoveStock(unsigned int _numOfStock);
	protected:
		
	private:
		size_t m_numOfStock;
};







#endif /* #ifndef __STOCK_ACCOUNT_H__ */













