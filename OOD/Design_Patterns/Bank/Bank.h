#ifndef __BANK_H__
#define __BANK_H__

#include "../Subject/Subject.h"
#include <map>
#include <string>
using namespace std;
class Subject;

class Bank : public Subject
{
	public:
		static Bank* CreateBank();
		static void DestroyBank();
		bool CreateAccount(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount, Subject* _subject)
		bool RemoveAccount(const string& _type, unsigned int _ID)
		bool Deposit(unsigned int _ID, unsigned int _amount)
		bool Withdraw(unsigned int _ID, unsigned int _amount)
		void InvestInStockAccounts()
		void GiveBonusToFamilyAccounts() const 
		void SummonPersonalAccountOwners() const
    	
    protected:
    	virtual ~Bank();
		
	private:
		static Bank* m_bank;
		multimap<string, Account*> m_accounts;
		
	private:
		Bank();
		Bank(const Bank& _bank);
		Bank& operator= (Bank& _bank);
}







#endif /* #ifndef __BANK_H__ */



