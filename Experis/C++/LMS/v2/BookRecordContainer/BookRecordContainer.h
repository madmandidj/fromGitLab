#ifndef __BOOK_RECORD_CONTAINER_H__
#define __BOOK_RECORD_CONTAINER_H__

#include <map>
#include <vector>
#include <string>

using namespace std;

class BookRecord;

class BookRecordContainer
{
	public:
		BookRecordContainer();
		
		~BookRecordContainer();
		
		bool Add(const BookRecord* _bookRcd);
		
		bool Remove(const string& _ISBN);
		
		vector<BookRecord*> SearchTitle(const string& _title) const; // O(n)
		
		vector<BookRecord*> SearchAuthor(const string& _author) const; // O(n)
		
		const BookRecord* SearchISBN(const string& _ISBN) const; // O(log(n))
		
		void Report(const BookRecord* _bookRcd) const;
		
		void ReportAll() const;
	
	private:
		BookRecordContainer(const BookRecordContainer& _bookRcdCont);
		
		BookRecordContainer& operator= (const BookRecordContainer& _bookRcdCont);
		
		map<string, BookRecord*> m_bookRcdCont;
};


#endif /* #ifndef __BOOK_RECORD_CONTAINER_H__ */











































