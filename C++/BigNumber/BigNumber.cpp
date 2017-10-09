#include "BigNumber.h"

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
	
//	std::reverse(m_str.begin(), m_str.end());
	
//	std::reverse(_bigNum.m_str.begin(), _bigNum.m_str.end());
	
	/*
	reverse string
	*/
	it1 = m_str.begin();
	it2 = m_str.end();
	while (it1 < it2)
	{
//		m_str.replace(
	}
	
	
}







std::ostream& operator<< (std::ostream& _os, const BigNumber& _bigNum)
{
	_os << _bigNum.m_str; /*TODO: Change this to GetBigNum because m_str is private*/
	
	return _os;
}


























