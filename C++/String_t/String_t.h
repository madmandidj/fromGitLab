#ifndef __STRING_T_H__
#define __STRING_T_H__

#include <stddef.h>
#include <iostream>
using namespace std;


class String_t
{
	public:
					String_t();									/* default CTOR */
					~String_t();								/* DTOR */
					String_t(const char* _str);					/* char* CTOR */
					String_t(const String_t& _str_t);			/* copy CTOR */
		size_t		Length() const;	
		void		Set(const char* _str);
		const char*	Get() const;
		int			Compare(const String_t& _str_t) const; 
		void		Print() const;
		void		ToLower();
		void		ToUpper();
		void		Prepend(const char* _str);
		void		Prepend(const String_t& _str_t);
		bool		Contains(const char* _str) const;
		bool		Contains(const String_t& _str_t) const;
		char		IthChar(size_t _i) const;					/* Get Ith char */
		String_t&	operator= (const String_t& _str_t);			/* assignment operator*/	
		String_t&	operator+= (const char* _str);				/* Append char* */
		String_t&	operator+= (const String_t& _str_t);		/* Append String_t */
		bool 		operator> (const char* _str) const; 		/* returns true if length larger than input char* */
		bool 		operator> (const String_t& _str_t) const; 	/* returns true if length larger than input String_t*/
		bool 		operator< (const char* _str) const; 		/* returns true if length smaller than input char* */
		char		operator[] (size_t _i);						/* [] Get Ith char operator*/
	
	private:
		char*	m_str;
		size_t	m_length;
		void	DefaultCTOR();								
};

ostream&	operator<< (ostream& _os, const String_t& _str_t);
istream&	operator>> (istream& _is, String_t& _str_t);


#endif /* #ifndef __STRING_T_H__ */






