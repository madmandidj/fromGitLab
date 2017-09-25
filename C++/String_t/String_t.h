#ifndef __STRING_T_H__
#define __STRING_T_H__

#include <stddef.h>
#include <iostream>
using namespace std;


class String_t
{
public:
				String_t();		/* default CTOR */
				~String_t();	/* default destructor */
				String_t(const char* _str);	/* string as input */
				String_t(const String_t& _str_t);	/* copy CTOR */
	String_t&	operator= (const String_t& _str_t);	/*assignment operator*/
	size_t		Length() const;	
	void		SetString(const char* _str);
	const char*	GetString() const;
	int			Compare(const String_t& _str_t) const; /* should be by reference */
	void		Print() const;
	void		ConvertToLowerCase();
	void		ConvertToUpperCase();
	void		Prepend(const char* _str);
	void		Prepend(const String_t& _str_t);
	String_t&	operator+= (const char* _str);	/*append operator*/
	String_t&	operator+= (const String_t& _str_t);	/*append operator*/
	int 		operator> (const char* _str) const;
	int			Contains(const char* _str) const;
	int			Contains(const String_t& _str_t) const;
	char		GetIthChar(size_t _i) const;
	char		operator[] (size_t _i);	/*Ith char operator*/
private:
	char*	m_str;
	size_t	m_length;
};

ostream&	operator<< (ostream& _os, const String_t& _str_t);
istream&	operator>> (istream& _is, String_t& _str_t);

/*
All helper functions should be private
*/































#endif /* #ifndef __STRING_T_H__ */







