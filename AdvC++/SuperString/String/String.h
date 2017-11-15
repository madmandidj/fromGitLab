#ifndef __STRING_H__
#define __STRING_H__
#include "../Buffer/Buffer.h"

namespace advcpp
{

class String
{
public:
	virtual ~String();
	explicit String();
	String(const String& _str);
	String(const char* _c_str);
	String& operator=(const String& _str);
	const char* C_Str() const;
	size_t Length() const;
	bool operator==(const String& _str) const;
	bool operator!=(const String& _str) const;
	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;
	String operator+(const String& _str) const;
	String& operator+=(const String& _str);
	
	//	void ToUpper(); //Should be in StringManip.h
	//	void ToLower(); //Should be in StringManip.h
	
protected:
	Buffer<char> 	m_buffer;
	size_t			m_length;
private:
	
};

std::ostream& operator<<(std::ostream& _os, String& _str);




} //namespace advcpp

#endif //#define __STRING_H__


