#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "../Observer/Observer.h"
#include <string>

using namespace std;
class Subject
class AccountImpl;

class Account : public Observer
{
	public:
		~Account()
		Account(const string& _impl, unsigned int _ID, const string& _name, unsigned int _amount, Subject* _subject);
		bool Deposit(unsigned int _amount); 
		bool Withdraw(unsigned int _amount);
		unsigned int GetBalance() const;
		const string& GetOwner() const;
		unsigned int GetID() const; 
		const string& GetType() const;
		virtual void Tell(); 
		virtual void Update(Subject* _subject);
	
	protected:
		// Inherited from Observer:
		// Subject* m_subject
	private:
		AccountImpl* m_account
};










#endif /* #ifndef __ACCOUNT_H__ */
