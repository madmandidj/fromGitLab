#include "asciiIO_t.h"
#include <string>
#include <string.h>


asciiIO_t::asciiIO_t(){}


asciiIO_t::asciiIO_t(const string& _fileName, const string& _mode) : virtIO_t(_fileName, _mode){}


asciiIO_t::~asciiIO_t(){}


bool asciiIO_t::IsReadMode() const
{
	string mode = GetMode();
	
	if (!strcmp(mode.c_str(), "r") || !strcmp(mode.c_str(), "r+") || !strcmp(mode.c_str(), "w+"))
	{
		return true;
	}
	
	return false;
}


bool asciiIO_t::IsWriteMode() const
{
	string mode = GetMode();
	
	if (!strcmp(mode.c_str(), "w") || !strcmp(mode.c_str(), "r+") || !strcmp(mode.c_str(), "w+"))
	{
		return true;
	}
	
	return false;
}


asciiIO_t& asciiIO_t:: operator>> (char& _char)
{
	return MyRead(_char, "%c");
}


asciiIO_t& asciiIO_t:: operator<< (const char& _char)
{
	return MyWrite(_char, "%c");
}


asciiIO_t& asciiIO_t:: operator>> (int& _int)
{
	return MyRead(_int, "%d");
}


asciiIO_t& asciiIO_t:: operator<< (const int& _int)
{
	return MyWrite(_int, "%d");
}


asciiIO_t& asciiIO_t:: operator>> (float& _float)
{
	return MyRead(_float, "%f");
}


asciiIO_t& asciiIO_t:: operator<< (const float& _float)
{
	return MyWrite(_float, "%f");
}


//Not used
size_t asciiIO_t::GetNumOfIntDigits(int _int) const
{
	int numOfDigits = 0;
	
	while (_int / 10 > 0)
	{
		++numOfDigits;
		
		_int /= 10;
	}
	
	++numOfDigits;
	
	return numOfDigits;
}


