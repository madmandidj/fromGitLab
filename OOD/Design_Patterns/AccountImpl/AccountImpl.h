#ifndef __ACCOUNT_IMPL_H__
#define __ACCOUNT_IMPL_H__

#include <string>

using namespace std;

class AccountImpl
{
	public:
		AccountImpl(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount);
		virtual ~AccountImpl();
		bool Deposit(unsigned int _amount);
		bool Withdraw(unsigned int _amount);
		unsigned int GetBalance() const;
		const string& GetOwner() const;
		unsigned int GetID() const;
		const string& GetType() const;
		virtual void Tell() = 0;
		
	protected:
		
	private:
		string 			m_type;
		string 			m_owner;
		int 			m_balance;
		unsigned int 	m_ID;	
};














#endif /* #ifndef __ACCOUNT_IMPL_H__ */

