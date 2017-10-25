#ifndef __ACCOUNT_IMPL_H__
#define __ACCOUNT_IMPL_H__

class AccountImpl
{
	public:
		AccountImpl(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount);
		
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
		m_balance : int
		m_owner : string
		m_ID : unsigned int
		m_type : unsigned int
};














#endif /* #ifndef __ACCOUNT_IMPL_H__ */

