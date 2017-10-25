#ifndef __PERSONAL_ACCOUNT_H__
#define __PERSONAL_ACCOUNT_H__


#include "../AccountImpl/AccountImpl.h"


class PersonalAccount : public AccountImpl
{
	public:
		~PersonalAccount();
		PersonalAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount);
		void virtual Tell();
	protected:
	
	private:
	
};
















#endif /* #ifndef __PERSONAL_ACCOUNT_H__ */












