#ifndef __BOOKADMIN_H__
#define __BOOKADMIN_H__

#include <string>
#include <vector>

class Book;
class BookRecord;
class BookRecordContainer;

using namespace std;

class BookAdmin
{
	public:
		BookAdmin(const BookRecordContainer* _bookRcdCont);
		
		~BookAdmin();
	
		bool AddBook(const Book* _book, size_t _numOfCopies);
		
		bool RemoveBook(const string& _ISBN);
		
		bool BorrowBook(const string& _ISBN, const string& _ID) const;
		
		bool ReturnBook(const string& _ISBN, const string& _ID) const;
		
		vector<BookRecord*> SearchBookTitle(const string& _title) const;
		
		vector<BookRecord*>	SearchBookAuthor(const string& _author) const;
		
		const BookRecord* SearchBookISBN(const string& _ISBN) const;
		
		void BookReport(const BookRecord* _bookRcd) const;
		
		void BookReportAll() const;
	
	private:
		string 					m_adminID;
		
		BookRecordContainer*	m_bookRcdCont;
};






#endif /* #ifndef __BOOKADMIN_H__ */





