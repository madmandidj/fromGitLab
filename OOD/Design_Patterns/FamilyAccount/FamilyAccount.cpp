#include "FamilyAccount.h"
#include "../AccountImpl/AccountImpl.h"
#include <set>


FamilyAccount::FamilyAccount(const string& _Impl, unsigned int _ID, const string& _name, unsigned int _amount) 
	: AccountImpl(_impl, _ID, _name, _amount){}


FamilyAccount::~FamilyAccount(){}


bool FamilyAccount::AddFamilyMember(unsigned int _ID)
{
	pair<set<unsigned int>::iterator, bool> ret = m_familyID.insert(_ID);
	
	return ret.second;
}


bool FamilyAccount::RemoveFamilyMember(unsigned int _ID)
{
	return m_familyID.erase(_ID);
}










