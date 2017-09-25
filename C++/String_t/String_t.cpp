#include "String_t.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>




/*
String_t Default constructor
*/
String_t::String_t()
{
	m_length = 0;
	
	m_str = new char[1];
	
	if(0 == m_str)
	{
		return;
	}
	
	m_str[m_length] = '\0';
	
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
	size_t length;
	
	if (NULL == _str)
	{
		return;
	}
	
	m_length = strlen(_str);
	
	m_str = new char[m_length + 1];
	
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
	size_t length;
	
	m_length = strlen(_str.m_str);
	
	m_str = new char[m_length + 1];
	
	m_str[m_length] = '\0';
	
	strcpy(this->m_str, _str.m_str);
	
	return;
}



/*
String_t = operator
*/
String_t String_t::operator= (const String_t& _str_t)
{
	this->SetString(_str_t.m_str);
	
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
const char* String_t::GetString() const
{
	return m_str;
}



/*
String_t Set string
*/
void String_t::SetString(const char* _str)
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
int String_t::Compare(const String_t _str_t) const
{	
	int result;
	
	result = strcmp(m_str, _str_t.m_str);
	
	if (result < 0)
	{
		return 1;
	}
	else if (result > 0)
	{
		return 2;
	}
	
	return 0; 
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
void String_t::ConvertToLowerCase()
{
	size_t index = 0;
	
	for (index = 0; index < m_length; ++index)
	{
		if ('A' <= m_str[index] && 'Z' >= m_str[index])
		{
			m_str[index] += 32;
		}
	}
	
	return;
}



/*
String_t convert to Upper case
*/
void String_t::ConvertToUpperCase()
{
	size_t index = 0;
	
	for (index = 0; index < m_length; ++index)
	{
		if ('a' <= m_str[index] && 'z' >= m_str[index])
		{
			m_str[index] -= 32;
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
String_t String_t::operator+= (const char* _str)
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
String_t String_t::operator+= (const String_t& _str_t)
{	
	return *this += _str_t.m_str;
}



/*
String_t > operator const String_t
*/
int String_t::operator> (const char* _str) const
{	
	if (NULL == _str)
	{
		return 0;
	}
	
	if (m_length > strlen(_str))
	{
		return 1;
	}
	return 0;
}



/*
String_t get Ith char
*/
char String_t::GetIthChar(const size_t _i) const
{
	if (0 == m_length || _i >= m_length)
	{
		return ' ';
	}
	
	return m_str[_i];
}



/*
String_t contains const char*
*/
int String_t::Contains(const char* _str) const
{
	size_t length;
	size_t index;
	size_t strtIndex;
	size_t strIndex;
	int cont;
	
	if (NULL == _str)
	{
		return 0;
	}
	
	length = strlen(_str);
	
	if (length > m_length)
	{
		return 0;
	}
	
	for (index = 0; index <= m_length - length; ++index)
	{
		cont = 1;
		strIndex = 0;
		strtIndex = index;
		while(cont)
		{
			if (m_str[strtIndex] == _str[strIndex])
			{
				if (strIndex == length - 1)
				{
					return 1;
				}
				++strtIndex;
				++strIndex;
			}
			else
			{
				cont = 0;
			}
		}
	}
	
	return 0;
}




/*
String_t contains const String_t
*/
int String_t::Contains(const String_t& _str_t) const
{
	return this->Contains(_str_t.m_str);
}

























