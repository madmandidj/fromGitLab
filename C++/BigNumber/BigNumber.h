#ifndef __BIG_NUMBER_H__
#define __BIG_NUMBER_H__

#include <stdio.h>
#include <iostream> 
#include <string> // std::string, std::stoi

class BigNumber
{
	public:
		BigNumber();
		
		BigNumber(const char* _str);
		
		BigNumber(int _num);
		
		BigNumber(const BigNumber& _bigNum);
		
		~BigNumber();
		
		BigNumber& operator= (const BigNumber& _bigNum);
	
		BigNumber& operator= (int _num);
		
		bool operator== (const BigNumber& _bigNum) const;	
	
		bool operator> (const BigNumber& _bigNum) const;
		
		bool operator< (const BigNumber& _bigNum) const;	
		
		BigNumber& operator+ (const BigNumber& _bigNum);
		
		BigNumber& operator- (const BigNumber& _bigNum);

	private:
		std::string m_str;
};

std::ostream& operator<< (std::ostream& _os, const BigNumber& _bigNum);

std::istream& operator>> (std::istream& _is, BigNumber& _bigNum);


inline BigNumber::BigNumber()
{
	m_str.assign("0");
}


inline BigNumber::BigNumber(const char* _str)
{
	m_str.assign(_str);
}


inline BigNumber::BigNumber(int _num)
{
//	m_str.assign(std::to_string(_num));
	char buf[11];
	
	sprintf(buf, "%d", _num);
	
	m_str.assign(buf);
}


inline BigNumber::BigNumber(const BigNumber& _bigNum)
{
	m_str.assign(_bigNum.m_str);
}


inline BigNumber::~BigNumber(){}


inline BigNumber& BigNumber::operator= (const BigNumber& _bigNum)
{
	m_str.assign(_bigNum.m_str);
	
	return *this;
}


inline BigNumber& BigNumber::operator= (int _num)
{
//	m_str.assign(std::to_string(_num));
	char buf[11];
	
	sprintf(buf, "%d", _num);
	
	m_str.assign(buf);

	
	return *this;
}


inline bool BigNumber::operator== (const BigNumber& _bigNum) const
{
	return (0 == m_str.compare(_bigNum.m_str)) ? true : false;
}









#endif /* #ifndef __BIG_NUMBER_H__ */



