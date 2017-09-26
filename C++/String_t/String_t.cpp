#include "String_t.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INIT_STRING_CAPACITY 128


/*
private String_t Default constructor
*/
void String_t::DefaultCTOR()
{
	m_length = 0;
	
	m_str = new char[1];
	
	if(0 == m_str)
	{
		/* TODO: Do something here*/
	}
	
	m_str[m_length] = '\0';
	
	return;
}



/*
String_t Default constructor
*/
String_t::String_t()
{
	this->DefaultCTOR();
	
	return;
}



/*
String_t Destructor
*/
String_t::~String_t()
{
	delete[] m_str;
	
	return;
}



/*
String_t Constructor with const char*
*/
String_t::String_t(const char* _str)
{
	if (NULL == _str)
	{
		this->DefaultCTOR();
		
		return; 
	}
	
	m_length = strlen(_str);
	
	m_str = new char[m_length + 1];
	
	if(0 == m_str)
	{
		/* TODO: Do something here*/
	}
	
	m_str[m_length] = '\0';
	
	strcpy(this->m_str, _str);
	
	return;
}



/*
String_t Constructor with const String_t reference
*/
String_t::String_t(const String_t& _str)
{
	/* TODO: how to check valid argument for reference? */
	
	m_length = strlen(_str.m_str);
	
	m_str = new char[m_length + 1];
	
	m_str[m_length] = '\0';
	
	strcpy(this->m_str, _str.m_str);
	
	return;
}



/*
String_t = operator
*/
String_t& String_t::operator= (const String_t& _str_t)
{
	if (this != &_str_t)
	{
		this->Set(_str_t.m_str);
	}
	
	return *this;
}



/*
String_t Get length
*/
size_t String_t::Length() const
{
	return m_length;
}



/*
String_t Get string
*/
const char* String_t::Get() const
{
	return m_str;
}



/*
String_t Set string
*/
void String_t::Set(const char* _str)
{
	if (NULL == _str)
	{
		return;
	}
	
	if (m_length < strlen(_str))
	{
		delete[] m_str;
		
		m_length = strlen(_str);
		
		m_str = new char[m_length + 1];
		
		strcpy(m_str, _str);
		
		return;
	}
	m_length = strlen(_str);
	
	strcpy(m_str, _str);
	
	return;
}



/*
String_t Compare
*/
int String_t::Compare(const String_t& _str_t) const
{	
	int result;
	
	result = strcmp(m_str, _str_t.m_str);

	return result < 0 ? 1 : (result > 0 ? 2 : 0);
}



/*
String_t Print
*/
void String_t::Print() const
{
	printf("%s\n",m_str);
	
	return;
}



/*
String_t convert to Lower case
*/
void String_t::ToLower()
{
	size_t index = 0;

	for (index = 0; index < m_length; ++index)
	{
		if (isupper(m_str[index]))
		{
			m_str[index] = (char)tolower(m_str[index]);
		}
	}
	
	return;
}



/*
String_t convert to Upper case
*/
void String_t::ToUpper()
{
	size_t index = 0;

	for (index = 0; index < m_length; ++index)
	{
		if (islower(m_str[index]))
		{
			m_str[index] = (char)toupper(m_str[index]);
		}
	}
	
	return;
}



/*
String_t prepend from char*
*/
void String_t::Prepend(const char* _str)
{
	if (NULL == _str)
	{
		return;
	}
	
	char* str = new char[strlen(_str) + strlen(m_str) + 1];
	
	strcpy(str, _str);
	
	strcat(str, m_str);
	
	delete[] m_str;
	
	m_length = strlen(str);
	
	m_str = str;
	
	return;
}



/*
String_t prepend from String_t
*/
void String_t::Prepend(const String_t& _str_t)
{
	this->Prepend(_str_t.m_str);
	
	return;
}



/*
String_t += operator const char*
*/
String_t& String_t::operator+= (const char* _str)
{
	if (NULL == _str)
	{
		return *this;
	}
	
	char* str = new char[strlen(_str) + strlen(m_str) + 1];
	
	strcpy(str, m_str);
	
	strcat(str, _str);
	
	delete[] m_str;
	
	m_length = strlen(str);
	
	m_str = str;
	
	return *this;
}



/*
String_t += operator const String_t
*/
String_t& String_t::operator+= (const String_t& _str_t)
{	
	return *this += _str_t.m_str;
}



/*
String_t > operator const char*
*/
bool String_t::operator> (const char* _str) const
{	
	if (NULL == _str)
	{
		return false;
	}

	return m_length > strlen(_str) ? true : false;
}



/*
String_t > operator String_t
*/
bool String_t::operator> (const String_t& _str_t) const
{
	return m_length > _str_t.m_length ? true : false;
}



/*
String_t < operator const char*
*/
bool String_t::operator< (const char* _str) const
{
	if (NULL == _str)
	{
		return false;
	}

	return m_length < strlen(_str) ? true : false;
}



/*
String_t get Ith char
*/
char String_t::IthChar(size_t _i) const
{
	if (0 == m_length || _i >= m_length)
	{
		return '*'; /* '*' indicator of possible error for user, instead of ' ' */
	}
	
	return m_str[_i];
}



/*
String_t get Ith char operator
*/
char String_t::operator[] (size_t _i)
{
	return this->IthChar(_i);
}



/*
String_t contains const char*
*/
bool String_t::Contains(const char* _str) const
{	
	if (NULL == _str)
	{
		return false;
	}
	
	return NULL != strstr(m_str, _str) ? true : false;
}



/*
String_t contains const String_t
*/
bool String_t::Contains(const String_t& _str_t) const
{
	return this->Contains(_str_t.m_str);
}



/*
String_t << operator (equivelant to C stdout)
*/
ostream& operator<< (ostream& _os, const String_t& _str_t)
{
	_os << _str_t.Get();
	
	return _os; 
}



/*
String_t >> operator (equivelant to C stdin)
*/
istream& operator>> (istream& _is, String_t& _str_t)
{
	char str[INIT_STRING_CAPACITY];
	
	_is >> str;
	
	_str_t.Set(str);
	
	return _is; 
}
	



















