#ifndef __CHARBUF_H__
#define __CHARBUF_H__

#include <stddef.h>
#include <iostream>
using namespace std;


class CharBuf
{
	public:	//public member functions
					CharBuf();												/* default CTOR */
					CharBuf(size_t _capacity = 1);							/* size_t CTOR */
					CharBuf(const char* _chars = 0);						/* char* CTOR */		
					CharBuf(const char* _chars = 0, size_t _capacity = 1);	/* char* and size_t CTOR*/	
					CharBuf(const CharBuf& _charbuf);						/* copy CTOR */
					~CharBuf();												/* DTOR */
		bool		SetCapacity(size_t _newCapacity);
		size_t		GetCapacity() const;				
		bool		SetLength(size_t _newLength);												
		size_t		GetLength() const;	
		bool		SetChars(const char* _chars);
		bool		SetChars(const char* _chars, size_t _bufIndex = 0);
		const char*	GetChars() const;
		const char*	GetChars(size_t _bufIndex = 0, size_t length = 1) const;	 			
		void		Print() const;	
		CharBuf&	operator= (const char* _chars);			
		CharBuf&	operator= (const CharBuf& _charbuf);				
		CharBuf&	operator+= (const char* _chars);				
		CharBuf&	operator+= (const CharBuf& _charbuf);
		bool		operator[] (char _char, size_t _i);				
		char		operator[] (size_t _i) const;	
		bool		operator() (const char* _chars, size_t _bufIndex = 0);				
		char*		operator() (size_t _bufIndex = 0, size_t length = 1) const;					
	
	public: // public static member functions
		static size_t 	GetDefaultCap();
		static size_t 	SetDefaultCap();
	
	private: //private members
		char*			m_buf;
		size_t			m_length;							
		size_t			m_capacity;
	
	private: //private member functions
		void			CharBufInit();
		char* 			CreateFrom(const char* _str, size_t _capacity);

	private: //private static members
		static size_t 	m_defaultCap;
};

ostream&	operator<< (ostream& _os, const CharBuf& _charbuf);
istream&	operator>> (istream& _is, CharBuf& _charbuf);


#endif /* #ifndef __CHARBUF_H__ */






