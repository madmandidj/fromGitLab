#include "asciiIO_t.h"
#include <string>



asciiIO_t::asciiIO_t(){}


asciiIO_t::asciiIO_t(const string& _fileName, const string& _mode) : virtIO_t(_fileName, _mode){}


asciiIO_t::~asciiIO_t(){}


asciiIO_t& asciiIO_t:: operator>> (char& _char)
{
	if ((0 != m_fp) && (GetMode() == "r" || GetMode() == "r+" || GetMode() == "rw" || GetMode() != "rw+"))
	{
		int result = fscanf(m_fp, "%c", &_char);
	
		if (sizeof(char) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


asciiIO_t& asciiIO_t:: operator<< (const char& _char)
{
	if ((0 != m_fp) && (GetMode() == "w" || GetMode() == "w+" || GetMode() == "rw" || GetMode() != "rw+"))
	{
		int result = fprintf(m_fp, "%c", _char);
		
		if (sizeof(char) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}






























