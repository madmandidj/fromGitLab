#include "binIO_t.h"
#include <string>


binIO_t::binIO_t(){}


binIO_t::binIO_t(const string& _fileName, const string& _mode) : virtIO_t(_fileName, _mode){}


binIO_t::~binIO_t(){}


binIO_t& binIO_t:: operator>> (char& _char)
{
	if ((0 != m_fp) && (GetMode() == "rb" || GetMode() == "r+b" || GetMode() == "rwb" || GetMode() != "rw+b"))
	{
		int result = fread(&_char, sizeof(char), 1, m_fp);
	
		if (1 != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


binIO_t& binIO_t:: operator<< (const char& _char)
{
	if ((0 != m_fp) && (GetMode() == "wb" || GetMode() == "w+b" || GetMode() == "rwb" || GetMode() != "rw+b"))
	{
		int result = fwrite(&_char, sizeof(char), 1, m_fp);
		
		if (sizeof(char) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}






























