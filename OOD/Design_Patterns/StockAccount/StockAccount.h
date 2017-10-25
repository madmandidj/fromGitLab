#ifndef __STOCK_ACCOUNT_H__
#define __STOCK_ACCOUNT_H__

#include "../AccountImpl/AccountImpl.h"

class StockAccount : public AccountImpl
{
	public:
		StockAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount);
		bool AddStock(unsigned int _numOfStock);
		bool RemoveStock(unsigned int _numOfStock);
		void virtual Tell();
	protected:
		~StockAccount();
	private:
		size_t m_numOfStock;
};













#endif /* #ifndef __STOCK_ACCOUNT_H__ */













