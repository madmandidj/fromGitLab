#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

class Book
{
	public:
		Book(std::string _title, std::string _firstName, std::string _lastName, std::string _ISBN);
		
		~Book();
		
		std::string 	GetTitle() const;
		
		std::string 	GetAuthor() const;
		
		std::string 	GetFirstName() const;
		
		std::string 	GetLastName() const;
		
		bool 			operator== (std::string _ISBN) const;
	
	private:
		Book(const Book& _book);
		
		Book& 			operator= (const Book& _book);
		
		std::string		m_title;
		
		std::string		m_firstName;
		
		std::string		m_lastName;
		
		std::string		m_ISBN;
};




#endif /* #ifndef __BOOK_H__ */











































