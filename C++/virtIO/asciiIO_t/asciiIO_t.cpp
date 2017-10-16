#include "asciiIO_t.h"
#include <string>
#include <string.h>



asciiIO_t::asciiIO_t(){}


asciiIO_t::asciiIO_t(const string& _fileName, const string& _mode) : virtIO_t(_fileName, _mode){}


asciiIO_t::~asciiIO_t(){}


bool asciiIO_t::IsReadMode() const
{
	string mode = GetMode();
	
	if (!strcmp(mode.c_str(), "r") || !strcmp(mode.c_str(), "r+") || !strcmp(mode.c_str(), "rw") || !strcmp(mode.c_str(), "rw+"))
	{
		return true;
	}
	
	return false;
}


bool asciiIO_t::IsWriteMode() const
{
	string mode = GetMode();
	
	if (!strcmp(mode.c_str(), "w") || !strcmp(mode.c_str(), "w+") || !strcmp(mode.c_str(), "rw") || !strcmp(mode.c_str(), "rw+"))
	{
		return true;
	}
	
	return false;
}

asciiIO_t& asciiIO_t:: operator>> (char& _char)
{
	if ((0 != m_fp) && (IsReadMode()))
	{
		int result = fscanf(m_fp, "%c", &_char);
	
		if (1 != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


asciiIO_t& asciiIO_t:: operator<< (const char& _char)
{
	if ((0 != m_fp) && (IsWriteMode()))
	{
		int result = fprintf(m_fp, "%c", _char);
		
		if (sizeof(char) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


asciiIO_t& asciiIO_t:: operator>> (int& _int)
{
	if ((0 != m_fp) && (IsReadMode()))
	{
		int result = fscanf(m_fp, "%d", &_int);
	
		if (1 != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


asciiIO_t& asciiIO_t:: operator<< (const int& _int)
{
	if ((0 != m_fp) && (IsWriteMode()))
	{
		int result = fprintf(m_fp, "%d", _int);
		
		if (sizeof(int) != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}






























