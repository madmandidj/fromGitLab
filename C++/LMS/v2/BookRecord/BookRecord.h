#ifndef __BOOK_RECORD_H__
#define __BOOK_RECORD_H__

#include <string>
#include <set>
#include <queue>

class Book;

using namespace std;

class BookRecord
{
	public:
		BookRecord(const Book* _book, size_t _numOfCopies);
		
		~BookRecord();
		
		const Book* GetBook() const;
		
		const string& GetBookID() const;
		
		size_t Borrow();	//returns numAvailable
		
		size_t Return();	//return numAvailable
		
		bool AddBorrower(const string& _ID);
		
		bool RemoveBorrower(const string& _ID);
		
		bool AddWaiting(const string& _ID);
		
		bool RemoveWaiting(const string& _ID);
		
		void ReportAllBorrowers() const;
	
	private:
		BookRecord(const BookRecord& _bookRcd);
		
		BookRecord& operator= (const BookRecord& _bookRcd);
		
		Book*				m_book;
		
		size_t				m_numAvailable;;
		
		size_t				m_numOfCopies;
		
		set<string> 		m_borrowersIDs;
		
		queue<string> 		m_waitingList;
};


#endif /* #ifndef __BOOK_RECORD_H__ */











































