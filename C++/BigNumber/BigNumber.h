#ifndef __BIG_NUMBER_H__
#define __BIG_NUMBER_H__

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

ostream&	operator<< (ostream& _os, const BigNumber& _bigNum);

istream&	operator>> (istream& _is, BigNumber& _bigNum);


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
	m_str.assign(std::to_string(_num));
}


inline BigNumber::BigNumber(const BigNumber& _bigNum)
{
	m_str.assign(_bigNum.m_str);
}


inline BigNumber::~BigNumber(){}


inline BigNumber& operator= (const BigNumber& _bigNum)
{
	m_str.assign(_bigNum.m_str);
	
	return *this;
}


inline BigNumber& operator= (int _num)
{
	m_str.assign(std::to_string(_num));
	
	return *this;
}


inline bool operator== (const BigNumber& _bigNum) const
{
	return (0 == strcmp(m_str, _bigNum.m_str)) ? true : false;
}









#endif /* #ifndef __BIG_NUMBER_H__ */



