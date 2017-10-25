#ifndef __FAMILY_ACCOUNT_H__
#define __FAMILY_ACCOUNT_H__


class FamilyAccount
{
	public:
		~FamilyAccount();
		FamilyAccount(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount);
		void virtual Tell();
		bool AddFamilyMember(unsigned int _ID);
		bool RemoveFamilyMember(unsigned int _ID);
	protected:
	
	private:
		vector<unsigned int> m_familyID;
};





























#endif /* #ifndef __FAMILY_ACCOUNT_H__ */

