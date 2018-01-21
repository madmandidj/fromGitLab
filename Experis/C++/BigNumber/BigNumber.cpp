#include "BigNumber.h"
#include <algorithm>
const size_t INT_DIGITS = 10;




BigNumber& BigNumber::operator+ (const BigNumber& _bigNum)
{
	BigNumber tempBigNum;
	char tempChar1;
	char tempChar2;
	char carry;
	size_t index;
	std::string::iterator it1;
	std::string::iterator it2;
	
	std::reverse(m_str.begin(), m_str.end());
	
	std::reverse(_bigNum.m_str.begin(), _bigNum.m_str.end());	
}







std::ostream& operator<< (std::ostream& _os, const BigNumber& _bigNum)
{
	_os << _bigNum.m_str; /*TODO: Change this to GetBigNum because m_str is private*/
	
	return _os;
}



std::string& BigNumber::GetNumStr() const
{
	return m_str;
}
























