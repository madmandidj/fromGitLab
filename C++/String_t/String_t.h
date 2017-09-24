#ifndef __STRING_T_H__
#define __STRING_T_H__
#include <stddef.h>


class String_t
{
public:
				String_t();		/* default CTOR */
				~String_t();	/* default destructor */
				String_t(const char* _str);	/* string as input */
				String_t(const String_t& _str_t);	/* copy CTOR */
	String_t	operator= (const String_t& _str_t);	/*assignment operator*/
	size_t		Length() const;	
	void		SetString(const char* _str);
	const char*	GetString() const;
	int			Compare(const String_t _str_t) const;
	void		Print() const;
	void		ConvertToLowerCase();
	void		ConvertToUpperCase();
	void		Prepend(const char* _str);
	void		Prepend(String_t _str_t);
	/* TODO: logical operators */
	void		Contains(const char* _str) const;
	void		Contains(const String_t _str_t) const;
	char		GetIthChar(const size_t _i) const;
	
private:
	char*	m_str;
	size_t	m_length;
};


































#endif /* #ifndef __STRING_T_H__ */







