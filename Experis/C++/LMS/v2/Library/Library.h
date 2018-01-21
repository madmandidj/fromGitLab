#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <map>
#include <string>

class Book;
class BookRecordContainer;
class BorrowerRecordContainer;
class BookAdmin;
class BorrowerAdmin;

using namespace std;

class Library
{
	public:
		Library();
		
		~Library();
		
		void Run();
		
		void Quit();
		
	private:
		Library(const Library& _library);
		
		Library& operator= (const Library& _library);
		
		map<string, Book*>			m_books;
		
		BookRecordContainer* 		m_bookRcdCont;
		
		BorrowerRecordContainer* 	m_borrRcdCont;
		
		BookAdmin*					m_bookAdmin;
		
		BorrowerAdmin*				m_borrowerAdmin;
};


#endif /* #ifndef __LIBRARY_H__ */












