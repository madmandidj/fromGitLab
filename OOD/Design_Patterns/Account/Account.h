#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <string>
using namespace std;
class Observer;
class AccountImpl;

class Account : public Observer
{
	public:
		~Account()
		Account(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount)
		bool Deposit(unsigned int _amount) 
		bool Withdraw(unsigned int _amount)
		unsigned int GetBalance() const
		const string& GetOwner() const
		unsigned int GetID() const 
		unsigned int GetType() const
		void virtual Tell() 
	
	protected:
	
	private:
		AccountImpl* m_account
};










#endif /* #ifndef __ACCOUNT_H__ */
