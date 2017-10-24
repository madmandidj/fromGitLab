#ifndef __BANK_H__
#define __BANK_H__

#include<map>

class AccntImpl;

class Bank
{
	enum AccountType
	{
		Personal,
		Family,
		StockX
	};
	
	public:
		static Bank& CreateBank();
		virtual void Attach(Observer*);
    	virtual void Detach(Observer*);
    	
    protected:
    	virtual ~Bank();
		
	private:
		static Bank m_bank;
		multimap<string, AccntImpl*> m_accounts;
		vector<Observer*> m_observers;
		
	private:
		Bank();
		Bank(const Bank& _bank);
		Bank& operator= (Bank& _bank);
}










#endif /* #ifndef __BANK_H__ */



