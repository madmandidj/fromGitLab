#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

typedef std::string String;

class Book
{
	public:
		Book(String _title, String _firstName, String _lastName, String _ISBN);
		
		~Book();
		
		String 	GetTitle() const;
		
		String 	GetAuthor() const;
		
		String 	GetFirstName() const;
		
		String 	GetLastName() const;
		
		bool operator== (String _ISBN) const;
	
	private:
		Book(const Book& _book);
		
		Book& operator= (const Book& _book);
		
		String m_title;
		
		String m_firstName;
		
		String m_lastName;
		
		String m_ISBN;
};


#endif /* #ifndef __BOOK_H__ */











































