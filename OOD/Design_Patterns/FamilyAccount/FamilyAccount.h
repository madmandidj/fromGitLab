#ifndef __FAMILY_ACCOUNT_H__
#define __FAMILY_ACCOUNT_H__

#include <set>
#include "../AccountImpl/AccountImpl.h"

class FamilyAccount : public AccountImpl
{
	public:
		~FamilyAccount();
		FamilyAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount);
		bool AddFamilyMember(unsigned int _ID);
		bool RemoveFamilyMember(unsigned int _ID);
		void virtual Tell();
	protected:
	
	private:
		set<unsigned int> m_familyID;
};





























#endif /* #ifndef __FAMILY_ACCOUNT_H__ */

