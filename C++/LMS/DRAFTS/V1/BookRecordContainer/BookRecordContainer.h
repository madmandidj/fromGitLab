#ifndef __BOOK_RECORD_CONTAINER_H__
#define __BOOK_RECORD_CONTAINER_H__

#include "../Book/BookRecord.h"
#include <map>
#include <vector>
#include <string>

/* TODO: Is an overriding Compare() / Less function required for map ?*/

class BookRecordContainer
{
	public:
		BookRecordContainer(std::string _bookRecordsPath);
		
		~BookRecordContainer();
		
		bool 		Add(const BookRecord* _bookRcd); /* If censorship mode ON, book might not be added */
		
		bool 		Remove(std::string _ISBN);
		
		BookRecord* SearchTitle(std::string _title) const; // O(n)
		
		BookRecord* SearchAuthor(std::string _author) const; // O(n)
		
		std::vector<BorrowerRecord*> SearchISBN(std::string _ISBN) const; // O(log(n))
		
		bool 		Report(std::string _ISBN) const;
		
		void 		ReportAll() const;
	
	private:
		BookRecordContainer(const BookRecordContainer& _bookRcdCont);
		
		BookRecordContainer& operator= (const BookRecordContainer& _bookRcdCont);
		
		map<string, BookRecord*>	m_bookRecords;
};









#endif /* #ifndef __BOOK_RECORD_CONTAINER_H__ */











































