#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include "../Book/Book.h"
#include <map>
#include <string>

typedef std::string String;

class Library
{
	public:
		Library(String _libraryConfigPath);
		
		~Library();
		
		bool	AddBook(const Book* _book);
		
		bool	RemoveBook(const Book* _book);
		
		Book*	SearchISBN(String _ISBN) const;
		
		size_t	NumOfBooks() const;
		
	private:
		Library(const Library& _library);
		
		Library& operator= (const Library& _library);
	
		String				m_libraryConfigPath;
		
		map<String, Book*>	m_books;

};


#endif /* #ifndef __LIBRARY_H__ */
















