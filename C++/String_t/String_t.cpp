#include "String_t.h"
#include <stdio.h>
#include <string.h>

#define INIT_CAPACITY 128

String_t::String_t()
{
	m_length = INIT_CAPACITY;
	m_length = 0;
	m_str = new char[m_length];
	if(0 == m_str)
	{
		printf("call to function new returned 0\n");
	}
	m_str[0] = '\0';
	
	return;
}



String_t::~String_t()
{
	delete[] m_str;
	
	return;
}



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



void String_t::Print() const
{
	printf("%s\n",m_str);
	
	return;
}
















