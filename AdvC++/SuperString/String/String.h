#ifndef __STRING_H__
#define __STRING_H__
namespace advcpp
{

class Buffer;

class String
{
public:
	virtual ~String();
	String();
	String(const String& _str);
	String& operator=(const String& _str);
	String(const char* _c_str);
	const char* C_Str() const;
	size_t Length();
	void ToUpper();
	void ToLower();
	bool operator==(const String& _str) const;
	bool operator!=(const String& _str) const;
	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;
	String operator+(const String& _str) const;
	
	
protected:
	Buffer* m_buffer;
private:
	
};










} //namespace advcpp
#endif //#define __STRING_H__


