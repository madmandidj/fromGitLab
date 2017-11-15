#include "String.h"
#include "../Buffer/Buffer.h"
#include<exception>
namespace advcpp
{

String::~String()
{
	//Empty
}

String::String() : m_buffer(1), m_length(0)
{
	//Empty
}

String::String(const String& _str)
{
//	const char* c_str = _str.C_Str();
	
	m_length = _str.Length();
	
	m_buffer.SetBuffer(_str.C_Str(), m_length + 1); //TODO: IfFailDo
}

String::String(const char* _c_str)
{
	if (0 == _c_str)
	{
		throw std::runtime_error("String::String(const char* _c_str), invalid parameter");
	}
	
	m_length = strlen(_c_str);
	
	m_buffer.SetBuffer(_c_str, m_length + 1);
}


String& String::operator=(const String& _str)
{
	m_length = _str.Length();
	
	m_buffer.SetBuffer(_str.C_Str(), m_length + 1); //TODO: IfFailDo
	
	return *this;
}


const char* String::C_Str() const
{
	return m_buffer.GetBuffer();
}


size_t String::Length() const
{
	return m_length;
}


bool String::operator==(const String& _str) const
{
	return (0 == strcmp(C_Str(), _str.C_Str())) ? true : false; 
}


bool String::operator!=(const String& _str) const
{
	return !(*this == _str);
}


char& String::operator[](size_t _index)
{
	return const_cast<char&>(m_buffer.GetElement(_index)); //NOTE: const_cast here
}


const char& String::operator[](size_t _index) const
{
	return m_buffer.GetElement(_index);
}


String String::operator+(const String& _str) const
{
	size_t newLength = Length() + _str.Length();
	char* new_c_str = new char[newLength + 1];
	const char* this_c_str = C_Str();
	const char* other_c_str = _str.C_Str();
	strcpy(new_c_str, this_c_str);
	strcat(new_c_str, other_c_str);
	String str(new_c_str);
	delete new_c_str;
	
	return str;
//	return "temp"; //NOTE: this could not be returned when explicit copy CTOR
//	return (String)"temp"; //NOTE: this is good!
}

String& String::operator+=(const String& _str)
{
	*this = (*this + _str);
	
	return *this;
}


std::ostream& operator<<(std::ostream& _os, String& _str)
{
	const char* c_str = _str.C_Str();
	_os << c_str;
	return _os;
}























} //namespace advcpp

