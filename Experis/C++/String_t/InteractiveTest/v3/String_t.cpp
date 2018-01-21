#include "String_t.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define INIT_STRING_CAPACITY 128



/*
Static member initializers
*/
unsigned int String_t::m_numOfStrings = 0;
bool String_t::m_caseSens = true;
unsigned int String_t::m_defaultCap = 1;



/*
private Get new capacity
*/
size_t String_t::GetNewCapacity()
{
	size_t newCapacity = 1;
	
	while (m_length >= newCapacity)
	{
		newCapacity *= 2; /* TODO: find more efficient way of finding closest power of 2 */
	}
	
	return newCapacity;
}



/*
private String_t Create From char*
*/
void String_t::CreateFrom(const char* _str)
{	
	m_capacity = String_t::m_defaultCap;
	
	m_length = 0;
	
	if (NULL != _str)
	{
		m_length = strlen(_str);
	
		if (m_length >= m_capacity)
		{
			m_capacity = this->GetNewCapacity();
		}
	}
	
	m_str = new char[m_capacity];
		
	if(0 == m_str)
	{
		/* TODO: Do something here*/
	}	
	
	strcpy(this->m_str, NULL == _str ? "" : _str);
	
	++String_t::m_numOfStrings;
	
	return;
}



/*
String_t Default constructor
*/
String_t::String_t()
{
	this->CreateFrom(NULL);
	
	return;
}



/*
String_t Destructor
*/
String_t::~String_t()
{
	delete[] m_str;
	
	--String_t::m_numOfStrings;
	
	return;
}



/*
String_t Constructor with const char*
*/
String_t::String_t(const char* _str)
{
	this->CreateFrom(_str);

	return;
}



/*
String_t Constructor with const String_t reference
*/
String_t::String_t(const String_t& _str_t)
{
	this->CreateFrom(_str_t.m_str);
	
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
	
	m_length = strlen(_str);
	
	if (m_length >= m_capacity)
	{
		delete[] m_str;
		
		m_capacity = this->GetNewCapacity();
		
		m_str = new char[m_capacity];
		
		strcpy(m_str, _str);
		
		return;
	}
	
	strcpy(m_str, _str);
	
	return;
}



/*
String_t Compare char*
*/
int String_t::Compare(const char* _str) const
{
	int result;
	
	if (NULL == _str)
	{
		return 1; /* TODO: what to do in case that m_str is empty */
	}
	
	if (true == m_caseSens)
	{
		result = strcmp(m_str, _str);
	}
	else
	{
		result = strcasecmp(m_str, _str);
	}
	
	return result < 0 ? 1 : (result > 0 ? 2 : 0);
}



/*
String_t Compare String_t
*/
//int String_t::Compare(String_t _str_t) const
//{	
//	int result;
//	String_t s1 = *this;
//	
//	if (true == m_caseSens)
//	{
//		result = strcmp(m_str, _str_t.m_str);
//	}
//	else
//	{
//		_str_t.ToLower();
//		s1.ToLower();
//		result = strcmp(s1.m_str, _str_t.m_str);
//	}
//	
//	return result < 0 ? 1 : (result > 0 ? 2 : 0);
//}

int String_t::Compare(const String_t& _str_t) const
{	
	return this->Compare(_str_t.m_str);
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
	
	m_length = strlen(_str) + strlen(m_str);
	
	if (m_length >= m_capacity)
	{	
		m_capacity = this->GetNewCapacity();
	}
	
	char* str = new char[m_capacity];
	
	strcpy(str, _str);

	strcat(str, m_str);
	
	delete[] m_str;
	
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
	
	m_length = strlen(_str) + strlen(m_str);
	
	if (m_length >= m_capacity)
	{	
		m_capacity = this->GetNewCapacity();
		
		char* str = new char[m_capacity];
	
		strcpy(str, m_str);

		strcat(str, _str);
	
		delete[] m_str;
	
		m_str = str;
		
		return *this;
	}

	strcat(m_str, _str);
	
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
	/* TODO: add case where this string is NULL and _str is NULL so then they are equal */
	if (NULL == _str)
	{
		return false;
	}
	
//	if (true == m_caseSens)
//	{
//		String_t s1 = _str;
		
		return 1 == this->Compare(_str) ? true : false;
//	}
	
//	String_t s1 = *this;
//	
//	String_t s2 = _str;
//	
//	s1.ToLower();
//	
//	s2.ToLower();

	
		
//	return 1 == s1.Compare(s2) ? true : false;
}



/*
String_t > operator String_t
*/
bool String_t::operator> (const String_t& _str_t) const
{
	/*TODO: Compare should be used here */
//	return m_length > _str_t.m_length ? true : false;
	
	return this->m_str > _str_t.m_str;
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
	
	/*TODO: Compare should be used here */
	return m_length < strlen(_str) ? true : false;
}



/*
String_t get Ith char
*/
char String_t::IthChar(size_t _i) const
{
	if (0 == m_length || _i >= m_length)
	{
		/*TODO: instead of return, should be exception handler here */
		return '*'; /* '*' indicator of possible error for user */
	}
	
	return m_str[_i];
}



/*
String_t get Ith char operator
TODO: make another prototype that returns char& so can do str[2] = 'c'
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
	
	if (true == m_caseSens)
	{
		return strstr(m_str, _str);
	}
	
	String_t s1 = *this;
	
	String_t s2 = _str;	
	
	s1.ToLower();
	
	s2.ToLower();

	return strstr(s1.m_str, s2.m_str);
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
	


/*
static member function get current number of String_t instances
*/
unsigned int String_t::GetNumOfStrings() 
{
	return String_t::m_numOfStrings;
}



/*
static member function get current Case sensitivity state
*/
bool String_t::GetCaseSens() 
{
	return String_t::m_caseSens;
}



/*
static member function set current Case sensitivity state
*/
void String_t::SetCaseSens(bool _value) 
{
	String_t::m_caseSens = _value;
	
	return;
}









