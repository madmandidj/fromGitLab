#ifndef __STOCK_ACCOUNT_H__
#define __STOCK_ACCOUNT_H__



class StockAccount
{
	public:
		StockAccount(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount)
		void virtual Tell();
		bool AddStock(unsigned int _numOfStock);
		bool RemoveStock(unsigned int _numOfStock);
	protected:
		
	private:
		size_t m_numOfStock;
};

















#endif /* #ifndef __STOCK_ACCOUNT_H__ */













