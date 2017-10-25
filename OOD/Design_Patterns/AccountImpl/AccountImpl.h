#ifndef __ACCOUNT_IMPL_H__
#define __ACCOUNT_IMPL_H__

class AccountImpl
{
	public:
		AccountImpl(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount);
		bool Deposit(unsigned int _amount);
		bool Withdraw(unsigned int _amount);
		unsigned int GetBalance() const;
		const string& GetOwner() const;
		unsigned int GetID() const;
		unsigned int GetType() const;
		virtual void Tell() = 0;
		
	protected:
		virtual ~AccountImpl();
		
	private:
		string 			m_type;
		string 			m_owner;
		int 			m_balance;
		unsigned int 	m_ID;	
};














#endif /* #ifndef __ACCOUNT_IMPL_H__ */

