#include "FamilyAccount.h"
#include "../AccountImpl/AccountImpl.h"
#include <set>
using namespace std;

FamilyAccount::FamilyAccount(const string& _impl, const string& _name, unsigned int _ID, unsigned int _amount) 
	: AccountImpl(_impl, _name, _ID, _amount){}


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



