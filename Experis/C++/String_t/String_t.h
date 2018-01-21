#ifndef __STRING_T_H__
#define __STRING_T_H__

#include <stddef.h>
#include <iostream>
using namespace std;


class String_t
{
	public:	//public member functions
					String_t();								/* default CTOR */
					String_t(const char* _str);				/* char* CTOR */
					String_t(const String_t& _str_t);		/* copy CTOR */
					~String_t();							/* DTOR */
		size_t		Length() const;	
		void		Set(const char* _str);
		const char*	Get() const;
		int			Compare(const String_t& _str_t) const;
		int			Compare(const char* _str) const; 	 		
		void		Print() const;
		void		ToLower();
		void		ToUpper();
		void		Prepend(const char* _str);
		void		Prepend(const String_t& _str_t);
		bool		Contains(const char* _str) const;
		bool		Contains(const String_t& _str_t) const;
		char		IthChar(size_t _i) const;					
		String_t&	operator= (const String_t& _str_t);				
		String_t&	operator+= (const char* _str);				
		String_t&	operator+= (const String_t& _str_t);		
		bool 		operator> (const char* _str) const; 		
		bool 		operator> (const String_t& _str_t) const; 	
		bool 		operator< (const char* _str) const; 		
		char		operator[] (size_t _i);						
	
	public: // public static member functions
		static size_t	GetNumOfStrings();
		static bool 	GetCaseSens();
		static void		SetCaseSens(bool _value);
		static size_t 	GetDefaultCap();
		static size_t 	SetDefaultCap();
	
	private: //private members
		char*			m_str;
		size_t			m_length;							
		size_t			m_capacity;
	
	private: //private member functions
		void			StringtInit();
		void 			SetCapacity(size_t _cap);
		void			SetLength(size_t _length);
		size_t			GetNewCapacity(size_t _newLength);
		char* 			CreateFrom(const char* _str, size_t _capacity);

	private: //private static members
		static size_t	m_numOfStrings;
		static size_t 	m_defaultCap;
		static bool		m_caseSens;
};

ostream&	operator<< (ostream& _os, const String_t& _str_t);
istream&	operator>> (istream& _is, String_t& _str_t);


#endif /* #ifndef __STRING_T_H__ */






