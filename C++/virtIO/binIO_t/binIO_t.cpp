#include "binIO_t.h"
#include <string>
#include <string.h>


binIO_t::binIO_t(){}


binIO_t::binIO_t(const string& _fileName, const string& _mode) : virtIO_t(_fileName, _mode){}


binIO_t::~binIO_t(){}


bool binIO_t::IsReadMode() const
{
	string mode = GetMode();
	
	if (!strcmp(mode.c_str(), "rb") || !strcmp(mode.c_str(), "r+b") || !strcmp(mode.c_str(), "rwb") || !strcmp(mode.c_str(), "rw+b"))
	{
		return true;
	}
	
	return false;
}


bool binIO_t::IsWriteMode() const
{
	string mode = GetMode();
	
	if (!strcmp(mode.c_str(), "wb") || !strcmp(mode.c_str(), "w+b") || !strcmp(mode.c_str(), "rwb") || !strcmp(mode.c_str(), "rw+b"))
	{
		return true;
	}
	
	return false;
}


binIO_t& binIO_t:: operator>> (char& _char)
{
	if ((0 != m_fp) && (IsReadMode()))
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
	if ((0 != m_fp) && (IsWriteMode()))
	{
		int result = fwrite(&_char, sizeof(char), 1, m_fp);
		
		if (sizeof(char) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


binIO_t& binIO_t:: operator>> (int& _int)
{
	if ((0 != m_fp) && (IsReadMode()))
	{
		int result = fread(&_int, sizeof(int), 1, m_fp);
	
		if (1 != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


binIO_t& binIO_t:: operator<< (const int& _int)
{
	if ((0 != m_fp) && (IsWriteMode()))
	{
		int result = fwrite(&_int, sizeof(int), 1, m_fp);
		
		if (sizeof(char) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}






























