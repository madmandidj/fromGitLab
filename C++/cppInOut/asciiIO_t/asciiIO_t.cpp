#include "asciiIO_t.h"
#include <string>

asciiIO_t::asciiIO_t(){}

asciiIO_t::asciiIO_t(const string& _fileName, const string& _mode) : virtIO_t(_fileName, _mode){}

asciiIO_t::~asciiIO_t(){}

asciiIO_t& asciiIO_t:: operator>> (char& _char)
{
	fscanf(m_fp, "%c", &_char);
}

asciiIO_t& asciiIO_t:: operator<< (char& _char)
{
	fprintf(m_fp, "%c", _char);
}






























