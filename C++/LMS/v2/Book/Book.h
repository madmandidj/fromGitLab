#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

using namespace std;

class Book
{
	public:
		Book(string _title, string _author, string _ISBN);
		
		~Book();
		
		const string& 	GetTitle() const;
		
		const string& 	GetAuthor() const;
		
		const string& 	GetISBN() const;
	
	private:
		Book(const Book& _book);
		
		Book& operator= (const Book& _book);
		
		string m_title;
		
		string m_author;
		
		string m_ISBN;
};


#endif /* #ifndef __BOOK_H__ */











































