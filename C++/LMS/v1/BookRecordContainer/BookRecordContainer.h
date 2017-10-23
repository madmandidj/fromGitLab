#ifndef __BOOK_RECORD_CONTAINER_H__
#define __BOOK_RECORD_CONTAINER_H__

#include "../BookRecord/BookRecord.h"
#include <map>
#include <vector>
#include <string>

typedef std::string String;

class BookRecordContainer
{
	public:
		BookRecordContainer(String _bookRecordConfigPath);
		
		~BookRecordContainer();
		
		bool 						Add(const BookRecord* _bookRcd);
		
		bool 						Remove(const BookRecord* _bookRcd);
		
		std::vector<BookRecord*> 	SearchTitle(String _title) const; // O(n)
		
		std::vector<BookRecord*> 	SearchAuthor(String _author) const; // O(n)
		
		BookRecord* 				SearchISBN(String _ISBN) const; // O(log(n))
		
		bool 						Report(const BookRecord* _bookRcd) const;
		
		void 						ReportAll() const;
	
	private:
		BookRecordContainer(const BookRecordContainer& _bookRcdCont);
		
		BookRecordContainer& operator= (const BookRecordContainer& _bookRcdCont);
		
		String						m_bookRecordConfigPath
		
		map<String, BookRecord*>	m_bookRecords;
};


#endif /* #ifndef __BOOK_RECORD_CONTAINER_H__ */











































