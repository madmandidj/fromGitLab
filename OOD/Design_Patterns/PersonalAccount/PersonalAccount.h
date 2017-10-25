#ifndef __PRIVATE_ACCOUNT_H__
#define __PRIVATE_ACCOUNT_H__


#include "AccountImpl.h"


class PersonalAccount : public AccountImpl
{
	public:
		PersonalAccount(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount)
		~PersonalAccount();
		void virtual Tell();
	protected:
	
	private:
	
};
















#endif /* #ifndef __PRIVATE_ACCOUNT_H__ */












